class CfgPatches {
	class tsp_animate {
		requiredAddons[] = {"tsp_core", "cba_common", "A3_Anims_F"};
		units[] = {};
	};
};

//-- FUNCTIONS
class Extended_PreInit_EventHandlers {class tsp_animate_cba {init = "[] call compileScript ['\tsp_animate\cba.sqf']";}; class tsp_animate_functions {init = "[] call compileScript ['\tsp_animate\functions.sqf']";};};
class Extended_PostInit_EventHandlers {class tsp_animate_init {init = "['CBA_settingsInitialized', {[] spawn compileScript ['\tsp_animate\init.sqf']}] call CBA_fnc_addEventHandler;";};};  

//-- ITEMS
class CfgWeapons {
	class CBA_MiscItem;
	class CBA_MiscItem_ItemInfo;
	class tsp_sling: CBA_MiscItem {
		scope = 2; displayName = "2-Point Sling"; picture = "\tsp_animate\gui\sling.paa"; model = "tsp_animate\sling.p3d"; 
		sling[] = {"Spine3", {-0.83,0.58,0.51}, {80,50,-180}, "tsp_animate_sling_sling", ""}; class ItemInfo: CBA_MiscItem_ItemInfo {mass = 0.1;};
	};
	class tsp_sling_3point: tsp_sling {displayName = "3-Point Sling"; picture = "\tsp_animate\gui\3point.paa"; sling[] = {"Spine3", {0.7,0.15,-0.8}, {80,130,-20}, "tsp_animate_sling_3point", ""};};
	class tsp_sling_1point: tsp_sling {displayName = "1-Point Sling"; picture = "\tsp_animate\gui\1point.paa"; sling[] = {"Spine3", {-0.8,0.9,0}, {10,75,-90}, "tsp_animate_sling_sling", ""};};
	class tsp_sling_lanyard: tsp_sling {displayName = "Lanyard"; picture = "\tsp_animate\gui\lanyard.paa"; sling[] = {"Pelvis", {0.72,0.85,-0.2}, {-90,80,90}, "tsp_animate_sling_lanyard", ""};};
};

//-- ACE Actions - has to be here in main tsp_animate.pbo for stuff at bottom of cba.sqf
class CfgVehicles {
	class Man;
	class CAManBase: Man {
		class ACE_SelfActions {
			class tsp_animate_drop {
				displayName = "Drop"; icon = "tsp_animate\gui\drop.paa"; 
				condition = "tsp_cba_animate_drop_ace"; 
				exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"};
			};
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
					condition = "tsp_cba_animate_inspect && (vehicle playa==playa || '_aim' in animationState playa) && stance playa != 'PRONE' && !('freefall' in animationState playa) && ([gestureState playa] call tsp_fnc_gesture_sanitize=='' || 'tactical' in gestureState playa) && (currentWeapon playa != '' && (currentWeapon playa==primaryWeapon playa || currentWeapon playa==handgunWeapon playa))";
					exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"};
					statement = "[playa] call tsp_fnc_animate_effect; [playa] spawn tsp_fnc_animate_inspect";
				};
				class tsp_animate_suicide {
					displayName = "Suicide"; icon = "tsp_animate\gui\suicide.paa";
					condition = "tsp_cba_animate_suicide && (vehicle playa==playa || '_aim' in animationState playa) && !('freefall' in animationState playa) && ([gestureState playa] call tsp_fnc_gesture_sanitize=='' || 'tactical' in gestureState playa) && (currentWeapon playa != '' && (currentWeapon playa==primaryWeapon playa || currentWeapon playa==handgunWeapon playa))";
					exceptions[] = {"isNotInside","isNotSitting","isNotSwimming","isNotEscorting"};
					statement = "[playa] call tsp_fnc_animate_effect; [playa] spawn tsp_fnc_animate_suicide";
				};
			};
		};
	};
};

//-- ANIMATIONS
class CfgMovesBasic {
    class default;
    class DefaultDie;
	class Actions {
		class LadderRifleActions;
		class ladderPistolActions: LadderRifleActions {
			up = "ladderPistolUpLoop";
			down = "ladderPistolDownLoop";
			ladderOff = "AmovPercMstpSrasWpstDnon";
			ladderOffBottom = "ladderPistolDownOff";
			ladderOffTop = "ladderPistolTopOff";
			ladderOnDown = "ladderPistolOn";
			ladderOnUp = "ladderPistolOn";
			default = "ladderPistolStatic";
			stop = "ladderPistolStatic";			
		};
	};
    class ManActions {
		tsp_animate_breach[] = {"tsp_animate_breach", "Gesture"};
		tsp_animate_bang[] = {"tsp_animate_bang", "Gesture"};
		tsp_animate_knock[] = {"tsp_animate_knock", "Gesture"};

		tsp_animate_horns_loop[] = {"tsp_animate_horns_loop", "Gesture"};
		tsp_animate_peace_loop[] = {"tsp_animate_peace_loop", "Gesture"};
		tsp_animate_bird_in[] = {"tsp_animate_bird_in", "Gesture"};
		tsp_animate_bird_loop[] = {"tsp_animate_bird_loop", "Gesture"};
		tsp_animate_ok_in[] = {"tsp_animate_ok_in", "Gesture"};
		tsp_animate_ok_loop[] = {"tsp_animate_ok_loop", "Gesture"};
		tsp_animate_thumbsup_loop[] = {"tsp_animate_thumbsup_loop", "Gesture"};
		tsp_animate_thumbsdown_loop[] = {"tsp_animate_thumbsdown_loop", "Gesture"};
		tsp_animate_jackoff_loop[] = {"tsp_animate_jackoff_loop", "Gesture"};
		tsp_animate_jackoff_out[] = {"tsp_animate_jackoff_out", "Gesture"};
		tsp_animate_mahalo_loop[] = {"tsp_animate_mahalo_loop", "Gesture"};
		tsp_animate_loser_loop[] = {"tsp_animate_loser_loop", "Gesture"};
		tsp_animate_dab_loop[] = {"tsp_animate_dab_loop", "Gesture"};
		tsp_animate_heart_loop[] = {"tsp_animate_heart_loop", "Gesture"};
		tsp_animate_rockpaperscissors_in[] = {"tsp_animate_rockpaperscissors_in", "Gesture"};
		tsp_animate_rockpaperscissors_rock_loop[] = {"tsp_animate_rockpaperscissors_rock_loop", "Gesture"};
		tsp_animate_rockpaperscissors_paper_loop[] = {"tsp_animate_rockpaperscissors_paper_loop", "Gesture"};
		tsp_animate_rockpaperscissors_scissors_loop[] = {"tsp_animate_rockpaperscissors_scissors_loop", "Gesture"};

		tsp_animate_map_in[] = {"tsp_animate_map_in", "Gesture"};
		tsp_animate_map_loop[] = {"tsp_animate_map_loop", "Gesture"};
		tsp_animate_compass_in[] = {"tsp_animate_compass_in", "Gesture"};
		tsp_animate_compass_loop[] = {"tsp_animate_compass_loop", "Gesture"};
		tsp_animate_watch_in[] = {"tsp_animate_watch_in", "Gesture"};
		tsp_animate_watch_loop[] = {"tsp_animate_watch_loop", "Gesture"};

		tsp_animate_nightvision_up[] = {"tsp_animate_nightvision_up", "Gesture"};
		tsp_animate_nightvision_down[] = {"tsp_animate_nightvision_down", "Gesture"};

		tsp_animate_suicide_wpst_in[] = {"tsp_animate_suicide_wpst_in", "Gesture"};
		tsp_animate_suicide_wpst_loop[] = {"tsp_animate_suicide_wpst_loop", "Gesture"};
		tsp_animate_suicide_wrfl_in[] = {"tsp_animate_suicide_wrfl_in", "Gesture"};
		tsp_animate_suicide_wrfl_loop[] = {"tsp_animate_suicide_wrfl_loop", "Gesture"};

		tsp_animate_inspect_wrfl[] = {"tsp_animate_inspect_wrfl", "Gesture"};
		tsp_animate_inspect_wpst[] = {"tsp_animate_inspect_wpst", "Gesture"};
		
		tsp_animate_throw_wrfl[] = {"tsp_animate_throw_wrfl", "Gesture"};
		tsp_animate_throw_wrfl_wind[] = {"tsp_animate_throw_wrfl_wind", "Gesture"};
		tsp_animate_throw_wrfl_wound[] = {"tsp_animate_throw_wrfl_wound", "Gesture"};
		tsp_animate_throw_wrfl_out[] = {"tsp_animate_throw_wrfl_out", "Gesture"};
		tsp_animate_throw_wpst[] = {"tsp_animate_throw_wpst", "Gesture"};
		tsp_animate_throw_wpst_wind[] = {"tsp_animate_throw_wpst_wind", "Gesture"};
		tsp_animate_throw_wpst_wound[] = {"tsp_animate_throw_wpst_wound", "Gesture"};
		tsp_animate_throw_wpst_out[] = {"tsp_animate_throw_wpst_out", "Gesture"};

		//-- None
		tsp_animate_shoulder_wnon_lnon[] = {"tsp_animate_shoulder_wnon_lnon", "Gesture"};
		tsp_animate_leg_wnon_lnon[] = {"tsp_animate_leg_wnon_lnon", "Gesture"};
		tsp_animate_door_wnon_lnon[] = {"tsp_animate_door_wnon_lnon", "Gesture"};
		tsp_animate_doorace_wnon_lnon[] = {"tsp_animate_doorace_wnon_lnon", "Gesture"};
		tsp_animate_chemlight_wnon_lnon[] = {"tsp_animate_chemlight_wnon_lnon", "Gesture"};

