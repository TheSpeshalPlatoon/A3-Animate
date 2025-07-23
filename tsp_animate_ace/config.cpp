class CfgPatches {
	class tsp_animate_ace {
		requiredAddons[] = {"tsp_core", "tsp_animate", "cba_common", "ace_common", "ace_interaction", "ace_captives", "ace_gestures"};		
        skipWhenMissingDependencies = 1;
		units[] = {};
	};
};
 
class Extended_PreInit_EventHandlers {class tsp_animate_ace_cba {init = "[] call compileScript ['\tsp_animate_ace\cba.sqf']";}; class tsp_animate_ace_functions {init = "[] call compileScript ['\tsp_animate_ace\functions.sqf']";};};
class Extended_PostInit_EventHandlers {class tsp_animate_ace_init {init = "['CBA_settingsInitialized', {[] spawn compileScript ['\tsp_animate_ace\init.sqf']}] call CBA_fnc_addEventHandler;";};};  
class CfgFunctions {
    class ace_common {class functions {class doGesture {file = "tsp_animate_ace\functions\gesture.sqf";};};};
    class ace_gestures {class functions {class playSignal {file = "tsp_animate_ace\functions\signal.sqf";};};};
    class ace_captives {class functions {class handleAnimChangedHandcuffed {file = "tsp_animate_ace\functions\captive.sqf";};};};
    class ace_dragging {class functions {class startCarryLocal {file = "tsp_animate_ace\functions\carry.sqf";};};};
};

