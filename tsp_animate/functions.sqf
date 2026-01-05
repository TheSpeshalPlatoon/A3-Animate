tsp_fnc_animate_effect = {
    params ["_unit", ["_shake", 1], ["_sound", "A3\Sounds_F\characters\stances\adjust_short"+str(round random 5 max 1)+".wss"], ["_volume", 0.1], ["_distance", 20]];
    playSound3D [_sound, _unit, true, getPosASL _unit, _volume*tsp_cba_animate_sound, 1, _distance];  //concrete_adjust_stand_side//adjust_short//lift_rifle
    if (isPlayer _unit) then {[_shake*tsp_cba_animate_shake, 2, 5] remoteExec ["tsp_fnc_shake", _unit]};
};

tsp_fnc_animate_dance = {
    params ["_unit", "_animation"];
    [_unit, _animation] remoteExec ["playMoveNow", 0]; waitUntil {animationState _unit == _animation || !alive _unit};
    while {sleep 0.5; animationState _unit == _animation} do {_unit action ["SWITCHWEAPON", _unit, _unit, -1]; _unit selectWeapon handgunWeapon _unit};
};

tsp_fnc_animate_suicide = {
    params ["_unit"];
    [_unit, "tsp_animate_suicide_wnon_in", "tsp_animate_suicide_wnon_loop"] spawn tsp_fnc_gesture_play;
    waitUntil {"suicide" in gestureState _unit || !alive _unit};
    _firedEH = _unit addEventHandler ["Fired", {params ["_unit"]; _unit setHitPointDamage ["HitHead", 1]; [_unit, "head", 999] call tsp_fnc_hitpoint_damage}];
    waitUntil {!("suicide" in gestureState _unit) || !alive _unit}; 
    _unit removeEventHandler ["Fired", _firedEH];
};

tsp_fnc_animate_inspect = {
    params ["_unit"];
    [_unit, "", "tsp_animate_inspect_wnon"] spawn tsp_fnc_gesture_play;
    if (!isNil "ace_reload_fnc_displayAmmo") then {_unit call ace_reload_fnc_displayAmmo; sleep 2; [_unit, currentWeapon _unit] call ace_overheating_fnc_displayTemperature};
};

tsp_fnc_animate_throw = {
    params ["_unit", ["_fancy", false], ["_force", 0.1], ["_forceMax", 8], ["_torque", 0.15]]; if (currentWeapon _unit == "") exitWith {};
    if ("throw" in gestureState _unit) exitWith {[_unit] call tsp_fnc_gesture_stop};  //-- Toggle
    if (_fancy) then {[_unit, "", "tsp_animate_throw_wnon", "tsp_common_stop", true, true] spawn tsp_fnc_gesture_play};  //-- Idle animation
    if (_fancy) then {waitUntil {sleep 0.1; inputMouse 0 == 2 || !("throw" in gestureState _unit)}};  //-- Wait for mouse hold or cancelled
    if (_fancy && !("throw" in gestureState _unit)) exitWith {};  //-- If cancelled - leave
    if (_fancy) then {[_unit, "tsp_animate_throw_wnon_wind", "tsp_animate_throw_wnon_wound", "tsp_common_stop", true, true] spawn tsp_fnc_gesture_play};
    if (_fancy) then {while {sleep 0.1; inputMouse 0 == 2 && _force < _forceMax} do {_force = _force + 0.5}};  //-- As winding anim plays, turn up the force
    if (_fancy) then {waitUntil {inputMouse 0 != 2}}; if (_fancy && !("throw" in gestureState _unit)) exitWith {};  //-- Wait for mouse release, if cancelled - leave
    [_unit, "", "tsp_animate_throw_wnon_out", "", true, true] spawn tsp_fnc_gesture_play;  //-- Throw animation
    sleep 0.1; _holder = [_unit, currentWeapon _unit] call tsp_fnc_throw;
    [_holder, _unit vectorModelToWorld [0, _force, _force]] remoteExec ["setVelocity", _unit]; 
    _holder addTorque (call CBA_fnc_randomVector3D vectorMultiply _torque);
};