		//-- Rifle
		tsp_animate_tactical_cant_wrfl_lnon[] = {"tsp_animate_tactical_cant_wrfl_lnon", "Gesture"};
		tsp_animate_tactical_over_wrfl_lnon[] = {"tsp_animate_tactical_over_wrfl_lnon", "Gesture"};
		tsp_animate_tactical_readybase_wrfl_lhig[] = {"tsp_animate_tactical_readybase_wrfl_lhig", "Gesture"};
		tsp_animate_tactical_readybase_wrfl_llow[] = {"tsp_animate_tactical_readybase_wrfl_llow", "Gesture"};
		tsp_animate_tactical_readycombat_wrfl_lhig[] = {"tsp_animate_tactical_readycombat_wrfl_lhig", "Gesture"};
		tsp_animate_tactical_readycombat_wrfl_llow[] = {"tsp_animate_tactical_readycombat_wrfl_llow", "Gesture"};
		tsp_animate_tactical_readyalt_wrfl_lhig[] = {"tsp_animate_tactical_readyalt_wrfl_lhig", "Gesture"};
		tsp_animate_tactical_readyalt_wrfl_llow[] = {"tsp_animate_tactical_readyalt_wrfl_llow", "Gesture"};
		tsp_animate_tactical_friend_wrfl_lhig[] = {"tsp_animate_tactical_friend_wrfl_lhig", "Gesture"};
		tsp_animate_tactical_friend_wrfl_llow[] = {"tsp_animate_tactical_friend_wrfl_llow", "Gesture"};
		tsp_animate_tactical_object_wrfl_lhig[] = {"tsp_animate_tactical_object_wrfl_lhig", "Gesture"};
		tsp_animate_tactical_object_wrfl_llow[] = {"tsp_animate_tactical_object_wrfl_llow", "Gesture"};
		tsp_animate_tactical_compress_wrfl_lhig[] = {"tsp_animate_tactical_compress_wrfl_lhig", "Gesture"};
		tsp_animate_tactical_compress_wrfl_llow[] = {"tsp_animate_tactical_compress_wrfl_llow", "Gesture"};
		tsp_animate_shoulder_wrfl_lnon[] = {"tsp_animate_shoulder_wrfl_lnon", "Gesture"};
		tsp_animate_shoulder_wrfl_lhig[] = {"tsp_animate_shoulder_wrfl_lhig", "Gesture"};
		tsp_animate_shoulder_wrfl_llow[] = {"tsp_animate_shoulder_wrfl_llow", "Gesture"};
		tsp_animate_leg_wrfl_lnon[] = {"tsp_animate_leg_wrfl_lnon", "Gesture"};
		tsp_animate_leg_wrfl_lhig[] = {"tsp_animate_leg_wrfl_lhig", "Gesture"};
		tsp_animate_leg_wrfl_llow[] = {"tsp_animate_leg_wrfl_llow", "Gesture"};
		tsp_animate_tactical_portbase_wrfl_lhig[] = {"tsp_animate_tactical_portbase_wrfl_lhig", "Gesture"};
		tsp_animate_tactical_portbase_wrfl_llow[] = {"tsp_animate_tactical_portbase_wrfl_llow", "Gesture"};
		tsp_animate_tactical_portmove_wrfl_lhig[] = {"tsp_animate_tactical_portmove_wrfl_lhig", "Gesture"};
		tsp_animate_tactical_portmove_wrfl_llow[] = {"tsp_animate_tactical_portmove_wrfl_llow", "Gesture"};
		tsp_animate_tactical_portchill_wrfl_lhig[] = {"tsp_animate_tactical_portchill_wrfl_lhig", "Gesture"};
		tsp_animate_tactical_portchill_wrfl_llow[] = {"tsp_animate_tactical_portchill_wrfl_llow", "Gesture"};
		tsp_animate_tactical_sprint_wrfl_lhig_in[] = {"tsp_animate_tactical_sprint_wrfl_lhig_in", "Gesture"};
		tsp_animate_tactical_sprint_wrfl_lhig_out[] = {"tsp_animate_tactical_sprint_wrfl_lhig_out", "Gesture"};
		tsp_animate_tactical_sprint_wrfl_lhig[] = {"tsp_animate_tactical_sprint_wrfl_lhig", "Gesture"};
		tsp_animate_tactical_sprint_wrfl_llow_in[] = {"tsp_animate_tactical_sprint_wrfl_llow_in", "Gesture"};
		tsp_animate_tactical_sprint_wrfl_llow_out[] = {"tsp_animate_tactical_sprint_wrfl_llow_out", "Gesture"};
		tsp_animate_tactical_sprint_wrfl_llow[] = {"tsp_animate_tactical_sprint_wrfl_llow", "Gesture"};
		tsp_animate_door_wrfl_lnon[] = {"tsp_animate_door_wrfl_lnon", "Gesture"};
		tsp_animate_door_wrfl_lhig[] = {"tsp_animate_door_wrfl_lhig", "Gesture"};
		tsp_animate_door_wrfl_llow[] = {"tsp_animate_door_wrfl_llow", "Gesture"};
		tsp_animate_doorcompress_wrfl_lnon[] = {"tsp_animate_doorcompress_wrfl_lnon", "Gesture"};
		tsp_animate_doorcompress_wrfl_lhig[] = {"tsp_animate_doorcompress_wrfl_lhig", "Gesture"};
		tsp_animate_doorcompress_wrfl_llow[] = {"tsp_animate_doorcompress_wrfl_llow", "Gesture"};
		tsp_animate_doorace_wrfl_lnon[] = {"tsp_animate_doorace_wrfl_lnon", "Gesture"};
		tsp_animate_doorace_wrfl_lhig[] = {"tsp_animate_doorace_wrfl_lhig", "Gesture"};
		tsp_animate_doorace_wrfl_llow[] = {"tsp_animate_doorace_wrfl_llow", "Gesture"};
		tsp_animate_chemlight_wrfl_lnon[] = {"tsp_animate_chemlight_wrfl_lnon", "Gesture"};
		tsp_animate_chemlight_wrfl_lhig[] = {"tsp_animate_chemlight_wrfl_lhig", "Gesture"};
		tsp_animate_chemlight_wrfl_llow[] = {"tsp_animate_chemlight_wrfl_llow", "Gesture"};

		//-- Pistol
		tsp_animate_tactical_cant_wpst_lnon[] = {"tsp_animate_tactical_cant_wpst_lnon", "Gesture"};
		tsp_animate_tactical_readybase_wpst_lhig[] = {"tsp_animate_tactical_readybase_wpst_lhig", "Gesture"};
		tsp_animate_tactical_readybase_wpst_llow[] = {"tsp_animate_tactical_readybase_wpst_llow", "Gesture"};
		tsp_animate_tactical_readycombat_wpst_lhig[] = {"tsp_animate_tactical_readycombat_wpst_lhig", "Gesture"};
		tsp_animate_tactical_readycombat_wpst_llow[] = {"tsp_animate_tactical_readycombat_wpst_llow", "Gesture"};
		tsp_animate_tactical_readyalt_wpst_lhig[] = {"tsp_animate_tactical_readyalt_wpst_lhig", "Gesture"};
		tsp_animate_tactical_readyalt_wpst_llow[] = {"tsp_animate_tactical_readyalt_wpst_llow", "Gesture"};
		tsp_animate_tactical_friend_wpst_lhig[] = {"tsp_animate_tactical_friend_wpst_lhig", "Gesture"};
		tsp_animate_tactical_friend_wpst_llow[] = {"tsp_animate_tactical_friend_wpst_llow", "Gesture"};
		tsp_animate_tactical_object_wpst_lhig[] = {"tsp_animate_tactical_object_wpst_lhig", "Gesture"};
		tsp_animate_tactical_object_wpst_llow[] = {"tsp_animate_tactical_object_wpst_llow", "Gesture"};
		tsp_animate_tactical_compress_wpst_lhig[] = {"tsp_animate_tactical_compress_wpst_lhig", "Gesture"};
		tsp_animate_tactical_compress_wpst_llow[] = {"tsp_animate_tactical_compress_wpst_llow", "Gesture"};
		tsp_animate_shoulder_wpst_lnon[] = {"tsp_animate_shoulder_wpst_lnon", "Gesture"};
		tsp_animate_shoulder_wpst_lhig[] = {"tsp_animate_shoulder_wpst_lhig", "Gesture"};
		tsp_animate_shoulder_wpst_llow[] = {"tsp_animate_shoulder_wpst_llow", "Gesture"};
		tsp_animate_leg_wpst_lnon[] = {"tsp_animate_leg_wpst_lnon", "Gesture"};
		tsp_animate_leg_wpst_lhig[] = {"tsp_animate_leg_wpst_lhig", "Gesture"};
		tsp_animate_leg_wpst_llow[] = {"tsp_animate_leg_wpst_llow", "Gesture"};
		tsp_animate_tactical_portbase_wpst_lhig[] = {"tsp_animate_tactical_portbase_wpst_lhig", "Gesture"};
		tsp_animate_tactical_portbase_wpst_llow[] = {"tsp_animate_tactical_portbase_wpst_llow", "Gesture"};
		tsp_animate_tactical_portmove_wpst_lhig[] = {"tsp_animate_tactical_portmove_wpst_lhig", "Gesture"};
		tsp_animate_tactical_portmove_wpst_llow[] = {"tsp_animate_tactical_portmove_wpst_llow", "Gesture"};
		tsp_animate_tactical_portchill_wpst_lhig[] = {"tsp_animate_tactical_portchill_wpst_lhig", "Gesture"};
		tsp_animate_tactical_portchill_wpst_llow[] = {"tsp_animate_tactical_portchill_wpst_llow", "Gesture"};
		tsp_animate_tactical_sprint_wpst_lhig_in[] = {"tsp_animate_tactical_sprint_wpst_lhig_in", "Gesture"};
		tsp_animate_tactical_sprint_wpst_lhig_out[] = {"tsp_animate_tactical_sprint_wpst_lhig_out", "Gesture"};
		tsp_animate_tactical_sprint_wpst_lhig[] = {"tsp_animate_tactical_sprint_wpst_lhig", "Gesture"};
		tsp_animate_tactical_sprint_wpst_llow_in[] = {"tsp_animate_tactical_sprint_wpst_llow_in", "Gesture"};
		tsp_animate_tactical_sprint_wpst_llow_out[] = {"tsp_animate_tactical_sprint_wpst_llow_out", "Gesture"};
		tsp_animate_tactical_sprint_wpst_llow[] = {"tsp_animate_tactical_sprint_wpst_llow", "Gesture"};
		tsp_animate_door_wpst_lnon[] = {"tsp_animate_door_wpst_lnon", "Gesture"};
		tsp_animate_door_wpst_lhig[] = {"tsp_animate_door_wpst_lhig", "Gesture"};
		tsp_animate_door_wpst_llow[] = {"tsp_animate_door_wpst_llow", "Gesture"};
		tsp_animate_doorcompress_wpst_lnon[] = {"tsp_animate_doorcompress_wpst_lnon", "Gesture"};
		tsp_animate_doorcompress_wpst_lhig[] = {"tsp_animate_doorcompress_wpst_lhig", "Gesture"};
		tsp_animate_doorcompress_wpst_llow[] = {"tsp_animate_doorcompress_wpst_llow", "Gesture"};
		tsp_animate_doorace_wpst_lnon[] = {"tsp_animate_doorace_wpst_lnon", "Gesture"};
		tsp_animate_doorace_wpst_lhig[] = {"tsp_animate_doorace_wpst_lhig", "Gesture"};
		tsp_animate_doorace_wpst_llow[] = {"tsp_animate_doorace_wpst_llow", "Gesture"};
		tsp_animate_chemlight_wpst_lnon[] = {"tsp_animate_chemlight_wpst_lnon", "Gesture"};
		tsp_animate_chemlight_wpst_lhig[] = {"tsp_animate_chemlight_wpst_lhig", "Gesture"};
		tsp_animate_chemlight_wpst_llow[] = {"tsp_animate_chemlight_wpst_llow", "Gesture"};

