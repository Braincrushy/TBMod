﻿#include "\a3\editor_f\Data\Scripts\dikCodes.h"
/*
    Part of the TBMod ( https://github.com/shukari/TBMod )
    Developed by http://tacticalbacon.de
*/
// https://github.com/CBATeam/CBA_A3/wiki/Keybinding
// https://github.com/CBATeam/CBA_A3/blob/master/addons/keybinding/fnc_addKeybind.sqf
[
    "TBMod",
    "TBMod_hideGUI_key",
    "Zeigt/Verbirgt die GUI",
    {
        ["sthud_settings_hudmode", [0 , 3] select (sthud_settings_hudmode == 0)] call CBA_settings_fnc_set;
        systemChat format ["HUD ist nun %1", ["sichtbar" , "unsichtbar"] select (sthud_settings_hudmode == 0)];
    },
    {},
    [DIK_J, [false, false, true]]
] call CBA_fnc_addKeybind;

// TODO: alle Keybinds to CBA

waitUntil {!isNull (findDisplay 46)};
(findDisplay 46) displayAddEventHandler ["KeyDown", {
    params ["", "_code", "_shift", "_ctrl", "_alt"];

    _ret = false;

    if !(getPlayerUID player in (TB_lvl3 + TB_lvl2)) exitWith {_ret};

    // ENDE + STRG
    if (_code == DIK_END && {_ctrl}) then
    {
        [ACE_player] spawn TB_fnc_showGCAM;
        ["TB_informAdminsAndZeus", ["%1 hat GCAM gestartet!", profileName]] call CBA_fnc_globalEvent;
        systemChat "GCAM gestartet!";
        _ret = true;
    };

    // ENDE + SHIFT
    if (_code == DIK_END && {_shift}) then
    {
        if (isNil "TB_main_spectator") then {TB_main_spectator = false};

        TB_main_spectator = !TB_main_spectator;

        //[ACE_player, TB_main_spectator] call TFAR_fnc_forceSpectator;
        ACE_player setVariable ["TFAR_curatorCamEars", TB_main_spectator, true];

        systemChat format ["TFAR-Spectator: %1", TB_main_spectator];

        _ret = true;
    };

    if !(getPlayerUID player in TB_lvl3) exitWith {_ret};

    // ALT + STRG
    if (_code == DIK_END && {_alt}) then
    {
        private _zeusModule = player getVariable ["TB_Admin_Zeus", objNull];
        if (isNull _zeusModule) then {
            if (!isNull (getAssignedCuratorLogic player)) exitWith {systemChat "Du hast bereits einen Zeus!"};

            ["TB_addZeus", player] call CBA_fnc_serverEvent;
            _ret = true;
        }
        else
        {
            deleteVehicle _zeusModule;
            player setVariable ["TB_Admin_Zeus", nil];
            ["TB_informAdminsAndZeus", ["%1 ist kein Zeus mehr", profileName]] call CBA_fnc_globalEvent;
            systemChat "Zeus gelöscht";
            _ret = true;
        };
    };

    _ret;
}];
