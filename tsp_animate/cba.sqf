#include "\a3\editor_f\Data\Scripts\dikCodes.h"; disableSerialization;

//-- SETTINGS
["tsp_cba_animate_tactical", "CHECKBOX", ["Tactical Stance System", "Enable/Disable tactical stance system."], ["TSP Animate", "Tactical"], true] call CBA_fnc_addSetting;
["tsp_cba_animate_style", "LIST", ["Tactical Style", "What gesture set to use."], ["TSP Animate", "Tactical"], [["","loose_","butt_","retro_"], ["Basic Bitch","Loosey Goosey","Tip to Butt","Retro"], 0]] call CBA_fnc_addSetting;
["tsp_cba_animate_style_autorifle", "LIST", ["Tactical Style (Autorifle)", "What gesture set to use."], ["TSP Animate", "Tactical"], [["","loose_","butt_","retro_"], ["Basic Bitch","Loosey Goosey","Tip to Butt","Retro"], 1]] call CBA_fnc_addSetting;
["tsp_cba_animate_style_shotgun", "LIST", ["Tactical Style (Shotgun)", "What gesture set to use."], ["TSP Animate", "Tactical"], [["","loose_","butt_","retro_"], ["Basic Bitch","Loosey Goosey","Tip to Butt","Retro"], 2]] call CBA_fnc_addSetting;
["tsp_cba_animate_style_sniper", "LIST", ["Tactical Style (Sniper)", "What gesture set to use."], ["TSP Animate", "Tactical"], [["","loose_","butt_","retro_"], ["Basic Bitch","Loosey Goosey","Tip to Butt","Retro"], 1]] call CBA_fnc_addSetting;

["tsp_cba_animate_tap", "CHECKBOX", ["Tap/Squeeze Animation", "Enable/disable animation leg/shoulder queeze."], ["TSP Animate", "Tactical"], true] call CBA_fnc_addSetting;
["tsp_cba_animate_door", "CHECKBOX", ["Door Opening Animation", "Enable/disable animation when opening doors."], ["TSP Animate", "Tactical"], true] call CBA_fnc_addSetting;
["tsp_cba_animate_sprint", "CHECKBOX", ["Sprint Animation", "Enable/disable sprint animation when in ready and sprinting."], ["TSP Animate", "Tactical"], true] call CBA_fnc_addSetting;
["tsp_cba_animate_port", "CHECKBOX", ["Port Animation", "Enable/disable port animation when in ready and weapon lowered."], ["TSP Animate", "Tactical"], true] call CBA_fnc_addSetting;
["tsp_cba_animate_cant", "CHECKBOX", ["Canting", "Enable/disable weapon canting."], ["TSP Animate", "Tactical"], true] call CBA_fnc_addSetting;
["tsp_cba_animate_black", "EDITBOX", ["Blacklist", "Blacklist attachments from using tactical stances when aiming."], ["TSP Animate", "Tactical"], '["optic_tws_mg"]', false, {tsp_cba_animate_black = call compile tsp_cba_animate_black}] call CBA_fnc_addSetting;
["tsp_cba_animate_poll", "SLIDER", ["Polling Rate", "How often script checks, 0 will disable automatic tactical stances."], ["TSP Animate", "Tactical"], [0, 5, 0.25], false] call CBA_fnc_addSetting;
["tsp_cba_animate_object", "SLIDER", ["Distance (Object)", "How close you have to be to an object."], ["TSP Animate", "Tactical"], [0, 5, 0.75], false] call CBA_fnc_addSetting;
["tsp_cba_animate_friend", "SLIDER", ["Distance (Friend)", "How close you have to be to a friendly unit."], ["TSP Animate", "Tactical"], [0, 5, 2], false] call CBA_fnc_addSetting;