		//-- Weapon
		tsp_animate_sling_sling[] = {"tsp_animate_sling_sling", "Gesture"};
		tsp_animate_sling_3point[] = {"tsp_animate_sling_3point", "Gesture"};
		tsp_animate_sling_lanyard[] = {"tsp_animate_sling_lanyard", "Gesture"};
		tsp_animate_sling_unsling[] = {"tsp_animate_sling_unsling", "Gesture"};
		tsp_animate_sling_swap[] = {"tsp_animate_sling_swap", "Gesture"};
		tsp_animate_sling_check[] = {"tsp_animate_sling_check", "Gesture"};
		tsp_animate_sling_draw[] = {"tsp_animate_sling_draw", "Gesture"};
		tsp_animate_sling_draw_israeli[] = {"tsp_animate_sling_draw_israeli", "Gesture"};
		tsp_animate_sling_holster[] = {"tsp_animate_sling_holster", "Gesture"};
		tsp_animate_sling_sheath[] = {"tsp_animate_sling_sheath", "Gesture"};
		tsp_animate_sling_launch[] = {"tsp_animate_sling_launch", "Gesture"};
		tsp_animate_sling_unlaunch[] = {"tsp_animate_sling_unlaunch", "Gesture"};
		tsp_animate_sling_unbino[] = {"tsp_animate_sling_unbino", "Gesture"};

		//-- Attachment
		GestureMountMuzzlePistol[] = {"GestureMountMuzzlePistol", "Gesture"};
		GestureMountMuzzlePronePistol[] = {"GestureMountMuzzlePronePistol", "Gesture"};
		GestureDismountMuzzlePistol[] = {"GestureDismountMuzzlePistol", "Gesture"};
		GestureDismountMuzzlePronePistol[] = {"GestureDismountMuzzlePronePistol", "Gesture"};

		tsp_animate_ffv[] = {"tsp_animate_ffv", "Gesture"};
	};
};
class CfgGesturesMale {
	skeletonName = "OFP2_ManSkeleton";
	class Default {};
	class States {
		class GestureNo;
		class tsp_animate_breach: GestureNo {mask = "leftArm"; file = "tsp_animate\gestures\breach.rtm"; speed = 1; interpolationSpeed = 2; leftHandIKCurve[] = {0,1,0.1,0,0.9,0,1,1}; rightHandIKCurve[] = {1}; disableWeapons = false;};
		class tsp_animate_bang: tsp_animate_breach {file = "tsp_animate\gestures\bang.rtm"; speed = 0.6;};		
		class tsp_animate_knock: tsp_animate_bang {file = "tsp_animate\gestures\knock.rtm";};

		//-- Gestures
		class tsp_animate_horns_loop: tsp_animate_breach {file = "tsp_animate\emotes\horns_loop.rtm"; mask = "leftArm"; cancel = true; leftHandIKCurve[] = {0}; looped = true; disableWeapons = true;};
		class tsp_animate_peace_loop: tsp_animate_horns_loop {file = "tsp_animate\emotes\peace_loop.rtm";};		
		class tsp_animate_bird_in: tsp_animate_horns_loop {file = "tsp_animate\emotes\bird_in.rtm"; mask = "rightArm"; looped = false; leftHandIKCurve[] = {1}; rightHandIKCurve[] = {0};};
		class tsp_animate_bird_loop: tsp_animate_bird_in {looped = true; file = "tsp_animate\emotes\bird_loop.rtm";};
		class tsp_animate_ok_in: tsp_animate_bird_in {file = "tsp_animate\emotes\ok_in.rtm";};
		class tsp_animate_ok_loop: tsp_animate_bird_loop {file = "tsp_animate\emotes\ok_loop.rtm";};
		class tsp_animate_thumbsup_loop: tsp_animate_bird_loop {file = "tsp_animate\emotes\thumbsup_loop.rtm";};
		class tsp_animate_thumbsdown_loop: tsp_animate_bird_loop {file = "tsp_animate\emotes\thumbsdown_loop.rtm";};
		class tsp_animate_jackoff_loop: tsp_animate_bird_loop {file = "tsp_animate\emotes\jackoff_loop.rtm"; speed = 2;};
		class tsp_animate_jackoff_out: tsp_animate_bird_in {file = "tsp_animate\emotes\jackoff_out.rtm"; speed = 2;};
		class tsp_animate_mahalo_loop: tsp_animate_bird_loop {file = "tsp_animate\emotes\mahalo_loop.rtm";};
		class tsp_animate_loser_loop: tsp_animate_bird_loop {file = "tsp_animate\emotes\loser_loop.rtm";};
		class tsp_animate_dab_loop: tsp_animate_bird_loop {file = "tsp_animate\emotes\dab_loop.rtm"; mask = "bothArms"; rightHandIKCurve[] = {0}; leftHandIKCurve[] = {0};};
		class tsp_animate_heart_loop: tsp_animate_dab_loop {file = "tsp_animate\emotes\heart_loop.rtm";};
		class tsp_animate_rockpaperscissors_in: tsp_animate_dab_loop {file = "tsp_animate\emotes\rockpaperscissors_in.rtm";};
		class tsp_animate_rockpaperscissors_rock_loop: tsp_animate_dab_loop {file = "tsp_animate\emotes\rockpaperscissors_rock_loop.rtm";};
		class tsp_animate_rockpaperscissors_paper_loop: tsp_animate_rockpaperscissors_rock_loop {file = "tsp_animate\emotes\rockpaperscissors_paper_loop.rtm";};
		class tsp_animate_rockpaperscissors_scissors_loop: tsp_animate_rockpaperscissors_rock_loop {file = "tsp_animate\emotes\rockpaperscissors_scissors_loop.rtm";};
		
		//-- Items
		class tsp_animate_map_in: tsp_animate_breach {file = "tsp_animate\gestures\map_in.rtm"; speed = 2.5; leftHandIKCurve[] = {1}; mask = "leftArmHead"; enableOptics = 0;};
		class tsp_animate_map_loop: tsp_animate_map_in {file = "tsp_animate\gestures\map_loop.rtm"; looped = true; leftHandIKCurve[] = {0};};
		class tsp_animate_compass_in: tsp_animate_map_in {file = "tsp_animate\gestures\compass_in.rtm";};
		class tsp_animate_compass_loop: tsp_animate_map_loop {file = "tsp_animate\gestures\compass_loop.rtm";};
		class tsp_animate_watch_in: tsp_animate_map_in {file = "tsp_animate\gestures\watch_in.rtm";};
		class tsp_animate_watch_loop: tsp_animate_map_loop {file = "tsp_animate\gestures\watch_loop.rtm";};

		//-- NVG
		class tsp_animate_nightvision_up: tsp_animate_breach {file = "tsp_animate\gestures\nightvision_up.rtm"; speed = 1.4;};
		class tsp_animate_nightvision_down: tsp_animate_nightvision_up {file = "tsp_animate\gestures\nightvision_down.rtm";};

		//-- Suicide
		class tsp_animate_suicide_wpst_in: tsp_animate_breach {leftHandIKCurve[] = {0}; file = "tsp_animate\gestures\suicide_wpst_in.rtm"; mask = "upperTorsoWeak"; speed = 0.3; cancel = true; enableOptics = 0;};
		class tsp_animate_suicide_wpst_loop: tsp_animate_suicide_wpst_in {file = "tsp_animate\gestures\suicide_wpst_loop.rtm"; looped = true;};
		class tsp_animate_suicide_wrfl_in: tsp_animate_suicide_wpst_in {file = "tsp_animate\gestures\suicide_wrfl_in.rtm"; mask = "weaponSpine"; leftHandIKCurve[] = {1};};
		class tsp_animate_suicide_wrfl_loop: tsp_animate_suicide_wrfl_in {file = "tsp_animate\gestures\suicide_wrfl_loop.rtm"; looped = true;};

		//-- Inspect
		class tsp_animate_inspect_wrfl: tsp_animate_suicide_wrfl_in {file = "tsp_animate\gestures\inspect_wrfl.rtm"; speed = 0.4;};
		class tsp_animate_inspect_wpst: tsp_animate_suicide_wpst_in {file = "tsp_animate\gestures\inspect_wpst.rtm"; speed = 0.4;};
		
		//-- Throw
		class tsp_animate_throw_wrfl: GestureNo {file = "tsp_animate\gestures\throw_wrfl.rtm"; speed = 0.5; mask="weaponSpine"; looped = true; cancel = true; enableOptics = 0; leftHandIKCurve[] = {1}; rightHandIKCurve[] = {1};};
		class tsp_animate_throw_wrfl_wind: tsp_animate_throw_wrfl {file = "tsp_animate\gestures\throw_wrfl_wind.rtm";};
		class tsp_animate_throw_wrfl_wound: tsp_animate_throw_wrfl {file = "tsp_animate\gestures\throw_wrfl_wound.rtm";};
		class tsp_animate_throw_wrfl_out: tsp_animate_throw_wrfl {file = "tsp_animate\gestures\throw_wrfl_out.rtm"; speed = 1.5; mask="upperTorso"; looped = false;};
		class tsp_animate_throw_wpst: tsp_animate_throw_wrfl {file = "tsp_animate\gestures\throw_wrfl.rtm"; mask = "upperTorsoWeak";};
		class tsp_animate_throw_wpst_wind: tsp_animate_throw_wpst {file = "tsp_animate\gestures\throw_wrfl_wind.rtm";};
		class tsp_animate_throw_wpst_wound: tsp_animate_throw_wpst {file = "tsp_animate\gestures\throw_wrfl_wound.rtm";};
		class tsp_animate_throw_wpst_out: tsp_animate_throw_wpst {file = "tsp_animate\gestures\throw_wrfl_out.rtm"; speed = 1.5; mask = "upperTorsoWeak"; looped = false;};

		//-- None
		class tsp_animate_shoulder_wnon_lnon: GestureNo {file = "tsp_animate\tactical\tap_wrfl_lhig.rtm"; mask = "leftArm"; leftHandIKCurve[] = {0,1,0.05,0,0.95,0,1,1}; speed = 0.8; enableOptics = 0;};
		class tsp_animate_leg_wnon_lnon: tsp_animate_shoulder_wnon_lnon {file = "tsp_animate\tactical\squeeze_wrfl_lhig.rtm";};
		class tsp_animate_door_wnon_lnon: tsp_animate_shoulder_wnon_lnon {file = "tsp_animate\tactical\door_wrfl_lhig.rtm"; speed = 1.2; enableOptics = 1;};
		class tsp_animate_doorace_wnon_lnon: tsp_animate_door_wnon_lnon {file = "tsp_animate\tactical\doorACE_wrfl_lhig.rtm"; leftHandIKCurve[] = {0}; looped = true;};
		class tsp_animate_chemlight_wnon_lnon: tsp_animate_door_wnon_lnon {file = "tsp_animate\tactical\chemlight_wrfl_lhig.rtm";};
		
