#include "\a3\editor_f\Data\Scripts\dikCodes.h"; disableSerialization;

["tsp_cba_animate_clacker", "CHECKBOX", ["Clacker", "Enable/disable animation when using ACE clacker."], ["TSP Animate", "ACE"], true] call CBA_fnc_addSetting;
["tsp_cba_animate_captive", "CHECKBOX", ["Captive", "Enable/disable animation when using escorting ACE Captive."], ["TSP Animate", "ACE"], true] call CBA_fnc_addSetting;
["tsp_cba_animate_grenade", "CHECKBOX", ["Grenade", "Enable/disable grenade throw animation."], ["TSP Animate", "ACE"], true] call CBA_fnc_addSetting;
["tsp_cba_animate_lift", "CHECKBOX", ["Lift", "Enable/disable ACE object lifting animation."], ["TSP Animate", "ACE"], true] call CBA_fnc_addSetting;
["tsp_cba_animate_carry", "SLIDER", ["Carry Speed", "How long it takes to carry someone."], ["TSP Animate", "ACE"], [0, 10, 2], false] call CBA_fnc_addSetting;
["tsp_cba_animate_drop_ace", "CHECKBOX", ["Droppable ACE actions", "Show droppable ACE actions."], ["TSP Animate", "ACE"], false] call CBA_fnc_addSetting;

{
    _x params ["_name", "_path", ["_key", 0]]; [getText (call compile (_path + " >> 'condition'")), getText (call compile (_path + " >> 'statement'"))] params ["_condition", "_statement"];
    ["tsp_cba_animate_" + _name, "CHECKBOX", [_name, "Enable/disable this animation."], ["TSP Animate", "Animations"], true, false] call CBA_fnc_addSetting;
    [["TSP Animate", "Animations (ACE)"], "tsp_" + _name, _name, compile ("if (" + _condition + ") then {" + _statement + "}"), {}, [_key, [false, false, false]]] call CBA_fnc_addKeybind;
} forEach [
    ["Advance", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'ace_gestures_cat_gestures'>>'ace_gestures_Advance'"], 
    ["Go", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'ace_gestures_cat_gestures'>>'ace_gestures_Go'"], 
    ["Follow", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'ace_gestures_cat_gestures'>>'ace_gestures_Follow'"], 
    ["Up", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'ace_gestures_cat_gestures'>>'ace_gestures_Up'"], 
    ["Cease Fire", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'ace_gestures_cat_gestures'>>'ace_gestures_CeaseFire'"], 
    ["Stop", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'ace_gestures_cat_gestures'>>'ace_gestures_Stop'"], 
    ["Forward", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'ace_gestures_cat_gestures'>>'ace_gestures_Forward'"], 
    ["Regroup", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'ace_gestures_cat_gestures'>>'ace_gestures_Regroup'"], 
    ["Freeze", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'ace_gestures_cat_gestures'>>'ace_gestures_Freeze'"], 
    ["Cover", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'ace_gestures_cat_gestures'>>'ace_gestures_Cover'"], 
    ["Point", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'ace_gestures_cat_gestures'>>'ace_gestures_Point'"], 
    ["Engage", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'ace_gestures_cat_gestures'>>'ace_gestures_Engage'"], 
    ["Hold", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'ace_gestures_cat_gestures'>>'ace_gestures_Hold'"], 
    ["Warning", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'ace_gestures_cat_gestures'>>'ace_gestures_Warning'"]
];

{
    _x params ["_name", "_class"];
    _drop = [_class, "Drop " + _name, getText (configFile >> "CfgMagazines" >> _class >> "picture"), 
        {params ["_source", "_player", "_params"]; _params params ["_class"]; [_player, _class] spawn tsp_fnc_animate_drop}, 
        {params ["_source", "_player", "_params"]; _params params ["_class"]; (_class in magazines _player || tsp_cba_animate_drop_infinite) && tsp_cba_animate_drop_ace},
    {},[_class],[0,0,0],5] call ace_interact_menu_fnc_createAction; 
    ["CAManBase", 1, ["ACE_SelfActions", "tsp_animate_drop"], _drop, true] call ace_interact_menu_fnc_addActionToClass;
} forEach (call compile tsp_cba_animate_drop);