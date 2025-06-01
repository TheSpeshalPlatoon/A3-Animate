class CfgPatches {
	class tsp_animate_retro {
		requiredAddons[] = {"tsp_core", "tsp_animate"};
		units[] = {};
	};
};
class CfgMovesBasic {
    class default;
    class DefaultDie;
    class ManActions {
		//-- Rifle
		tsp_animate_tactical_retro_cant_wrfl_lnon[] = {"tsp_animate_tactical_retro_cant_wrfl_lnon", "Gesture"};
		tsp_animate_tactical_retro_over_wrfl_lnon[] = {"tsp_animate_tactical_retro_over_wrfl_lnon", "Gesture"};
		tsp_animate_tactical_retro_readybase_wrfl_lhig[] = {"tsp_animate_tactical_retro_readybase_wrfl_lhig", "Gesture"};
		tsp_animate_tactical_retro_readybase_wrfl_llow[] = {"tsp_animate_tactical_retro_readybase_wrfl_llow", "Gesture"};
		tsp_animate_tactical_retro_readycombat_wrfl_lhig[] = {"tsp_animate_tactical_retro_readycombat_wrfl_lhig", "Gesture"};
		tsp_animate_tactical_retro_readycombat_wrfl_llow[] = {"tsp_animate_tactical_retro_readycombat_wrfl_llow", "Gesture"};
		tsp_animate_tactical_retro_readyalt_wrfl_lhig[] = {"tsp_animate_tactical_retro_readyalt_wrfl_lhig", "Gesture"};
		tsp_animate_tactical_retro_readyalt_wrfl_llow[] = {"tsp_animate_tactical_retro_readyalt_wrfl_llow", "Gesture"};
		tsp_animate_tactical_retro_friend_wrfl_lhig[] = {"tsp_animate_tactical_retro_friend_wrfl_lhig", "Gesture"};
		tsp_animate_tactical_retro_friend_wrfl_llow[] = {"tsp_animate_tactical_retro_friend_wrfl_llow", "Gesture"};
		tsp_animate_tactical_retro_object_wrfl_lhig[] = {"tsp_animate_tactical_retro_object_wrfl_lhig", "Gesture"};
		tsp_animate_tactical_retro_object_wrfl_llow[] = {"tsp_animate_tactical_retro_object_wrfl_llow", "Gesture"};
		tsp_animate_tactical_retro_compress_wrfl_lhig[] = {"tsp_animate_tactical_retro_compress_wrfl_lhig", "Gesture"};
		tsp_animate_tactical_retro_compress_wrfl_llow[] = {"tsp_animate_tactical_retro_compress_wrfl_llow", "Gesture"};
		tsp_animate_tactical_retro_portbase_wrfl_lhig[] = {"tsp_animate_tactical_retro_portbase_wrfl_lhig", "Gesture"};
		tsp_animate_tactical_retro_portbase_wrfl_llow[] = {"tsp_animate_tactical_retro_portbase_wrfl_llow", "Gesture"};
		tsp_animate_tactical_retro_portmove_wrfl_lhig[] = {"tsp_animate_tactical_retro_portmove_wrfl_lhig", "Gesture"};
		tsp_animate_tactical_retro_portmove_wrfl_llow[] = {"tsp_animate_tactical_retro_portmove_wrfl_llow", "Gesture"};
		tsp_animate_tactical_retro_portchill_wrfl_lhig[] = {"tsp_animate_tactical_retro_portchill_wrfl_lhig", "Gesture"};
		tsp_animate_tactical_retro_portchill_wrfl_llow[] = {"tsp_animate_tactical_retro_portchill_wrfl_llow", "Gesture"};
		tsp_animate_tactical_retro_sprint_wrfl_lhig_in[] = {"tsp_animate_tactical_retro_sprint_wrfl_lhig_in", "Gesture"};
		tsp_animate_tactical_retro_sprint_wrfl_lhig_out[] = {"tsp_animate_tactical_retro_sprint_wrfl_lhig_out", "Gesture"};
		tsp_animate_tactical_retro_sprint_wrfl_lhig[] = {"tsp_animate_tactical_retro_sprint_wrfl_lhig", "Gesture"};
		tsp_animate_tactical_retro_sprint_wrfl_llow_in[] = {"tsp_animate_tactical_retro_sprint_wrfl_llow_in", "Gesture"};
		tsp_animate_tactical_retro_sprint_wrfl_llow_out[] = {"tsp_animate_tactical_retro_sprint_wrfl_llow_out", "Gesture"};
		tsp_animate_tactical_retro_sprint_wrfl_llow[] = {"tsp_animate_tactical_retro_sprint_wrfl_llow", "Gesture"};

