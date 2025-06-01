#include "\a3\editor_f\Data\Scripts\dikCodes.h"; disableSerialization;

["tsp_cba_animate_clacker", "CHECKBOX", ["Clacker", "Enable/disable animation when using ACE clacker."], ["TSP Animate", "ACE"], true] call CBA_fnc_addSetting;
["tsp_cba_animate_captive", "CHECKBOX", ["Captive", "Enable/disable animation when using escorting ACE Captive."], ["TSP Animate", "ACE"], true] call CBA_fnc_addSetting;
["tsp_cba_animate_grenade", "CHECKBOX", ["Grenade", "Enable/disable grenade throw animation."], ["TSP Animate", "ACE"], true] call CBA_fnc_addSetting;
["tsp_cba_animate_carry", "SLIDER", ["Carry Speed", "How long it takes to carry someone."], ["TSP Animate", "ACE"], [0, 10, 2], false] call CBA_fnc_addSetting;