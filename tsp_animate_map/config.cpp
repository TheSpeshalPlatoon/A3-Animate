class CfgPatches {class tsp_animate_map {requiredAddons[] = {"tsp_core", "cba_common", "tsp_animate"}; units[] = {};};};

class Extended_PostInit_EventHandlers {class tsp_animate_map_init {init = "['CBA_settingsInitialized', {[] spawn compileScript ['\tsp_animate_map\init.sqf']}] call CBA_fnc_addEventHandler;";};};  