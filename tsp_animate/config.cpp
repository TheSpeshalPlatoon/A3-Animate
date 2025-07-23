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
	class tsp_sling: CBA_MiscItem {scope = 2; displayName = "Sling"; picture = "\tsp_animate\gui\sling.paa"; model = "tsp_animate\sling.p3d"; class ItemInfo: CBA_MiscItem_ItemInfo {mass = 1;};};
	//class tsp_sling_1point: tsp_sling {displayName = "1-Point Sling";};
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

		tsp_animate_ladder[] = {"tsp_animate_ladder", "Gesture"};
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
		class tsp_animate_dab_loop: tsp_animate_bird_loop {file = "tsp_animate\emotes\dab_loop.rtm"; mask = "bothArms"; rightHandIKCurve[] = {1}; leftHandIKCurve[] = {1};};
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
		class tsp_animate_suicide_wpst_in: tsp_animate_breach {leftHandIKCurve[] = {0}; file = "tsp_animate\gestures\suicide_wpst_in.rtm"; mask = "upperTorsoWeak"; speed = 0.3; cancel = true;};
		class tsp_animate_suicide_wpst_loop: tsp_animate_suicide_wpst_in {file = "tsp_animate\gestures\suicide_wpst_loop.rtm"; looped = true;};
		class tsp_animate_suicide_wrfl_in: tsp_animate_suicide_wpst_in {file = "tsp_animate\gestures\suicide_wrfl_in.rtm"; mask = "weaponSpine"; leftHandIKCurve[] = {1};};
		class tsp_animate_suicide_wrfl_loop: tsp_animate_suicide_wrfl_in {file = "tsp_animate\gestures\suicide_wrfl_loop.rtm"; looped = true;};

		//-- Inspect
		class tsp_animate_inspect_wrfl: tsp_animate_suicide_wrfl_in {file = "tsp_animate\gestures\inspect_wrfl.rtm";};
		class tsp_animate_inspect_wpst: tsp_animate_suicide_wpst_in {file = "tsp_animate\gestures\inspect_wpst.rtm";};
		
		//-- Throw
		class tsp_animate_throw_wrfl: GestureNo {file = "tsp_animate\gestures\throw_wrfl.rtm"; speed = 0.5; mask="weaponSpine"; looped = true; cancel = true; enableOptics = 0;};
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

		class tsp_animate_tactical_friend_wrfl_lhig: tsp_animate_tactical_readybase_wrfl_lhig {file = "tsp_animate\tactical\friend_wrfl_lhig.rtm"; mask = "handsWeapon";};
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

		class tsp_animate_ladder: tsp_animate_tactical_compress_wpst_lhig {file = "tsp_animate\gestures\ladder.rtm"; mask = "rightArmHead";};
	};
	class BlendAnims {
		readyRifle[] = {"weapon",1,"Spine",0.3,"Spine1",0.2,"Spine2",0.1,"Spine3",0,"Neck",0,"RightShoulder",0.2,"RightArm",0.2,"RightArmRoll",0.2,"RightForeArm",0.2};	
		readyRifleAndArm[] = {"weapon",1,"Spine",0.2,"Spine1",0.1,"Spine2",0,"Spine3",0,"Neck",0,"RightShoulder",1,"RightArm",1,"RightArmRoll",1,"RightForeArm",1};
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

		class mountside: default {speed = 0.3;};
		class dismountside: default {speed = 0.2;};
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