["tsp_cba_animate_walk", "CHECKBOX", ["Adjustable Walking Speed", "Enable/Disable adjustable walking speed."], ["TSP Animate", "Walk"], true] call CBA_fnc_addSetting;
["tsp_cba_animate_walk_default", "SLIDER", ["Default Walking Speed", "Default walking speed."], ["TSP Animate", "Walk"], [0.5, 2, 1], false] call CBA_fnc_addSetting;
["tsp_cba_animate_walk_max", "SLIDER", ["Max Walking Speed", "Maximum walking speed."], ["TSP Animate", "Walk"], [1, 2, 1.6], false] call CBA_fnc_addSetting;
["tsp_cba_animate_walk_lower", "SLIDER", ["Lowered Walking Speed", "Walking speed while swag walking."], ["TSP Animate", "Walk"], [0.5, 2, 1], false] call CBA_fnc_addSetting;

["tsp_cba_animate_sling", "CHECKBOX", ["Sling System", "Enable/Disable sling system."], ["TSP Animate", "Sling"], true] call CBA_fnc_addSetting;
["tsp_cba_animate_sling_pos", "EDITBOX", ["Sling Position", "Attachment position and rotation for 2 point sling."], ["TSP Animate", "Sling"], '[[0.1, 0.8, 0.15], [-90, 40, 70]]', false, {tsp_cba_animate_sling_pos = call compile tsp_cba_animate_sling_pos}] call CBA_fnc_addSetting;
["tsp_cba_animate_sling_scroll", "CHECKBOX", ["Sling Scroll Menu", "Scroll menu actions for slings."], ["TSP Animate", "Sling"], true] call CBA_fnc_addSetting;
["tsp_cba_animate_sling_add", "CHECKBOX", ["Add Slings", "Attempt to add slings to all units."], ["TSP Animate", "Sling"], false] call CBA_fnc_addSetting;
["tsp_cba_animate_sling_sprint", "CHECKBOX", ["Enable Sprinting", "Disable sprinting with slung weapon."], ["TSP Animate", "Sling"], false] call CBA_fnc_addSetting;
["tsp_cba_animate_sling_style", "LIST", ["Sling Style", "What gesture set to use."], ["TSP Animate", "Sling"], [["","adhd","israeli"], ["Simpleton","ADHD","Israeli"], 1]] call CBA_fnc_addSetting;
["tsp_cba_animate_sling_required", "CHECKBOX", ["Require Sling", "Whether a sling is required to use sling system."], ["TSP Animate", "Sling"], true] call CBA_fnc_addSetting;

["tsp_cba_animate_sound", "SLIDER", ["Sound Volume", "Sound effect volume."], "TSP Animate", [0, 10, 1], false] call CBA_fnc_addSetting;
["tsp_cba_animate_shake", "SLIDER", ["Shake Intensity", "Camera shake intensity."], "TSP Animate", [0, 10, 1], false] call CBA_fnc_addSetting;

["tsp_cba_animate_attachment", "CHECKBOX", ["Attachment Change", "Play animation of attachment change."], "TSP Animate", true] call CBA_fnc_addSetting;
["tsp_cba_animate_ladder", "CHECKBOX", ["Shooting from Ladders", "Enable/Disable shooting from ladders."], "TSP Animate", true] call CBA_fnc_addSetting;
["tsp_cba_animate_throw", "CHECKBOX", ["Weapon Throwing", "Enables the throwing of weapons by hotkey."], "TSP Animate", true] call CBA_fnc_addSetting;

["tsp_cba_animate_nvg", "CHECKBOX", ["Night Vision Animation", "Enable/disable animation when toggling night vision goggles."], "TSP Animate", true] call CBA_fnc_addSetting;
["tsp_cba_animate_map", "CHECKBOX", ["Map Animation", "Enable/disable animation when using map."], "TSP Animate", true] call CBA_fnc_addSetting;
["tsp_cba_animate_uav", "CHECKBOX", ["UAV Animation", "Enable/disable animation when using UAV terminal."], "TSP Animate", true] call CBA_fnc_addSetting;
["tsp_cba_animate_watch", "CHECKBOX", ["Watch Animation", "Enable/disable animation when using watch."], "TSP Animate", true] call CBA_fnc_addSetting;
["tsp_cba_animate_compass", "CHECKBOX", ["Compass Animation", "Enable/disable animation when using compass."], "TSP Animate", true] call CBA_fnc_addSetting;