tsp_fnc_animate_attachment = {
	params ["_unit", "_item", ["_mode", "mount"], ["_itemsNew", []], ["_itemsOld", []], ["_suffix", ""]];
    if (currentWeapon _unit == "" || currentWeapon _unit != tsp_animate_attach#0 || isNull (findDisplay 602) || !(stance _unit in ["STAND", "CROUCH"])) exitWith {};
    if (currentWeapon _unit == primaryWeapon _unit) then {_itemsNew = primaryWeaponItems _unit; _itemsOld = tsp_animate_attach#1};
    if (currentWeapon _unit == secondaryWeapon _unit) then {_itemsNew = secondaryWeaponItems _unit; _itemsOld = tsp_animate_attach#2};
    if (currentWeapon _unit == handgunWeapon _unit) then {_itemsNew = handgunItems _unit; _itemsOld = tsp_animate_attach#3; _suffix = "pistol"};
	if (_itemsOld#0 isNotEqualTo _itemsNew#0) then {_unit playAction ("gesture" + _mode + "muzzle" + _suffix)};
	if (_itemsOld#1 isNotEqualTo _itemsNew#1) then {_unit playAction (_mode + "side" + _suffix)};
	if (_itemsOld#2 isNotEqualTo _itemsNew#2) then {_unit playAction (_mode + "optic" + _suffix)};
	if (_itemsOld#3 isNotEqualTo _itemsNew#3) then {_unit playAction (_mode + "side" + _suffix)};
	tsp_animate_attach = [currentWeapon _unit, primaryWeaponItems _unit, secondaryWeaponItems _unit, handgunItems _unit];
};

tsp_fnc_animate_nvg = {
    params ["_unit", ["_gesture", "tsp_animate_nightvision_up"], ["_vision", currentVisionMode (_this#0)]]; 
    if ((cameraView == "GUNNER" && [_unit] call tsp_fnc_vision)) exitWith {}; [_unit] call tsp_fnc_animate_effect;
    [_unit, "", if (_vision == 1) then {"tsp_animate_nightvision_up"} else {"tsp_animate_nightvision_down"}, "", "tsp" in gestureState _unit, false, true] spawn tsp_fnc_gesture_play;
};

tsp_fnc_animate_walk = {
    params ["_unit", "_anim", ["_speed", -1], ["_min", 0.5]]; if (!tsp_cba_animate_walk) exitWith {};
    if (_speed != -1) then {tsp_cba_animate_walk_default = (tsp_cba_animate_walk_default + _speed) min tsp_cba_animate_walk_max max _min};  //-- Adjuster
    if ("mwlksras" in _anim) exitWith {tsp_walk_set = true; _unit setAnimSpeedCoef tsp_cba_animate_walk_default};
    if ("mwlkslow" in _anim) exitWith {tsp_walk_set = true; _unit setAnimSpeedCoef tsp_cba_animate_walk_lower};
    if (!("mwlksras" in _anim) && !("mwlkslow" in _anim) && !(isNil "tsp_walk_set")) then {tsp_walk_set = nil; _unit setAnimSpeedCoef 1};
};

tsp_fnc_animate_sling = {  //-- FUCK FUCK FUCK FUCK I DONT LIKE IT MAKE IT GO AWAY
    params ["_unit", ["_sling", false], ["_holster", false], ["_drawPistol", false], ["_drawLauncher", false], ["_unsling", false], ["_time", 0], ["_slung", (_this#0) getVariable ["tsp_slung", []]]];
    _knife = if (!isNil "tsp_fnc_melee_weapon") then {!([_unit, handGunWeapon _unit] call tsp_fnc_melee_weapon in ["", "pistol"])} else {false};
    if ("sling" in gestureState _unit) exitWith {};
    if (_sling) then {
        if (_drawPistol && !_knife && tsp_cba_animate_sling_style == "adhd") then {  //-- Chamber check
            [_unit, "tsp_animate_sling_check"] remoteExec ["playActionNow"];
            playSound3D ["A3\Sounds_F\weapons\Other\dry5-rifle.wss", _unit, false, getPosASL _unit, 5, 1, 10];
            _time = _time + 0.1;
        };
        tsp_future pushBack [time + _time, [_unit], {params ["_unit"]; [_unit, "tsp_animate_sling_sling"] remoteExec ["playActionNow"]}];  //-- Play animation
        tsp_future pushBack [time + _time + 0.2, [_unit], {params ["_unit"]; _holder = [_unit, primaryWeapon _unit, true, false, "tsp_holder2"] call tsp_fnc_throw; _unit setVariable ["tsp_holder", _holder]}];  //-- Throw weapon, hide it
        tsp_future pushBack [time + _time + 0.2, [_unit], {  //-- Attach it, orient it
            params ["_unit"]; 
            (_unit getVariable "tsp_holder") setDamage 1;
            (_unit getVariable "tsp_holder") attachTo [_unit, tsp_cba_animate_sling_pos#0, "Spine3", true]; 
            [_unit getVariable "tsp_holder", tsp_cba_animate_sling_pos#1] call BIS_fnc_setObjectRotation;
        }];
        tsp_future pushBack [time + _time + 0.2, [_unit, !_drawPistol && !_drawLauncher && !_unsling], {  //-- Remove weapon and unhide chest weapon
            params ["_unit", "_unarmed"];
            _rifle = (getUnitLoadout _unit)#0; _unit removeWeapon (primaryWeapon _unit);
            [_unit getVariable "tsp_holder", false] remoteExec ["hideObjectGlobal"];
            if (_unarmed) then {_unit action ["SWITCHWEAPON", _unit, _unit, -1]};
            if (_unarmed && vehicle _unit == _unit) then {[_unit, [animationState _unit regexReplace ["wrfl", "wnon"] regexReplace ["sras", "snon"] regexReplace ["slow", "snon"], 0, 0, false]] remoteExec ["switchMove"]};
            if (_unarmed) then {[_unit, "tsp_common_stop"] remoteExec ["playActionNow"]};
            _unit setVariable ["tsp_slung", [_unit getVariable "tsp_holder", _rifle]];
        }];
        _time = _time + 0.2;
    };
    if (_holster) then {
        [_unit, handgunWeapon _unit] remoteExec ["selectWeapon"];
        [_unit, "tsp_animate_sling_" + (if (_knife) then {"sheath"} else {"holster"})] remoteExec ["playActionNow"];
        _unit spawn {sleep 0.2; playSound3D ["A3\Sounds_F\weapons\Closure\firemode_changer_1.wss", _this, false, getPosASL _this, 5, 1, 5]};
        _time = 0.7;
    };
    if (_drawPistol) then {
        tsp_future pushBack [time + _time, [_unit], {
            params ["_unit"];
            //if (vehicle _unit == _unit) then {[_unit, [animationState _unit regexReplace ["wrfl", "wpst"], 0, 0, false]] remoteExec ["switchMove"]};
            if (vehicle _unit == _unit) then {[_unit, [animationState _unit regexReplace ["wrfl", "wpst"]]] remoteExec ["switchMove"]};
            if (_knife) exitWith {[_unit, "ready"] spawn tsp_fnc_melee_action};
            [_unit, "tsp_animate_sling_draw" + (if (tsp_cba_animate_sling_style == "israeli") then {"_israeli"} else {""})] remoteExec ["playActionNow"];
            if (tsp_cba_animate_sling_style == "israeli") then {playSound3D ["A3\Sounds_F\weapons\Other\reload_bolt_1.wss", _unit, false, getPosASL _unit, 5, 1, 10]};
        }];
        //tsp_future pushBack [time + _time + 0.01, [_unit], {params ["_unit"]; if (vehicle _unit == _unit) then {[_unit, animationState _unit] remoteExec ["switchMove"]}}];
    };
    if (_drawLauncher) then {
        tsp_future pushBack [time + _time, [_unit], {
            params ["_unit"];
            if (vehicle _unit == _unit) then {[_unit, [animationState _unit regexReplace ["wrfl", "wlnr"], 0, 0, false]] remoteExec ["switchMove"]};
            [_unit, secondaryWeapon _unit] remoteExec ["selectWeapon"];
            [_unit, "tsp_animate_sling_unlaunch"] remoteExec ["playActionNow"];
        }];
    };
    if (_unsling) then {
        if (currentWeapon _unit == secondaryWeapon _unit && secondaryWeapon _unit != "") then {[_unit, "tsp_animate_sling_launch"] remoteExec ["playActionNow"]; _time = 1};
        if (currentWeapon _unit == binocular _unit && binocular _unit != "") then {[_unit, "tsp_animate_sling_unbino"] remoteExec ["playActionNow"]; _time = 0.7};
        tsp_future pushBack [time + _time, [_unit, _sling, _slung], {
            params ["_unit", "_sling", "_slung"]; _slung params ["_holder", "_rifle"]; _rifle params ["_class", "_suppressor", "_pointer", "_optic", "_magazine1", "_magazine2", "_bipod"];
            _unit addWeapon _class; {_unit addPrimaryWeaponItem _x} forEach [_suppressor, _pointer, _optic, _bipod];          //-- Add weapon and attachments
            _weaponItems = (weaponsItems _unit select {_x#0 == _class})#0; deleteVehicle _holder;                            //-- Get weapon items (including any magazines that were auto-loaded)
            {if (count _x > 0) then {_unit addWeaponItem [_class, [_x#0, _x#1], true]}} forEach [_magazine1, _magazine2];   //-- Load correct magazine into weapon
            {if (count _x == 0) then {_unit removePrimaryWeaponItem ((getUnitLoadout _unit#0#(4+_forEachIndex)))#0}} forEach [_magazine1, _magazine2]; //-- If mag is empty, remove auto loaded magazine
            {if (count _x > 0) then {_unit addMagazine [_x#0, _x#1]}} forEach [_weaponItems#4, _weaponItems#5];           //-- Return auto-loaded magazine to inventory
            if (vehicle _unit == _unit && stance _unit == "CROUCH") then {[_unit, "amovpknlmstpslowwrfldnon_amovpknlmstpsraswrfldnon"] remoteExec ["switchMove"]};
            if (vehicle _unit == _unit && stance _unit != "CROUCH") then {[_unit, "amovpercmstpslowwrfldnon_amovpercmstpsraswrfldnon"] remoteExec ["switchMove"]};
            [_unit, primaryWeapon _unit] remoteExec ["selectWeapon"];
            if (_sling) then {[_unit, "tsp_animate_sling_swap"] remoteExec ["playActionNow"]} else {_unit setVariable ["tsp_slung", []]};  //-- Dont overwrite if we slung a rifle beforehand
        }]
    };
};

tsp_fnc_animate_sling_actions = {
    params ["_unit", ["_common", "[currentWeapon playa, primaryWeapon playa, handgunWeapon playa, playa getVariable ['tsp_slung',[]]] params ['_current', '_primary', '_handgun', '_slung']; tsp_cba_animate_sling_scroll && stance playa in ['STAND', 'CROUCH'] && "]];
    _unit addAction ["Sling Rifle", {[playa, true] spawn tsp_fnc_animate_sling}, nil, 0, false, true, "", (_common + "_current == _primary && _primary != '' && count _slung < 1 && 'tsp_sling' in items playa"), 0.1];
    _unit addAction ["Unsling Rifle", {[playa, false, currentWeapon playa == handgunWeapon playa, false, false, true] spawn tsp_fnc_animate_sling}, nil, 0, false, true, "", (_common + "_primary == '' && count _slung > 1"), 0.1];
    _unit addAction ["Swap Rifles", {[playa, true, false, false, false, true] spawn tsp_fnc_animate_sling}, nil, 0, false, true, "", (_common + "_current == _primary && _primary != '' && count _slung > 0 && 'tsp_sling' in items playa"), -.1];
};

tsp_fnc_animate_drop = {
    params ["_unit", ["_class", "Chemlight_green"]];
    if !((_class in magazines _unit || tsp_cba_animate_drop_infinite) && !("chemlight" in gestureState _unit)) exitWith {};
    _interupt = [gestureState _unit] call tsp_fnc_gesture_sanitize == "" || ("tsp" in gestureState _unit && gestureState _unit call tsp_fnc_gesture_looped);
    [_unit, "", "tsp_animate_chemlight_wnon_laut", "", _interupt, true, true] spawn tsp_fnc_gesture_play;
    if (!tsp_cba_animate_drop_infinite) then {_unit removeMagazine _class}; 
    _chemlight = (if (_class == "ACE_Chemlight_IR") then {"ACE_Chemlight_IR_Dummy"} else {_class}) createVehicle [0,0,0]; 
    sleep 0.2; _chemlight attachTo [_unit, [0,0,0], "LeftHand", true]; 
    sleep 0.1; [_unit, 1, "tsp_animate\snd\chemlight.ogg", 0.5] call tsp_fnc_animate_effect; 
    sleep 0.4; detach _chemlight;
};

tsp_fnc_animate_tap = {
    params ["_unit", ["_target", objNull], ["_side", -1], ["_mode", if ((getCameraViewDirection (_this#0))#2 < -0.2) then {"leg"} else {"shoulder"}]];
    _targets = [_unit, eyePos _unit, [0,15,30,45,60,-15,-30,-45,-60], 3, getCameraViewDirection _unit] call tsp_fnc_obstruction select {alive (_x#0) && _x#0 isKindOf "CAManBase"};
    if (_target isEqualTo objNull && count _targets > 0) then {_target = _targets#0#0};
    if (_target isEqualTo objNull || "leg" in gestureState _unit || "shoulder" in gestureState _unit) exitWith {};
    if (_side == -1) then {_side = [0,1] select([ACE_player, _target] call BIS_fnc_relativeDirTo < 180)};
    [_unit, "", "tsp_animate_"+_mode+"_wnon_laut", "", "tsp" in gestureState _unit, true, true] spawn tsp_fnc_gesture_play;
    [[name _unit, "Squeezed your " + (["right", "left"] select _side) + " " + _mode], tsp_fnc_hint] remoteExec ["call", _target];
    [_unit, 5, "", 0] call tsp_fnc_animate_effect; sleep 0.3; 
    [_target, 5, "A3\Sounds_F\characters\footsteps\int_carpet\carpet_int_sprint_HPF_"+str(round random 8 max 1)+".wss", 1] call tsp_fnc_animate_effect;
};

tsp_fnc_animate_door = {
    params ["_unit", ["_mode", "door"]];
    if (_mode == "door" && ("compress" in gestureState _unit || "object" in gestureState _unit || "cant" in gestureState _unit)) then {_mode = "doorcompress"};
    [_unit, "", "tsp_animate_"+_mode+"_wnon_laut", "tsp_common_stop", "tsp" in gestureState _unit, true, true] spawn tsp_fnc_gesture_play; [_unit] call tsp_fnc_animate_effect;
};

tsp_fnc_animate_scroll = {
    params ["_unit", ["_mode", "scrollUp"]]; if (!isNil "tsp_tactical_delay") exitWith {};
    getArray (configFile >> "CfgGesturesMale" >> "States" >> gestureState _unit >> _mode) params [["_nextMode", ""], ["_nextLevel", ""]];
    if ("ready" in _nextMode && tsp_animate_combat && stance _unit == "STAND") then {_nextMode = "readycombat"};
    if ("ready" in _nextMode && !tsp_animate_combat && tsp_animate_walk && stance _unit == "STAND") then {_nextMode = "readyalt"};
    if (_nextMode != "") then {[_unit, "", "tsp_animate_tactical_"+_nextMode+"_wnon_"+_nextLevel, "tsp_common_stop", true, true, false] spawn tsp_fnc_gesture_play};
    tsp_tactical_delay = true; sleep 0.08; tsp_tactical_delay = nil; 
};

tsp_fnc_animate_stop = {
    params ["_unit", ["_aim", false], ["_compress", false], ["_cant", false], ["_over", false], ["_gesture", gestureState (_this#0)]];
    if (!("tactical" in _gesture) || (!_compress && "compress" in _gesture) || (!_cant && "cant" in _gesture) || (!_over && "over" in _gesture)) exitWith {};
    if (("friend" in _gesture) || ("object" in _gesture) || ("door" in _gesture)) exitWith {};
    [_unit] call tsp_fnc_gesture_stop; [_unit] call tsp_fnc_animate_effect;
    if (_aim && cameraView == "INTERNAL") then {_unit switchCamera "GUNNER"}; 
};

tsp_fnc_animate_gate = {
    ("amov" in animationState _this || "aadj" in animationState _this || "aovr" in animationState _this) && !("salute" in animationState _this) && 
    ("tactical" in gestureState _this || "melee" in gestureState _this || [gestureState _this] call tsp_fnc_gesture_sanitize == "") &&
    !("melee" in currentWeapon _this) && !(currentWeapon _this in [binocular _this, secondaryWeapon _this]) &&
    !(cameraView == "GUNNER" && ([_this] call tsp_fnc_vision || count (primaryWeaponItems _this select {_x in tsp_cba_animate_black}) > 0)) &&
    vehicle _this == _this && stance _this in ["STAND","CROUCH"] && tsp_cba_animate_tactical
};

tsp_fnc_animate_tactical = {
    params ["_unit", ["_mode", ""], ["_level", "laut"], ["_return", false], ["_style", tsp_cba_animate_style], ["_weapon", currentWeapon (_this#0) call BIS_fnc_itemType], ["_modeO", _this#1], ["_out", "tsp_common_stop"]]; 
    if !(_unit call tsp_fnc_animate_gate) exitWith {if ("tactical" in gestureState _unit) then {[_unit] call tsp_fnc_gesture_stop}};
    
    if (tsp_cba_animate_sprint && "sprint" in gestureState _unit && !("percmeva" in animationState _unit)) exitWith {[_unit] call tsp_fnc_gesture_stop};
    if (tsp_cba_animate_sprint && "tactical" in gestureState _unit && !("sprint" in gestureState _unit) && "percmeva" in animationState _unit) then {_mode = "sprint"; _return = true};
    if (tsp_cba_animate_sprint && _mode == "sprint" && "lhig" in gestureState _unit && !("slow" in animationState _unit)) then {_out = "tsp_animate_tactical_"+_style+"sprint_wnon_laut_out"};

    if (_mode == "ready" || (_mode == "" && "tactical" in gestureState _unit && ("ready" in gestureState _unit || "port" in gestureState _unit))) then {
        _mode = "readybase";
        if (tsp_animate_combat && stance _unit == "STAND") then {_mode = "readycombat"};
        if (!tsp_animate_combat && tsp_animate_walk && stance _unit == "STAND") then {_mode = "readyalt"};
        _port = "slow" in animationState _unit && (stance _unit == "STAND" || speed _unit == 0);
        if (_port && "mtac" in animationState _unit) then {_mode = "portmove"};
        if (_port && "mwlk" in animationState _unit) then {_mode = "portmove"};
        if (_port && "mstp" in animationState _unit) then {_mode = if (tsp_animate_combat) then {"portbase"} else {"portchill"}};
        if (_port && ("mrun" in animationState _unit || "_ver2" in animationState _unit)) then {_mode = "portchill"};
    };

    //-- Toggles, decide whether stop or obstruct later
    if (_modeO != "" && _modeO in gestureState _unit) then {_mode = "stop"}; 
    if (_modeO == "ready" && ("ready" in gestureState _unit || "port" in gestureState _unit)) then {_mode = "stop"};
       
    if (_mode in ["", "stop"] && tsp_cba_animate_poll > 0) then {
        _length = ([_unit] call tsp_fnc_length) max 0.7; if ("animate_tactical" in gestureState _unit) then {_length = _length + 0.2};
        _dir = _unit weaponDirection currentWeapon _unit; if ("animate_tactical" in gestureState _unit) then {_dir = if (freelook) then {vectorDirVisual _unit} else {getCameraViewDirection _unit}};
        _friends = [_unit, _unit modelToWorldWorld (_unit selectionPosition ["Neck", "Memory"]), [0,3,-5,-10], _length * tsp_cba_animate_friend, _dir] call tsp_fnc_obstruction;
        _friends = _friends select {[side group (_x#0), side group _unit] call BIS_fnc_sideIsFriendly && (_x#0) isKindOf "Man"};
        _objects = [_unit, eyePos _unit, [0], _length * tsp_cba_animate_object, _dir] call tsp_fnc_obstruction; 
        _objects = _objects select {!([side group (_x#0), side group _unit] call BIS_fnc_sideIsFriendly && (_x#0) isKindOf "Man")};
        _canBeObstructed = ([gestureState _unit] call tsp_fnc_gesture_sanitize == "" || _mode == "stop") && !weaponLowered _unit;
        if (count _friends > 0 && _canBeObstructed && isNil "tsp_tactical_delay") exitWith {_mode = "friend"; _level = "laut"; [] spawn {tsp_tactical_delay = true; sleep 0.4; tsp_tactical_delay = nil}}; 
        if (count _objects > 0 && _canBeObstructed && isNil "tsp_tactical_delay") exitWith {_mode = "object"; _level = "laut"; [] spawn {tsp_tactical_delay = true; sleep 0.4; tsp_tactical_delay = nil}}; 
        if (count (_friends+_objects) == 0 && ("friend" in gestureState _unit || "object" in gestureState _unit)) exitWith {_mode = ""; [_unit] call tsp_fnc_gesture_stop}; 
    };

    if (_mode == "stop") exitWith {[_unit] call tsp_fnc_gesture_stop};  //-- If still "stop" and not friend/object - cancel, else continue to obstruct
    if (_mode == "" || _mode in gestureState _unit) exitWith {}; [_unit] call tsp_fnc_animate_effect;
    if ("MachineGun" in _weapon) then {_style = tsp_cba_animate_style_autorifle}; 
    if ("SniperRifle" in _weapon) then {_style = tsp_cba_animate_style_sniper};
    if ("Shotgun" in _weapon) then {_style = tsp_cba_animate_style_shotgun};
    //_returnable = _mode in ["ready","readycombat","readyalt","compress", "cant","friend","over","port","portchill","portmove"];
    //_return = _mode in ["tap","leg","shoulder","door","doorcompress","sprint","over"] || (_mode in ["readybase","readycombat","readyalt","compress"] && "cant" in gestureState _unit);
    [_unit, "", "tsp_animate_tactical_"+_style+_mode+"_wnon_"+_level, _out, true, true, _return, if ("ready" in _mode) then {true} else {!_return}] spawn tsp_fnc_gesture_play;
};

tsp_fnc_animate_commands = {  //gestureFreeze//tsp_animate_halt
    if (_this getVariable ["commandeded", false]) exitWith {};
    _this getVariable ["commandeded", true];
    _this addEventHandler ["CommandChanged", {
        params ["_group", "_cmd"]; if (stance (leader _group) == "PRONE" || commandingMenu == "" || [gestureState (leader _group)] call tsp_fnc_gesture_sanitize != "") exitWith {};
        if (_cmd in ["MOVE"]) exitWith {(leader _group) playActionNow (selectRandom ["gestureGo","ace_gestures_forward"])};
        if (_cmd in ["ATTACK","ATTACK AND FIRE"]) exitWith {(leader _group) playActionNow (selectRandom ["gestureGo","ace_gestures_forward"])};
        if (_cmd in ["SUPPORT"]) exitWith {(leader _group) playActionNow (selectRandom ["gestureUp","ace_gestures_point"])};
        if (_cmd in ["DISMISS"]) exitWith {(leader _group) playActionNow "gestureCeaseFire"};
        if (_cmd in ["JOIN"]) exitWith {(leader _group) playActionNow "ace_gestures_regroup"};
        if (_cmd in ["STOP"]) exitWith {(leader _group) playActionNow (selectRandom ["ace_gestures_freeze"])};
        if (_cmd in ["FIRE","Suppress"]) exitWith {(leader _group) playActionNow "gestureAdvance"};
        if (_cmd in ["EXPECT"]) exitWith {(leader _group) playActionNow "ace_gestures_cover"};
        if (_cmd in ["ACTION","FIRE AT POSITION"]) exitWith {(leader _group) playActionNow "ace_gestures_engage"};
        if (_cmd in ["WAIT"]) exitWith {(leader _group) playActionNow "ace_gestures_hold"};
        if (_cmd in ["HIDE"]) exitWith {(leader _group) playActionNow "ace_gestures_warning"};
        if (_cmd in ["DISASSEMBLE","DROP BAG","DISABLE MINE","UNLOAD FROM"]) exitWith {(leader _group) playActionNow (selectRandom ["gestureFollow", "tsp_animate_abort"])};
        if (_cmd in ["GET IN","GET OUT"]) exitWith {(leader _group) playActionNow (selectRandom ["tsp_animate_ready","gestureUp"])};
        if (_cmd in ["HEAL","HEAL SOLDIER","PATCH SOLDIER","FIRST AID","HEAL SELF","CARRY SOLDIER","DROP CARRIED"]) exitWith {(leader _group) playActionNow "tsp_animate_wedge"};
        if (_cmd in ["REPAIR VEHICLE","REPAIR","REFUEL","REARM","TAKE BAG","ASSEMBLE","OPEN BAG","PUT IN","ACTIVATE MINE"]) exitWith {(leader _group) playActionNow "tsp_animate_peek"};
    }];
    _this addEventHandler ["FormationChanged", {
        params ["_group", "_formation"]; if (stance (leader _group) == "PRONE" || commandingMenu == "" || [gestureState (leader _group)] call tsp_fnc_gesture_sanitize != "") exitWith {};
        if (_formation == formation _group) then {(leader _group) playActionNow "ace_gestures_regroup"};
        if (_formation in ["COLUMN","STAG COLUMN"]) exitWith {(leader _group) playActionNow "tsp_animate_column"};
        if (_formation in ["ECH LEFT"]) exitWith {(leader _group) playActionNow "ace_gestures_cover"};
        if (_formation in ["ECH RIGHT"]) exitWith {(leader _group) playActionNow "gestureUp"};
        if (_formation in ["LINE","FILE","ECH RIGHT"]) exitWith {(leader _group) playActionNow "tsp_animate_line"};
        if (_formation in ["VEE","WEDGE"]) exitWith {(leader _group) playActionNow "tsp_animate_wedge"};
        if (_formation in ["DIAMOND"]) exitWith {(leader _group) playActionNow "ace_gestures_freeze"};
    }];
};