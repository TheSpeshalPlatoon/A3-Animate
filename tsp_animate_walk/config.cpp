class CfgPatches {
	class tsp_animate_walk {
		//addonRootClass = "A3_Anims_F";
		requiredAddons[] = {
			"A3_Anims_F",
			"A3_Anims_F_AoW",
			"A3_Anims_F_Bootcamp",
			"A3_Anims_F_Config_Sdr",
			"A3_Anims_F_Config_Sdr_WeaponSwitching",
			"A3_Anims_F_Data",
			"A3_Anims_F_Enoch",
			"A3_Anims_F_EPA",
			"A3_Anims_F_EPC",
			"A3_Anims_F_Exp",
			"A3_Anims_F_Exp_A",
			"A3_Anims_F_Exp_Revive",
			"A3_Anims_F_Heli",
			"A3_Anims_F_Jets",
			"A3_Anims_F_Kart",
			"A3_Anims_F_Mark",
			"A3_Anims_F_Mark_Deployment",
			"A3_Anims_F_Mod"
		};
		units[] = {};
	};
	class tsp_animate_walk {requiredAddons[] = {"tsp_animate"}; units[] = {};};
};

//-- ANIMATIONS
class CfgMovesBasic {
	class Default;
	class DefaultDie;
	class ManActions;
	class Actions {
		class NoActions;
		class RifleBaseLowStandActions: NoActions {
			WalkF = "AmovPercMwlkSlowWrflDf";
			WalkLF = "AmovPercMwlkSlowWrflDfl";
			WalkRF = "AmovPercMwlkSlowWrflDfr";
			WalkL = "AmovPercMwlkSlowWrflDl";
			WalkR = "AmovPercMwlkSlowWrflDr";
			WalkLB = "AmovPercMwlkSlowWrflDbl";
			WalkRB = "AmovPercMwlkSlowWrflDbr";
			WalkB = "AmovPercMwlkSlowWrflDb";
			PlayerWalkF = "AmovPercMwlkSlowWrflDf";
			PlayerWalkLF = "AmovPercMwlkSlowWrflDfl";
			PlayerWalkRF = "AmovPercMwlkSlowWrflDfr";
			PlayerWalkL = "AmovPercMwlkSlowWrflDl";
			PlayerWalkR = "AmovPercMwlkSlowWrflDr";
			PlayerWalkLB = "AmovPercMwlkSlowWrflDbl";
			PlayerWalkRB = "AmovPercMwlkSlowWrflDbr";
			PlayerWalkB = "AmovPercMwlkSlowWrflDb";
			SlowF = "AmovPercMrunSlowWrflDf";
			SlowLF = "AmovPercMrunSlowWrflDfl";
			SlowRF = "AmovPercMrunSlowWrflDfr";
			SlowL = "AmovPercMrunSlowWrflDl";
			SlowR = "AmovPercMrunSlowWrflDr";
			SlowLB = "AmovPercMrunSlowWrflDbl";
			SlowRB = "AmovPercMrunSlowWrflDbr";
			SlowB = "AmovPercMrunSlowWrflDb";
			PlayerSlowF = "AmovPercMrunSlowWrflDf";
			PlayerSlowLF = "AmovPercMrunSlowWrflDfl";
			PlayerSlowRF = "AmovPercMrunSlowWrflDfr";
			PlayerSlowL = "AmovPercMrunSlowWrflDl";
			PlayerSlowR = "AmovPercMrunSlowWrflDr";
			PlayerSlowLB = "AmovPercMrunSlowWrflDbl";
			PlayerSlowRB = "AmovPercMrunSlowWrflDbr";
			PlayerSlowB = "AmovPercMrunSlowWrflDb";
			TactF = "AmovPercMtacSlowWrflDf";
			TactLF = "AmovPercMtacSlowWrflDfl";
			TactRF = "AmovPercMtacSlowWrflDfr";
			TactL = "AmovPercMtacSlowWrflDl";
			TactR = "AmovPercMtacSlowWrflDr";
			TactLB = "AmovPercMtacSlowWrflDbl";
			TactRB = "AmovPercMtacSlowWrflDbr";
			TactB = "AmovPercMtacSlowWrflDb";
			PlayerTactF = "AmovPercMtacSlowWrflDf";
			PlayerTactLF = "AmovPercMtacSlowWrflDfl";
			PlayerTactRF = "AmovPercMtacSlowWrflDfr";
			PlayerTactL = "AmovPercMtacSlowWrflDl";
			PlayerTactR = "AmovPercMtacSlowWrflDr";
			PlayerTactLB = "AmovPercMtacSlowWrflDbl";
			PlayerTactRB = "AmovPercMtacSlowWrflDbr";
			PlayerTactB = "AmovPercMtacSlowWrflDb";
		};
	};
};

class CfgMovesMaleSdr: CfgMovesBasic {
    class States {
		class AmovPercMevaSrasWrflDf; 
		class AmovPercMevaSrasWrflDfr;
		class AmovPercMevaSlowWrflDf: AmovPercMevaSrasWrflDf {interpolateTo[] += {"amovpercmtacslowwrfldf",0.01,"amovpercmtacslowwrfldfr",0.01,"amovpercmtacslowwrfldfl",0.01};};  //0.85
		class AmovPercMevaSlowWrflDfr: AmovPercMevaSrasWrflDfr {interpolateTo[] += {"amovpercmtacslowwrfldf",0.01,"amovpercmtacslowwrfldfr",0.01,"amovpercmtacslowwrfldfl",0.01};};  //0.85
		class AmovPercMevaSlowWrflDfl: AmovPercMevaSrasWrflDf {interpolateTo[] += {"amovpercmtacslowwrfldf",0.01,"amovpercmtacslowwrfldfr",0.01,"amovpercmtacslowwrfldfl",0.01};};  //0.85
	};
};

//class CfgMovesMaleSdr: CfgMovesBasic {
    //class States {
		//class AmovPercMstpSrasWrflDnon;
		//class AmovPercMwlkSrasWrflDf: AmovPercMstpSrasWrflDnon {speed = 1.38;};  //0.85
		//class AmovPercMwlkSrasWrflDfr: AmovPercMwlkSrasWrflDf {speed = 1.38;};  //0.85
		//class AmovPercMwlkSrasWrflDfl: AmovPercMwlkSrasWrflDf {speed = 1.38;};  //0.85
		//class AmovPercMwlkSrasWrflDl: AmovPercMwlkSrasWrflDf {speed = 0.6;};  //0.411523
		//class AmovPercMwlkSrasWrflDr: AmovPercMwlkSrasWrflDf {speed = 0.6;};  //0.362319
		//class AmovPercMstpSrasWpstDnon;
		//class AmovPercMwlkSrasWpstDf: AmovPercMstpSrasWpstDnon {speed = 0.6;};  //0.463483
		//class AmovPercMwlkSrasWpstDfr: AmovPercMwlkSrasWpstDf {speed = 0.6;};  //0.463483
		//class AmovPercMwlkSrasWpstDfl: AmovPercMwlkSrasWpstDf {speed = 0.6;};  //0.463483
		//class AmovPercMwlkSrasWpstDl: AmovPercMwlkSrasWpstDf {speed = 0.6;};  //0.400049;
		//class AmovPercMwlkSrasWpstDr: AmovPercMwlkSrasWpstDf {speed = 0.6;};  //0.406341;
	//};
//};