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
					class tsp_animate_frag {displayName = "Frag"; condition = "tsp_cba_animate_frag"; statement = "[playa, 'Frag it!', 5] call tsp_fnc_notify; [playa] call tsp_fnc_animate_effect; [playa, '', 'tsp_animate_frag', '', true, true, true] spawn tsp_fnc_gesture_play"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
					class tsp_animate_shotgun {displayName = "Shotgun"; condition = "tsp_cba_animate_shotgun"; statement = "[playa, 'Shotgun breach!', 5] call tsp_fnc_notify; [playa] call tsp_fnc_animate_effect; [playa, '', 'tsp_animate_shotgun', '', true, true, true] spawn tsp_fnc_gesture_play"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
					class tsp_animate_ready {displayName = "Ready"; condition = "tsp_cba_animate_ready"; statement = "[playa, 'I am ready!', 5] call tsp_fnc_notify; [playa] call tsp_fnc_animate_effect; [playa, '', 'tsp_animate_ready', '', true, true, true] spawn tsp_fnc_gesture_play"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
					class tsp_animate_peek {displayName = "Peek"; condition = "tsp_cba_animate_peek"; statement = "[playa, 'Peek it!', 5] call tsp_fnc_notify; [playa] call tsp_fnc_animate_effect; [playa, '', 'tsp_animate_peek', '', true, true, true] spawn tsp_fnc_gesture_play"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
					class tsp_animate_abort {displayName = "Abort"; condition = "tsp_cba_animate_abort"; statement = "[playa, 'Abort!', 5] call tsp_fnc_notify; [playa] call tsp_fnc_animate_effect; [playa, '', 'tsp_animate_abort', '', true, true, true] spawn tsp_fnc_gesture_play"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
				};
				class tsp_animate_formations {
					class tsp_animate_halt {displayName = "Halt"; condition = "tsp_cba_animate_halt"; statement = "[playa, 'Halt!', 5] call tsp_fnc_notify; [playa] call tsp_fnc_animate_effect; [playa, '', 'tsp_animate_halt', '', true, true, true] spawn tsp_fnc_gesture_play"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
					class tsp_animate_column {displayName = "Column"; condition = "tsp_cba_animate_column"; statement = "[playa, 'Form a column!', 5] call tsp_fnc_notify; [playa] call tsp_fnc_animate_effect; [playa, '', 'tsp_animate_column', '', true, true, true] spawn tsp_fnc_gesture_play"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
					class tsp_animate_line {displayName = "Line"; condition = "tsp_cba_animate_line"; statement = "[playa, 'Form a line!', 5] call tsp_fnc_notify; [playa] call tsp_fnc_animate_effect; [playa, '', 'tsp_animate_line', '', true, true, true] spawn tsp_fnc_gesture_play"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
					class tsp_animate_wedge {displayName = "Wedge"; condition = "tsp_cba_animate_wedge"; statement = "[playa, 'Form a wedge!', 5] call tsp_fnc_notify; [playa] call tsp_fnc_animate_effect; [playa, '', 'tsp_animate_wedge', '', true, true, true] spawn tsp_fnc_gesture_play"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
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
		tsp_animate_abort[] = {"tsp_animate_abort", "Gesture"};
		tsp_animate_halt[] = {"tsp_animate_halt", "Gesture"};
		tsp_animate_line[] = {"tsp_animate_line", "Gesture"};
		tsp_animate_ready[] = {"tsp_animate_ready", "Gesture"};
		tsp_animate_wedge[] = {"tsp_animate_wedge", "Gesture"};
		tsp_animate_frag[] = {"tsp_animate_frag", "Gesture"};
		tsp_animate_shotgun[] = {"tsp_animate_shotgun", "Gesture"};
		tsp_animate_peek[] = {"tsp_animate_peek", "Gesture"};
	};
};
class CfgGesturesMale {
	skeletonName = "OFP2_ManSkeleton";
	class Default {};
	class States {
		class tsp_animate_knock;
		class tsp_animate_column: tsp_animate_knock {file = "tsp_animate_viper\column.rtm"; speed = 0.5; cancel = true; interpolationSpeed = 3; leftHandIKCurve[] = {0}; rightHandIKCurve[] = {1}; disableWeapons = false;};
		class tsp_animate_abort: tsp_animate_column {file = "tsp_animate_viper\danger.rtm"; speed = 1.0; cancel = true; interpolationSpeed = 3; leftHandIKCurve[] = {0}; rightHandIKCurve[] = {1}; disableWeapons = false;};
		class tsp_animate_halt: tsp_animate_abort {file = "tsp_animate_viper\hold.rtm"; speed = 1.0; cancel = true; interpolationSpeed = 3; leftHandIKCurve[] = {0}; rightHandIKCurve[] = {1}; disableWeapons = false;};
		class tsp_animate_line: tsp_animate_halt {file = "tsp_animate_viper\line.rtm"; speed = 1.0; cancel = true; interpolationSpeed = 3; leftHandIKCurve[] = {0}; rightHandIKCurve[] = {1}; disableWeapons = false;};
		class tsp_animate_ready: tsp_animate_line {file = "tsp_animate_viper\ready.rtm"; speed = 1.0; cancel = true; interpolationSpeed = 3; leftHandIKCurve[] = {0}; rightHandIKCurve[] = {1}; disableWeapons = false;};
		class tsp_animate_wedge: tsp_animate_ready {file = "tsp_animate_viper\wedge.rtm"; speed = 1.0; cancel = true; interpolationSpeed = 3; leftHandIKCurve[] = {0}; rightHandIKCurve[] = {1}; disableWeapons = false;};
		class tsp_animate_frag: tsp_animate_ready {file = "tsp_animate_viper\frag.rtm"; speed = 0.75; cancel = true; interpolationSpeed = 3; leftHandIKCurve[] = {0}; rightHandIKCurve[] = {1}; disableWeapons = false;};
		class tsp_animate_shotgun: tsp_animate_ready {file = "tsp_animate_viper\shotgunup.rtm"; speed = 1.0; cancel = true; interpolationSpeed = 3; leftHandIKCurve[] = {0}; rightHandIKCurve[] = {1}; disableWeapons = false;};
		class tsp_animate_peek: tsp_animate_ready {file = "tsp_animate_viper\peakdoor.rtm"; speed = 1.2; cancel = true; interpolationSpeed = 3; leftHandIKCurve[] = {0}; rightHandIKCurve[] = {1}; disableWeapons = false;};
	};
};

