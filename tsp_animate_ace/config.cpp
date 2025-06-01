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
		tsp_animate_detonate[] = {"tsp_animate_detonate", "Gesture"};
		tsp_animate_detonate_shock[] = {"tsp_animate_detonate_shock", "Gesture"};

		tsp_animate_captive[] = {"tsp_animate_captive", "Gesture"};
		tsp_animate_captor_wnon[] = {"tsp_animate_captor_wnon", "Gesture"};
		tsp_animate_captor_wrfl[] = {"tsp_animate_captor_wrfl", "Gesture"};
		tsp_animate_captor_wpst[] = {"tsp_animate_captor_wpst", "Gesture"};

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
		class tsp_animate_detonate: tsp_animate_breach {leftHandIKCurve[] = {0}; file = "tsp_animate_ace\gestures\detonate.rtm"; enableOptics = 0;};
		class tsp_animate_detonate_shock: tsp_animate_detonate {file = "tsp_animate_ace\gestures\detonate_shock.rtm";};

		//-- Captive
		class tsp_animate_captive: tsp_animate_breach {mask = "HandsWeapon"; leftHandIKCurve[] = {0}; rightHandIKCurve[] = {0}; looped = true; file = "tsp_animate_ace\gestures\captive.rtm";};
		class tsp_animate_captor_wnon: tsp_animate_captive {mask = "leftArm"; file = "tsp_animate_ace\gestures\captor.rtm";};
		class tsp_animate_captor_wrfl: tsp_animate_captor_wnon {mask = "HandsWeapon"; rightHandIKCurve[] = {1};};
		class tsp_animate_captor_wpst: tsp_animate_captor_wnon {mask = "HandsWeapon";};

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