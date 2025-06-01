params ["_unit", "_animation", ["_priority", 0]];
if ("ThrowGrenade" in _animation && "tsp_animate" in gestureState _unit) exitWith {tsp_animate_throwing = true};  //-- Dont play ThrowGrenade, just tell tsp_fnc_animate_grenade to do something
if (!ace_common_isReloading || {_priority > 0}) then {_unit playActionNow _animation};