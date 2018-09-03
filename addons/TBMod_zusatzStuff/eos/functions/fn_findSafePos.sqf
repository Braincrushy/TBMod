params ["_mrk", "_radveh"];

private _pos = [_mkr, true] call TB_EOS_fnc_shk_pos;
private _newpos = [0,0,0];

for "_i" from 0 to 20 do
{
    _newpos = [_pos, 0, _radveh, 5, 1, 20, 0] call BIS_fnc_findSafePos;
    if ((_pos distance _newpos) < (_radveh + 5)) exitWith {_pos = _newpos};
};

_newpos