//-- ACE Actions - Overwrite Tapping
class CfgVehicles {
	class Man;
	class CAManBase: Man {
		class ACE_SelfActions {
			class ACE_Animations {
				displayName = "Animations";
				icon = "\z\ace\addons\gestures\UI\gestures_ca.paa";
				exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"};
				class tsp_animate_cancel {
					displayName = "Cancel"; icon = "tsp_animate\gui\cancel.paa"; 
					condition = "getNumber(configFile>>'CfgGesturesMale'>>'States'>>gestureState playa>>'cancel')==1 || getNumber(configFile>>'CfgMovesMaleSdr'>>'States'>>(animationState playa)>>'cancel')==1";
					statement = "if (getNumber(configFile>>'CfgMovesMaleSdr'>>'States'>>(animationState playa)>>'cancel')==1) then {[playa, ''] remoteExec ['switchMove', 0]}; [playa] call tsp_fnc_animate_effect; [playa] call tsp_fnc_gesture_stop";
				};
				class ace_gestures_cat_gestures {
					displayName = "Signals"; icon = "tsp_animate\gui\signal.paa"; 
					condition = "stance _target != 'PRONE' && ([gestureState playa] call tsp_fnc_gesture_sanitize=='' || 'tactical' in gestureState playa)"; 
					exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"};
					class ace_gestures_Advance {displayName = "Advance"; condition = "!('freefall' in animationState ACE_player)"; statement = "[ACE_player, 'Advance!'] call tsp_fnc_notify; [ACE_player] call tsp_fnc_animate_effect; [ACE_player, 'gestureAdvance'] call ace_common_fnc_doGesture"; showDisabled = 1;};
					class ace_gestures_Go {displayName = "Go"; condition = "!('freefall' in animationState ACE_player)"; statement = "[ACE_player, 'Go Go Go!'] call tsp_fnc_notify; [ACE_player] call tsp_fnc_animate_effect; [ACE_player, selectRandom ['gestureGo', 'gestureGoB']] call ace_common_fnc_doGesture"; showDisabled = 1;};
					class ace_gestures_Follow {displayName = "Follow"; condition = "!('freefall' in animationState ACE_player)"; statement = "[ACE_player, 'Follow me!'] call tsp_fnc_notify; [ACE_player] call tsp_fnc_animate_effect; [ACE_player, 'gestureFollow'] call ace_common_fnc_doGesture"; showDisabled = 1;};
					class ace_gestures_Up {displayName = "Up"; condition = "!('freefall' in animationState ACE_player)"; statement = "[ACE_player, 'Up there!'] call tsp_fnc_notify; [ACE_player] call tsp_fnc_animate_effect; [ACE_player, 'gestureUp'] call ace_common_fnc_doGesture"; showDisabled = 1;};
					class ace_gestures_CeaseFire {displayName = "Cease Fire"; condition = "!('freefall' in animationState ACE_player)"; statement = "[ACE_player, 'Oi!'] call tsp_fnc_notify; [ACE_player] call tsp_fnc_animate_effect; [ACE_player, 'gestureCeaseFire'] call ace_common_fnc_doGesture"; showDisabled = 1;};
					class ace_gestures_Stop {displayName = "Stop"; condition = "!('freefall' in animationState ACE_player)"; statement = "[ACE_player, 'Stop!'] call tsp_fnc_notify; [ACE_player] call tsp_fnc_animate_effect; [ACE_player, 'gestureFreeze'] call ace_common_fnc_doGesture"; showDisabled = 1;};
					class ace_gestures_Forward {displayName = "Forward"; condition = "true"; statement = "[ACE_player, 'Forward!'] call tsp_fnc_notify; [ACE_player] call tsp_fnc_animate_effect; 'ace_gestures_forward' call ace_gestures_fnc_playSignal"; showDisabled = 1;};
					class ace_gestures_Regroup {displayName = "Regroup"; condition = "true"; statement = "[ACE_player, 'Regroup!'] call tsp_fnc_notify; [ACE_player] call tsp_fnc_animate_effect; 'ace_gestures_regroup' call ace_gestures_fnc_playSignal"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
					class ace_gestures_Freeze {displayName = "Freeze"; condition = "true"; statement = "[ACE_player, 'Freeze!'] call tsp_fnc_notify; [ACE_player] call tsp_fnc_animate_effect; 'ace_gestures_freeze' call ace_gestures_fnc_playSignal"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
					class ace_gestures_Cover {displayName = "Cover"; condition = "true"; statement = "[ACE_player, 'Cover me!'] call tsp_fnc_notify; [ACE_player] call tsp_fnc_animate_effect; 'ace_gestures_cover' call ace_gestures_fnc_playSignal"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
					class ace_gestures_Point {displayName = "Point"; condition = "true"; statement = "[ACE_player, 'Over there!'] call tsp_fnc_notify; [ACE_player] call tsp_fnc_animate_effect; 'ace_gestures_point' call ace_gestures_fnc_playSignal"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
					class ace_gestures_Engage {displayName = "Engage"; condition = "true"; statement = "[ACE_player, 'Engage!'] call tsp_fnc_notify; [ACE_player] call tsp_fnc_animate_effect; 'ace_gestures_engage' call ace_gestures_fnc_playSignal"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
					class ace_gestures_Hold {displayName = "Hold"; condition = "true"; statement = "[ACE_player, 'Hold!'] call tsp_fnc_notify; [ACE_player] call tsp_fnc_animate_effect; 'ace_gestures_hold' call ace_gestures_fnc_playSignal"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
					class ace_gestures_Warning {displayName = "Warning"; condition = "true"; statement = "[ACE_player, 'Watch out!'] call tsp_fnc_notify; [ACE_player] call tsp_fnc_animate_effect; 'ace_gestures_warning' call ace_gestures_fnc_playSignal"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
				};
				class tsp_animate_doors {
					displayName = "Doors"; icon = "tsp_animate\gui\door.paa";  
					condition = "stance _target != 'PRONE' && ([gestureState playa] call tsp_fnc_gesture_sanitize=='' || 'tactical' in gestureState playa)"; 
					exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"};
					class tsp_animate_bang {displayName = "Bang"; condition = "tsp_cba_animate_bang"; statement = "[playa, selectRandom ['Bang it!','Crash it!'], 5] call tsp_fnc_notify; [playa] call tsp_fnc_animate_effect; [playa, '', 'tsp_animate_bang', '', true, true, true] spawn tsp_fnc_gesture_play"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
					class tsp_animate_breach {displayName = "Breach"; condition = "tsp_cba_animate_breach"; statement = "[playa, 'Breach it!', 5] call tsp_fnc_notify; [playa] call tsp_fnc_animate_effect; [playa, '', 'tsp_animate_breach', '', true, true, true] spawn tsp_fnc_gesture_play"; exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; showDisabled = 1;};
				};
				class tsp_animate_formations: tsp_animate_doors {displayName = "Formations"; icon = "A3\ui_f\data\map\vehicleicons\iconManLeader_ca.paa";};
				class tsp_animate_emotes {  //-- unit,in,loop,out,interupt,instant,return,returnable,toggle,lower,code
					displayName = "Emotes"; icon = "tsp_animate\gui\emotes.paa";
					condition = "stance playa != 'PRONE'";
					exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"};
					class tsp_animate_bird {
						displayName = "Bird"; 
						condition = "tsp_cba_animate_bird && ([gestureState playa] call tsp_fnc_gesture_sanitize=='' || 'tactical' in gestureState playa)"; 
						exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"};
						statement = "[playa] call tsp_fnc_animate_effect; [playa, 'tsp_animate_bird_in', 'tsp_animate_bird_loop', 'tsp_common_stop', true, false, false, false, true, true] spawn tsp_fnc_gesture_play";
					};
					class tsp_animate_thumbsup {
						displayName = "Thumbs Up"; 
						condition = "tsp_cba_animate_thumbsup && ([gestureState playa] call tsp_fnc_gesture_sanitize=='' || 'tactical' in gestureState playa)"; 
						exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"};
						statement = "[playa] call tsp_fnc_animate_effect; [playa, '', 'tsp_animate_thumbsup_loop', 'tsp_common_stop', true, false, false, false, true, true] spawn tsp_fnc_gesture_play";
					};
					class tsp_animate_thumbsdown {
						displayName = "Thumbs Down"; 
						condition = "tsp_cba_animate_thumbsdown && ([gestureState playa] call tsp_fnc_gesture_sanitize=='' || 'tactical' in gestureState playa)"; 
						exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"};
						statement = "[playa] call tsp_fnc_animate_effect; [playa, '', 'tsp_animate_thumbsdown_loop', 'tsp_common_stop', true, false, false, false, true, true] spawn tsp_fnc_gesture_play";
					};
					class tsp_animate_ok {
						displayName = "Ok"; 
						condition = "tsp_cba_animate_ok && ([gestureState playa] call tsp_fnc_gesture_sanitize=='' || 'tactical' in gestureState playa)"; 
						exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"};
						statement = "[playa] call tsp_fnc_animate_effect; [playa, 'tsp_animate_ok_in', 'tsp_animate_ok_loop', 'tsp_common_stop', true, false, false, false, true, true] spawn tsp_fnc_gesture_play";
					};
					class tsp_animate_jackoff {
						displayName = "Jackoff"; 
						condition = "tsp_cba_animate_jackoff && ([gestureState playa] call tsp_fnc_gesture_sanitize=='' || 'tactical' in gestureState playa)";
						exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; 
						statement = "[playa] call tsp_fnc_animate_effect; [playa, '', 'tsp_animate_jackoff_loop', 'tsp_animate_jackoff_out', true, false, false, false, true, true] spawn tsp_fnc_gesture_play";
					};
					class tsp_animate_mahalo {
						displayName = "Mahalo"; 
						condition = "tsp_cba_animate_mahalo && ([gestureState playa] call tsp_fnc_gesture_sanitize=='' || 'tactical' in gestureState playa)"; 
						exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"};
						statement = "[playa] call tsp_fnc_animate_effect; [playa, '', 'tsp_animate_mahalo_loop', 'tsp_common_stop', true, false, false, false, true, true] spawn tsp_fnc_gesture_play";
					};
					class tsp_animate_loser {
						displayName = "L"; 
						condition = "tsp_cba_animate_loser && ([gestureState playa] call tsp_fnc_gesture_sanitize=='' || 'tactical' in gestureState playa)"; 
						exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"};
						statement = "[playa] call tsp_fnc_animate_effect; [playa, '', 'tsp_animate_loser_loop', 'tsp_common_stop', true, false, false, false, true, true] spawn tsp_fnc_gesture_play";
					};
					class tsp_animate_horns {
						displayName = "Horns"; 
						condition = "tsp_cba_animate_horns && ([gestureState playa] call tsp_fnc_gesture_sanitize=='' || 'tactical' in gestureState playa)";
						exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"}; 
						statement = "[playa] call tsp_fnc_animate_effect; [playa, '', 'tsp_animate_horns_loop', 'tsp_common_stop', true, false, fales, false, true, true] spawn tsp_fnc_gesture_play";
					};
					class tsp_animate_peace {
						displayName = "Peace"; 
						condition = "tsp_cba_animate_peace && ([gestureState playa] call tsp_fnc_gesture_sanitize=='' || 'tactical' in gestureState playa)"; 
						exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"};
						statement = "[playa] call tsp_fnc_animate_effect; [playa, '', 'tsp_animate_peace_loop', 'tsp_common_stop', true, false, false, false, true, true] spawn tsp_fnc_gesture_play";
					};
					class tsp_animate_dab {
						displayName = "Dab"; 
						condition = "tsp_cba_animate_dab && ([gestureState playa] call tsp_fnc_gesture_sanitize=='' || 'tactical' in gestureState playa) && currentWeapon playa=='' || (vehicle playa != playa && driver vehicle playa != playa)"; 
						exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"};
						statement = "[playa] call tsp_fnc_animate_effect; [playa, '', 'tsp_animate_dab_loop', 'tsp_common_stop', true, false, false, false, true, true] spawn tsp_fnc_gesture_play";
					};
					class tsp_animate_heart {
						displayName = "Heart"; 
						condition = "tsp_cba_animate_heart && ([gestureState playa] call tsp_fnc_gesture_sanitize=='' || 'tactical' in gestureState playa) && currentWeapon playa=='' || (vehicle playa != playa && driver vehicle playa != playa)"; 
						exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"};
						statement = "[playa] call tsp_fnc_animate_effect; [playa, '', 'tsp_animate_heart_loop', 'tsp_common_stop', true, false, false, false, true, true] spawn tsp_fnc_gesture_play";
					};
					class tsp_animate_rock {//unit,in,loop,out,interupt,instant,return,toggle,lower,level
						displayName = "Rock"; 
						condition = "tsp_cba_animate_rock && (([gestureState playa] call tsp_fnc_gesture_sanitize=='' || 'tactical' in gestureState playa) || 'rockpaperscissors' in gestureState playa) && currentWeapon playa=='' || (vehicle playa != playa && driver vehicle playa != playa)"; 
						exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"};
						statement = "[playa] call tsp_fnc_animate_effect; [playa, 'tsp_animate_rockpaperscissors_in', 'tsp_animate_rockpaperscissors_rock_loop', 'tsp_common_stop', true, 'rockpaperscissors' in gestureState playa, false, false, true, true] spawn tsp_fnc_gesture_play";
					};
					class tsp_animate_paper {
						displayName = "Paper"; 
						condition = "tsp_cba_animate_paper && (([gestureState playa] call tsp_fnc_gesture_sanitize=='' || 'tactical' in gestureState playa) || 'rockpaperscissors' in gestureState playa) && currentWeapon playa=='' || (vehicle playa != playa && driver vehicle playa != playa)"; 
						exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"};						
						statement = "[playa] call tsp_fnc_animate_effect; [playa, 'tsp_animate_rockpaperscissors_in', 'tsp_animate_rockpaperscissors_paper_loop', 'tsp_common_stop', true, 'rockpaperscissors' in gestureState playa, false, false, true, true] spawn tsp_fnc_gesture_play";
					};
					class tsp_animate_scissors {
						displayName = "Scissors"; 
						condition = "tsp_cba_animate_scissors && (([gestureState playa] call tsp_fnc_gesture_sanitize=='' || 'tactical' in gestureState playa) || 'rockpaperscissors' in gestureState playa) && currentWeapon playa=='' || (vehicle playa != playa && driver vehicle playa != playa)"; 
						exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"};
						statement = "[playa] call tsp_fnc_animate_effect; [playa, 'tsp_animate_rockpaperscissors_in', 'tsp_animate_rockpaperscissors_scissors_loop', 'tsp_common_stop', true, 'rockpaperscissors' in gestureState playa, false, false, true, true] spawn tsp_fnc_gesture_play";
					};
				};
				class tsp_animate_dances {
					displayName = "Dances"; icon = "tsp_animate\gui\dances.paa";
					condition = "vehicle playa==playa && stance playa != 'PRONE' && (currentWeapon playa=='' || currentWeapon playa==handgunWeapon player)";
					class tsp_animate_contact {displayName = "Contact"; condition = "tsp_cba_animate_contact"; statement = "[playa, selectRandom ['Acts_Dance_01','Acts_Dance_02']] spawn tsp_fnc_animate_dance";};
					class tsp_animate_duoIvan {displayName = "Duo (Ivan)"; condition = "tsp_cba_animate_ivan"; statement = "[playa, 'a2_duoivan'] spawn tsp_fnc_animate_dance";};
					class tsp_animate_duoStefan {displayName = "Duo (Stefan)"; condition = "tsp_cba_animate_duo"; statement = "[playa, 'a2_duostefan'] spawn tsp_fnc_animate_dance";};
					class tsp_animate_stefan {displayName = "Stefan"; condition = "tsp_cba_animate_stefan"; statement = "[playa, 'a2_stefan'] spawn tsp_fnc_animate_dance";};
					class tsp_animate_zozo {displayName = "ZoZo"; condition = "tsp_cba_animate_zozo"; statement = "[playa, 'a2_zozo'] spawn tsp_fnc_animate_dance";};
					class tsp_animate_metal {displayName = "Metal"; condition = "tsp_cba_animate_metal"; statement = "[playa, 'a2_metal'] spawn tsp_fnc_animate_dance";};
					class tsp_animate_kata {displayName = "Kata"; condition = "tsp_cba_animate_kata"; statement = "[playa, 'AmovPercMstpSnonWnonDnon_exerciseKata'] remoteExec ['playMove', 0]";};
					class tsp_animate_pushups {displayName = "Pushups"; condition = "tsp_cba_animate_pushups"; statement = "[playa, 'amovpercmstpsnonwnondnon_exercisepushup'] remoteExec ['playMove', 0]";};
					class tsp_animate_squats {displayName = "Squats"; condition = "tsp_cba_animate_squats"; statement = "[playa, 'amovpercmstpsnonwnondnon_exercisekneebenda'] remoteExec ['playMove', 0]";};
				};
				class tsp_animate_inspect {
					displayName = "Inspect"; icon = "tsp_animate\gui\inspect.paa"; 
					condition = "tsp_cba_animate_inspect && vehicle playa==playa && stance playa != 'PRONE' && !('freefall' in animationState playa) && ([gestureState playa] call tsp_fnc_gesture_sanitize=='' || 'tactical' in gestureState playa) && (currentWeapon playa != '' && (currentWeapon playa==primaryWeapon playa || currentWeapon playa==handgunWeapon playa))";
					exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"};
					statement = "[playa] call tsp_fnc_animate_effect; [playa] spawn tsp_fnc_animate_inspect";
				};
				class tsp_animate_suicide {
					displayName = "Suicide"; icon = "tsp_animate\gui\suicide.paa";
					condition = "tsp_cba_animate_suicide && vehicle playa==playa && stance playa != 'PRONE' && !('freefall' in animationState playa) && ([gestureState playa] call tsp_fnc_gesture_sanitize=='' || 'tactical' in gestureState playa) && (currentWeapon playa != '' && (currentWeapon playa==primaryWeapon playa || currentWeapon playa==handgunWeapon playa))";
					exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"};
					statement = "[playa] call tsp_fnc_animate_effect; [playa] spawn tsp_fnc_animate_suicide";
				};
			};
		};
        class ACE_Actions {
			class ACE_TapShoulderRight {
                displayName = "Tap Shoulder"; selection = "rightshoulder"; distance = 2; condition = "[_player, _target] call ace_interaction_fnc_canTapShoulder"; 
                statement = "if (tsp_cba_animate_tap) exitWith {[_player,objNull,0,'shoulder'] spawn tsp_fnc_animate_tap}; [_player, _target, 1] call ace_interaction_fnc_tapShoulder";
            };
            class ACE_TapShoulderLeft: ACE_TapShoulderRight {
                selection = "leftshoulder"; 
                statement = "if (tsp_cba_animate_tap) exitWith {[_player,objNull,1,'shoulder'] spawn tsp_fnc_animate_tap}; [_player, _target, 1] call ace_interaction_fnc_tapShoulder";
            };
			class ACE_SqueezeLegRight: ACE_TapShoulderRight {
                displayName = "Squeeze Leg"; selection = "rightupleg"; 
                condition = "[_player, _target] call ace_interaction_fnc_canTapShoulder && tsp_cba_animate_tap"; 
                statement = "[_player,objNull,0,'leg'] spawn tsp_fnc_animate_tap";
            };
            class ACE_SqueezeLegLeft: ACE_SqueezeLegRight {
                displayName = "Squeeze Leg"; selection = "leftupleg"; 
                statement = "[_player,objNull,1,'leg'] spawn tsp_fnc_animate_tap";
            };
            class ACE_MainActions {
                class ACE_EscortCaptive {
                    displayName = "Escort Captive"; icon = "\z\ace\addons\captives\UI\captive_ca.paa"; distance = 4;
                    condition = "[_player,_target] call ace_captives_fnc_canEscortCaptive"; exceptions[] = {"isNotSwimming"};
                    statement = "[_player,_target,true] call ace_captives_fnc_doEscortCaptive; if (tsp_cba_animate_captive) then {[_player,_target] spawn tsp_fnc_animate_captive}";
                    showDisabled = 0;
                };
			};
		};
	};
};

//-- ANIMATIONS
class CfgMovesBasic {
    class default;
    class DefaultDie;
	class Actions;
    class ManActions {
		tsp_animate_clacker[] = {"tsp_animate_clacker", "Gesture"};
		tsp_animate_shock_out_wnon[] = {"tsp_animate_shock_out_wnon", "Gesture"};
		tsp_animate_shock_loop_wnon[] = {"tsp_animate_shock_loop_wnon", "Gesture"};
		tsp_animate_shock_out_wrfl[] = {"tsp_animate_shock_out_wrfl", "Gesture"};
		tsp_animate_shock_loop_wrfl[] = {"tsp_animate_shock_loop_wrfl", "Gesture"};