		//-- Pistol
		tsp_animate_tactical_retro_cant_wpst_lnon[] = {"tsp_animate_tactical_retro_cant_wpst_lnon", "Gesture"};
		tsp_animate_tactical_retro_readybase_wpst_lhig[] = {"tsp_animate_tactical_retro_readybase_wpst_lhig", "Gesture"};
		tsp_animate_tactical_retro_readybase_wpst_llow[] = {"tsp_animate_tactical_retro_readybase_wpst_llow", "Gesture"};
		tsp_animate_tactical_retro_readycombat_wpst_lhig[] = {"tsp_animate_tactical_retro_readycombat_wpst_lhig", "Gesture"};
		tsp_animate_tactical_retro_readycombat_wpst_llow[] = {"tsp_animate_tactical_retro_readycombat_wpst_llow", "Gesture"};
		tsp_animate_tactical_retro_readyalt_wpst_lhig[] = {"tsp_animate_tactical_retro_readyalt_wpst_lhig", "Gesture"};
		tsp_animate_tactical_retro_readyalt_wpst_llow[] = {"tsp_animate_tactical_retro_readyalt_wpst_llow", "Gesture"};
		tsp_animate_tactical_retro_friend_wpst_lhig[] = {"tsp_animate_tactical_retro_friend_wpst_lhig", "Gesture"};
		tsp_animate_tactical_retro_friend_wpst_llow[] = {"tsp_animate_tactical_retro_friend_wpst_llow", "Gesture"};
		tsp_animate_tactical_retro_object_wpst_lhig[] = {"tsp_animate_tactical_retro_object_wpst_lhig", "Gesture"};
		tsp_animate_tactical_retro_object_wpst_llow[] = {"tsp_animate_tactical_retro_object_wpst_llow", "Gesture"};
		tsp_animate_tactical_retro_compress_wpst_lhig[] = {"tsp_animate_tactical_retro_compress_wpst_lhig", "Gesture"};
		tsp_animate_tactical_retro_compress_wpst_llow[] = {"tsp_animate_tactical_retro_compress_wpst_llow", "Gesture"};
		tsp_animate_tactical_retro_portbase_wpst_lhig[] = {"tsp_animate_tactical_retro_portbase_wpst_lhig", "Gesture"};
		tsp_animate_tactical_retro_portbase_wpst_llow[] = {"tsp_animate_tactical_retro_portbase_wpst_llow", "Gesture"};
		tsp_animate_tactical_retro_portmove_wpst_lhig[] = {"tsp_animate_tactical_retro_portmove_wpst_lhig", "Gesture"};
		tsp_animate_tactical_retro_portmove_wpst_llow[] = {"tsp_animate_tactical_retro_portmove_wpst_llow", "Gesture"};
		tsp_animate_tactical_retro_portchill_wpst_lhig[] = {"tsp_animate_tactical_retro_portchill_wpst_lhig", "Gesture"};
		tsp_animate_tactical_retro_portchill_wpst_llow[] = {"tsp_animate_tactical_retro_portchill_wpst_llow", "Gesture"};
		tsp_animate_tactical_retro_sprint_wpst_lhig_in[] = {"tsp_animate_tactical_retro_sprint_wpst_lhig_in", "Gesture"};
		tsp_animate_tactical_retro_sprint_wpst_lhig_out[] = {"tsp_animate_tactical_retro_sprint_wpst_lhig_out", "Gesture"};
		tsp_animate_tactical_retro_sprint_wpst_lhig[] = {"tsp_animate_tactical_retro_sprint_wpst_lhig", "Gesture"};
		tsp_animate_tactical_retro_sprint_wpst_llow_in[] = {"tsp_animate_tactical_retro_sprint_wpst_llow_in", "Gesture"};
		tsp_animate_tactical_retro_sprint_wpst_llow_out[] = {"tsp_animate_tactical_retro_sprint_wpst_llow_out", "Gesture"};
		tsp_animate_tactical_retro_sprint_wpst_llow[] = {"tsp_animate_tactical_retro_sprint_wpst_llow", "Gesture"};
	};
};
class CfgGesturesMale {
	skeletonName = "OFP2_ManSkeleton";
	class Default {};
	class States {
		class tsp_animate_tactical_cant_wrfl_lnon;
		class tsp_animate_tactical_over_wrfl_lnon;
		class tsp_animate_tactical_readybase_wrfl_lhig;
		class tsp_animate_tactical_readybase_wrfl_llow;
		class tsp_animate_tactical_readycombat_wrfl_lhig;
		class tsp_animate_tactical_readycombat_wrfl_llow;
		class tsp_animate_tactical_readyalt_wrfl_lhig;
		class tsp_animate_tactical_readyalt_wrfl_llow;
		class tsp_animate_tactical_friend_wrfl_lhig;
		class tsp_animate_tactical_friend_wrfl_llow;
		class tsp_animate_tactical_object_wrfl_lhig;
		class tsp_animate_tactical_object_wrfl_llow;
		class tsp_animate_tactical_compress_wrfl_lhig;
		class tsp_animate_tactical_compress_wrfl_llow;
		class tsp_animate_tactical_portbase_wrfl_lhig;
		class tsp_animate_tactical_portbase_wrfl_llow;
		class tsp_animate_tactical_portmove_wrfl_lhig;
		class tsp_animate_tactical_portmove_wrfl_llow;
		class tsp_animate_tactical_portchill_wrfl_lhig;
		class tsp_animate_tactical_portchill_wrfl_llow;
		class tsp_animate_tactical_sprint_wrfl_lhig_in;
		class tsp_animate_tactical_sprint_wrfl_lhig_out;
		class tsp_animate_tactical_sprint_wrfl_lhig;
		class tsp_animate_tactical_sprint_wrfl_llow_in;
		class tsp_animate_tactical_sprint_wrfl_llow_out;
		class tsp_animate_tactical_sprint_wrfl_llow;

