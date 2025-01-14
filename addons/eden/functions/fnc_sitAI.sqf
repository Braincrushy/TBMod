#include "../script_component.hpp"
/*
    Part of the TBMod ( https://github.com/TacticalBaconDevs/TBMod )
    Developed by http://tacticalbacon.de
*/
params ["_unit"];

if (!alive _unit || !local _unit) exitWith {};

_unit setVariable ["acex_headless_blacklist", true, true];

private _objs = (nearestObjects [_unit, [], 2]) select {getNumber (configOf _x >> "acex_sitting_canSit") == 1};
if (_objs isEqualTo []) then {(nearestTerrainObjects [_unit, [], 2]) select {getNumber (configOf _x >> "acex_sitting_canSit") == 1}};
private _stuhl = objNull;

private _canBeDamaged = isDamageAllowed _unit;
_unit allowDamage false;

if (_objs isEqualTo []) then
{
    private _typeOf = selectRandom ["Land_ChairWood_F", "Land_CampingChair_V1_F", "Land_CampingChair_V2_F"];
    _stuhl = createVehicle [_typeOf, [0,0,0], [], 0, "CAN_COLLIDE"];
    _stuhl setDir ((getDir _unit) - getNumber (configOf _stuhl >> "acex_sitting_sitDirection"));
    _stuhl setPosASL (getPosASL _unit);
    [_stuhl, false] remoteExec ["enableSimulationGlobal", [0, 2] select isMultiplayer];
}
else
{
    _stuhl = _objs select 0;
};

[_stuhl, _unit] call acex_sitting_fnc_sit;
if (_canBeDamaged) then {_unit allowDamage true};