		tsp_animate_captive[] = {"tsp_animate_captive", "Gesture"};
		tsp_animate_captor_wnon[] = {"tsp_animate_captor_wnon", "Gesture"};
		tsp_animate_captor_wrfl[] = {"tsp_animate_captor_wrfl", "Gesture"};
		tsp_animate_captor_wpst[] = {"tsp_animate_captor_wpst", "Gesture"};
		tsp_animate_lift[] = {"tsp_animate_lift", "Gesture"};

		tsp_animate_grenade_left_wnon_lnon_loop[] = {"tsp_animate_grenade_left_wnon_lnon_loop", "Gesture"};
		tsp_animate_grenade_left_wnon_lnon_normal[] = {"tsp_animate_grenade_left_wnon_lnon_normal", "Gesture"};
		tsp_animate_grenade_left_wnon_lnon_high[] = {"tsp_animate_grenade_left_wnon_lnon_high", "Gesture"};
		tsp_animate_grenade_left_wrfl_lnon_loop[] = {"tsp_animate_grenade_left_wrfl_lnon_loop", "Gesture"};
		tsp_animate_grenade_left_wrfl_lnon_normal[] = {"tsp_animate_grenade_left_wrfl_lnon_normal", "Gesture"};
		tsp_animate_grenade_left_wrfl_lnon_high[] = {"tsp_animate_grenade_left_wrfl_lnon_high", "Gesture"};
		tsp_animate_grenade_left_wrfl_lhig_loop[] = {"tsp_animate_grenade_left_wrfl_lhig_loop", "Gesture"};
		tsp_animate_grenade_left_wrfl_lhig_normal[] = {"tsp_animate_grenade_left_wrfl_lhig_normal", "Gesture"};
		tsp_animate_grenade_left_wrfl_lhig_high[] = {"tsp_animate_grenade_left_wrfl_lhig_high", "Gesture"};
		tsp_animate_grenade_left_wrfl_llow_loop[] = {"tsp_animate_grenade_left_wrfl_llow_loop", "Gesture"};
		tsp_animate_grenade_left_wrfl_llow_normal[] = {"tsp_animate_grenade_left_wrfl_llow_normal", "Gesture"};
		tsp_animate_grenade_left_wrfl_llow_high[] = {"tsp_animate_grenade_left_wrfl_llow_high", "Gesture"};
		
