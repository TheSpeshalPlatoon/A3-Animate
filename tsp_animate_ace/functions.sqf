tsp_fnc_animate_captive = {
    params ["_unit", "_captive"];
    _unit allowSprint false; [_unit, "", "tsp_animate_captor_wnon", "tsp_common_stop", true, true, true] spawn tsp_fnc_gesture_play;
    _eh = _unit addEventHandler ["AnimStateChanged", {
        params ["_unit", "_anim"]; 
        {_anim = _anim regexReplace [_x, "wnon"]} forEach ["wrfl","wpst","wlnr","wbin"];
        {_anim = _anim regexReplace [_x, "snon"]} forEach ["sras","slow"];
        {_anim = _anim regexReplace [_x, "mrun"]} forEach ["mtac"];
        [_unit getVariable "ace_captives_escortedUnit", _anim] remoteExec ["playMoveNow", 0];
    }];
    {[_captive, _x] remoteExec ["disableAI", 0]} forEach ["ANIM", "MOVE"]; [_captive, "AmovPercMstpSnonWnonDnon"] remoteExec ["switchMove", 0];
    [_captive, "tsp_animate_captive"] remoteExec ["playActionNow", 0]; _captive attachTo [_unit, [-0.15,0.7,0]];  
    waitUntil {isNull attachedTo _captive || stance _unit == "PRONE"};
    _unit allowSprint true; [_unit] call tsp_fnc_gesture_stop; 
    _unit removeEventHandler ["AnimStateChanged", _eh]; 
    {[_captive, _x] remoteExec ["enableAI", 0]} forEach ["ANIM", "MOVE"]; [_captive, "ace_AmovPercMstpScapWnonDnon"] remoteExec ["switchMove", 0];
    [_captive, "tsp_common_stop"] remoteExec ["playActionNow", 0]; _unit setVariable ["ace_captives_isEscorting", false, true];
};

tsp_fnc_animate_clacker = {
    params ["_unit", "_range", "_explosive", "_fuze", "_clacker", ["_exit", {sleep 0.5; true}]];
    if ("shock" in _clacker) then {[_unit, "", "tsp_animate_shock_out_wnon", "\tsp_breach_shock\shock.p3d", "leftHand", [0.02,0,0], [0,0,-100], _exit, false] spawn tsp_fnc_gesture_item};
    if ("ACE_Clacker" in _clacker) then {[_unit, "", "tsp_animate_clacker", "\z\ace\addons\explosives\data\ace_m57.p3d", "left", [0.02,0,0], [0,0,-100], _exit, false] spawn tsp_fnc_gesture_item};
    sleep 0.2; [_unit, ["OMLightSwitch", 50]] remoteExec ["say3D", 0]; if (_fuze != -1) then {sleep _fuze; _explosive setDamage 1};
};

tsp_fnc_animate_grenade = {
    params ["_unit", ["_mode", "right"], ["_hand", "rightHand"], ["_angle", [-90,0,0]], ["_pos", [-0.06,0,0]]]; 
    tsp_animate_grenade_flag = true; sleep 0.01; tsp_animate_grenade_flag = false;
    if (!isNil "tsp_object") then {[tsp_object, true] remoteExec ["hideObjectGlobal", 2]};  //-- Hide old object
    if ((currentWeapon _unit == secondaryWeapon _unit && secondaryWeapon _unit != "") || stance _unit == "PRONE") exitWith {};
    sleep 0.1; _grenade = typeOf(_unit getVariable "ace_advanced_throwing_activeThrowable");  //-- Takes a moment
    if (currentWeapon _unit != "" && ("Chem" in _grenade || "flash" in _grenade || "lhig" in gestureState _unit)) then {_mode = "left"; _hand = "leftHand"; _pos = [0.02,0.03,0.02]};
    if ("compress" in gestureState _unit) then {_mode = "compress"};
    if ("Chem" in _grenade) then {_angle = [0,-90,0]};
    [_unit, "", "tsp_animate_grenade_"+_mode+"_wnon_laut_loop", getText(configFile >> "CfgAmmo" >> _grenade >> "model"), _hand, _pos, _angle, {!(_unit getVariable "ace_advanced_throwing_inHand") || stance _unit == "PRONE"}, false] spawn tsp_fnc_gesture_item;
    [_unit, 1, "A3\Sounds_F\characters\stances\grenade_throw2.wss", 1] call tsp_fnc_animate_effect;
    while {sleep 0.001; _unit getVariable "ace_advanced_throwing_inHand" && !tsp_animate_grenade_flag} do {tsp_ace_throwType = _unit getVariable ["ace_advanced_throwing_throwMod", 1]};  //-- Have to do this cause ace_advanced_throwing_throwMod resets
    if (isNil "tsp_animate_throwing" || tsp_animate_grenade_flag) exitWith {};  //-- Throw canceled
    _unit playActionNow ([_unit, "tsp_animate_grenade_"+_mode+"_wnon_laut_"+(if (tsp_ace_throwType > 0.5) then {"normal"} else {"high"})] call tsp_fnc_gesture_variant);
    tsp_animate_throwing = nil; sleep 0.7;
    if (count (_unit getVariable ["tsp_gestureReturn", []]) > 0 && "grenade" in gestureState _unit) then {(_unit getVariable ["tsp_gestureReturn", []]) spawn tsp_fnc_gesture_play};
};
//ACE_player getVariable "ace_advanced_throwing_throwMod"