{
    _x params ["_name", "_path", ["_key", 0]]; [getText (call compile (_path + " >> 'condition'")), getText (call compile (_path + " >> 'statement'"))] params ["_condition", "_statement"];
    ["tsp_cba_animate_" + _name, "CHECKBOX", [_name, "Enable/disable this animation."], ["TSP Animate", "Animations"], true, false] call CBA_fnc_addSetting;
    [["TSP Animate", "Animations"], "tsp_" + _name, _name, compile ("if (" + _condition + ") then {" + _statement + "}"), {}, [_key, [false, false, false]]] call CBA_fnc_addKeybind;
} forEach [
    ["Frag", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_doors'>>'tsp_animate_frag'"],
    ["Shotgun", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_doors'>>'tsp_animate_shotgun'"],
    ["Ready", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_doors'>>'tsp_animate_ready'"],
    ["Peek", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_doors'>>'tsp_animate_peek'"],
    ["Abort", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_doors'>>'tsp_animate_abort'"],
    ["Halt", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_formations'>>'tsp_animate_halt'"],
    ["Column", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_formations'>>'tsp_animate_column'"],
    ["Line", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_formations'>>'tsp_animate_line'"],
    ["Wedge", "configFile>>'CfgVehicles'>>'CAManBase'>>'ACE_SelfActions'>>'ACE_Animations'>>'tsp_animate_formations'>>'tsp_animate_wedge'"]
];