		tsp_animate_grenade_left_wpst_lnon_loop[] = {"tsp_animate_grenade_left_wpst_lnon_loop", "Gesture"};
		tsp_animate_grenade_left_wpst_lnon_normal[] = {"tsp_animate_grenade_left_wpst_lnon_normal", "Gesture"};
		tsp_animate_grenade_left_wpst_lnon_high[] = {"tsp_animate_grenade_left_wpst_lnon_high", "Gesture"};
		tsp_animate_grenade_left_wpst_lhig_loop[] = {"tsp_animate_grenade_left_wpst_lhig_loop", "Gesture"};
		tsp_animate_grenade_left_wpst_lhig_normal[] = {"tsp_animate_grenade_left_wpst_lhig_normal", "Gesture"};
		tsp_animate_grenade_left_wpst_lhig_high[] = {"tsp_animate_grenade_left_wpst_lhig_high", "Gesture"};
		tsp_animate_grenade_left_wpst_llow_loop[] = {"tsp_animate_grenade_left_wpst_llow_loop", "Gesture"};
		tsp_animate_grenade_left_wpst_llow_normal[] = {"tsp_animate_grenade_left_wpst_llow_normal", "Gesture"};
		tsp_animate_grenade_left_wpst_llow_high[] = {"tsp_animate_grenade_left_wpst_llow_high", "Gesture"};
		
