class CfgPatches {
	class tsp_animate_dutch {
		requiredAddons[] = {"tsp_core", "cba_common", "tsp_animate"};
		units[] = {};
	};
};

class CfgVehicles {
	class Man;
	class CAManBase: Man {
		class ACE_SelfActions {
			class ACE_Animations {
				displayName = "Animations";
				icon = "\z\ace\addons\gestures\UI\gestures_ca.paa";
				exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"};
				class ace_gestures_cat_gestures {
					displayName = "Signals"; icon = "tsp_animate\gui\signal.paa"; 
					condition = "stance _target != 'PRONE' && ([gestureState playa] call tsp_fnc_gesture_sanitize=='' || 'tactical' in gestureState playa)"; 
					exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"};
					class ace_gestures_Advance {displayName = "Advance"; condition = "!('freefall' in animationState ACE_player)"; statement = "[ACE_player, 'Advance!'] call tsp_fnc_notify; [ACE_player] call tsp_fnc_animate_effect; [ACE_player, 'gestureAdvance'] call ace_common_fnc_doGesture"; showDisabled = 1;};
					class ace_gestures_Go {displayName = "Go"; condition = "!('freefall' in animationState ACE_player)"; statement = "[ACE_player, 'Go'] call tsp_fnc_notify; [ACE_player] call tsp_fnc_animate_effect; [ACE_player, selectRandom ['gestureGo', 'gestureGoB']] call ace_common_fnc_doGesture"; showDisabled = 1;};
					class ace_gestures_Follow {displayName = "Follow"; condition = "!('freefall' in animationState ACE_player)"; statement = "[ACE_player, 'Follow me!'] call tsp_fnc_notify; [ACE_player] call tsp_fnc_animate_effect; [ACE_player, 'gestureFollow'] call ace_common_fnc_doGesture"; showDisabled = 1;};
					class ace_gestures_Up {displayName = "Up"; condition = "!('freefall' in animationState ACE_player)"; statement = "[ACE_player, 'Up'] call tsp_fnc_notify; [ACE_player] call tsp_fnc_animate_effect; [ACE_player, 'gestureUp'] call ace_common_fnc_doGesture"; showDisabled = 1;};
					class ace_gestures_CeaseFire {displayName = "Cease Fire"; condition = "!('freefall' in animationState ACE_player)"; statement = "[ACE_player, 'Cease Fire'] call tsp_fnc_notify; [ACE_player] call tsp_fnc_animate_effect; [ACE_player, 'gestureCeaseFire'] call ace_common_fnc_doGesture"; showDisabled = 1;};
					class ace_gestures_Stop {displayName = "Stop"; condition = "!('freefall' in animationState ACE_player)"; statement = "[ACE_player, 'Stop!'] call tsp_fnc_notify; [ACE_player] call tsp_fnc_animate_effect; [ACE_player, 'gestureFreeze'] call ace_common_fnc_doGesture"; showDisabled = 1;};
					class ace_gestures_Forward {displayName = "Forward"; condition = "true"; statement = "[ACE_player, 'Forward!'] call tsp_fnc_notify; [ACE_player] call tsp_fnc_animate_effect; 'ace_gestures_forward' call ace_gestures_fnc_playSignal"; showDisabled = 1;};
					class ace_gestures_Regroup {displayName = "Regroup"; condition = "true"; statement = "[ACE_player, 'Regroup!'] call tsp_fnc_notify; [ACE_player] call tsp_fnc_animate_effect; 'ace_gestures_regroup' call ace_gestures_fnc_playSignal"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
					class ace_gestures_Freeze {displayName = "Freeze"; condition = "true"; statement = "[ACE_player, 'Freeze!'] call tsp_fnc_notify; [ACE_player] call tsp_fnc_animate_effect; 'ace_gestures_freeze' call ace_gestures_fnc_playSignal"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
					class ace_gestures_Cover {displayName = "Cover"; condition = "true"; statement = "[ACE_player, 'Cover'] call tsp_fnc_notify; [ACE_player] call tsp_fnc_animate_effect; 'ace_gestures_cover' call ace_gestures_fnc_playSignal"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
					class ace_gestures_Point {displayName = "Point"; condition = "true"; statement = "[ACE_player, 'Points'] call tsp_fnc_notify; [ACE_player] call tsp_fnc_animate_effect; 'ace_gestures_point' call ace_gestures_fnc_playSignal"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
					class ace_gestures_Engage {displayName = "Engage"; condition = "true"; statement = "[ACE_player, 'Engage!'] call tsp_fnc_notify; [ACE_player] call tsp_fnc_animate_effect; 'ace_gestures_engage' call ace_gestures_fnc_playSignal"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
					class ace_gestures_Hold {displayName = "Hold"; condition = "true"; statement = "[ACE_player, 'Hold!'] call tsp_fnc_notify; [ACE_player] call tsp_fnc_animate_effect; 'ace_gestures_hold' call ace_gestures_fnc_playSignal"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
					class ace_gestures_Warning {displayName = "Warning"; condition = "true"; statement = "[ACE_player, 'Warning'] call tsp_fnc_notify; [ACE_player] call tsp_fnc_animate_effect; 'ace_gestures_warning' call ace_gestures_fnc_playSignal"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
				};
				class tsp_animate_doors {
					displayName = "Doors"; icon = "tsp_animate\gui\door.paa";  
					condition = "stance _target != 'PRONE' && ([gestureState playa] call tsp_fnc_gesture_sanitize=='' || 'tactical' in gestureState playa)"; 
					exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"};
					class tsp_animate_bang {displayName = "Bang"; condition = "tsp_cba_animate_bang"; statement = "[playa, 'Bang', 5] call tsp_fnc_notify; [playa] call tsp_fnc_animate_effect; [playa, '', 'tsp_animate_bang', '', true, true, true] spawn tsp_fnc_gesture_play"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
					class tsp_animate_breach {displayName = "Breach"; condition = "tsp_cba_animate_breach"; statement = "[playa, 'Breacher', 5] call tsp_fnc_notify; [playa] call tsp_fnc_animate_effect; [playa, '', 'tsp_animate_breach', '', true, true, true] spawn tsp_fnc_gesture_play"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
				};
			};
		};
	};
};