		//-- Rifle
		class tsp_animate_tactical_cant_wrfl_lnon: GestureNo {file = "tsp_animate\tactical\ready_wrfl_lnon.rtm"; mask = "handsWeapon"; looped = true; enableOptics = 0; scrollUp[] = {"compress","lhig"}; scrollDown[] = {"compress","llow"}; disableWeapons = false;};		
		class tsp_animate_tactical_over_wrfl_lnon: tsp_animate_tactical_cant_wrfl_lnon {file = "tsp_animate\tactical\compress_wrfl_over.rtm"; scrollUp[] = {}; scrollDown[] = {"compress", "llow"};};

		class tsp_animate_tactical_readybase_wrfl_lhig: tsp_animate_tactical_cant_wrfl_lnon {file = "tsp_animate\tactical\ready_wrfl_lhig.rtm"; mask = "readyRifle"; scrollUp[] = {}; scrollDown[] = {"compress","lhig"}; disableWeapons = true;};
		class tsp_animate_tactical_readybase_wrfl_llow: tsp_animate_tactical_readybase_wrfl_lhig {file = "tsp_animate\tactical\ready_wrfl_llow.rtm"; scrollUp[] = {"compress","llow"}; scrollDown[] = {};};
		class tsp_animate_tactical_readycombat_wrfl_lhig: tsp_animate_tactical_readybase_wrfl_lhig {file = "tsp_animate\tactical\readyCombat_wrfl_lhig.rtm"; mask = "handsWeapon";};
		class tsp_animate_tactical_readycombat_wrfl_llow: tsp_animate_tactical_readybase_wrfl_llow {file = "tsp_animate\tactical\readyCombat_wrfl_llow.rtm"; mask = "handsWeapon";};
		class tsp_animate_tactical_readyalt_wrfl_lhig: tsp_animate_tactical_readybase_wrfl_lhig {file = "tsp_animate\tactical\readyAlt_wrfl_lhig.rtm"; mask = "handsWeapon";};
		class tsp_animate_tactical_readyalt_wrfl_llow: tsp_animate_tactical_readybase_wrfl_llow {file = "tsp_animate\tactical\readyAlt_wrfl_llow.rtm"; mask = "handsWeapon";};

		class tsp_animate_tactical_friend_wrfl_lhig: tsp_animate_tactical_readybase_wrfl_lhig {file = "tsp_animate\tactical\friend_wrfl_lhig.rtm"; mask = "handsWeapon"; };
		class tsp_animate_tactical_friend_wrfl_llow: tsp_animate_tactical_friend_wrfl_lhig {file = "tsp_animate\tactical\friend_wrfl_llow.rtm";};
		
		class tsp_animate_tactical_object_wrfl_lhig: tsp_animate_tactical_readybase_wrfl_lhig {file = "tsp_animate\tactical\object_wrfl_lhig.rtm"; mask = "readyRifle"; disableWeapons = false;};
		class tsp_animate_tactical_object_wrfl_llow: tsp_animate_tactical_object_wrfl_lhig {file = "tsp_animate\tactical\object_wrfl_llow.rtm";};
		
		class tsp_animate_tactical_compress_wrfl_lhig: tsp_animate_tactical_readybase_wrfl_lhig {file = "tsp_animate\tactical\compress_wrfl_llow.rtm"; mask = "handsWeapon"; disableWeapons = false; scrollUp[] = {"readybase","lhig"}; scrollDown[] = {"cant","lnon"};};
		class tsp_animate_tactical_compress_wrfl_llow: tsp_animate_tactical_compress_wrfl_lhig {file = "tsp_animate\tactical\compress_wrfl_lhig.rtm"; scrollUp[] = {"cant","lnon"}; scrollDown[] = {"readybase","llow"};};
		
		class tsp_animate_shoulder_wrfl_lnon: tsp_animate_shoulder_wnon_lnon {enableOptics = 1;};
		class tsp_animate_shoulder_wrfl_lhig: tsp_animate_shoulder_wrfl_lnon {file = "tsp_animate\tactical\tap_wrfl_lhig.rtm"; mask = "handsWeapon"; disableWeapons = true; enableOptics = 0;};
		class tsp_animate_shoulder_wrfl_llow: tsp_animate_shoulder_wrfl_lhig {file = "tsp_animate\tactical\tap_wrfl_llow.rtm";};
		class tsp_animate_leg_wrfl_lnon: tsp_animate_leg_wnon_lnon {enableOptics = 0;};
		class tsp_animate_leg_wrfl_lhig: tsp_animate_shoulder_wrfl_lhig {file = "tsp_animate\tactical\squeeze_wrfl_lhig.rtm";};
		class tsp_animate_leg_wrfl_llow: tsp_animate_leg_wrfl_lhig {file = "tsp_animate\tactical\squeeze_wrfl_llow.rtm";};

		class tsp_animate_tactical_portbase_wrfl_lhig: tsp_animate_tactical_readybase_wrfl_lhig {file = "tsp_animate\tactical\port_wrfl_lhig.rtm"; mask = "weaponLeftArm"; leftHandIKCurve[] = {0}; scrollUp[] = {}; scrollDown[] = {};};
		class tsp_animate_tactical_portbase_wrfl_llow: tsp_animate_tactical_portbase_wrfl_lhig {file = "tsp_animate\tactical\port_wrfl_llow.rtm";};
		class tsp_animate_tactical_portmove_wrfl_lhig: tsp_animate_tactical_portbase_wrfl_lhig {mask = "weapon"; leftHandIKCurve[] = {0};};
		class tsp_animate_tactical_portmove_wrfl_llow: tsp_animate_tactical_portmove_wrfl_lhig {file = "tsp_animate\tactical\port_wrfl_llow.rtm"; leftHandIKCurve[] = {0};};
		class tsp_animate_tactical_portchill_wrfl_lhig: tsp_animate_tactical_portbase_wrfl_lhig {file = "tsp_animate\tactical\portchill_wrfl_lhig.rtm";};
		class tsp_animate_tactical_portchill_wrfl_llow: tsp_animate_tactical_portchill_wrfl_lhig {file = "tsp_animate\tactical\portchill_wrfl_llow.rtm";};

		class tsp_animate_tactical_sprint_wrfl_lhig_in: tsp_animate_tactical_readybase_wrfl_lhig {file = "tsp_animate\tactical\sprint_wrfl_lhig_in.rtm"; speed = 4; looped = false; mask = "weaponLeftArm"; leftHandIKCurve[] = {0,1,1,0};};
		class tsp_animate_tactical_sprint_wrfl_lhig_out: tsp_animate_tactical_sprint_wrfl_lhig_in {file = "tsp_animate\tactical\sprint_wrfl_lhig_in.rtm"; leftHandIKCurve[] = {0,0,1,1};};
		class tsp_animate_tactical_sprint_wrfl_lhig: tsp_animate_tactical_sprint_wrfl_lhig_in {file = "tsp_animate\tactical\sprint_wrfl_lhig.rtm"; speed = 1.6; looped = true; leftHandIKCurve[] = {0};};
		class tsp_animate_tactical_sprint_wrfl_llow_in: tsp_animate_tactical_sprint_wrfl_lhig_in {file = "tsp_animate\tactical\sprint_wrfl_llow_in.rtm"; leftHandIKCurve[] = {1};};
		class tsp_animate_tactical_sprint_wrfl_llow_out: tsp_animate_tactical_sprint_wrfl_lhig_out {file = "tsp_animate\tactical\sprint_wrfl_llow_in.rtm"; leftHandIKCurve[] = {1};};
		class tsp_animate_tactical_sprint_wrfl_llow: tsp_animate_tactical_sprint_wrfl_lhig {file = "tsp_animate\tactical\sprint_wrfl_llow.rtm"; leftHandIKCurve[] = {1};};
		
		class tsp_animate_door_wrfl_lnon: tsp_animate_door_wnon_lnon {file = "tsp_animate\tactical\door_wrfl_llow.rtm"; mask = "leftArm"; disableWeapons = false;};
		class tsp_animate_door_wrfl_lhig: tsp_animate_door_wrfl_lnon {file = "tsp_animate\tactical\door_wrfl_lhig.rtm"; mask = "handsWeapon"; disableWeapons = true; enableOptics = 0;};
		class tsp_animate_door_wrfl_llow: tsp_animate_door_wrfl_lhig {file = "tsp_animate\tactical\door_wrfl_llow.rtm";};		
		class tsp_animate_doorcompress_wrfl_lnon: tsp_animate_door_wnon_lnon {file = "tsp_animate\tactical\doorcompress_wrfl_llow.rtm"; mask = "handsWeapon"; disableWeapons = false; enableOptics = 0;};
		class tsp_animate_doorcompress_wrfl_lhig: tsp_animate_doorcompress_wrfl_lnon {file = "tsp_animate\tactical\doorcompress_wrfl_llow.rtm";};
		class tsp_animate_doorcompress_wrfl_llow: tsp_animate_doorcompress_wrfl_lhig {file = "tsp_animate\tactical\doorcompress_wrfl_lhig.rtm";};
		class tsp_animate_doorace_wrfl_lnon: tsp_animate_doorcompress_wrfl_lhig {file = "tsp_animate\tactical\doorACE_wrfl_llow.rtm"; leftHandIKCurve[] = {0}; looped = true; enableOptics = 0;};
		class tsp_animate_doorace_wrfl_lhig: tsp_animate_doorace_wrfl_lnon {file = "tsp_animate\tactical\doorACE_wrfl_llow.rtm";};
		class tsp_animate_doorace_wrfl_llow: tsp_animate_doorace_wrfl_lnon {file = "tsp_animate\tactical\doorACE_wrfl_lhig.rtm";};

		class tsp_animate_chemlight_wrfl_lnon: tsp_animate_door_wnon_lnon {file = "tsp_animate\tactical\chemlight_wrfl_llow.rtm"; mask = "leftArm"; disableWeapons = false;};
		class tsp_animate_chemlight_wrfl_lhig: tsp_animate_chemlight_wrfl_lnon {file = "tsp_animate\tactical\chemlight_wrfl_lhig.rtm"; mask = "handsWeapon"; disableWeapons = true; enableOptics = 0;};
		class tsp_animate_chemlight_wrfl_llow: tsp_animate_chemlight_wrfl_lhig {file = "tsp_animate\tactical\chemlight_wrfl_llow.rtm";};		

		//-- Pistol
		class tsp_animate_tactical_cant_wpst_lnon: GestureNo {file = "tsp_animate\tactical\compress_wpst.rtm"; mask = "readyPistolSpine"; looped = true; disableWeapons = false; enableOptics = 0; scrollUp[] = {"readybase","lhig"}; scrollDown[] = {"readybase","llow"};};		
		