		tsp_animate_grenade_right_wnon_lnon_loop[] = {"tsp_animate_grenade_right_wnon_lnon_loop", "Gesture"};
		tsp_animate_grenade_right_wnon_lnon_normal[] = {"tsp_animate_grenade_right_wnon_lnon_normal", "Gesture"};
		tsp_animate_grenade_right_wnon_lnon_high[] = {"tsp_animate_grenade_right_wnon_lnon_high", "Gesture"};
		tsp_animate_grenade_right_wrfl_lnon_loop[] = {"tsp_animate_grenade_right_wrfl_lnon_loop", "Gesture"};
		tsp_animate_grenade_right_wrfl_lnon_normal[] = {"tsp_animate_grenade_right_wrfl_lnon_normal", "Gesture"};
		tsp_animate_grenade_right_wrfl_lnon_high[] = {"tsp_animate_grenade_right_wrfl_lnon_high", "Gesture"};
		tsp_animate_grenade_right_wrfl_llow_loop[] = {"tsp_animate_grenade_right_wrfl_llow_loop", "Gesture"};
		tsp_animate_grenade_right_wrfl_llow_normal[] = {"tsp_animate_grenade_right_wrfl_llow_normal", "Gesture"};
		tsp_animate_grenade_right_wrfl_llow_high[] = {"tsp_animate_grenade_right_wrfl_llow_high", "Gesture"};
		
