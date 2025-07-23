if (isClass (configFile >> "CfgPatches" >> "acre_main")) then {
	["acre_startedSpeaking", {[_this#0, _this#1, _this#2] spawn tsp_fnc_radio}, player] call CBA_fnc_addEventHandler;
	["acre_stoppedSpeaking", {tsp_animate_radio_stop = true}, player] call CBA_fnc_addEventHandler;
};
if (isClass (configFile >> "CfgPatches" >> "tfar_core") || isClass (configFile >> "CfgPatches" >> "task_force_radio")) then {
	["TFAR_RadioEventStart", "OnTangent", {
		_this params ["_unit", "_radio", "_idk", "_idk2", "_state"];
		if (_state) then {[_unit, true, _radio] spawn tsp_fnc_radio} else {tsp_animate_radio_stop = true};
	}, ObjNull] call TFAR_fnc_addEventHandler;
};