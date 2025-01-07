if (tsp_cba_animate_sling) then {player addEventHandler ["Respawn", {params ["_unit", "_corpse"]; [_unit] spawn tsp_fnc_animate_sling_actions}]; [player] call tsp_fnc_animate_sling_actions};   //-- Scroll actions
tsp_animate_combat = false; addUserActionEventHandler ["TactToggle", "Activate", {tsp_animate_combat = !tsp_animate_combat; [playa, ""] call tsp_fnc_animate_tactical}];  //-- Detect if doing tactical pace
tsp_animate_walk = false; addUserActionEventHandler ["WalkRunToggle", "Activate", {tsp_animate_walk = !tsp_animate_walk; [playa, ""] call tsp_fnc_animate_tactical}];    //-- Detect if doing slow walk
player addEventHandler ["InventoryOpened", {tsp_animate_attach = [currentWeapon player, primaryWeaponItems player, secondaryWeaponItems player, handgunItems player]}];
player addEventhandler ["Take", {if (tsp_cba_animate_attachment) then {[_this#0, _this#2, "mount"] call tsp_fnc_animate_attachment}}];
player addEventhandler ["Put",  {if (tsp_cba_animate_attachment) then {[_this#0, _this#2, "dismount"] call tsp_fnc_animate_attachment}}];
player addEventHandler ["InventoryOpened", {playSound3D ["tsp_animate\snd\inventory_open.ogg", player, false, getPosASL player, 5, 1, 20]}];
player addEventHandler ["InventoryClosed", {playSound3D ["tsp_animate\snd\inventory_close.ogg", player, false, getPosASL player, 5, 1, 20]}];
player addEventHandler ["Take", {if (!isNull (findDisplay 602)) then {playSound3D ["tsp_animate\snd\take.ogg", player, false, getPosASL player, 5, 1, 20]}}];
player addEventHandler ["Put", {if (!isNull (findDisplay 602)) then {playSound3D ["tsp_animate\snd\put.ogg", player, false, getPosASL player, 5, 1, 20]}}];
player addEventHandler ["AnimStateChanged", {
    params ["_unit", "_anim"];
    if (tsp_cba_animate_ladder && _anim == "LadderCivilStatic" && currentWeapon _unit == handgunWeapon _unit && handgunWeapon _unit != "") then {[_unit, "LadderPistolstatic"] remoteExec ["switchMove"]};
    if (tsp_cba_animate_ladder && _anim in ["ladderpistoltopoff", "ladderpistoldownoff"]) then {[_unit, "amovpercmstpslowwpstdnon_amovpercmstpsraswpstdnon"] remoteExec ["switchMove"]};
    if ("mtac" in _anim) then {tsp_animate_walk = false; tsp_animate_combat = true}; 
    if ("mrun" in _anim) then {tsp_animate_walk = false; tsp_animate_combat = false};
    if ("mwlk" in _anim) then {tsp_animate_walk = true};
    [_unit, ""] call tsp_fnc_animate_tactical;
    [_unit, _anim] call tsp_fnc_animate_walk;
}];
["unit", {params ["_new", "_old"]; if (!isPlayer _new) then {_new addEventHandler ["AnimStateChanged", {params ["_unit", "_anim"]; [_unit, _anim] call tsp_fnc_animate_walk}]}}] call CBA_fnc_addPlayerEventHandler;

//-- Utility handlers
["if (tsp_cba_animate_uav && 'Open UAV' in (_this#4)) then {[playa,0.5,'A3\Missions_F_Oldman\Data\sound\beep.ogg',0.1] call tsp_fnc_animate_effect; [playa, 'tsp_animate_map_in', 'tsp_animate_map_loop', '\A3\Props_F_Exp_A\Military\Equipment\Tablet_02_F.p3d', [-0.07,0.01,-0.05], [200,-50,10], {isNull findDisplay 160}] spawn tsp_fnc_gesture_item};"] spawn tsp_fnc_scroll;
addUserActionEventHandler ["NightVision", "Activate", {if (tsp_cba_animate_nvg) then {[playa] spawn tsp_fnc_animate_nvg; [playa] call tsp_fnc_animate_effect}}];
addUserActionEventHandler ["Compass", "Activate", {[] spawn {sleep 0.01; if (tsp_cba_animate_compass && visibleCompass) then {
    [playa, "", "tsp_animate_compass_loop", getText(configFile>>'CfgWeapons'>>playa getSlotItemName 609>>'model'), [0.06,0.02,0.01], [70,90,0], {!visibleCompass}] spawn tsp_fnc_gesture_item;
    [playa] call tsp_fnc_animate_effect; 
}}}];
addUserActionEventHandler ["Watch", "Activate", {[] spawn {sleep 0.01; if (tsp_cba_animate_watch && (visibleWatch || missionNameSpace getVariable ["ace_parachute_AltimeterActive", false])) then {        
    [playa, "", "tsp_animate_watch_loop", "", [0,0,999], [0,0,0], {!visibleWatch && !(missionNameSpace getVariable ["ace_parachute_AltimeterActive", false])}] spawn tsp_fnc_gesture_item;
    [playa] call tsp_fnc_animate_effect; 
}}}];
addUserActionEventHandler ["ShowMap", "Activate", {[] spawn {sleep 0.01; if (tsp_cba_animate_map && visibleMap && isNull findDisplay 312) then {
    [playa] call tsp_fnc_animate_effect;
    if ("tsp_trijatta" in assignedItems playa) exitWith {[playa, "tsp_animate_map_in", "tsp_animate_map_loop", "\tsp_tracker\trijatta.p3d", [-0.06,0,-0.06], [80,-35,0], {sleep 0.2;!visibleMap}] spawn tsp_fnc_gesture_item};
    if ("tsp_fbcb2" in assignedItems playa) exitWith {[playa, "tsp_animate_map_in", "tsp_animate_map_loop", "\A3\Props_F_Exp_A\Military\Equipment\Tablet_02_F.p3d", [-0.07,0.01,-0.05], [200,-50,10], {sleep 0.2;!visibleMap}] spawn tsp_fnc_gesture_item};
    if ("ItemGPS" in assignedItems playa) exitWith {[playa, "tsp_animate_map_in", "tsp_animate_map_loop", "\a3\Weapons_F\Ammo\mag_gps.p3d", [-0.02,0.03,0], [-70,-60,0], {sleep 0.2;!visibleMap}] spawn tsp_fnc_gesture_item};
    if ("ACE_microDAGR" in assignedItems playa) exitWith {[playa, "tsp_animate_map_in", "tsp_animate_map_loop", "\z\ace\addons\microdagr\data\MicroDAGR.p3d", [0.01,0.035,0], [-80,-50,0], {sleep 0.2;!visibleMap}] spawn tsp_fnc_gesture_item};        
    [playa, "tsp_animate_map_in", "tsp_animate_map_loop", "\A3\Structures_F\Items\Documents\Map_unfolded_F.p3d", [-0.01,0.01,-0.01], [50,170,-90], {sleep 0.2;!visibleMap}] spawn tsp_fnc_gesture_item;
    playa spawn {[_this, 1, "tsp_animate\snd\map_open.ogg", 0.7] call tsp_fnc_animate_effect; waitUntil {!visibleMap}; [_this, 1, "tsp_animate\snd\map_close.ogg", 0.7] call tsp_fnc_animate_effect};
}}}];

player addEventHandler ["GestureChanged", {  //-- Signal Hints (Must be done this way for ACE keybinds to activate them)
    params ["_unit", "_gesture"];
    if (_gesture == "gestureAdvance") exitWith {[playa, 'Advance!'] call tsp_fnc_notify};
    if (_gesture == "gestureGo") exitWith {[playa, 'Go Go Go!'] call tsp_fnc_notify};
    if (_gesture == "gestureFollow") exitWith {[playa, 'Follow me!'] call tsp_fnc_notify};
    if (_gesture == "gestureUp") exitWith {[playa, 'Up there!'] call tsp_fnc_notify};
    if (_gesture == "gestureCeaseFire") exitWith {[playa, 'Oi!'] call tsp_fnc_notify};
    if (_gesture == "gestureFreeze") exitWith {[playa, 'Freeze!'] call tsp_fnc_notify};
    if (_gesture == "ace_gestures_forward") exitWith {[playa, 'Forward!'] call tsp_fnc_notify};
    if (_gesture == "ace_gestures_regroup") exitWith {[playa, 'Regroup!'] call tsp_fnc_notify};
    if (_gesture == "ace_gestures_freeze") exitWith {[playa, 'Freeze!'] call tsp_fnc_notify};
    if (_gesture == "ace_gestures_cover") exitWith {[playa, 'Cover me!'] call tsp_fnc_notify};
    if (_gesture == "ace_gestures_point") exitWith {[playa, 'Over there!'] call tsp_fnc_notify};
    if (_gesture == "ace_gestures_engage") exitWith {[playa, 'Engage!'] call tsp_fnc_notify};
    if (_gesture == "ace_gestures_hold") exitWith {[playa, 'Hold'] call tsp_fnc_notify};
    if (_gesture == "ace_gestures_warning") exitWith {[playa, 'Watch out!'] call tsp_fnc_notify};
}];

["if (tsp_cba_animate_door && ['door', _this#4] call BIS_fnc_inString || ['gate', _this#4] call BIS_fnc_inString) then {[playa,'door'] call tsp_fnc_animate_tactical};"] spawn tsp_fnc_scroll;

if (tsp_cba_animate_sling_add) then {addMissionEventHandler ["EntityCreated", {params ["_entity"]; if (local _entity && _entity isKindOf "CAManBase" && !("tsp_sling" in items _entity)) then {_entity addItem "tsp_sling"}}]};
if (tsp_cba_animate_sling_add && isServer) then {{if !("tsp_sling" in items _x) then {_x addItem "tsp_sling"}} forEach allUnits}; 

tsp_old = currentWeapon playa; tsp_future = [];
addMissionEventHandler ["Draw3D", {
    if (count tsp_future > 0) exitWith {{_x params ["_time", "_params", "_code"]; if (time > _time) then {_params call _code; tsp_future = tsp_future select {_x#2 isNotEqualTo _code}}} forEach tsp_future};
    [tsp_old, currentWeapon playa] params ["_old", "_new"]; tsp_old = _new;  //-- Exit if no switch or unarmed or no sling
	if (currentWeapon playa == _old || _new == "" || !("tsp_sling" in items playa) || !tsp_cba_animate_sling || !(stance playa in ["CROUCH","STAND"]) || (playa getVariable ["tsp_slung", []]) isNotEqualTo []) exitWith {};
    if (_new == secondaryWeapon playa && _old == primaryWeapon playa && _old != "") exitWith {[playa, true, false, false, true] call tsp_fnc_animate_sling};  //-- Rifle > launcher
    if (_new == handgunWeapon playa && _old == primaryWeapon playa && _old != "") exitWith {[playa, true, false, true] call tsp_fnc_animate_sling};          //-- Rifle > pistol
}];

while {tsp_cba_animate_poll > 0} do {[playa, ""] call tsp_fnc_animate_tactical; sleep tsp_cba_animate_poll};  //-- Tactical polling