		tsp_animate_grenade_right_wpst_lnon_loop[] = {"tsp_animate_grenade_right_wpst_lnon_loop", "Gesture"};
		tsp_animate_grenade_right_wpst_lnon_normal[] = {"tsp_animate_grenade_right_wpst_lnon_normal", "Gesture"};
		tsp_animate_grenade_right_wpst_lnon_high[] = {"tsp_animate_grenade_right_wpst_lnon_high", "Gesture"};
		tsp_animate_grenade_right_wpst_llow_loop[] = {"tsp_animate_grenade_right_wpst_llow_loop", "Gesture"};
		tsp_animate_grenade_right_wpst_llow_normal[] = {"tsp_animate_grenade_right_wpst_llow_normal", "Gesture"};
		tsp_animate_grenade_right_wpst_llow_high[] = {"tsp_animate_grenade_right_wpst_llow_high", "Gesture"};

		tsp_animate_grenade_compress_wrfl_lhig_loop[] = {"tsp_animate_grenade_compress_wrfl_lhig_loop", "Gesture"};
		tsp_animate_grenade_compress_wrfl_lhig_normal[] = {"tsp_animate_grenade_compress_wrfl_lhig_normal", "Gesture"};
		tsp_animate_grenade_compress_wrfl_lhig_high[] = {"tsp_animate_grenade_compress_wrfl_lhig_high", "Gesture"};
		tsp_animate_grenade_compress_wrfl_llow_loop[] = {"tsp_animate_grenade_compress_wrfl_llow_loop", "Gesture"};
		tsp_animate_grenade_compress_wrfl_llow_normal[] = {"tsp_animate_grenade_compress_wrfl_llow_normal", "Gesture"};
		tsp_animate_grenade_compress_wrfl_llow_high[] = {"tsp_animate_grenade_compress_wrfl_llow_high", "Gesture"};

		tsp_animate_grenade_compress_wpst_lhig_loop[] = {"tsp_animate_grenade_compress_wpst_lhig_loop", "Gesture"};
		tsp_animate_grenade_compress_wpst_lhig_normal[] = {"tsp_animate_grenade_compress_wpst_lhig_normal", "Gesture"};
		tsp_animate_grenade_compress_wpst_lhig_high[] = {"tsp_animate_grenade_compress_wpst_lhig_high", "Gesture"};
		tsp_animate_grenade_compress_wpst_llow_loop[] = {"tsp_animate_grenade_compress_wpst_llow_loop", "Gesture"};
		tsp_animate_grenade_compress_wpst_llow_normal[] = {"tsp_animate_grenade_compress_wpst_llow_normal", "Gesture"};
		tsp_animate_grenade_compress_wpst_llow_high[] = {"tsp_animate_grenade_compress_wpst_llow_high", "Gesture"};
	};
};
class CfgGesturesMale {
	skeletonName = "OFP2_ManSkeleton";
	class Default {};
	class States {
		class tsp_animate_breach;

		//-- Clackers
		class tsp_animate_clacker: tsp_animate_breach {leftHandIKCurve[] = {0}; file = "tsp_animate_ace\gestures\clacker.rtm"; speed = 2; enableOptics = 0;};
		class tsp_animate_shock_out_wnon: tsp_animate_clacker {speed = 0.7; mask = "bothArms"; file = "tsp_animate_ace\gestures\shock.rtm";};
		class tsp_animate_shock_loop_wnon: tsp_animate_shock_out_wnon {file = "tsp_animate_ace\gestures\shock_loop.rtm"; looped = true;};
		class tsp_animate_shock_out_wrfl: tsp_animate_clacker {mask = "handsWeapon"; speed = 0.7; rightHandIKCurve[] = {0}; file = "tsp_animate_ace\gestures\shock.rtm";};
		class tsp_animate_shock_loop_wrfl: tsp_animate_shock_out_wrfl {file = "tsp_animate_ace\gestures\shock_loop.rtm"; looped = true;};

		//-- Captive
		class tsp_animate_captive: tsp_animate_breach {mask = "HandsWeapon"; leftHandIKCurve[] = {0}; rightHandIKCurve[] = {0}; looped = true; file = "tsp_animate_ace\gestures\captive.rtm";};
		class tsp_animate_captor_wnon: tsp_animate_captive {mask = "leftArm"; file = "tsp_animate_ace\gestures\captor.rtm";};
		class tsp_animate_captor_wrfl: tsp_animate_captor_wnon {mask = "HandsWeapon"; rightHandIKCurve[] = {1};};
		class tsp_animate_captor_wpst: tsp_animate_captor_wnon {mask = "HandsWeapon";};

