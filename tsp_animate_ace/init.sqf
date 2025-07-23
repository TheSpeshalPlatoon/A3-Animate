ace_gestures_showOnInteractionMenu = 1;  //-- REMOVE ACE GESTURES

if (!isNil "ace_explosives_fnc_addDetonateHandler" && tsp_cba_animate_clacker) then {[{_this spawn tsp_fnc_animate_clacker; true}] call ace_explosives_fnc_addDetonateHandler};  //-- Clacker

if (!isNil "ace_advanced_fatigue_setAnimExclusions") then {ace_advanced_fatigue_setAnimExclusions pushBackUnique [  //-- Exempt from ACE stamina, i dont remember why
    "AmovPercMwlkSrasWrflDf","AmovPercMwlkSrasWrflDfr","AmovPercMwlkSrasWrflDfl","AmovPercMwlkSrasWrflDl",
    "AmovPercMwlkSrasWrflDb","AmovPercMwlkSrasWrflDbr","AmovPercMwlkSrasWrflDbl","AmovPercMwlkSrasWrflDr",
    "AmovPercMwlkSrasWpstDf","AmovPercMwlkSrasWpstDfr","AmovPercMwlkSrasWpstDfl","AmovPercMwlkSrasWpstDl",
    "AmovPercMwlkSrasWpstDb","AmovPercMwlkSrasWpstDbr","AmovPercMwlkSrasWpstDbl","AmovPercMwlkSrasWpstDr",
    "AmovPercMwlkSlowWrflDf","AmovPercMwlkSlowWrflDfr","AmovPercMwlkSlowWrflDfl","AmovPercMwlkSlowWrflDl",
    "AmovPercMwlkSlowWrflDb","AmovPercMwlkSlowWrflDbr","AmovPercMwlkSlowWrflDbl","AmovPercMwlkSlowWrflDr",
    "AmovPercMwlkSlowWpstDf","AmovPercMwlkSlowWpstDfr","AmovPercMwlkSlowWpstDfl","AmovPercMwlkSlowWpstDl",
    "AmovPercMwlkSlowWpstDb","AmovPercMwlkSlowWpstDbr","AmovPercMwlkSlowWpstDbl","AmovPercMwlkSlowWpstDr"
]};

//-- Overwrite ACE incremental door control
["ACE3 Common", "ace_interaction_openDoor", "Incemental Door Opening", {
	if (!([ACE_player, objNull, []] call ace_common_fnc_canInteractWith) || ace_interaction_isOpeningDoor || {[2] call ace_interaction_fnc_getDoor select 1 == ''}) exitWith {false};
	if (tsp_cba_animate_door) then {[ACE_player, "doorACE"] call tsp_fnc_animate_door}; call ace_interaction_fnc_openDoor;
}, {ace_interaction_isOpeningDoor = false; if ("door" in gestureState ACE_player) then {[ACE_player] call tsp_fnc_gesture_stop}},[57, [false, true, false]], false] call CBA_fnc_addKeybind;

//-- Overwrite ACE throwing control
["ACE3 Weapons", "ace_advanced_throwing_prepare", "Prepare", {
	if (ace_common_isReloading || !([ACE_player] call ace_advanced_throwing_fnc_canPrepare)) exitWith {false};
	[ACE_player] call ace_advanced_throwing_fnc_prepare; 
    if (tsp_cba_animate_grenade) then {[ACE_player] spawn tsp_fnc_animate_grenade};
	true
}, {false}, [34, [true, false, false]], false] call CBA_fnc_addKeybind;

//-- Overwrite ACE tapping control 
["ACE3 Common", "ace_interaction_tapShoulder", "Tap Shoulder", {
	if (tsp_cba_animate_tap) exitWith {false};
	if !([ACE_player, objNull, []] call ace_common_canInteractWith) exitWith {false};
	if !([ACE_player, cursorTarget] call ace_interaction_canTapShoulder) exitWith {false};
	private _shoulderNum = [0, 1] select (([ACE_player, cursorTarget] call BIS_fnc_relativeDirTo) < 180);
	[ACE_player, cursorTarget, _shoulderNum] call ace_interaction_fnc_tapShoulder;
}, {false}, [20, [true, false, false]], false] call CBA_fnc_addKeybind;

player addEventHandler ["AnimStateChanged", {  //-- No dropping with slings
    params ["_unit", "_anim"]; 
    if ("tsp_sling" in items _unit && isNil "tsp_ace_sling") then {tsp_ace_sling = ace_medical_dropWeaponUnconsciousChance; ace_medical_dropWeaponUnconsciousChance = 0};
    if (!("tsp_sling" in items _unit) && !(isNil "tsp_ace_sling")) then {ace_medical_dropWeaponUnconsciousChance = tsp_ace_sling; tsp_ace_sling = nil};
}];

["ace_dragging_startedCarry", {params ["_unit", "_target"];	if (tsp_cba_animate_lift && !(_target isKindOf "Man")) then {_unit spawn {sleep 1; [_this, "", "tsp_animate_lift", "tsp_common_stop", true, true] spawn tsp_fnc_gesture_play}}}] call CBA_fnc_addEventHandler;
["ace_dragging_stoppedCarry", {params ["_unit", "_target"]; if ("carry" in gestureState _unit) exitWith {[_unit] call tsp_fnc_gesture_stop}}] call CBA_fnc_addEventHandler;
