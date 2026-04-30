class CfgPatches {
	class tsp_animate_viper {
		requiredAddons[] = {"tsp_core", "tsp_animate"};
		units[] = {};
	};
};

//-- FUNCTIONS
class Extended_PreInit_EventHandlers {class tsp_animate_viper_cba {init = "[] call compileScript ['\tsp_animate_viper\cba.sqf']";};};

//-- ACE Actions
class CfgVehicles {
	class Man;
	class CAManBase: Man {
		class ACE_SelfActions {
			class ACE_Animations {
				class tsp_animate_doors {
					class tsp_animate_frag {displayName = "Frag"; condition = "tsp_cba_animate_frag"; statement = "[playa, 'Frag', 5] call tsp_fnc_notify; [playa] call tsp_fnc_animate_effect; [playa, '', 'tsp_animate_frag', '', true, true, true] spawn tsp_fnc_gesture_play"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
					class tsp_animate_ballistic {displayName = "Ballistic"; condition = "tsp_cba_animate_ballistic"; statement = "[playa, 'Ballistic', 5] call tsp_fnc_notify; [playa] call tsp_fnc_animate_effect; [playa, '', 'tsp_animate_ballistic', '', true, true, true] spawn tsp_fnc_gesture_play"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
					class tsp_animate_ready {displayName = "Ready"; condition = "tsp_cba_animate_ready"; statement = "[playa, 'Ready', 5] call tsp_fnc_notify; [playa] call tsp_fnc_animate_effect; [playa, '', 'tsp_animate_ready', '', true, true, true] spawn tsp_fnc_gesture_play"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
					class tsp_animate_peek {displayName = "Peek"; condition = "tsp_cba_animate_peek"; statement = "[playa, 'Peek', 5] call tsp_fnc_notify; [playa] call tsp_fnc_animate_effect; [playa, '', 'tsp_animate_peek', '', true, true, true] spawn tsp_fnc_gesture_play"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
					class tsp_animate_danger {displayName = "Danger"; condition = "tsp_cba_animate_danger"; statement = "[playa, 'Danger', 5] call tsp_fnc_notify; [playa] call tsp_fnc_animate_effect; [playa, '', 'tsp_animate_danger', '', true, true, true] spawn tsp_fnc_gesture_play"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
				};
				class tsp_animate_formations {
					class tsp_animate_halt {displayName = "Halt"; condition = "tsp_cba_animate_halt"; statement = "[playa, 'Halt', 5] call tsp_fnc_notify; [playa] call tsp_fnc_animate_effect; [playa, '', 'tsp_animate_halt', '', true, true, true] spawn tsp_fnc_gesture_play"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
					class tsp_animate_column {displayName = "Column"; condition = "tsp_cba_animate_column"; statement = "(group playa) setFormation 'COLUMN'; [playa, 'Column', 5] call tsp_fnc_notify; [playa] call tsp_fnc_animate_effect; [playa, '', 'tsp_animate_column', '', true, true, true] spawn tsp_fnc_gesture_play"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
					class tsp_animate_line {displayName = "Line"; condition = "tsp_cba_animate_line"; statement = "(group playa) setFormation 'LINE'; [playa, 'Line', 5] call tsp_fnc_notify; [playa] call tsp_fnc_animate_effect; [playa, '', 'tsp_animate_line', '', true, true, true] spawn tsp_fnc_gesture_play"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
					class tsp_animate_wedge {displayName = "Wedge"; condition = "tsp_cba_animate_wedge"; statement = "(group playa) setFormation 'WEDGE'; [playa, 'Wedge', 5] call tsp_fnc_notify; [playa] call tsp_fnc_animate_effect; [playa, '', 'tsp_animate_wedge', '', true, true, true] spawn tsp_fnc_gesture_play"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
				};
			};
		};
	};
};

//-- GESTURES
class CfgMovesBasic {
    class default;
    class DefaultDie;
    class ManActions {
		tsp_animate_column[] = {"tsp_animate_column", "Gesture"};
		tsp_animate_danger[] = {"tsp_animate_danger", "Gesture"};
		tsp_animate_halt[] = {"tsp_animate_halt", "Gesture"};
		tsp_animate_line[] = {"tsp_animate_line", "Gesture"};
		tsp_animate_ready[] = {"tsp_animate_ready", "Gesture"};
		tsp_animate_wedge[] = {"tsp_animate_wedge", "Gesture"};
		tsp_animate_frag[] = {"tsp_animate_frag", "Gesture"};
		tsp_animate_ballistic[] = {"tsp_animate_ballistic", "Gesture"};
		tsp_animate_peek[] = {"tsp_animate_peek", "Gesture"};
	};
};
class CfgGesturesMale {
	skeletonName = "OFP2_ManSkeleton";
	class Default {};
	class States {
		class tsp_animate_knock;
		class tsp_animate_column: tsp_animate_knock {file = "tsp_animate_viper\column.rtm"; speed = 0.5; cancel = true; interpolationSpeed = 3; leftHandIKCurve[] = {0}; rightHandIKCurve[] = {1}; disableWeapons = false;};
		class tsp_animate_danger: tsp_animate_column {file = "tsp_animate_viper\danger.rtm"; speed = 1.0; cancel = true; interpolationSpeed = 3; leftHandIKCurve[] = {0}; rightHandIKCurve[] = {1}; disableWeapons = false;};
		class tsp_animate_halt: tsp_animate_danger {file = "tsp_animate_viper\hold.rtm"; speed = 1.0; cancel = true; interpolationSpeed = 3; leftHandIKCurve[] = {0}; rightHandIKCurve[] = {1}; disableWeapons = false;};
		class tsp_animate_line: tsp_animate_halt {file = "tsp_animate_viper\line.rtm"; speed = 1.0; cancel = true; interpolationSpeed = 3; leftHandIKCurve[] = {0}; rightHandIKCurve[] = {1}; disableWeapons = false;};
		class tsp_animate_ready: tsp_animate_line {file = "tsp_animate_viper\ready.rtm"; speed = 1.0; cancel = true; interpolationSpeed = 3; leftHandIKCurve[] = {0}; rightHandIKCurve[] = {1}; disableWeapons = false;};
		class tsp_animate_wedge: tsp_animate_ready {file = "tsp_animate_viper\wedge.rtm"; speed = 1.0; cancel = true; interpolationSpeed = 3; leftHandIKCurve[] = {0}; rightHandIKCurve[] = {1}; disableWeapons = false;};
		class tsp_animate_frag: tsp_animate_ready {file = "tsp_animate_viper\frag.rtm"; speed = 0.75; cancel = true; interpolationSpeed = 3; leftHandIKCurve[] = {0}; rightHandIKCurve[] = {1}; disableWeapons = false;};
		class tsp_animate_ballistic: tsp_animate_ready {file = "tsp_animate_viper\shotgunup.rtm"; speed = 1.0; cancel = true; interpolationSpeed = 3; leftHandIKCurve[] = {0}; rightHandIKCurve[] = {1}; disableWeapons = false;};
		class tsp_animate_peek: tsp_animate_ready {file = "tsp_animate_viper\peakdoor.rtm"; speed = 1.2; cancel = true; interpolationSpeed = 3; leftHandIKCurve[] = {0}; rightHandIKCurve[] = {1}; disableWeapons = false;};
	};
};