		class tsp_animate_lift: tsp_animate_captive {mask = "bothArmsSpine"; file = "tsp_animate_ace\gestures\carry.rtm";};

		//-- Grenades
		class tsp_animate_grenade_left_wnon_lnon_loop: tsp_animate_breach {mask = "leftHand"; leftHandIKCurve[] = {0}; looped = true; speed = 2; enableOptics = 0; file = "tsp_animate_ace\grenade\compress_loop_lhig.rtm";};
		class tsp_animate_grenade_left_wnon_lnon_normal: tsp_animate_grenade_left_wnon_lnon_loop {looped = false; file = "tsp_animate_ace\grenade\compress_normal_lhig.rtm";};
		class tsp_animate_grenade_left_wnon_lnon_high: tsp_animate_grenade_left_wnon_lnon_normal {file = "tsp_animate_ace\grenade\compress_high_lhig.rtm";};

		class tsp_animate_grenade_left_wrfl_lnon_loop: tsp_animate_grenade_left_wnon_lnon_loop {mask = "handsWeapon"; file = "tsp_animate_ace\grenade\compress_loop_lhig.rtm";};
		class tsp_animate_grenade_left_wrfl_lnon_normal: tsp_animate_grenade_left_wrfl_lnon_loop {looped = false; file = "tsp_animate_ace\grenade\compress_normal_lhig.rtm";};
		class tsp_animate_grenade_left_wrfl_lnon_high: tsp_animate_grenade_left_wrfl_lnon_normal {file = "tsp_animate_ace\grenade\compress_high_lhig.rtm";};
		class tsp_animate_grenade_left_wrfl_lhig_loop: tsp_animate_grenade_left_wrfl_lnon_loop {file = "tsp_animate_ace\grenade\left_loop_lhig.rtm";};
		class tsp_animate_grenade_left_wrfl_lhig_normal: tsp_animate_grenade_left_wrfl_lhig_loop {looped = false; file = "tsp_animate_ace\grenade\left_normal_lhig.rtm";};
		class tsp_animate_grenade_left_wrfl_lhig_high: tsp_animate_grenade_left_wrfl_lhig_normal {file = "tsp_animate_ace\grenade\left_high_lhig.rtm";};
		class tsp_animate_grenade_left_wrfl_llow_loop: tsp_animate_grenade_left_wrfl_lhig_loop {file = "tsp_animate_ace\grenade\left_loop_llow.rtm";};
		class tsp_animate_grenade_left_wrfl_llow_normal: tsp_animate_grenade_left_wrfl_llow_loop {looped = false; file = "tsp_animate_ace\grenade\left_normal_llow.rtm";};
		class tsp_animate_grenade_left_wrfl_llow_high: tsp_animate_grenade_left_wrfl_llow_normal {file = "tsp_animate_ace\grenade\left_high_llow.rtm";};

		class tsp_animate_grenade_left_wpst_lnon_loop: tsp_animate_grenade_left_wnon_lnon_loop {mask = "bothArmsSpine"; file = "tsp_animate_ace\grenade\compress_loop_lhig.rtm";};
		class tsp_animate_grenade_left_wpst_lnon_normal: tsp_animate_grenade_left_wpst_lnon_loop {looped = false; file = "tsp_animate_ace\grenade\compress_normal_lhig.rtm";};
		class tsp_animate_grenade_left_wpst_lnon_high: tsp_animate_grenade_left_wpst_lnon_normal {file = "tsp_animate_ace\grenade\compress_high_lhig.rtm";};
		class tsp_animate_grenade_left_wpst_lhig_loop: tsp_animate_grenade_left_wpst_lnon_loop {file = "tsp_animate_ace\grenade\left_loop_lhig.rtm";};
		class tsp_animate_grenade_left_wpst_lhig_normal: tsp_animate_grenade_left_wpst_lhig_loop {looped = false; file = "tsp_animate_ace\grenade\left_normal_lhig.rtm";};
		class tsp_animate_grenade_left_wpst_lhig_high: tsp_animate_grenade_left_wpst_lhig_normal {file = "tsp_animate_ace\grenade\left_high_lhig.rtm";};
		class tsp_animate_grenade_left_wpst_llow_loop: tsp_animate_grenade_left_wpst_lhig_loop {file = "tsp_animate_ace\grenade\left_loop_llow.rtm";};
		class tsp_animate_grenade_left_wpst_llow_normal: tsp_animate_grenade_left_wpst_llow_loop {looped = false; file = "tsp_animate_ace\grenade\left_normal_llow.rtm";};
		class tsp_animate_grenade_left_wpst_llow_high: tsp_animate_grenade_left_wpst_llow_normal {file = "tsp_animate_ace\grenade\left_high_llow.rtm";};

		class tsp_animate_grenade_right_wnon_lnon_loop: tsp_animate_grenade_left_wrfl_lhig_loop {mask = "bothArmsSpine"; rightHandIKCurve[] = {0}; file = "tsp_animate_ace\grenade\right_loop_llow.rtm";};
		class tsp_animate_grenade_right_wnon_lnon_normal: tsp_animate_grenade_right_wnon_lnon_loop {looped = false; file = "tsp_animate_ace\grenade\right_normal_llow.rtm";};
		class tsp_animate_grenade_right_wnon_lnon_high: tsp_animate_grenade_right_wnon_lnon_normal {file = "tsp_animate_ace\grenade\right_high_llow.rtm";};

