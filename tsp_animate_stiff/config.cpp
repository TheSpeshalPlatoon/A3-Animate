class CfgPatches {
	class tsp_animate_stiff {
		requiredAddons[] = {"tsp_core", "tsp_animate"};
		units[] = {};
	};
};

class CfgGesturesMale {
	skeletonName = "OFP2_ManSkeleton";
	class Default {};
	class States {
		class tsp_animate_tactical_cant_wrfl_lnon;
		class tsp_animate_tactical_ready_wrfl_lhig: tsp_animate_tactical_cant_wrfl_lnon {mask = "handsWeapon"; file = "tsp_animate_stiff\ready_wrfl_lhig.rtm";};
		class tsp_animate_tactical_ready_wrfl_llow: tsp_animate_tactical_ready_wrfl_lhig {file = "tsp_animate_stiff\ready_wrfl_llow.rtm";};
	};
};