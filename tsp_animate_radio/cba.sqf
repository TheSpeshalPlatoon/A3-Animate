tsp_animate_radio_library = [  //-- Library containing all info required to create hand animation with radio as well as decide which anim to use
	[
		"acre_prc343",                                                    //-- Radio classname
		"idi\acre\addons\sys_prc343\Data\Models\acre_prc343_model.p3d",  //-- Object
		[0.02,-0.02,-0.04],                                             //-- Attach
		[-90,-90,0],                                                   //-- Rotation
		0,                                                            //-- Default CBA animation for this radio (0 - Vest, 1 - Ear, 2 - Radio, 3 - Handset, 4 - Wrist)
		"ACRE"                                                       //-- Category name
	], [
		"acre_prc152",
		if (isClass(configFile >> "CfgPatches" >> "rhsusf_c_radio")) then {"rhsusf\addons\rhsusf_commskit\RHS_ANPRC152.p3d"} else {"idi\acre\addons\sys_prc152\Data\Models\PRC152.p3d"},
		if (isClass(configFile >> "CfgPatches" >> "rhsusf_c_radio")) then {[0.015,0.23,0]} else {[0.03,0,0.01]}, [-90,-90,0], 0, "ACRE"
	],
	["acre_prc148", "idi\acre\addons\sys_prc148\Data\Models\PRC148.p3d", [0.02,0.25,0], [-90,-90,0], 2, "ACRE"], 
	["acre_sem52sl", "idi\acre\addons\sys_sem52sl\Data\model\sem52sl.p3d", [0.04,0.05,0], [-90,-90,0], 0, "ACRE"], 
	["acre_bf888s", "idi\acre\addons\sys_bf888s\Data\models\acre_bf888s_model.p3d", [-0.07,0.06,0], [-90,-90,0], 2, "ACRE"], 
	["ACRE_PRC117F", "tsp_h189", [0.03,0.05,0], [0,260,180], 3, "ACRE"], 
	["ACRE_PRC77", "tsp_h189", [0.03,0.05,0], [0,260,180], 3, "ACRE"], 
	["ACRE_SEM70", "tsp_h189", [0.02,0.25,0], [-90,-90,0], 3, "ACRE"],
	["TFAR_anprc152", "z\tfar\addons\handhelds\anprc152\data\tfr_anprc152.p3d", [0.04,0.05,-0.02], [-80,-100,0], 0, "TFAR"], 
	["TFAR_anprc154", "z\tfar\addons\handhelds\anprc154\data\tfr_anprc154.p3d", [0.05,0.02,-0.02], [-90,-70,-20], 0, "TFAR"], 
	["TFAR_anprc148jem", "z\tfar\addons\handhelds\anprc148jem\data\tfr_anprc148.p3d", [0.03,0.15,-0.01], [0,0,90], 2, "TFAR"], 
	["TFAR_rf7800str", "z\tfar\addons\handhelds\RF7800\data\tfr_RF7800.p3d", [0.03,0.02,-0.03], [-80,-80,0], 0, "TFAR"], 
	["TFAR_pnr1000a", "z\tfar\addons\handhelds\PNR1000A\data\tfr_PNR1000a.p3d", [0.05,0,-0.01], [-80,-80,0], 2, "TFAR"], 
	["TFAR_fadak", "z\tfar\addons\handhelds\fadak\data\tfr_fadak.p3d", [0.03,0.07,-0.01], [-80,-80,0], 2, "TFAR"],
	["JLTS_clone_comlink", "z\tfar\addons\handhelds\fadak\data\tfr_fadak.p3d", [0,0.07,-0.3], [-50,0,-80], 4, "JLTS"],
	["JLTS_droid_comlink", "z\tfar\addons\handhelds\fadak\data\tfr_fadak.p3d", [0,0.07,-0.3], [-50,0,-80], 1, "JLTS"],
	["Others", "tsp_h189", [0.03,0.05,0], [0,260,180], 3, "Radio"]
];
//tsp_object attachto [player, [0.03,0.05,0], "leftHand", true]; [tsp_object, [0,260,180]] remoteExec ["tsp_fnc_rotate", 0];