//-- CONTROLS
["TSP Animate", "tsp_animate_walk_scrollUp", "Walking Speed Up", {[playa, animationState playa, 0.2] call tsp_fnc_animate_walk}, {}, [0xF8, [false, true, false]]] call CBA_fnc_addKeybind;
["TSP Animate", "tsp_animate_walk_scrollDown", "Walking Speed Down", {[playa, animationState playa, -0.2] call tsp_fnc_animate_walk}, {}, [0xF9, [false, true, false]]] call CBA_fnc_addKeybind;

["TSP Animate", "tsp_animate_tactical_cancel", "Tactical Cancel (Ready)", {[playa, false, true] call tsp_fnc_animate_tactical_stop}, {}, [0xF0, [false, false, false]]] call CBA_fnc_addKeybind;
["TSP Animate", "tsp_animate_tactical_cancel_compress", "Tactical Cancel (Ready, Compress)", {[] spawn {tsp_animate_key = gestureState playa; sleep 0.3; tsp_animate_key = nil}}, {if (!isNil "tsp_animate_key") then {[playa, false, true, true, false, false, tsp_animate_key] call tsp_fnc_animate_tactical_stop}}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["TSP Animate", "tsp_animate_tactical_cancel_keyup", "Tactical Cancel (Cant, Over)", {[] spawn {tsp_animate_key = gestureState playa; sleep 0.3; tsp_animate_key = nil}}, {if (!isNil "tsp_animate_key") then {[playa, false, false, false, true, true, tsp_animate_key] call tsp_fnc_animate_tactical_stop}}, [0, [false, false, false]]] call CBA_fnc_addKeybind;

["TSP Animate", "tsp_animate_tactical_cancel_aim", "Tactical Cancel (Ready - Aim)", {[playa, true, true] call tsp_fnc_animate_tactical_stop}, {}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["TSP Animate", "tsp_animate_tactical_cancel_compress_aim", "Tactical Cancel (Ready, Compress - Aim)", {[] spawn {tsp_animate_key = gestureState playa; sleep 0.3; tsp_animate_key = nil}}, {if (!isNil "tsp_animate_key") then {[playa, true, true, true, false, false, tsp_animate_key] call tsp_fnc_animate_tactical_stop}}, [0xF1, [false, false, false]]] call CBA_fnc_addKeybind;
["TSP Animate", "tsp_animate_tactical_cancel_keyup_aim", "Tactical Cancel (Cant, Over - Key Up - Aim)", {[] spawn {tsp_animate_key = gestureState playa; sleep 0.3; tsp_animate_key = nil}}, {if (!isNil "tsp_animate_key") then {[playa, true, false, false, true, true, tsp_animate_key] call tsp_fnc_animate_tactical_stop}}, [0xF1, [false, false, false]]] call CBA_fnc_addKeybind;

["TSP Animate", "tsp_animate_tactical_scrollUp", "Tactical Up", {[playa, "scrollUp"] spawn tsp_fnc_animate_tactical}, {}, [0, [false, true, false]]] call CBA_fnc_addKeybind;
["TSP Animate", "tsp_animate_tactical_scrollDown", "Tactical Down", {[playa, "scrollDown"] spawn tsp_fnc_animate_tactical}, {}, [0, [false, true, false]]] call CBA_fnc_addKeybind;

["TSP Animate", "tsp_animate_ready_auto", "Tactical Ready (Auto)", {[playa, "ready", "laut"] call tsp_fnc_animate_tactical}, {}, [20, [false, false, false]]] call CBA_fnc_addKeybind;
["TSP Animate", "tsp_animate_ready_high", "Tactical Ready (High)", {[playa, "ready", "lhig"] call tsp_fnc_animate_tactical}, {}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["TSP Animate", "tsp_animate_ready_low", "Tactical Ready (Low)", {[playa, "ready", "llow"] call tsp_fnc_animate_tactical}, {}, [0, [false, false, false]]] call CBA_fnc_addKeybind;

["TSP Animate", "tsp_animate_compress_auto", "Tactical Compress (Auto)", {[playa, "compress", "laut"] call tsp_fnc_animate_tactical}, {}, [20, [false, true, false]]] call CBA_fnc_addKeybind;
["TSP Animate", "tsp_animate_compress_high", "Tactical Compress (High)", {[playa, "compress", "lhig"] call tsp_fnc_animate_tactical}, {}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["TSP Animate", "tsp_animate_compress_low", "Tactical Compress (Low)", {[playa, "compress", "llow"] call tsp_fnc_animate_tactical}, {}, [0, [false, false, false]]] call CBA_fnc_addKeybind;

["TSP Animate", "tsp_animate_over", "Overhead Shooting", {[playa, "over", "lnon"] call tsp_fnc_animate_tactical}, {}, [0xF1, [true, true, false]]] call CBA_fnc_addKeybind;
["TSP Animate", "tsp_animate_cant", "Cant Weapon", {
    if (count ((configFile >> "CfgWeapons" >> primaryWeaponItems playa#2 >> "ItemInfo" >> "OpticsModes") call BIS_fnc_getCfgSubClasses) > 1 && cameraView == "GUNNER") exitWith {};  //-- If double optic and aiming
    if (tsp_cba_animate_cant) then {[playa, "cant", "lnon"] call tsp_fnc_animate_tactical};
}, {}, [0xF1, [false, true, false]]] call CBA_fnc_addKeybind;

["TSP Animate", "tsp_animate_sling_sling", "Sling/Unsling/Swap", {
    [currentWeapon playa, primaryWeapon playa, handgunWeapon playa, playa getVariable ["tsp_slung",[]]] params ["_current", "_primary", "_handgun", "_slung"]; if (!tsp_cba_animate_sling) exitWith {};
    if (_current == _primary && _primary != "" && count _slung > 1 && stance playa in ["STAND","CROUCH"] && ("tsp_sling" in items playa || !tsp_cba_animate_sling_required)) exitWith {[playa, true, false, false, false, true] call tsp_fnc_animate_sling};  //-- Swap
    if (_current == _primary && _primary != "" && count _slung < 1 && stance playa in ["STAND","CROUCH"] && ("tsp_sling" in items playa || !tsp_cba_animate_sling_required)) exitWith {[playa, true] call tsp_fnc_animate_sling};  //-- Sling
    if (count _slung > 1 && stance playa in ["STAND","CROUCH"] && primaryWeapon playa == "") exitWith {[playa, false, _current == _handgun, false, false, true] call tsp_fnc_animate_sling};  //-- Unsling
}, {}, [2, [false, false, false]]] call CBA_fnc_addKeybind;

["TSP Animate", "tsp_animate_sling_slingo", "Sling", {
    [currentWeapon playa, primaryWeapon playa, handgunWeapon playa, playa getVariable ["tsp_slung",[]]] params ["_current", "_primary", "_handgun", "_slung"]; if (!tsp_cba_animate_sling) exitWith {};
    if (_current == _primary && _primary != "" && count _slung < 1 && stance playa in ["STAND","CROUCH"] && ("tsp_sling" in items playa || !tsp_cba_animate_sling_required)) exitWith {[playa, true] call tsp_fnc_animate_sling};  //-- Sling
}, {}, [0, [false, false, false]]] call CBA_fnc_addKeybind;

["TSP Animate", "tsp_animate_sling_unslingo", "Unsling", {
    [currentWeapon playa, primaryWeapon playa, handgunWeapon playa, playa getVariable ["tsp_slung",[]]] params ["_current", "_primary", "_handgun", "_slung"]; if (!tsp_cba_animate_sling) exitWith {};
    if (count _slung > 1 && stance playa in ["STAND","CROUCH"]) exitWith {[playa, false, _current == _handgun, false, false, true] call tsp_fnc_animate_sling};  //-- Unsling
}, {}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
  
["TSP Animate", "tsp_animate_throw", "Throw Weapon", {if (tsp_cba_animate_throw) then {[playa, true] spawn tsp_fnc_animate_throw}}, {}, [20, [false, false, true]]] call CBA_fnc_addKeybind;
["TSP Animate", "tsp_animate_throw_quick", "Throw Weapon (Quick)", {if (tsp_cba_animate_throw) then {[playa, false, 5, 8] spawn tsp_fnc_animate_throw}}, {}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["TSP Animate", "tsp_animate_drop", "Drop Weapon", {if (tsp_cba_animate_throw) then {([playa, currentWeapon playa] call tsp_fnc_throw) setVelocityModelSpace [2,3,0]}}, {}, [20, [false, true, true]]] call CBA_fnc_addKeybind;

{
    _x params ["_name", "_path", ["_key", 0]];
    [getText (call compile (_path + " >> 'condition'")), getText (call compile (_path + " >> 'statement'"))] params ["_condition", "_statement"];
    ["tsp_cba_animate_" + _name, "CHECKBOX", [_name, "Enable/disable this animation."], ["TSP Animate", "Animations"], true, false] call CBA_fnc_addSetting;
    [["TSP Animate", "Animations"], "tsp_" + _name, _name, compile ("if (" + _condition + ") then {" + _statement + "}"), {}, [_key, [false, false, false]]] call CBA_fnc_addKeybind;
} forEach [
    ["Cancel", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_cancel'", 57], 
    ["Contact", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_dances'>>'tsp_animate_contact'"], 
    ["Ivan", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_dances'>>'tsp_animate_duoIvan'"], 
    ["Duo", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_dances'>>'tsp_animate_duoStefan'"], 
    ["Stefan", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_dances'>>'tsp_animate_stefan'"], 
    ["Zozo", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_dances'>>'tsp_animate_zozo'"], 
    ["Metal", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_dances'>>'tsp_animate_metal'"], 
    ["Kata", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_dances'>>'tsp_animate_kata'"], 
    ["Pushups", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_dances'>>'tsp_animate_pushups'"],
    ["Squats", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_dances'>>'tsp_animate_squats'"],
    ["Suicide", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_suicide'"],
    ["Inspect", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_inspect'"],
    ["Bird", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_emotes'>>'tsp_animate_bird'"], 
    ["Ok", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_emotes'>>'tsp_animate_ok'"], 
    ["ThumbsUp", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_emotes'>>'tsp_animate_thumbsup'"], 
    ["ThumbsDown", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_emotes'>>'tsp_animate_thumbsdown'"], 
    ["Jackoff", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_emotes'>>'tsp_animate_jackoff'"], 
    ["Mahalo", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_emotes'>>'tsp_animate_mahalo'"], 
    ["Loser", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_emotes'>>'tsp_animate_loser'"], 
    ["Horns", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_emotes'>>'tsp_animate_horns'"], 
    ["Peace", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_emotes'>>'tsp_animate_peace'"], 
    ["Dab", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_emotes'>>'tsp_animate_dab'"],
    ["Heart", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_emotes'>>'tsp_animate_heart'"],
    ["Rock", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_emotes'>>'tsp_animate_rock'"],
    ["Paper", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_emotes'>>'tsp_animate_paper'"],
    ["Scissors", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_emotes'>>'tsp_animate_scissors'"],
    ["Bang", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_doors'>>'tsp_animate_bang'"],
    ["Breach", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_doors'>>'tsp_animate_breach'"]
];