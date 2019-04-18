/*
    Part of the TBMod ( https://github.com/TacticalBaconDevs/TBMod )
    Developed by http://tacticalbacon.de

    0 - kein DEBUG
    1 - diag_log
    2 - + systemChat
    3 - + hint
*/
if (TB_debug_lvl <= 0) exitWith {};

// Remote Support Code
if (isRemoteExecuted && !TB_debug_remote) exitWith {};
private _index = [cba_diagnostic_clientIDs, remoteExecutedOwner] call BIS_fnc_findNestedElement;
private _remoteName = if (isRemoteExecuted && !(_index isEqualTo [])) then
{
    (cba_diagnostic_clientIDs select (_index select 0)) select 1
}
else
{
    format ["<UNKNOWN-%1>", remoteExecutedOwner]
};
private _remoteID = [clientOwner, [0, -2] select isDedicated] select TB_debug_remote;

private _text = format ["[DEBUG%1][%2] %3",
        if (isRemoteExecuted) then {"-REMOTE]["+ _remoteName} else {""},
        _fnc_scriptNameParent,
        if (_this isEqualType []) then {format _this} else {_this}
    ];

if (TB_debug_lvl >= 1) then {_text remoteExecCall ["diag_log", _remoteID]};
if (TB_debug_lvl >= 2) then {_text remoteExecCall ["systemChat", _remoteID]};
if (TB_debug_lvl >= 3) then {_text remoteExecCall ["hintSilent", _remoteID]};