//-- SETTINGS	
	["tsp_cba_radio", "CHECKBOX", ["Radio Animations", "Enables radio animation."], "TSP Animate - Radio", true, true] call CBA_fnc_addSetting;  //-- Main
	["tsp_cba_radio_aiming", "CHECKBOX", ["Aiming", "If enabled, players will be able to aim while using a radio."], "TSP Animate - Radio", true, false] call CBA_fnc_addSetting;  //-- Aiming Down Sights
	["tsp_cba_radio_vehicle", "CHECKBOX", ["Allow in Vehicles", "Enables radio animation in vehicles."], "TSP Animate - Radio", true, false] call CBA_fnc_addSetting;
	["tsp_cba_radio_helmets", "EDITBOX", ["Helmet List", "Array of helmets/goggles that use helmet animation."], "TSP Animate - Radio", '["NCR_Helmet15th","NCR_Helmet15thBlack","NCR_Helmet15thWhite","NCR_CVCHelmet15th","NCR_CVCHelmet15thBlack","NCR_CVCHelmet15thGogglesBlack","NCR_CVCHelmet15thGoggles","NCR_CVCHelmet15thWhite","NCR_CVCHelmet15thGogglesWhite","NCR_CVCHelmet15th_Allfather","NCR_CVCHelmet15th_Foxo","NCR_CVCHelmet15th_Lance","NCR_CVCHelmet15th_Roe","NCR_CVCHelmet15th_Sunny","NCR_CVCHelmet15th_Tato","NCR_CVCHelmet15th_Tex","NCR_ReconHelmet","NCR_ReconHelmetBrown","NCR_ReconHelmetGray","RA_Slater_helmet","RA_Marine_helmet","RA_Ranger_helmet","power_armor_helmet_t45d_dow"]', false, {tsp_cba_radio_helmets = call compile tsp_cba_radio_helmets}] call CBA_fnc_addSetting;  //-- Helmets
	["tsp_cba_radio_headsets", "EDITBOX", ["Headset List", "Array of helmets/goggles that use ear animation."], "TSP Animate - Radio", '["G_WirelessEarpiece_F"]', false, {tsp_cba_radio_headsets = call compile tsp_cba_radio_headsets}] call CBA_fnc_addSetting;  //-- Headsets
	["tsp_cba_radio_vests", "EDITBOX", ["Vest List", "Array of vests that should be considered for vest animation."], "TSP Animate - Radio", '[]', false, {tsp_cba_radio_vests = call compile tsp_cba_radio_vests}] call CBA_fnc_addSetting;  //-- Vests
	["tsp_cba_radio_vest_armor", "CHECKBOX", ["Vest Armor", "If enabled, all vests that have armor values will be added to the vest list."], "TSP Animate - Radio", true, false] call CBA_fnc_addSetting;  //-- Vest Armor
	{  //-- Radio Preferences
		_x params ["_radioClass", "_radioObject", "_radioAttach", "_radioRotation", "_defaultPreference", "_category"];
		[
			"tsp_cba_radio_preference_" + _radioClass, "LIST",
			["Animation Preference (" + _radioClass + ")", "Preferred Animation for this radio. Doesn't mean that it will always be used as the vest/ear animations are only used when the player has a vest/headset from the vest/headset list."],
			["TSP Animate - Radio", _category], [["Vest", "Ear", "Model", "Handset", "Wrist", "Helmet"], ["Vest", "Ear", "Radio", "Handset", "Wrist", "Helmet"], _defaultPreference], false
		] call CBA_fnc_addSetting;
	} forEach tsp_animate_radio_library;

//-- CONTROLS
if (isClass (configFile >> "CfgPatches" >> "acre_main")) then {
	["TSP Animate", "tsp_animate_radio", "Listen to Radio", {if (tsp_cba_radio) then {[playa,true,[call acre_api_fnc_getCurrentRadio] call acre_api_fnc_getBaseRadio,"Model"] spawn tsp_fnc_radio}}, {tsp_animate_radio_stop = true}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
};
if (isClass (configFile >> "CfgPatches" >> "tfar_core")) then {
	["TSP Animate", "tsp_animate_radio", "Listen to Radio", {
		if (tsp_cba_radio && call TFAR_fnc_haveSWRadio) then {[playa,true,call TFAR_fnc_activeSwRadio,"Model"] spawn tsp_fnc_radio};
		if (tsp_cba_radio && call TFAR_fnc_activelRRadio) then {[playa,true,call TFAR_fnc_activelRRadio,"Model"] spawn tsp_fnc_radio};
	}, {tsp_animate_radio_stop = true}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
};