		class tsp_animate_tactical_readybase_wpst_lhig: tsp_animate_tactical_cant_wrfl_lnon {file = "tsp_animate\tactical\ready_wpst_lhig.rtm"; disableWeapons = true; mask = "readyPistol"; scrollUp[] = {}; scrollDown[] = {"compress","lnon"};};
		class tsp_animate_tactical_readybase_wpst_llow: tsp_animate_tactical_readybase_wpst_lhig {file = "tsp_animate\tactical\ready_wpst_llow.rtm"; scrollUp[] = {"compress","lnon"}; scrollDown[] = {};};
		class tsp_animate_tactical_readycombat_wpst_lhig: tsp_animate_tactical_readybase_wpst_lhig {file = "tsp_animate\tactical\readyCombat_wpst_lhig.rtm";};
		class tsp_animate_tactical_readycombat_wpst_llow: tsp_animate_tactical_readybase_wpst_llow {file = "tsp_animate\tactical\readyCombat_wpst_llow.rtm";};
		class tsp_animate_tactical_readyalt_wpst_lhig: tsp_animate_tactical_readybase_wpst_lhig {file = "tsp_animate\tactical\ready_wpst_lhig.rtm";};
		class tsp_animate_tactical_readyalt_wpst_llow: tsp_animate_tactical_readybase_wpst_llow {file = "tsp_animate\tactical\ready_wpst_llow.rtm";};

		class tsp_animate_tactical_friend_wpst_lhig: tsp_animate_tactical_readybase_wpst_lhig {};
		class tsp_animate_tactical_friend_wpst_llow: tsp_animate_tactical_friend_wpst_lhig {};
		
		class tsp_animate_tactical_object_wpst_lhig: tsp_animate_tactical_readybase_wpst_lhig {file = "tsp_animate\tactical\compress_wpst.rtm"; mask = "readyPistolSpine"; disableWeapons = false;};
		class tsp_animate_tactical_object_wpst_llow: tsp_animate_tactical_object_wpst_lhig {file = "tsp_animate\tactical\compress_wpst.rtm";};
		
		class tsp_animate_tactical_compress_wpst_lhig: tsp_animate_tactical_cant_wrfl_lnon {file = "tsp_animate\tactical\compress_wpst.rtm"; mask = "readyPistolSpine"; disableWeapons = false; scrollUp[] = {"readybase","lhig"}; scrollDown[] = {"readybase","llow"};};
		class tsp_animate_tactical_compress_wpst_llow: tsp_animate_tactical_compress_wpst_lhig {};
		
		class tsp_animate_shoulder_wpst_lnon: tsp_animate_shoulder_wnon_lnon {enableOptics = 1;};
		class tsp_animate_shoulder_wpst_lhig: tsp_animate_shoulder_wnon_lnon {file = "tsp_animate\tactical\tap_wpst_lhig.rtm"; mask = "readyPistolSpine"; disableWeapons = true; enableOptics = 0;};
		class tsp_animate_shoulder_wpst_llow: tsp_animate_shoulder_wpst_lhig {file = "tsp_animate\tactical\tap_wpst_llow.rtm";};
		class tsp_animate_leg_wpst_lnon: tsp_animate_leg_wnon_lnon {enableOptics = 0;};
		class tsp_animate_leg_wpst_lhig: tsp_animate_shoulder_wpst_lhig {file = "tsp_animate\tactical\squeeze_wpst_lhig.rtm";};
		class tsp_animate_leg_wpst_llow: tsp_animate_leg_wpst_lhig {file = "tsp_animate\tactical\squeeze_wpst_llow.rtm";};

		class tsp_animate_tactical_portbase_wpst_lhig: tsp_animate_tactical_readybase_wpst_lhig {file = "tsp_animate\tactical\port_wpst.rtm"; mask = "readyPistol"; leftHandIKCurve[] = {0};};
		class tsp_animate_tactical_portbase_wpst_llow: tsp_animate_tactical_portbase_wpst_lhig {};
		class tsp_animate_tactical_portmove_wpst_lhig: tsp_animate_tactical_portbase_wpst_lhig {file = "tsp_animate\tactical\portchill_wpst.rtm";};
		class tsp_animate_tactical_portmove_wpst_llow: tsp_animate_tactical_portmove_wpst_lhig {};
		class tsp_animate_tactical_portchill_wpst_lhig: tsp_animate_tactical_portbase_wpst_lhig {file = "tsp_animate\tactical\portchill_wpst.rtm";};
		class tsp_animate_tactical_portchill_wpst_llow: tsp_animate_tactical_portchill_wpst_lhig {};

		class tsp_animate_tactical_sprint_wpst_lhig_in: tsp_animate_tactical_readybase_wpst_lhig {file = "tsp_animate\tactical\sprint_wrfl_lhig_in.rtm"; speed = 4; looped = false; mask = "readyPistol"; leftHandIKCurve[] = {0,1,1,0};};
		class tsp_animate_tactical_sprint_wpst_lhig_out: tsp_animate_tactical_sprint_wpst_lhig_in {file = "tsp_animate\tactical\sprint_wrfl_lhig_in.rtm"; leftHandIKCurve[] = {0,0,1,1};};
		class tsp_animate_tactical_sprint_wpst_lhig: tsp_animate_tactical_sprint_wpst_lhig_in {file = "tsp_animate\tactical\sprint_wrfl_lhig.rtm"; speed = 1.6; looped = true; leftHandIKCurve[] = {0};};
		class tsp_animate_tactical_sprint_wpst_llow_in: tsp_animate_tactical_sprint_wpst_lhig_in {file = "tsp_animate\tactical\sprint_wrfl_lhig_in.rtm";};
		class tsp_animate_tactical_sprint_wpst_llow_out: tsp_animate_tactical_sprint_wpst_lhig_out {file = "tsp_animate\tactical\sprint_wrfl_lhig_in.rtm";};
		class tsp_animate_tactical_sprint_wpst_llow: tsp_animate_tactical_sprint_wpst_lhig {file = "tsp_animate\tactical\sprint_wrfl_lhig.rtm";};
		
		class tsp_animate_door_wpst_lnon: tsp_animate_door_wnon_lnon {file = "tsp_animate\tactical\door_wpst_llow.rtm"; mask = "leftArm"; disableWeapons = false;};
		class tsp_animate_door_wpst_lhig: tsp_animate_door_wpst_lnon {file = "tsp_animate\tactical\door_wpst_lhig.rtm"; mask = "readyPistol"; disableWeapons = true; enableOptics = 0;};
		class tsp_animate_door_wpst_llow: tsp_animate_door_wpst_lhig {file = "tsp_animate\tactical\door_wpst_llow.rtm";};		
		class tsp_animate_doorcompress_wpst_lnon: tsp_animate_door_wpst_lhig {file = "tsp_animate\tactical\doorcompress_wpst.rtm"; mask = "readyPistolSpine"; disableWeapons = false; enableOptics = 0;};
		class tsp_animate_doorcompress_wpst_lhig: tsp_animate_doorcompress_wpst_lnon {file = "tsp_animate\tactical\doorcompress_wpst.rtm";};
		class tsp_animate_doorcompress_wpst_llow: tsp_animate_doorcompress_wpst_lhig {};
		class tsp_animate_doorace_wpst_lnon: tsp_animate_doorcompress_wpst_lhig {file = "tsp_animate\tactical\doorACE_wpst.rtm"; leftHandIKCurve[] = {0}; looped = true; enableOptics = 0;};
		class tsp_animate_doorace_wpst_lhig: tsp_animate_doorace_wpst_lnon {};
		class tsp_animate_doorace_wpst_llow: tsp_animate_doorace_wpst_lnon {};

		class tsp_animate_chemlight_wpst_lnon: tsp_animate_door_wnon_lnon {file = "tsp_animate\tactical\chemlight_wrfl_llow.rtm"; mask = "leftArm"; disableWeapons = false;};
		class tsp_animate_chemlight_wpst_lhig: tsp_animate_chemlight_wpst_lnon {file = "tsp_animate\tactical\chemlight_wrfl_lhig.rtm"; mask = "handsWeapon"; disableWeapons = true; enableOptics = 0;};
		class tsp_animate_chemlight_wpst_llow: tsp_animate_chemlight_wpst_lhig {file = "tsp_animate\tactical\chemlight_wrfl_llow.rtm";};		

		//-- Weapon
		class tsp_animate_sling_sling: tsp_animate_tactical_compress_wrfl_lhig {interpolationSpeed = 10; speed = 3; looped = false; file = "tsp_animate\sling\sling.rtm"; rightHandIKCurve[] = {0,1,0.7,0};};
		class tsp_animate_sling_3point: tsp_animate_sling_sling {file = "tsp_animate\sling\3point.rtm"; speed = 3.5; leftHandIKCurve[] = {0,1,0.7,0};};		
		class tsp_animate_sling_lanyard: tsp_animate_sling_sling {file = "tsp_animate\sling\lanyard.rtm"; speed = 3.5; leftHandIKCurve[] = {0,1,0.7,0};};
		class tsp_animate_sling_unsling: tsp_animate_sling_sling {file = "tsp_animate\sling\unsling.rtm";};
		class tsp_animate_sling_swap: tsp_animate_sling_unsling {file = "tsp_animate\sling\swap.rtm"; speed = 1.2; rightHandIKCurve[] = {1}; leftHandIKCurve[] = {1};};
		class tsp_animate_sling_check: tsp_animate_sling_sling {file = "tsp_animate\sling\check.rtm"; rightHandIKCurve[] = {1}; leftHandIKCurve[] = {1};};
		class tsp_animate_sling_draw: tsp_animate_tactical_compress_wpst_lhig {interpolationSpeed = 10; speed = 3; looped = false; file = "tsp_animate\sling\draw.rtm";};
		class tsp_animate_sling_draw_israeli: tsp_animate_sling_draw {speed = 2; file = "tsp_animate\sling\draw_israeli.rtm";};
		class tsp_animate_sling_holster: tsp_animate_sling_draw {file = "tsp_animate\sling\holster.rtm"; speed = 1.5;};
		class tsp_animate_sling_sheath: tsp_animate_sling_draw {file = "tsp_animate\sling\sheath.rtm"; speed = 2;};
		class tsp_animate_sling_launch: tsp_animate_sling_unsling {
			file = "a3\anims_f\data\anim\sdr\mov\erc\stp\ras\lnr\amovpercmstpsraswlnrdnon_amovpercmstpsraswrfldnon.rtm";
			mask = "launcher"; interpolationSpeed = 999; speed = 1;
			leftHandIKCurve[] = {0.628571,1,0.84,0};
			rightHandIKCurve[] = {0.442857,1,0.5,0};
		};
		class tsp_animate_sling_unlaunch: tsp_animate_sling_launch {
			file = "a3\anims_f\data\anim\sdr\mov\erc\stp\ras\rfl\amovpercmstpsraswrfldnon_amovpercmstpsraswlnrdnon_end.rtm"; 
			leftHandIKCurve[] = {0.252252,0,0.468468,1};
			rightHandIKCurve[] = {0.333333,0,0.666667,1};
		};
		class tsp_animate_sling_unbino: tsp_animate_sling_holster {file = "a3\anims_f\data\anim\sdr\wop\erc\stp\opt\bin\awoppercmstpsoptwbindnon_amovpercmstpsnonwnondnon.rtm";};

