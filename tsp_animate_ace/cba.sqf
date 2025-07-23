#include "\a3\editor_f\Data\Scripts\dikCodes.h"; disableSerialization;

["tsp_cba_animate_clacker", "CHECKBOX", ["Clacker", "Enable/disable animation when using ACE clacker."], ["TSP Animate", "ACE"], true] call CBA_fnc_addSetting;
["tsp_cba_animate_captive", "CHECKBOX", ["Captive", "Enable/disable animation when using escorting ACE Captive."], ["TSP Animate", "ACE"], true] call CBA_fnc_addSetting;
["tsp_cba_animate_grenade", "CHECKBOX", ["Grenade", "Enable/disable grenade throw animation."], ["TSP Animate", "ACE"], true] call CBA_fnc_addSetting;
["tsp_cba_animate_lift", "CHECKBOX", ["Lift", "Enable/disable ACE object lifting animation."], ["TSP Animate", "ACE"], true] call CBA_fnc_addSetting;
["tsp_cba_animate_carry", "SLIDER", ["Carry Speed", "How long it takes to carry someone."], ["TSP Animate", "ACE"], [0, 10, 2], false] call CBA_fnc_addSetting;

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