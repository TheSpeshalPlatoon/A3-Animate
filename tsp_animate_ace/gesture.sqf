params ["_unit", "_animation", ["_priority", 0]];

if ("ThrowGrenade" in _animation && "tsp_animate_grenade" in gestureState _unit) exitWith {  //-- The actual throwing part
	_unit spawn {
		_unit = _this;
		_previous = _unit getVariable ["tsp_gestureReturn", []];
		_unit playActionNow ([_unit, "tsp_animate_grenade_wnon_" + (if (tsp_ace_throwType == "normal") then {"over"} else {"under"})] call tsp_fnc_gesture_variant); sleep 0.9;
		if (count _previous == 0) exitWith {};
		if (count (["ready","readyalt","readycombat","compress","cant","friend","over","port","portchill","portmove"] select {_x in _previous#2}) > 0) then {_previous spawn tsp_fnc_gesture_play};
	};
};//unit,in,loop,out,interupt,instant,return,returnable,toggle,lower,code

if (!ace_common_isReloading || {_priority > 0}) then {
    //["ace_common_playActionNow", [_unit, _animation], _unit] call CBA_fnc_targetEvent;
	_unit playActionNow _animation;
};