		//-- Attachments
		class GestureMountMuzzle;
		class GestureMountMuzzleProne;
		class GestureDismountMuzzle;
		class GestureDismountMuzzleProne;
		class GestureMountMuzzlePistol: GestureMountMuzzle {mask = "readyPistol";};
		class GestureMountMuzzlePronePistol: GestureMountMuzzleProne {mask = "readyPistol";};
		class GestureDismountMuzzlePistol: GestureDismountMuzzle {mask = "readyPistol";};
		class GestureDismountMuzzlePronePistol: GestureDismountMuzzleProne {mask = "readyPistol";};

		class tsp_animate_ffv: tsp_animate_tactical_compress_wpst_lhig {speed = 0.5; mask = "ffv"; file = "tsp_animate\gestures\ffv.rtm";};
	};
	class BlendAnims {
		readyRifle[] = {"weapon",1,"Spine",0.3,"Spine1",0.2,"Spine2",0.1,"Spine3",0,"Neck",0,"RightShoulder",0.2,"RightArm",0.2,"RightArmRoll",0.2,"RightForeArm",0.2};	
		readyRifleAndArm[] = {"weapon",1,"Spine",0.2,"Spine1",0.1,"Spine2",0,"Spine3",0,"Neck",0,"RightShoulder",1,"RightArm",1,"RightArmRoll",1,"RightForeArm",1};
		ffv[] = {
            "RightShoulder", 1, "RightArm", 1, "RightArmRoll", 1, "RightForeArm", 1, "RightForeArmRoll", 1, "RightHand", 1, 
            "RightHandThumb1", 1, "RightHandThumb2", 1, "RightHandThumb3", 1,
            "RightHandIndex1", 1, "RightHandIndex2", 1, "RightHandIndex3", 1, 
            "RightHandMiddle1", 1, "RightHandMiddle2", 1, "RightHandMiddle3", 1, 
            "RightHandRing", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, 
            "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1
		};
		captorPistol[] = {"head",1,"neck1",1,"neck",1,"weapon",1,"LeftShoulder",1,"LeftArm",1,"LeftArmRoll",1,"LeftForeArm",1,"LeftForeArmRoll",1,"LeftHand",1,"LeftHandRing",1,"LeftHandPinky1",1,"LeftHandPinky2",1,"LeftHandPinky3",1,"LeftHandRing1",1,"LeftHandRing2",1,"LeftHandRing3",1,"LeftHandMiddle1",1,"LeftHandMiddle2",1,"LeftHandMiddle3",1,"LeftHandIndex1",1,"LeftHandIndex2",1,"LeftHandIndex3",1,"LeftHandThumb1",1,"LeftHandThumb2",1,"LeftHandThumb3",1,"Spine",1,"Spine1",1,"Spine2",1,"Spine3",1,"pelvis","MaskStart"};
	};
};
class CfgMovesMaleSdr: CfgMovesBasic {
    class States {
		class CutSceneAnimationBase;
        class a2_duoivan: CutSceneAnimationBase {
			file = "tsp_animate\anim\ActsPercMstpSnonWnonDnon_DancingDuoIvan.rtm";
			speed = 0.025000;
			interpolationSpeed = 2;
			showHandGun = true;
			canPullTrigger = true;
			weaponLowered = false;
			disableWeapons = false;
			disableWeaponsLong = false;	
			weaponIK = 0;
			head = "headDefault";
			InterpolateTo[] = {"AmovPercMstpSnonWnonDnon", 1};
			InterpolateFrom[] = {"AmovPercMstpSnonWnonDnon", 1};
			cancel = true;
		};
		class a2_duostefan: a2_duoivan {file = "tsp_animate\anim\ActsPercMstpSnonWnonDnon_DancingDuoStefan.rtm"; speed = 0.025000;};
		class a2_stefan: a2_duoivan {file = "tsp_animate\anim\ActsPercMstpSnonWnonDnon_DancingStefan.rtm"; speed = 0.010400;};
		class a2_zozo: a2_duoivan {file = "tsp_animate\anim\ZozinoDancing.rtm"; speed = 0.034130;};
		class a2_metal: a2_duoivan {file = "tsp_animate\anim\MadMetalDancing.rtm"; speed = 0.019036;};
		class Acts_Dance_01: CutSceneAnimationBase {interpolateTo[] = {"amovpercmstpsnonwnondnon", 100, "Unconscious", 0.02}; interpolateFrom[] = {"amovpercmstpsnonwnondnon", 100}; interpolationSpeed = 1; cancel = true;};
		class Acts_Dance_02: CutSceneAnimationBase {interpolateTo[] = {"amovpercmstpsnonwnondnon", 100, "Unconscious", 0.02}; interpolateFrom[] = {"amovpercmstpsnonwnondnon", 100}; interpolationSpeed = 1; cancel = true;};
		class AmovPercMstpSnonWnonDnon_exerciseKata: CutSceneAnimationBase {cancel = true;};
		class amovpercmstpsnonwnondnon_exercisepushup: CutSceneAnimationBase {cancel = true;};
		class amovpercmstpsnonwnondnon_exercisekneebenda: CutSceneAnimationBase {cancel = true;};

		class LadderRifleOn;
		class LadderRifleStatic;
		class LadderRifleUpLoop;
		class LadderRifleDownLoop;
		class LadderRifleTopOff;
		class LadderRifleDownOff;
		class ladderPistolOn: LadderRifleOn {actions = "ladderPistolActions"; ConnectTo[] = {"ladderPistolStatic",0.1}; showHandGun = 1;};
		class ladderPistolStatic: LadderRifleStatic {
			actions = "ladderPistolActions"; 
			ConnectTo[] = {"ladderPistolTopOff",0.1,"ladderPistolDownOff",0.1}; 
			InterpolateTo[] = {"Unconscious",0.02,"ladderPistolUpLoop",0.1,"ladderPistolDownLoop",0.1};
			file = "tsp_animate\anim\ladder.rtm";
			showHandGun = 1;	
			disableWeapons = 0;
			disableWeaponsLong = 0;
			showWeaponAim = 1;
			weaponIK = 2;
			enableOptics = 2;
			forceAim = 0;
			mask = "weaponSwitching";	
			aiming = "ladder";
			aimingBody = "ladderUp";
			head = "ladderHead";
		};
		class ladderPistolUpLoop: LadderRifleUpLoop {actions = "ladderPistolActions"; InterpolateTo[] = {"Unconscious",0.02,"ladderPistolStatic",0.1,"ladderPistolTopOff",0.1,"ladderPistolDownLoop",0.1}; showHandGun = 1;};
		class ladderPistolDownLoop: LadderRifleDownLoop {actions = "ladderPistolActions"; InterpolateTo[] = {"Unconscious",0.02,"ladderPistolStatic",0.1,"ladderPistolDownOff",0.1,"ladderPistolUpLoop",0.1}; showHandGun = 1;};
		class ladderPistolTopOff: LadderRifleTopOff {actions = "ladderPistolActions"; ConnectTo[] = {"AmovPercMstpSrasWpstDnon",1}; InterpolateTo[] = {"AmovPercMstpSrasWpstDnon",1,"Unconscious",0.02};};
		class ladderPistolDownOff: LadderRifleDownOff {actions = "ladderPistolActions"; ConnectTo[] = {"AmovPercMstpSrasWpstDnon",1}; InterpolateTo[] = {"AmovPercMstpSrasWpstDnon",1,"Unconscious",0.02};};

		class ladderRifleSlide: LadderRifleDownLoop {actions = "NoActions"; file = "tsp_animate\anim\slideRifle.rtm"; InterpolateTo[] = {"Unconscious",0.02};};
		class ladderUnarmedSlide: LadderRifleDownLoop {actions = "NoActions"; file = "tsp_animate\anim\slideUnarmed.rtm"; InterpolateTo[] = {"Unconscious",0.02};};

		class mountside: default {speed = 0.3;};
		class dismountside: default {speed = 0.2;};