		class tsp_animate_tactical_cant_wpst_lnon;
		class tsp_animate_tactical_readybase_wpst_lhig;
		class tsp_animate_tactical_readybase_wpst_llow;
		class tsp_animate_tactical_readycombat_wpst_lhig;
		class tsp_animate_tactical_readycombat_wpst_llow;
		class tsp_animate_tactical_readyalt_wpst_lhig;
		class tsp_animate_tactical_readyalt_wpst_llow;
		class tsp_animate_tactical_friend_wpst_lhig;
		class tsp_animate_tactical_friend_wpst_llow;
		class tsp_animate_tactical_object_wpst_lhig;
		class tsp_animate_tactical_object_wpst_llow;
		class tsp_animate_tactical_compress_wpst_lhig;
		class tsp_animate_tactical_compress_wpst_llow;
		class tsp_animate_tactical_portbase_wpst_lhig;
		class tsp_animate_tactical_portbase_wpst_llow;
		class tsp_animate_tactical_portmove_wpst_lhig;
		class tsp_animate_tactical_portmove_wpst_llow;
		class tsp_animate_tactical_portchill_wpst_lhig;
		class tsp_animate_tactical_portchill_wpst_llow;
		class tsp_animate_tactical_sprint_wpst_lhig_in;
		class tsp_animate_tactical_sprint_wpst_lhig_out;
		class tsp_animate_tactical_sprint_wpst_lhig;
		class tsp_animate_tactical_sprint_wpst_llow_in;
		class tsp_animate_tactical_sprint_wpst_llow_out;
		class tsp_animate_tactical_sprint_wpst_llow;
		
