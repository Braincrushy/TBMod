#include "../script_component.hpp"
/*
    Part of the TBMod ( https://github.com/TacticalBaconDevs/TBMod )
    Developed by http://tacticalbacon.de
*/
if (isMultiplayer && !isServer && !isRemoteExecuted) exitWith {_this remoteExec [QFUNC(initCRAM), 2]};

params ["_cram", "_truck"];

if (!isNil "_truck") then {_cram attachTo [_truck, [-0.05,-0.3,1.7]]};

if (isNil QGVAR(CRAM_active)) then {GVAR(CRAM_active) = true};
if (isNil QGVAR(CRAM_range)) then {GVAR(CRAM_range) = 1000};
if (isNil QGVAR(CRAM_chance)) then {GVAR(CRAM_chance) = 30};
if (isNil QGVAR(CRAM_check)) then {GVAR(CRAM_check) = 0.5};
if (isNil QGVAR(CRAM_dauerAdd)) then {GVAR(CRAM_dauerAdd) = 0.1};
if (isNil QGVAR(CRAM_loopSpeed)) then {GVAR(CRAM_loopSpeed) = 0.01};

if (isNil QFUNC(activeTarget)) then
{
    FUNC(activeTarget) = {
        params ["_cram", "_target"];
        alive _target && {((getPosATL _target) param [2, 0]) > ((getPosATL _cram) param [2, 0])} && {count (magazines _cram) > 0};
    };
};

if (isNil QFUNC(getTargetPos)) then
{
    FUNC(getTargetPos) = {
        private _pos = if ((unitAimPositionVisual _this) isEqualTo [0,0,0]) then {getPosVisual _this} else {unitAimPositionVisual _this};
        private _velocity = velocity _this;
        _pos vectorAdd (_velocity vectorMultiply 0.55);
    };
};

if (isNil QFUNC(getBestTarget)) then
{
    FUNC(getBestTarget) = {
        params ["_target", "_seeker"];
        private _downSpeed = abs (((velocityModelSpace _target) select 2) min 0);

        (((getPosATL _x) param [2, 0]) - (2 * _downSpeed)) > ((getPosATL _seeker) param [2, 0]);
    };
};

//GVAR(arty_seekers) pushBackUnique ["CRAM", _cram, GVAR(CRAM_range)];
//[QGVAR(arty_seekers), GVAR(arty_seekers)] call CBA_fnc_publicVariable;

// make dumb
private _group = group (gunner _cram);
_group setBehaviour "CARELESS";
_group setCombatBehaviour "CARELESS";
_group enableAttack false;
{
    _x setBehaviour "CARELESS";
    _x setCombatBehaviour "CARELESS";
    _x setSkill 1;
    _x setVariable ["lambs_danger_disableAI", true, true];
    _x disableAI "AUTOCOMBAT";
    _x disableAI "AUTOTARGET";
}
forEach (units _group);

_group setVariable ["lambs_danger_disableGroupAI", true, true];

private _search = 0;
while {GVAR(CRAM_active)} do
{
    scopeName "getTarget";

    for "_i" from 0 to 3 do
    {
        private _targets = _cram nearObjects [["ShellCore", "RocketCore", "MissileCore", "SubmunitionCore"] select _i, GVAR(CRAM_range)];
        private _target = _targets param [_targets findIf {[_x, _cram] call FUNC(getBestTarget)}, objNull];

        if (alive _target) then
        {
            _cram reveal [_target, 4];
            ["CRAM: Target recived: %1 - Target: %2 (%3)", _cram, _target, typeOf _target] call TBMod_main_fnc_debug;

            // drauf zielen
            private _iter = 10;
            for "_i" from 1 to _iter do
            {
                if !([_cram, _target] call FUNC(activeTarget)) exitWith {};

                _cram lookAt _target;
                _cram doWatch _target;

                uiSleep (1 / _iter);
            };

            ["CRAM: Target anvisiert: %1 - Target: %2 (%3)", _cram, _target, typeOf _target] call TBMod_main_fnc_debug;

            // bekämpfen
            private _adding = 0;
            while {[_cram, _target] call FUNC(activeTarget)} do
            {
                //_cram lookAt _target;
                private _posVor = _target call FUNC(getTargetPos);
                _cram lookAt _posVor;
                _cram doWatch _posVor;

                private _value = 0;
                if (deg (_cram animationSourcePhase "maingun") > 1) then //&& (_cram getRelDir _target) < 50 || (_cram getRelDir _target) > 310*/) then {
                {
                    _cram fireAtTarget [_target];

                    _value = _adding + (linearConversion [GVAR(CRAM_range), 0, _target distance _cram, 1, GVAR(CRAM_chance), true]);
                    _value = _value + (linearConversion [300, 0, (getPosATL _target) param [2, 0], 0, GVAR(CRAM_chance), true]);
                    private _random = floor (random 100);

                    if (diag_tickTime % GVAR(CRAM_check) <= 0.01) then
                    {
                        if (diag_tickTime % 1 <= 0.01) then {playSound3D ["a3\sounds_f\sfx\alarm_3.wss", _cram, false, getPosASL _cram, 2, 1, 300]};

                        //["Chance: %1 - DauerBonus: %2 - Random: %3", _value, _adding, _random] call TBMod_main_fnc_debug;

                        if (_random < _value) then
                        {
                            createVehicle [selectRandomWeighted ["HelicopterExploSmall", 0.8, "HelicopterExploBig", 0.2], getPosATL _target, [], 0, "FLY"];
                            _target setDamage 1;
                            deleteVehicle _target;

                            breakTo "getTarget"
                        };
                    };
                };

                _adding = _adding + GVAR(CRAM_dauerAdd);
                uiSleep GVAR(CRAM_loopSpeed);
            };

            ["CRAM: Target bekämpft / weg: %1", _cram] call TBMod_main_fnc_debug;
        } else {
            _search = if (_search >= 360) then {0} else {_search + 1};

            //_cram animateSource ["maingun", rad 30, true];
            private _pos = _cram getPos [20, _search];
            _pos set [2, (_pos select 2) + 20];

            _cram lookAt _pos;
        };
    };

    uiSleep 0.1;
};

/*
    Vorhalten anzeigen:

    onEachFrame
    {
        if (!isNil Q_target && alive _target) then
        {
            private _pos = if ((unitAimPositionVisual _target) isEqualTo [0,0,0]) then {getPosVisual _target} else {unitAimPositionVisual _target};
            //systemChat str _pos;
            private _velocity = velocity _target;

            // Rot
            drawIcon3D ["", [1,0,0,1], _pos, 0, 0, 0, "X"];

            // Grün
            drawIcon3D ["", [0,1,0,1], _pos vectorAdd _velocity, 0, 0, 0, "X1"];
            // Blau
            drawIcon3D ["", [0,0,1,1], _pos vectorAdd (_velocity vectorMultiply 0.6), 0, 0, 0, "X2"];
            // GELB
            drawIcon3D ["", [1,1,0,1], _pos vectorAdd (_velocity vectorMultiply 1.3), 0, 0, 0, "X3"];
        };
    };
*/