		class Acts_HeliCargo_loop; class Acts_HeliCargo_loop_ffv: Acts_HeliCargo_loop {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Acts_passenger_boat_holdleft; class Acts_passenger_boat_holdleft_ffv: Acts_passenger_boat_holdleft {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Acts_passenger_boat_holdright; class Acts_passenger_boat_holdright_ffv: Acts_passenger_boat_holdright {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Acts_passenger_boat_rightrear; class Acts_passenger_boat_rightrear_ffv: Acts_passenger_boat_rightrear {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Acts_passenger_flatground_leanright; class Acts_passenger_flatground_leanright_ffv: Acts_passenger_flatground_leanright {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class BasicDriver; class BasicDriver_ffv: BasicDriver {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class BasicDriverDead; class BasicDriverDead_ffv: BasicDriverDead {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class BasicDriverDying; class BasicDriverDying_ffv: BasicDriverDying {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class BasicDriverOut; class BasicDriverOut_ffv: BasicDriverOut {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class BasicDriverOutDead; class BasicDriverOutDead_ffv: BasicDriverOutDead {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class BasicDriverOutDying; class BasicDriverOutDying_ffv: BasicDriverOutDying {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class cargo_base; class cargo_base_ffv: cargo_base {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class cargo_base_idle; class cargo_base_idle_ffv: cargo_base_idle {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class cargo_base_idle_pistol; class cargo_base_idle_pistol_ffv: cargo_base_idle_pistol {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class cargo_basebinoc; class cargo_basebinoc_ffv: cargo_basebinoc {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class cargo_basepistol; class cargo_basepistol_ffv: cargo_basepistol {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class cargo_marksman; class cargo_marksman_ffv: cargo_marksman {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class CoDriver_Van_02; class CoDriver_Van_02_ffv: CoDriver_Van_02 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class DefaultDriver; class DefaultDriver_ffv: DefaultDriver {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class DefaultPassenger; class DefaultPassenger_ffv: DefaultPassenger {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Driver_AFV_Wheeled_01_in; class Driver_AFV_Wheeled_01_in_ffv: Driver_AFV_Wheeled_01_in {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Driver_AFV_Wheeled_01_out; class Driver_AFV_Wheeled_01_out_ffv: Driver_AFV_Wheeled_01_out {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Driver_APC_tracked_01_crv_in; class Driver_APC_tracked_01_crv_in_ffv: Driver_APC_tracked_01_crv_in {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Driver_APC_tracked_02_cannon_F_in; class Driver_APC_tracked_02_cannon_F_in_ffv: Driver_APC_tracked_02_cannon_F_in {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Driver_APC_tracked_02_cannon_F_out; class Driver_APC_tracked_02_cannon_F_out_ffv: Driver_APC_tracked_02_cannon_F_out {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Driver_APC_tracked_03_cannon_F_in; class Driver_APC_tracked_03_cannon_F_in_ffv: Driver_APC_tracked_03_cannon_F_in {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Driver_APC_tracked_03_cannon_F_out; class Driver_APC_tracked_03_cannon_F_out_ffv: Driver_APC_tracked_03_cannon_F_out {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Driver_APC_Wheeled_01_in; class Driver_APC_Wheeled_01_in_ffv: Driver_APC_Wheeled_01_in {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Driver_APC_Wheeled_01_out; class Driver_APC_Wheeled_01_out_ffv: Driver_APC_Wheeled_01_out {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Driver_APC_Wheeled_02_rcws_F_in; class Driver_APC_Wheeled_02_rcws_F_in_ffv: Driver_APC_Wheeled_02_rcws_F_in {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Driver_APC_Wheeled_02_rcws_F_out; class Driver_APC_Wheeled_02_rcws_F_out_ffv: Driver_APC_Wheeled_02_rcws_F_out {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Driver_APC_Wheeled_03_cannon_F_in; class Driver_APC_Wheeled_03_cannon_F_in_ffv: Driver_APC_Wheeled_03_cannon_F_in {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Driver_APC_Wheeled_03_cannon_F_out; class Driver_APC_Wheeled_03_cannon_F_out_ffv: Driver_APC_Wheeled_03_cannon_F_out {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class driver_apctracked3_in; class driver_apctracked3_in_ffv: driver_apctracked3_in {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class driver_apctracked3_out; class driver_apctracked3_out_ffv: driver_apctracked3_out {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class driver_apcwheeled1_out; class driver_apcwheeled1_out_ffv: driver_apcwheeled1_out {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class driver_apcwheeled2_in; class driver_apcwheeled2_in_ffv: driver_apcwheeled2_in {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class driver_apcwheeled2_out; class driver_apcwheeled2_out_ffv: driver_apcwheeled2_out {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class driver_apcwheeled3_in; class driver_apcwheeled3_in_ffv: driver_apcwheeled3_in {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class driver_boat_transport_02; class driver_boat_transport_02_ffv: driver_boat_transport_02 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class driver_boat01; class driver_boat01_ffv: driver_boat01 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class driver_hemtt; class driver_hemtt_ffv: driver_hemtt {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Driver_High01; class Driver_High01_ffv: Driver_High01 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Driver_low01; class Driver_low01_ffv: Driver_low01 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class driver_lsv_01; class driver_lsv_01_ffv: driver_lsv_01 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class driver_lsv_02; class driver_lsv_02_ffv: driver_lsv_02 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Driver_LT_01_AT_F_in; class Driver_LT_01_AT_F_in_ffv: Driver_LT_01_AT_F_in {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Driver_LT_01_AT_F_out; class Driver_LT_01_AT_F_out_ffv: Driver_LT_01_AT_F_out {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class driver_mantis; class driver_mantis_ffv: driver_mantis {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Driver_MBT_01_cannon_F_in; class Driver_MBT_01_cannon_F_in_ffv: Driver_MBT_01_cannon_F_in {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Driver_MBT_02_F_in; class Driver_MBT_02_F_in_ffv: Driver_MBT_02_F_in {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Driver_MBT_03_cannon_F_in; class Driver_MBT_03_cannon_F_in_ffv: Driver_MBT_03_cannon_F_in {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Driver_MBT_03_cannon_F_out; class Driver_MBT_03_cannon_F_out_ffv: Driver_MBT_03_cannon_F_out {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Driver_MBT_04_in; class Driver_MBT_04_in_ffv: Driver_MBT_04_in {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Driver_MBT_04_out; class Driver_MBT_04_out_ffv: Driver_MBT_04_out {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Driver_mid01; class Driver_mid01_ffv: Driver_mid01 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class driver_mid01_idlebreathing; class driver_mid01_idlebreathing_ffv: driver_mid01_idlebreathing {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class driver_MRAP_01; class driver_MRAP_01_ffv: driver_MRAP_01 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class driver_MRAP_03; class driver_MRAP_03_ffv: driver_MRAP_03 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class driver_offroad01; class driver_offroad01_ffv: driver_offroad01 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class driver_Quadbike; class driver_Quadbike_ffv: driver_Quadbike {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class driver_scooter_01; class driver_scooter_01_ffv: driver_scooter_01 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class driver_sdv; class driver_sdv_ffv: driver_sdv {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class driver_tractor; class driver_tractor_ffv: driver_tractor {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class driver_Truck_02; class driver_Truck_02_ffv: driver_Truck_02 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class driver_Truck_03; class driver_Truck_03_ffv: driver_Truck_03 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class driver_ugv_01; class driver_ugv_01_ffv: driver_ugv_01 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class driver_Van_01; class driver_Van_01_ffv: driver_Van_01 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Driver_Van_02; class Driver_Van_02_ffv: Driver_Van_02 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class GetInAMV_cargo; class GetInAMV_cargo_ffv: GetInAMV_cargo {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class GetInHeli_Transport_01Cargo; class GetInHeli_Transport_01Cargo_ffv: GetInHeli_Transport_01Cargo {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class GetInHeli_Transport_02Cargo; class GetInHeli_Transport_02Cargo_ffv: GetInHeli_Transport_02Cargo {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class GetInHelicopterCargo; class GetInHelicopterCargo_ffv: GetInHelicopterCargo {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class GetInHelicopterCargoPst; class GetInHelicopterCargoPst_ffv: GetInHelicopterCargoPst {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class GetInHelicopterCargoRfl; class GetInHelicopterCargoRfl_ffv: GetInHelicopterCargoRfl {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class GetInMRAP_01_cargo; class GetInMRAP_01_cargo_ffv: GetInMRAP_01_cargo {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class GetInMRAP_01_cargoPst; class GetInMRAP_01_cargoPst_ffv: GetInMRAP_01_cargoPst {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class GetInMRAP_01_cargoRfl; class GetInMRAP_01_cargoRfl_ffv: GetInMRAP_01_cargoRfl {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class GetInOffroadCargo; class GetInOffroadCargo_ffv: GetInOffroadCargo {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class GetInQuadbike_cargo; class GetInQuadbike_cargo_ffv: GetInQuadbike_cargo {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class GetOutHelicopterCargo; class GetOutHelicopterCargo_ffv: GetOutHelicopterCargo {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class GetOutHelicopterCargoPst; class GetOutHelicopterCargoPst_ffv: GetOutHelicopterCargoPst {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class GetOutHelicopterCargoRfl; class GetOutHelicopterCargoRfl_ffv: GetOutHelicopterCargoRfl {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class GetOutMRAP_01_cargo; class GetOutMRAP_01_cargo_ffv: GetOutMRAP_01_cargo {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class GetOutMRAP_01_cargoPst; class GetOutMRAP_01_cargoPst_ffv: GetOutMRAP_01_cargoPst {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class GetOutMRAP_01_cargoRfl; class GetOutMRAP_01_cargoRfl_ffv: GetOutMRAP_01_cargoRfl {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class GetOutQuadbike_cargo; class GetOutQuadbike_cargo_ffv: GetOutQuadbike_cargo {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Heli_Attack_02_Cargo; class Heli_Attack_02_Cargo_ffv: Heli_Attack_02_Cargo {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Heli_Light_02_Cargo; class Heli_Light_02_Cargo_ffv: Heli_Light_02_Cargo {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Kart_driver; class Kart_driver_ffv: Kart_driver {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_apc_generic01; class passenger_apc_generic01_ffv: passenger_apc_generic01 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_apc_generic02; class passenger_apc_generic02_ffv: passenger_apc_generic02 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_apc_generic02b; class passenger_apc_generic02b_ffv: passenger_apc_generic02b {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_apc_generic03; class passenger_apc_generic03_ffv: passenger_apc_generic03 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_apc_generic03_low; class passenger_apc_generic03_low_ffv: passenger_apc_generic03_low {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_apc_generic04; class passenger_apc_generic04_ffv: passenger_apc_generic04 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_apc_generic04still; class passenger_apc_generic04still_ffv: passenger_apc_generic04still {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_apc_narrow_generic01; class passenger_apc_narrow_generic01_ffv: passenger_apc_narrow_generic01 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_apc_narrow_generic01_low; class passenger_apc_narrow_generic01_low_ffv: passenger_apc_narrow_generic01_low {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_apc_narrow_generic02; class passenger_apc_narrow_generic02_ffv: passenger_apc_narrow_generic02 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_apc_narrow_generic02_low; class passenger_apc_narrow_generic02_low_ffv: passenger_apc_narrow_generic02_low {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_apc_narrow_generic03; class passenger_apc_narrow_generic03_ffv: passenger_apc_narrow_generic03 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_apc_narrow_generic03_low; class passenger_apc_narrow_generic03_low_ffv: passenger_apc_narrow_generic03_low {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_apc_narrow_generic03still; class passenger_apc_narrow_generic03still_ffv: passenger_apc_narrow_generic03still {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_boat_holdleft; class passenger_boat_holdleft_ffv: passenger_boat_holdleft {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_boat_holdleft2; class passenger_boat_holdleft2_ffv: passenger_boat_holdleft2 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_boat_holdright; class passenger_boat_holdright_ffv: passenger_boat_holdright {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_boat_holdright2; class passenger_boat_holdright2_ffv: passenger_boat_holdright2 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_boat_rightrear; class passenger_boat_rightrear_ffv: passenger_boat_rightrear {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_flatground_crosslegs; class passenger_flatground_crosslegs_ffv: passenger_flatground_crosslegs {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_flatground_generic01; class passenger_flatground_generic01_ffv: passenger_flatground_generic01 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_flatground_generic02; class passenger_flatground_generic02_ffv: passenger_flatground_generic02 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_flatground_generic03; class passenger_flatground_generic03_ffv: passenger_flatground_generic03 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_flatground_generic04; class passenger_flatground_generic04_ffv: passenger_flatground_generic04 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_flatground_generic05; class passenger_flatground_generic05_ffv: passenger_flatground_generic05 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_flatground_leanleft; class passenger_flatground_leanleft_ffv: passenger_flatground_leanleft {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_flatground_leanright; class passenger_flatground_leanright_ffv: passenger_flatground_leanright {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_generic01_foldhands; class passenger_generic01_foldhands_ffv: passenger_generic01_foldhands {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_generic01_leanleft; class passenger_generic01_leanleft_ffv: passenger_generic01_leanleft {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_generic01_leanright; class passenger_generic01_leanright_ffv: passenger_generic01_leanright {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_generic02_foldhands; class passenger_generic02_foldhands_ffv: passenger_generic02_foldhands {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_injured_medevac_truck01; class passenger_injured_medevac_truck01_ffv: passenger_injured_medevac_truck01 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_injured_medevac_truck02; class passenger_injured_medevac_truck02_ffv: passenger_injured_medevac_truck02 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_injured_medevac_truck03; class passenger_injured_medevac_truck03_ffv: passenger_injured_medevac_truck03 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_low01; class passenger_low01_ffv: passenger_low01 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_mantisrear; class passenger_mantisrear_ffv: passenger_mantisrear {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_MRAP_01_back; class passenger_MRAP_01_back_ffv: passenger_MRAP_01_back {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_MRAP_01_front; class passenger_MRAP_01_front_ffv: passenger_MRAP_01_front {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_MRAP_03exgunner; class passenger_MRAP_03exgunner_ffv: passenger_MRAP_03exgunner {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Passenger_Plane_Civil_01_L; class Passenger_Plane_Civil_01_L_ffv: Passenger_Plane_Civil_01_L {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Passenger_Plane_Civil_01_R; class Passenger_Plane_Civil_01_R_ffv: Passenger_Plane_Civil_01_R {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_Quadbike; class passenger_Quadbike_ffv: passenger_Quadbike {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_scooter_01; class passenger_scooter_01_ffv: passenger_scooter_01 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_scooter_02; class passenger_scooter_02_ffv: passenger_scooter_02 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_sdv; class passenger_sdv_ffv: passenger_sdv {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Passenger_Van_02_Medevac_Back; class Passenger_Van_02_Medevac_Back_ffv: Passenger_Van_02_Medevac_Back {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Passenger_Van_02_Medevac_Front; class Passenger_Van_02_Medevac_Front_ffv: Passenger_Van_02_Medevac_Front {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Passenger_Van_02_Transport_Left_1; class Passenger_Van_02_Transport_Left_1_ffv: Passenger_Van_02_Transport_Left_1 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Passenger_Van_02_Transport_Left_2; class Passenger_Van_02_Transport_Left_2_ffv: Passenger_Van_02_Transport_Left_2 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Passenger_Van_02_Transport_Left_3; class Passenger_Van_02_Transport_Left_3_ffv: Passenger_Van_02_Transport_Left_3 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Passenger_Van_02_Transport_Middle_3; class Passenger_Van_02_Transport_Middle_3_ffv: Passenger_Van_02_Transport_Middle_3 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Passenger_Van_02_Transport_Right_1; class Passenger_Van_02_Transport_Right_1_ffv: Passenger_Van_02_Transport_Right_1 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Passenger_Van_02_Transport_Right_2; class Passenger_Van_02_Transport_Right_2_ffv: Passenger_Van_02_Transport_Right_2 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Passenger_Van_02_Transport_Right_3; class Passenger_Van_02_Transport_Right_3_ffv: Passenger_Van_02_Transport_Right_3 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_VAN_codriver01; class passenger_VAN_codriver01_ffv: passenger_VAN_codriver01 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class passenger_VAN_codriver02; class passenger_VAN_codriver02_ffv: passenger_VAN_codriver02 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class PBX_Cargo01; class PBX_Cargo01_ffv: PBX_Cargo01 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class PBX_Cargo02; class PBX_Cargo02_ffv: PBX_Cargo02 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class PBX_Cargo03; class PBX_Cargo03_ffv: PBX_Cargo03 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class PBX_Driver; class PBX_Driver_ffv: PBX_Driver {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class RHIB_Cargo; class RHIB_Cargo_ffv: RHIB_Cargo {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class RHIB_Driver; class RHIB_Driver_ffv: RHIB_Driver {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Truck_02_Driver; class Truck_02_Driver_ffv: Truck_02_Driver {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Truck_Cargo01; class Truck_Cargo01_ffv: Truck_Cargo01 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Truck_Cargo02; class Truck_Cargo02_ffv: Truck_Cargo02 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Truck_Cargo02_V1; class Truck_Cargo02_V1_ffv: Truck_Cargo02_V1 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Truck_Cargo02_V2; class Truck_Cargo02_V2_ffv: Truck_Cargo02_V2 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Truck_Cargo02_V3; class Truck_Cargo02_V3_ffv: Truck_Cargo02_V3 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Truck_Cargo02_V4; class Truck_Cargo02_V4_ffv: Truck_Cargo02_V4 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Truck_Cargo03; class Truck_Cargo03_ffv: Truck_Cargo03 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Truck_Cargo03_V1; class Truck_Cargo03_V1_ffv: Truck_Cargo03_V1 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Truck_Cargo03_V2; class Truck_Cargo03_V2_ffv: Truck_Cargo03_V2 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Truck_Cargo04; class Truck_Cargo04_ffv: Truck_Cargo04 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Truck_Cargo04_V1; class Truck_Cargo04_V1_ffv: Truck_Cargo04_V1 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Truck_Cargo04_V2; class Truck_Cargo04_V2_ffv: Truck_Cargo04_V2 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Truck_Cargo04_V3; class Truck_Cargo04_V3_ffv: Truck_Cargo04_V3 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Truck_Driver; class Truck_Driver_ffv: Truck_Driver {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Zodiac_Cargo01; class Zodiac_Cargo01_ffv: Zodiac_Cargo01 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Zodiac_Cargo02; class Zodiac_Cargo02_ffv: Zodiac_Cargo02 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Zodiac_Cargo03; class Zodiac_Cargo03_ffv: Zodiac_Cargo03 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Zodiac_Cargo04; class Zodiac_Cargo04_ffv: Zodiac_Cargo04 {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
		class Zodiac_Driver; class Zodiac_Driver_ffv: Zodiac_Driver {rightHandIKCurve[] = {}; showHandGun = 1; weaponIK = 2; mask = "weaponSwitching"; aiming = "ladder"; aimingBody = "ladderUp"; head = "ladderHead";};
	};
	class BlendAnims {
		ladder[] = {
			"launcher",1,"weapon",1,
			"head",1,"neck1",1,"neck",1,"Spine3",1,"Spine2",1,"Spine1",1,"Spine",1,
			"RightShoulder",1,"RightArm",1,"RightArmRoll",1,"RightForeArm",1,"RightForeArmRoll",1,"RightHand",1,
			"RightHandThumb1",1,"RightHandThumb2",1,"RightHandThumb3",1,
			"RightHandIndex1",1,"RightHandIndex2",1,"RightHandIndex3",1,
			"RightHandMiddle1",1,"RightHandMiddle2",1,"RightHandMiddle3",1,
			"RightHandRing",1,"RightHandRing1",1,"RightHandRing2",1,"RightHandRing3",1,
			"RightHandPinky1",1,"RightHandPinky2",1,"RightHandPinky3",1,
			"LeftShoulder",0.5,"LeftArm",0.35,"LeftArmRoll",0.3,"LeftForeArm",0.25,"LeftForeArmRoll",0.2,"LeftHand",0,
			"LeftHandThumb1",0,"LeftHandThumb2",0,"LeftHandThumb3",0,
			"LeftHandIndex1",0,"LeftHandIndex2",0,"LeftHandIndex3",0,
			"LeftHandMiddle1",0,"LeftHandMiddle2",0,"LeftHandMiddle3",0,
			"LeftHandRing",0,"LeftHandRing1",0,"LeftHandRing2",0,"LeftHandRing3",0,
			"LeftHandPinky1",0,"LeftHandPinky2",0,"LeftHandPinky3",0
		};
		ladderUp[] = {
			"weapon",0.2,"Camera",0.35,"launcher",0.2,
			"Head",0.5,"Neck",0.5,"Neck1",0.5,"spine3",0.45,"spine2",0.4,"spine1",0.3,"spine",0.2,
			"RightShoulder",0.6,"RightArm",0.63,"RightArmRoll",0.67,"RightForeArm",0.7,"RightForeArmRoll",0.7,"RightHand",0.7,
			"RightHandThumb1",0.7,"RightHandThumb2",0.7,"RightHandThumb3",0.7,
			"RightHandRing",0.7,"RightHandRing1",0.7,"RightHandRing2",0.7,"RightHandRing3",0.7,
			"RightHandIndex1",0.7,"RightHandIndex2",0.7,"RightHandIndex3",0.7,
			"RightHandMiddle1",0.7,"RightHandMiddle2",0.7,"RightHandMiddle3",0.7,
			"RightHandPinky1",0.7,"RightHandPinky2",0.7,"RightHandPinky3",0.7,
			"LeftShoulder",0.25,"LeftArm",0.2,"LeftArmRoll",0.15,"LeftForeArm",0.1,"LeftForeArmRoll",0.05,"LeftHand",0,
			"LeftHandThumb1",0,"LeftHandThumb2",0,"LeftHandThumb3",0,
			"LeftHandIndex1",0,"LeftHandIndex2",0,"LeftHandIndex3",0,
			"LeftHandMiddle1",0,"LeftHandMiddle2",0,"LeftHandMiddle3",0,
			"LeftHandRing",0,"LeftHandRing1",0,"LeftHandRing2",0,"LeftHandRing3",0,
			"LeftHandPinky1",0,"LeftHandPinky2",0,"LeftHandPinky3",0
		};
		ladderHead[] = {
			"head",1,"neck1",0.5,"neck",0.5,"spine3",0.4,"spine2",0.3,"spine1",0.2,"spine",0.1,
			"RightShoulder",0.7,"RightArm",0.7,"RightArmRoll",0.7,"RightForeArm",0.7,"RightForeArmRoll",0.7,"RightHand",0.7,
			"RightHandThumb1",0.7,"RightHandThumb2",0.7,"RightHandThumb3",0.7,
			"RightHandRing",0.7,"RightHandRing1",0.7,"RightHandRing2",0.7,"RightHandRing3",0.7,
			"RightHandIndex1",0.7,"RightHandIndex2",0.7,"RightHandIndex3",0.7,
			"RightHandMiddle1",0.7,"RightHandMiddle2",0.7,"RightHandMiddle3",0.7,
			"RightHandPinky1",0.7,"RightHandPinky2",0.7,"RightHandPinky3",0.7,
			"LeftShoulder",0.25,"LeftArm",0.2,"LeftArmRoll",0.15,"LeftForeArm",0.1,"LeftForeArmRoll",0.05,"LeftHand",0,
			"LeftHandThumb1",0,"LeftHandThumb2",0,"LeftHandThumb3",0,
			"LeftHandIndex1",0,"LeftHandIndex2",0,"LeftHandIndex3",0,
			"LeftHandMiddle1",0,"LeftHandMiddle2",0,"LeftHandMiddle3",0,
			"LeftHandRing",0,"LeftHandRing1",0,"LeftHandRing2",0,"LeftHandRing3",0,
			"LeftHandPinky1",0,"LeftHandPinky2",0,"LeftHandPinky3",0
		};
	};
};