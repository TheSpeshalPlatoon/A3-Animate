tsp_fnc_animate_captive = {
    params ["_unit", "_captive"];
    _unit allowSprint false; [_unit, "", "tsp_animate_captor_wnon", "tsp_common_stop", true, true, true] spawn tsp_fnc_gesture_play;
    _eh = _unit addEventHandler ["AnimStateChanged", {
        params ["_unit", "_anim"]; 
        {_anim = _anim regexReplace [_x, "wnon"]} forEach ["wrfl","wpst","wlnr","wbin"];
        {_anim = _anim regexReplace [_x, "snon"]} forEach ["sras","slow"];
        {_anim = _anim regexReplace [_x, "mrun"]} forEach ["mtac"];
        [_unit getVariable "ace_captives_escortedUnit", [_anim, 0, 0, false]] remoteExec ["switchMove"];
    }];
    {[_captive, _x] remoteExec ["disableAI", 0]} forEach ["ANIM", "MOVE"];
    [_captive, "tsp_animate_captive"] remoteExec ["playActionNow", 0]; 
    _captive attachTo [_unit, [-0.15,0.7,0]];  
    waitUntil {sleep 0.1; isNull attachedTo _captive || stance _unit == "PRONE" || !("captor" in gestureState _unit)};
    _unit setVariable ["ace_captives_isEscorting", false, true];
    _unit allowSprint true; [_unit] call tsp_fnc_gesture_stop; 
    _unit removeEventHandler ["AnimStateChanged", _eh]; 
    {[_captive, _x] remoteExec ["enableAI", 0]} forEach ["ANIM", "MOVE"]; 
    [_captive, ["ace_AmovPercMstpScapWnonDnon", 0, 0, false]] remoteExec ["switchMove"];
    sleep 0.4; [_captive, "tsp_common_stop"] remoteExec ["playActionNow", 0]; 
};

tsp_fnc_animate_carry = {
    params ["_unit", ["_duration", tsp_cba_animate_carry]];
    _target = _unit getVariable ["ace_dragging_carriedObject", objNull];
    {[_x, 10/_duration] remoteExec ["setAnimSpeedCoef"]} forEach [_unit, _target];
    sleep _duration; {[_x, 1] remoteExec ["setAnimSpeedCoef"]} forEach [_unit, _target];
    [_unit, "blockThrow", "ace_dragging", true] call ace_common_fnc_statusEffect_set;
    _position = _target getVariable ["ace_dragging_carryPosition", [0, 0, 0]];
    _direction = _target getVariable ["ace_dragging_carryDirection", 0];
    _target attachTo [_unit, _position, "LeftShoulder"];
    ["ace_common_setDir", [_target, _direction], _target] call CBA_fnc_targetEvent;
    _unit setVariable ["ace_dragging_isCarrying", true, true];
    _unit setVariable ["ace_dragging_carriedObject", _target, true];
    [ace_dragging_fnc_startCarryPFH, 0.2, [_unit, _target, time]] call CBA_fnc_addPerFrameHandler;
};

tsp_fnc_animate_clacker = {
    params ["_unit", "_range", "_explosive", "_fuze", "_clacker", ["_exit", {sleep 0.5; true}]];
    if ("shock" in _clacker) then {[_unit, "", "tsp_animate_shock_out_wnon", "\tsp_breach_shock\shock.p3d", "leftHand", [0.02,0,0], [0,0,-100], _exit, false] spawn tsp_fnc_gesture_item};
    if ("ACE_Clacker" in _clacker) then {[_unit, "", "tsp_animate_clacker", "\z\ace\addons\explosives\data\ace_m57.p3d", "left", [0.02,0,0], [0,0,-100], _exit, false] spawn tsp_fnc_gesture_item};
    sleep 0.2; [_unit, ["OMLightSwitch", 50]] remoteExec ["say3D", 0]; if (_fuze != -1) then {sleep _fuze; _explosive setDamage 1};
};

tsp_fnc_animate_grenade = {
    params ["_unit", ["_attach", "rightHand"], ["_angle", [-90,0,0]], ["_pos", [-0.06,0,0]], ["_aceThrowType", 1]];    
    if (stance _unit == "PRONE" || (currentWeapon _unit == secondaryWeapon _unit && secondaryWeapon _unit != "")) exitWith {};
    if (!isNil "tsp_object") then {[tsp_object, true] remoteExec ["hideObjectGlobal", 2]};  //-- Hide old gesture item object

    sleep 0.01; _grenade = typeOf (_unit getVariable "ace_advanced_throwing_activeThrowable");  //-- Takes a moment for ace_advanced_throwing_activeThrowable to be present

    tsp_grenade_mode = "right";
    if (currentWeapon _unit != "" && ("Chem" in _grenade || "flash" in _grenade)) then {tsp_grenade_mode = "left"; _attach = "leftHand"; _pos = [0.02,0.03,0.02]};  //-- If has weapon and throwing chem/flash  
    if ("lhig" in gestureState _unit) then {tsp_grenade_mode = "left"; _attach = "leftHand"; _pos = [0.02,0.03,0.02]};  //-- If in high ready
    if ("compress" in gestureState _unit) then {tsp_grenade_mode = "compress"};  //-- If in compress
    if ("Chem" in _grenade) then {_angle = [0,-90,0]};  //-- Chemlight model has different rotation to other nades

    [_unit, 1, "A3\Sounds_F\characters\stances\grenade_throw2.wss", 1] call tsp_fnc_animate_effect;  //-- Grenade prep sound
    [_unit, "", "tsp_animate_grenade_"+tsp_grenade_mode+"_wnon_laut_loop", getText(configFile >> "CfgAmmo" >> _grenade >> "model"), _attach, _pos, _angle, {
        !(_unit getVariable "ace_advanced_throwing_inHand") ||  //-- Cancel animation if not throwing anymore
        stance _unit == "PRONE"  //-- Cancel animation if prone
    }, false] spawn tsp_fnc_gesture_item;

    if ("animate_grenade" in gestureState _unit) exitWith {};  //-- Just replace the model, dont do the rest if we are already doing it

    //-- Wait until throw or cancelled, have to update _aceThrowType since it gets reset to 1 after throw
    _aceThrowType = 1; while {sleep 0.01; _unit getVariable "ace_advanced_throwing_inHand"} do {_aceThrowType = _unit getVariable ["ace_advanced_throwing_throwMod", 1]};

    if (!isNil "tsp_animate_throwing") then {
        _unit playActionNow ([_unit, "tsp_animate_grenade_"+tsp_grenade_mode+"_wnon_laut_"+(if (_aceThrowType > 0.5) then {"normal"} else {"high"})] call tsp_fnc_gesture_variant); 
        sleep 0.7; tsp_animate_throwing = nil;
    };    

    if (count (_unit getVariable ["tsp_gestureReturn", []]) > 0) then {(_unit getVariable ["tsp_gestureReturn", []]) spawn tsp_fnc_gesture_play};  //-- Need custom return cause throw anim
    sleep 0.1; tsp_grenade_mode = nil;
};