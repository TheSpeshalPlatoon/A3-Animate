sleep 3;  //-- Wait so this runs after the original
tsp_cba_animate_map = false;  //-- Disable original map
addUserActionEventHandler ["ShowMap", "Activate", {[] spawn {sleep 0.01; if (visibleMap && isNull findDisplay 312) then {
    [playa] call tsp_fnc_animate_effect;
    //if ("tsp_trijatta" in assignedItems playa) exitWith {[playa, "tsp_animate_map_in", "tsp_animate_map_loop", "\tsp_tracker\trijatta.p3d", "leftHand", [-0.06,0,-0.06], [80,-35,0], {sleep 0.2;!visibleMap}] spawn tsp_fnc_gesture_item};
    //if ("tsp_fbcb2" in assignedItems playa) exitWith {[playa, "tsp_animate_map_in", "tsp_animate_map_loop", "\A3\Props_F_Exp_A\Military\Equipment\Tablet_02_F.p3d", "leftHand", [-0.07,0.01,-0.05], [200,-50,10], {sleep 0.2;!visibleMap}] spawn tsp_fnc_gesture_item};
    //if ("ItemGPS" in assignedItems playa) exitWith {[playa, "tsp_animate_map_in", "tsp_animate_map_loop", "\a3\Weapons_F\Ammo\mag_gps.p3d", "leftHand", [-0.02,0.03,0], [-70,-60,0], {sleep 0.2;!visibleMap}] spawn tsp_fnc_gesture_item};
    //if ("ACE_microDAGR" in assignedItems playa) exitWith {[playa, "tsp_animate_map_in", "tsp_animate_map_loop", "\z\ace\addons\microdagr\data\MicroDAGR.p3d", "leftHand", [0.01,0.035,0], [-80,-50,0], {sleep 0.2;!visibleMap}] spawn tsp_fnc_gesture_item};        
    [playa, "tsp_animate_map_in", "tsp_animate_map_loop", "\A3\Structures_F\Items\Documents\Map_unfolded_F.p3d", "leftHand", [-0.01,0.01,-0.01], [50,170,-90], {sleep 0.2;!visibleMap}] spawn tsp_fnc_gesture_item;
    [playa, 1, "tsp_animate\snd\map_open.ogg", 0.7] call tsp_fnc_animate_effect; waitUntil {!visibleMap}; [playa, 1, "tsp_animate\snd\map_close.ogg", 0.7] call tsp_fnc_animate_effect;
}}}];