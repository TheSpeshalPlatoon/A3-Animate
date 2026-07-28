class CfgPatches {
	class tsp_animate_ladder {
		requiredAddons[] = {"A3_Data_F_Sams_Loadorder"};
		units[] = {};
	};
};

class CfgAnimation {ladderSpeed = "1.3";};

class CfgMovesBasic;
class CfgMovesMaleSdr: CfgMovesBasic {
	class States {
		class LadderCivilStatic;
		class LadderCivilUpLoop: LadderCivilStatic {speed = 1.3;};
		class LadderCivilDownLoop: LadderCivilUpLoop {speed = 1.3;};
		class LadderRifleUpLoop: LadderCivilUpLoop {speed = 1.3;};
		class LadderRifleDownLoop: LadderCivilDownLoop {speed = 1.3;};
		class ladderPistolUpLoop: LadderRifleUpLoop {speed = 1.3;};	
		class ladderPistolDownLoop: LadderRifleDownLoop {speed = 1.3;};
	};
};