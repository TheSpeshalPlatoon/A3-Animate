if (isClass (configFile >> "CfgPatches" >> "tfar_core") || isClass (configFile >> "CfgPatches" >> "task_force_radio")) then {
	["TFAR_RadioEventStart", "OnTangent", {
		_this params ["_unit", "_radio", "_idk", "_idk2", "_state"];
		if (_state) then {[_unit, true, _radio] spawn tsp_fnc_radio} else {tsp_animate_radio_stop = true};
	}, ObjNull] call TFAR_fnc_addEventHandler;
};
if (isClass (configFile >> "CfgPatches" >> "acre_main")) then {
	["acre_startedSpeaking", {[_this#0, _this#1, _this#2] spawn tsp_fnc_radio}, player] call CBA_fnc_addEventHandler;
	["acre_stoppedSpeaking", {tsp_animate_radio_stop = true}, player] call CBA_fnc_addEventHandler;
	if (isClass (configFile >> "CfgPatches" >> "acre_main") && !isNil "ace_arsenal_fnc_addRightPanelButton") then {
		_items = getArray(configFile >> "CfgPatches" >> "acre_sys_gsa" >> "weapons");
		_radios = "(getNumber(_x >> 'acre_isRadio')) == 1 && (getNumber(_x >> 'scope')) > 1" configClasses (configFile >> "CfgWeapons") apply {configName _x};  // && (getNumber(_x >> 'scope')) > 1
		[_items + _radios, "Radio Items", "a3\modules_f_curator\data\portraitradio_ca.paa"] call ace_arsenal_fnc_addRightPanelButton;
	};
};