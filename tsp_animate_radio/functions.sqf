tsp_fnc_radio_custom = {
	params ["_unit", ["_anim", "tsp_animate_radio_wrist_stand_unarmed"]];
	if (stance _unit == "PRONE") then {_anim = _anim regexReplace ["stand", "prone"]};
	if (currentWeapon _unit == primaryWeapon _unit && primaryWeapon _unit != "") then {_anim = _anim regexReplace ["unarmed", "rifle"]};
	if (currentWeapon _unit == handgunWeapon _unit && handgunWeapon _unit != "") then {_anim = _anim regexReplace ["unarmed", "pistol"]};
	if (currentWeapon _unit == secondaryWeapon _unit && secondaryWeapon _unit != "") then {_anim = _anim regexReplace ["unarmed", "launcher"]};
	[_unit, "", _anim, "tsp_common_stop_right"] spawn tsp_fnc_gesture_play;
};

tsp_fnc_radio_data = {
	params ["_radioID"];
	_radioData = tsp_animate_radio_library select {_x#0 == "Others"};                //-- Use handset by default
	_radioDataTry = (tsp_animate_radio_library select {_radioID find _x#0 != -1});  //-- Look for unit radio in radio library
	if (count _radioDataTry > 0) then {_radioData = _radioDataTry};
	_radioData#0
};

tsp_fnc_radio = {
	params ["_unit", "_onRadio", "_radioID", ["_mode", ""]];

	//-- Exceptions
	if !(tsp_cba_radio) exitWith {};
	if !(_onRadio) exitWith {};
	if (isWeaponDeployed _unit) exitWith {};
	if ("ainv" in animationState _unit) exitWith {};
	if (currentWeapon _unit == binocular _unit && binocular _unit != "") exitWith {};
	if (!tsp_cba_radio_vehicle && vehicle _unit != _unit) exitWith {};                //-- No radio while in vehicle
    if (_unit getVariable ["ace_captives_handcuffAnimEHID", -1] != -1) exitWith {};  //-- No radio while handcuffed	
	if (_unit getVariable ["ace_captives_isSurrendering", false]) exitWith {};      //-- No radio while surrendered

	//-- Which animation to use? Based on CBA settings
	([_radioID] call tsp_fnc_radio_data) params ["_radioClass", "_radioObject", "_radioAttach", "_radioRotation", "_defaultPreference"];
	if (_mode == "") then {_mode = call compile ("tsp_cba_radio_preference_" + _radioClass)};
	
	//-- Decide best animation and do it
	_hasHelmet = headgear _unit in tsp_cba_radio_helmets;
	_hasEar = (headgear _unit in tsp_cba_radio_headsets) || (goggles _unit in tsp_cba_radio_headsets);
	_hasVest = (vest _unit in tsp_cba_radio_vests) || (tsp_cba_radio_vest_armor && [vest _unit] call tsp_fnc_hitpoint_armor > 5);
	_interupt = [gestureState _unit] call tsp_fnc_gesture_sanitize == "" || ("tsp" in gestureState _unit && gestureState _unit call tsp_fnc_gesture_looped);
	_aim = if (tsp_cba_radio_aiming) then {"_aim"} else {""};
	switch (true) do {
		case (_mode == "Wrist"): {[_unit, "tsp_animate_radio_wrist_stand_unarmed"] spawn tsp_fnc_radio_custom};
		case (_mode == "Helmet" || _hasHelmet): {[_unit, "tsp_animate_radio_helmet_stand_unarmed"] spawn tsp_fnc_radio_custom};
		case (_mode == "Ear" && _hasEar): {[_unit, "tsp_animate_radio_ear_wnon_laut_in" + _aim, "tsp_animate_radio_ear_wnon_laut" + _aim, "tsp_common_stop", _interupt, true, true] spawn tsp_fnc_gesture_play};
		case (_mode == "Vest" && _hasVest): {[_unit, "tsp_animate_radio_vest_wnon_laut_in" + _aim, "tsp_animate_radio_vest_wnon_laut" + _aim, "tsp_common_stop", _interupt, true, true] spawn tsp_fnc_gesture_play};
		case (_mode == "Handset"): {
			(["Others"] call tsp_fnc_radio_data) params ["_radioClass", "_radioObject", "_radioAttach", "_radioRotation", "_defaultPreference"];
			[_unit, "tsp_animate_radio_hand_wnon_laut_in" + _aim, "tsp_animate_radio_hand_wnon_laut" + _aim, _radioObject, "leftHand", _radioAttach, _radioRotation, {!isNil "tsp_animate_radio_stop"}, false] spawn tsp_fnc_gesture_item;
		};	
		default {[_unit, "tsp_animate_radio_hand_wnon_laut_in" + _aim, "tsp_animate_radio_hand_wnon_laut" + _aim, _radioObject, "leftHand", _radioAttach, _radioRotation, {!isNil "tsp_animate_radio_stop"}, false] spawn tsp_fnc_gesture_item};
	};

	//-- Exit
	tsp_animate_radio_stop = nil; waitUntil {!isNil "tsp_animate_radio_stop"}; 
	if ("radio" in gestureState _unit) then {[_unit] call tsp_fnc_gesture_stop};  //-- Only stop gesture if you are doing radio gesture
};

tsp_fnc_radio_model = {
	params ["_unit", ["_radioID", "Others"]];	
	([_radioID] call tsp_fnc_radio_data) params ["_radioClass", "_radioObject", "_radioAttach", "_radioRotation", "_defaultPreference"];
	if (vehicle _unit != _unit) exitWith {};  //-- Doesnt work in vehicles, radio will stay in same position as created
	_interupt = [gestureState _unit] call tsp_fnc_gesture_sanitize == "" || ("tsp" in gestureState _unit && gestureState _unit call tsp_fnc_gesture_looped);
	[_unit, "tsp_animate_radio_hand_wnon_laut_in" + (if (tsp_cba_radio_aiming) then {"_aim"} else {""}), "tsp_animate_radio_hand_wnon_laut" + (if (tsp_cba_radio_aiming) then {"_aim"} else {""}), "tsp_common_stop", _interupt, true, true] spawn tsp_fnc_gesture_play;
	if (isNil "tsp_animate_radio_model") then {
		tsp_animate_radio_model = createSimpleObject [_radioObject, [0,0,0]];
		sleep 0.3; if (isNil "tsp_animate_radio_model" || !("radio" in gestureState _unit)) exitWith {};
		tsp_animate_radio_model attachto [_unit, _radioAttach, "leftHand", true];
		[tsp_animate_radio_model, _radioRotation] call BIS_fnc_setObjectRotation;
	};
};