		class tsp_animate_grenade_right_wrfl_lnon_loop: tsp_animate_grenade_right_wnon_lnon_loop {mask = "handsWeapon"; file = "tsp_animate_ace\grenade\right_loop_llow.rtm";};
		class tsp_animate_grenade_right_wrfl_lnon_normal: tsp_animate_grenade_right_wrfl_lnon_loop {looped = false; file = "tsp_animate_ace\grenade\right_normal_llow.rtm";};
		class tsp_animate_grenade_right_wrfl_lnon_high: tsp_animate_grenade_right_wrfl_lnon_normal {file = "tsp_animate_ace\grenade\right_high_llow.rtm";};
		class tsp_animate_grenade_right_wrfl_llow_loop: tsp_animate_grenade_right_wrfl_lnon_loop {file = "tsp_animate_ace\grenade\right_loop_llow.rtm";};
		class tsp_animate_grenade_right_wrfl_llow_normal: tsp_animate_grenade_right_wrfl_llow_loop {looped = false; file = "tsp_animate_ace\grenade\right_normal_llow.rtm";};
		class tsp_animate_grenade_right_wrfl_llow_high: tsp_animate_grenade_right_wrfl_llow_normal {file = "tsp_animate_ace\grenade\right_high_llow.rtm";};

		class tsp_animate_grenade_right_wpst_lnon_loop: tsp_animate_grenade_right_wnon_lnon_loop {mask = "bothArmsSpine"; file = "tsp_animate_ace\grenade\right_loop_llow.rtm";};
		class tsp_animate_grenade_right_wpst_lnon_normal: tsp_animate_grenade_right_wpst_lnon_loop {looped = false; file = "tsp_animate_ace\grenade\right_normal_llow.rtm";};
		class tsp_animate_grenade_right_wpst_lnon_high: tsp_animate_grenade_right_wpst_lnon_normal {file = "tsp_animate_ace\grenade\right_high_llow.rtm";};
		class tsp_animate_grenade_right_wpst_llow_loop: tsp_animate_grenade_right_wpst_lnon_loop {file = "tsp_animate_ace\grenade\right_loop_llow.rtm";};
		class tsp_animate_grenade_right_wpst_llow_normal: tsp_animate_grenade_right_wpst_llow_loop {looped = false; file = "tsp_animate_ace\grenade\right_normal_llow.rtm";};
		class tsp_animate_grenade_right_wpst_llow_high: tsp_animate_grenade_right_wpst_llow_normal {file = "tsp_animate_ace\grenade\right_high_llow.rtm";};

		class tsp_animate_grenade_compress_wrfl_lhig_loop: tsp_animate_grenade_left_wrfl_lhig_loop {mask = "handsWeapon"; file = "tsp_animate_ace\grenade\compress_loop_lhig.rtm";};
		class tsp_animate_grenade_compress_wrfl_lhig_normal: tsp_animate_grenade_compress_wrfl_lhig_loop {looped = false; file = "tsp_animate_ace\grenade\compress_normal_lhig.rtm";};
		class tsp_animate_grenade_compress_wrfl_lhig_high: tsp_animate_grenade_compress_wrfl_lhig_normal {file = "tsp_animate_ace\grenade\compress_high_lhig.rtm";};
		class tsp_animate_grenade_compress_wrfl_llow_loop: tsp_animate_grenade_left_wrfl_lhig_loop {file = "tsp_animate_ace\grenade\compress_loop_llow.rtm";};
		class tsp_animate_grenade_compress_wrfl_llow_normal: tsp_animate_grenade_compress_wrfl_llow_loop {looped = false; file = "tsp_animate_ace\grenade\compress_normal_llow.rtm";};
		class tsp_animate_grenade_compress_wrfl_llow_high: tsp_animate_grenade_compress_wrfl_llow_normal {file = "tsp_animate_ace\grenade\compress_high_llow.rtm";};

		class tsp_animate_grenade_compress_wpst_lhig_loop: tsp_animate_grenade_left_wpst_lhig_loop {mask = "bothArmsSpine"; file = "tsp_animate_ace\grenade\compress_loop_lhig.rtm";};
		class tsp_animate_grenade_compress_wpst_lhig_normal: tsp_animate_grenade_compress_wpst_lhig_loop {looped = false; file = "tsp_animate_ace\grenade\compress_normal_lhig.rtm";};
		class tsp_animate_grenade_compress_wpst_lhig_high: tsp_animate_grenade_compress_wpst_lhig_normal {file = "tsp_animate_ace\grenade\compress_high_lhig.rtm";};
		class tsp_animate_grenade_compress_wpst_llow_loop: tsp_animate_grenade_left_wpst_lhig_loop {file = "tsp_animate_ace\grenade\compress_loop_llow.rtm";};
		class tsp_animate_grenade_compress_wpst_llow_normal: tsp_animate_grenade_compress_wpst_llow_loop {looped = false; file = "tsp_animate_ace\grenade\compress_normal_llow.rtm";};
		class tsp_animate_grenade_compress_wpst_llow_high: tsp_animate_grenade_compress_wpst_llow_normal {file = "tsp_animate_ace\grenade\compress_high_llow.rtm";};
	};
};