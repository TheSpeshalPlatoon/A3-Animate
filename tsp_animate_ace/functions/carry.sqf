
params ["_unit", "_target", "_claimed"];
if (!_claimed) exitWith { diag_log text format ['[%1] (%2) %3: %4', toUpper 'ace', 'dragging', 'WARNING', format["already claimed %1", _this]] };

private _weight = 0;
if !(_target getVariable ["ace_dragging_ignoreWeightCarry", false]) then {_weight = _target call ace_dragging_fnc_getWeight};

if (_weight > (missionNamespace getVariable ["ACE_maxWeightCarry", 1E11])) exitWith {
    [objNull, _target, true] call ace_common_fnc_claim;
    [localize "STR_ace_dragging_UnableToDrag"] call ace_common_fnc_displayTextStructured;
};

private _timer = CBA_missionTime + 5;
if (_target isKindOf "CAManBase") then {
    if (!alive _target) then {_target = [_unit, _target] call ace_dragging_fnc_createClone};

    private _primaryWeapon = primaryWeapon _unit;
    if (_primaryWeapon == "") then {_unit addWeapon "ACE_FakePrimaryWeapon"; _primaryWeapon = "ACE_FakePrimaryWeapon"};
    _unit selectWeapon _primaryWeapon; 

    ["ace_common_setDir", [_target, getDir _unit + 180], _target] call CBA_fnc_targetEvent;
    _target setPosASL (getPosASL _unit vectorAdd (vectorDir _unit));

    [_unit, "AcinPknlMstpSnonWnonDnon_AcinPercMrunSnonWnonDnon", 2] call ace_common_fnc_doAnimation;
    [_target, "AinjPfalMstpSnonWrflDnon_carried_Up", 2] call ace_common_fnc_doAnimation;

    //-- DINOWASHERE
	[_unit, 10/tsp_cba_animate_carry] remoteExec ["setAnimSpeedCoef"];
	[_target, 10/tsp_cba_animate_carry] remoteExec ["setAnimSpeedCoef"];
    _timer = CBA_missionTime + tsp_cba_animate_carry;
	_unit spawn {sleep tsp_cba_animate_carry; [_this, 1] remoteExec ["setAnimSpeedCoef"]};
	_target spawn {sleep tsp_cba_animate_carry; [_this, 1] remoteExec ["setAnimSpeedCoef"]};
    //-- DINOWASHERE
} else {
    if (currentWeapon _unit != "") then {
        _unit setVariable ["ace_dragging_previousWeapon", (weaponState _unit) select [0, 3], true];
        _unit action ["SwitchWeapon", _unit, _unit, 299];
    };

    [_unit, "AmovPercMstpSnonWnonDnon", 0] call ace_common_fnc_doAnimation;

    private _canRun = _weight call ace_dragging_fnc_canRun_carry;
    [_unit, "forceWalk", "ace_dragging", !_canRun] call ace_common_fnc_statusEffect_set;
    [_unit, "blockSprint", "ace_dragging", _canRun] call ace_common_fnc_statusEffect_set;
};

[_unit, "blockThrow", "ace_dragging", true] call ace_common_fnc_statusEffect_set;
_unit setVariable ["ace_dragging_isCarrying", true, true];
_unit setVariable ["ace_dragging_carriedObject", _target, true];
[ace_dragging_fnc_startCarryPFH, 0.2, [_unit, _target, _timer]] call CBA_fnc_addPerFrameHandler;

private _mass = getMass _target;
if (_mass > 1) then {
    _target setVariable ["ace_dragging_originalMass", _mass, true];
    ["ace_common_setMass", [_target, 1e-12]] call CBA_fnc_globalEvent; 
};

["ace_dragging_setupCarry", [_unit, _target]] call CBA_fnc_localEvent;