		//-- Rifle
		class tsp_animate_tactical_retro_cant_wrfl_lnon: tsp_animate_tactical_cant_wrfl_lnon {};		
		class tsp_animate_tactical_retro_over_wrfl_lnon: tsp_animate_tactical_over_wrfl_lnon {};

		class tsp_animate_tactical_retro_readybase_wrfl_lhig: tsp_animate_tactical_readybase_wrfl_lhig {};
		class tsp_animate_tactical_retro_readybase_wrfl_llow: tsp_animate_tactical_readybase_wrfl_llow {};
		class tsp_animate_tactical_retro_readycombat_wrfl_lhig: tsp_animate_tactical_readycombat_wrfl_lhig {};
		class tsp_animate_tactical_retro_readycombat_wrfl_llow: tsp_animate_tactical_readycombat_wrfl_llow {};
		class tsp_animate_tactical_retro_readyalt_wrfl_lhig: tsp_animate_tactical_readyalt_wrfl_lhig {};
		class tsp_animate_tactical_retro_readyalt_wrfl_llow: tsp_animate_tactical_readyalt_wrfl_llow {};

		class tsp_animate_tactical_retro_friend_wrfl_lhig: tsp_animate_tactical_friend_wrfl_lhig {};
		class tsp_animate_tactical_retro_friend_wrfl_llow: tsp_animate_tactical_friend_wrfl_llow {};
		
		class tsp_animate_tactical_retro_object_wrfl_lhig: tsp_animate_tactical_object_wrfl_lhig {};
		class tsp_animate_tactical_retro_object_wrfl_llow: tsp_animate_tactical_object_wrfl_llow {};
		
		class tsp_animate_tactical_retro_compress_wrfl_lhig: tsp_animate_tactical_compress_wrfl_lhig {};
		class tsp_animate_tactical_retro_compress_wrfl_llow: tsp_animate_tactical_compress_wrfl_llow {};

		class tsp_animate_tactical_retro_portbase_wrfl_lhig: tsp_animate_tactical_portbase_wrfl_lhig {};
		class tsp_animate_tactical_retro_portbase_wrfl_llow: tsp_animate_tactical_portbase_wrfl_llow {};
		class tsp_animate_tactical_retro_portmove_wrfl_lhig: tsp_animate_tactical_portmove_wrfl_lhig {};
		class tsp_animate_tactical_retro_portmove_wrfl_llow: tsp_animate_tactical_portmove_wrfl_llow {};
		class tsp_animate_tactical_retro_portchill_wrfl_lhig: tsp_animate_tactical_portchill_wrfl_lhig {};
		class tsp_animate_tactical_retro_portchill_wrfl_llow: tsp_animate_tactical_portchill_wrfl_llow {};

		class tsp_animate_tactical_retro_sprint_wrfl_lhig_in: tsp_animate_tactical_sprint_wrfl_lhig_in {file = "tsp_animate\tactical\ready_wrfl_lhig.rtm"; leftHandIKCurve[] = {1};};
		class tsp_animate_tactical_retro_sprint_wrfl_lhig_out: tsp_animate_tactical_sprint_wrfl_lhig_out {file = "tsp_animate\tactical\ready_wrfl_lhig.rtm"; leftHandIKCurve[] = {1};};
		class tsp_animate_tactical_retro_sprint_wrfl_lhig: tsp_animate_tactical_sprint_wrfl_lhig {file = "tsp_animate\tactical\ready_wrfl_lhig.rtm"; leftHandIKCurve[] = {1};};
		class tsp_animate_tactical_retro_sprint_wrfl_llow_in: tsp_animate_tactical_sprint_wrfl_llow_in {mask = "weaponLeftArm"; file = "tsp_animate_retro\anim\sprint_wrfl_llow_loop.rtm"; leftHandIKCurve[] = {0,1,1,0};};
		class tsp_animate_tactical_retro_sprint_wrfl_llow_out: tsp_animate_tactical_sprint_wrfl_llow_out {mask = "weaponLeftArm"; file = "tsp_animate_retro\anim\sprint_wrfl_llow_loop.rtm"; leftHandIKCurve[] = {0,0,1,1};};
		class tsp_animate_tactical_retro_sprint_wrfl_llow: tsp_animate_tactical_sprint_wrfl_llow {mask = "weaponLeftArm"; file = "tsp_animate_retro\anim\sprint_wrfl_llow_loop.rtm"; leftHandIKCurve[] = {0};};

		//-- Pistol
		class tsp_animate_tactical_retro_cant_wpst_lnon: tsp_animate_tactical_cant_wpst_lnon {};		
		
		class tsp_animate_tactical_retro_readybase_wpst_lhig: tsp_animate_tactical_readybase_wpst_lhig {};
		class tsp_animate_tactical_retro_readybase_wpst_llow: tsp_animate_tactical_readybase_wpst_llow {};
		class tsp_animate_tactical_retro_readycombat_wpst_lhig: tsp_animate_tactical_readycombat_wpst_lhig {};
		class tsp_animate_tactical_retro_readycombat_wpst_llow: tsp_animate_tactical_readycombat_wpst_llow {};
		class tsp_animate_tactical_retro_readyalt_wpst_lhig: tsp_animate_tactical_readyalt_wpst_lhig {};
		class tsp_animate_tactical_retro_readyalt_wpst_llow: tsp_animate_tactical_readyalt_wpst_llow {};

		class tsp_animate_tactical_retro_friend_wpst_lhig: tsp_animate_tactical_friend_wpst_lhig {};
		class tsp_animate_tactical_retro_friend_wpst_llow: tsp_animate_tactical_friend_wpst_llow {};
		
		class tsp_animate_tactical_retro_object_wpst_lhig: tsp_animate_tactical_object_wpst_lhig {};
		class tsp_animate_tactical_retro_object_wpst_llow: tsp_animate_tactical_object_wpst_llow {};
		
		class tsp_animate_tactical_retro_compress_wpst_lhig: tsp_animate_tactical_compress_wpst_lhig {};
		class tsp_animate_tactical_retro_compress_wpst_llow: tsp_animate_tactical_compress_wpst_llow {};

		class tsp_animate_tactical_retro_portbase_wpst_lhig: tsp_animate_tactical_portbase_wpst_lhig {};
		class tsp_animate_tactical_retro_portbase_wpst_llow: tsp_animate_tactical_portbase_wpst_llow {};
		class tsp_animate_tactical_retro_portmove_wpst_lhig: tsp_animate_tactical_portmove_wpst_lhig {};
		class tsp_animate_tactical_retro_portmove_wpst_llow: tsp_animate_tactical_portmove_wpst_llow {};
		class tsp_animate_tactical_retro_portchill_wpst_lhig: tsp_animate_tactical_portchill_wpst_lhig {};
		class tsp_animate_tactical_retro_portchill_wpst_llow: tsp_animate_tactical_portchill_wpst_llow {};

		class tsp_animate_tactical_retro_sprint_wpst_lhig_in: tsp_animate_tactical_sprint_wpst_lhig_in {};
		class tsp_animate_tactical_retro_sprint_wpst_lhig_out: tsp_animate_tactical_sprint_wpst_lhig_out {};
		class tsp_animate_tactical_retro_sprint_wpst_lhig: tsp_animate_tactical_sprint_wpst_lhig {};
		class tsp_animate_tactical_retro_sprint_wpst_llow_in: tsp_animate_tactical_sprint_wpst_llow_in {};
		class tsp_animate_tactical_retro_sprint_wpst_llow_out: tsp_animate_tactical_sprint_wpst_llow_out {};
		class tsp_animate_tactical_retro_sprint_wpst_llow: tsp_animate_tactical_sprint_wpst_llow {};
	};
};