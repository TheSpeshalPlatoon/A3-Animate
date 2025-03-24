tsp_fnc_animate_nvg = {
    params ["_unit", ["_gesture", "tsp_animate_nightvision_up"]]; [currentVisionMode _unit] params ["_vision"]; [_unit] call tsp_fnc_animate_effect;  //-- 0 = normal, 1 = nvg
    if ((cameraView == "GUNNER" && [_unit] call tsp_fnc_visionModes) || !("NVG" in (getArray (configFile >> "CfgWeapons" >> hmd _unit >> "visionMode")))) exitWith {};
    [_unit, "", if (_vision == 1) then {"tsp_animate_nightvision_up"} else {"tsp_animate_nightvision_down"}, "", "tsp" in gestureState _unit, false, true] spawn tsp_fnc_gesture_play;
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
    if (_fancy) then {
        [_unit, "", "tsp_animate_throw_wnon", "tsp_common_stop", true, true] spawn tsp_fnc_gesture_play;  //-- Idle animation
        waitUntil {sleep 0.1; inputMouse 0 == 2 || !("throw" in gestureState _unit)}; if !("throw" in gestureState _unit) exitWith {};  //-- Wait for mouse hold or cancelled, if cancelled - leave
        [_unit, "tsp_animate_throw_wnon_wind", "tsp_animate_throw_wnon_wound", "tsp_common_stop", true, true] spawn tsp_fnc_gesture_play;  //-- Play winding animation
        while {sleep 0.1; inputMouse 0 == 2 && _force < _forceMax} do {_force = _force + 0.5};  //-- As winding anim plays, turn up the force
        waitUntil {inputMouse 0 != 2}; if !("throw" in gestureState _unit) exitWith {};  //-- Wait for mouse release, if cancelled - leave
        [_unit, "", "tsp_animate_throw_wnon_out", "", true, true] spawn tsp_fnc_gesture_play;  //-- Throw animation
    } else {[_unit, "", "tsp_animate_throw_wnon_out", "", true, true] spawn tsp_fnc_gesture_play;};  //-- If not fancy, just skip to throw animation
    sleep 0.1; _holder = [_unit, currentWeapon _unit] call tsp_fnc_throw;
    [_holder, _unit vectorModelToWorld [0, _force, _force]] remoteExec ["setVelocity", _unit]; 
    _holder addTorque (call CBA_fnc_randomVector3D vectorMultiply _torque);
};

tsp_fnc_animate_dance = {
    params ["_unit", "_animation"];
    [_unit, _animation] remoteExec ["playMoveNow", 0]; waitUntil {animationState _unit == _animation || !alive _unit};
    while {sleep 0.5; animationState _unit == _animation} do {_unit action ["SWITCHWEAPON", _unit, _unit, -1]; _unit selectWeapon handgunWeapon _unit};
};

tsp_fnc_animate_tactical = {  //-- Ready, Compress, Tap (Shoulder/Leg), Door, doorcompress
    params ["_unit", ["_mode", ""], ["_level", "laut"], ["_params", []], ["_modeOriginal", _this#1], ["_ready", "ready"], ["_style", tsp_cba_animate_style], ["_weapon", currentWeapon (_this#0) call BIS_fnc_itemType]];

    //-- Gate
    if !(
        tsp_cba_animate_tactical && !("melee" in currentWeapon _unit) && 
        vehicle _unit == _unit && stance _unit in ["STAND","CROUCH"] && ("amov" in animationState _unit || "aadj" in animationState _unit) && isNil "tsp_animate_switching" &&
        ("tactical" in gestureState _unit || "melee" in gestureState _unit || [gestureState _unit] call tsp_fnc_gesture_sanitize == "") && 
        (((currentWeapon _unit != binocular _unit) && (currentWeapon _unit != secondaryWeapon _unit)) || currentWeapon _unit == "") &&   //-- No ready with launchers/binocs
        !(cameraView == "GUNNER" && ([_unit] call tsp_fnc_visionModes || count (primaryWeaponItems _unit select {_x in tsp_cba_animate_black}) > 0))  //-- No ready when aiming with lockable weapons
    ) exitWith {if ("tactical" in gestureState _unit) then {[_unit] call tsp_fnc_gesture_stop}};

    //-- Sprint
    if (tsp_cba_animate_sprint && "percmeva" in animationState _unit && "tactical" in gestureState _unit && !("sprint" in gestureState _unit)) then {_mode = "sprint"};
    if (!("percmeva" in animationState _unit) && "sprint" in gestureState _unit) exitWith {[_unit] call tsp_fnc_gesture_stop};

    //-- Port (Dont touch, this code is a cucky mess to allow for removing tsp_animate_walk.pbo)
    if ("slow" in animationState _unit && ("tactical" in gestureState _unit || _mode != "") && !(_mode in ["tap","leg","shoulder","door","doorcompress","sprint"]) && stance _unit == "STAND") then {
        if ("mstp" in animationState _unit) then {_mode = if (tsp_animate_combat) then {"port"} else {"portchill"}};
        if (isClass (configFile >> "CfgPatches" >> "tsp_animate_walk") && tsp_animate_combat && ("mwlk" in animationState _unit || "mtac" in animationState _unit)) then {_mode = "portmove"};
        if ("mrun" in animationState _unit || stance _unit != "STAND" || ("ver2" in animationState _unit && "lhig" in gestureState _unit)) then {_mode = "portchill"};
    };
    if ((!("slow" in animationState _unit) || stance _unit != "STAND") && "port" in gestureState _unit) then {_mode = "ready"};  //-- Exit from port

    //-- Scroll
    if ("scroll" in _mode && isNil "tsp_tactical_delay") then {
        getArray (configFile >> "CfgGesturesMale" >> "States" >> gestureState _unit >> _mode) params [["_nextMode", ""], ["_nextLevel", ""]]; 
        if (_nextMode == "") then {_mode = ""} else {_mode = _nextMode; _level = _nextLevel}; 
        [] spawn {tsp_tactical_delay = true; sleep 0.08; tsp_tactical_delay = nil}; 
    };

    //-- Ready
    if (tsp_animate_combat && stance _unit == "STAND") then {_ready = "readycombat"};
    if (!tsp_animate_combat) then {_ready = if (tsp_animate_walk && stance _unit == "STAND") then {"readyalt"} else {"ready"}};
    //-- Only replace ready if mode is normal "ready" or already doing special ready
    if (_mode == "ready" || ("tactical" in gestureState _unit && "ready" in gestureState _unit && !((_ready+"_") in gestureState _unit) && isNil "tsp_animate_readyflag")) then {
        _mode = _ready; tsp_animate_readyflag = true; [] spawn {sleep 0.1; tsp_animate_readyflag = nil};  //-- No spam yo, smoother transition when combat mode changed
    };

    //-- Door
    if (_mode == "door" && ("compress" in gestureState _unit || "object" in gestureState _unit || "cant" in gestureState _unit)) then {_mode = "doorcompress"};

    //-- Tap
    if (_mode in ["tap", "leg", "shoulder"]) then {
        if (_mode == "tap") then {_mode = if ((getCameraViewDirection _unit)#2 < -0.2) then {"leg"} else {"shoulder"}}; 
        [[name _unit, "Squeezed your " + (["right", "left"] select _params#1) + " " + _mode], tsp_fnc_hint] remoteExec ["call", _params#0];
        _params spawn {sleep 0.3; [_this#0, 5, "A3\Sounds_F\characters\footsteps\int_carpet\carpet_int_sprint_HPF_"+str(round random 8 max 1)+".wss", 1] call tsp_fnc_animate_effect};
    };

    //-- If toggle, exit with either stop or switch to object/friend if applicable
    _base = _mode regexReplace ["combat", ""] regexReplace ["alt", ""] regexReplace ["move", ""] regexReplace ["chill", ""];
    _toggle = _modeOriginal != "" && _mode in ["ready","readycombat","readyalt","compress","cant","over","port","portchill","portmove"] && _base in gestureState _unit;

    //-- Object/Friend variables
    _length = ([_unit] call tsp_fnc_length) max 0.7; if ("tsp_animate_tactical_" in gestureState _unit) then {_length = _length + 0.2};
    _dir = _unit weaponDirection currentWeapon _unit; if ("tsp_animate_tactical_" in gestureState _unit) then {_dir = if (freelook) then {vectorDirVisual _unit} else {getCameraViewDirection _unit}};
    _friends = [_unit, _unit modelToWorldWorld (_unit selectionPosition ["Neck", "Memory"]), [0,3,-5,-10], _length * tsp_cba_animate_friend, _dir] call tsp_fnc_obstruction;
    _friends = _friends select {[side group (_x#0), side group _unit] call BIS_fnc_sideIsFriendly && (_x#0) isKindOf "Man"};
    _objects = [_unit, eyePos _unit, [0], _length * tsp_cba_animate_object, _dir] call tsp_fnc_obstruction; 
    _objects = _objects select {!([side group (_x#0), side group _unit] call BIS_fnc_sideIsFriendly && (_x#0) isKindOf "Man")};

    //-- Handle toggle in between object/friend since we may need to exit into obstruction
    if (_toggle && count (_friends+_objects) == 0) exitWith {[_unit] call tsp_fnc_gesture_stop};  //-- Normal exit toggle
    if (_toggle && count (_friends+_objects) > 0) then {_mode = "obstruct"};  //-- Exit into obstructed

    //-- Object/Friend actual
    if (_mode in ["","obstruct"] && tsp_cba_animate_poll > 0) then {
        _canBeObstructed = ([gestureState _unit] call tsp_fnc_gesture_sanitize == "" || _mode == "obstruct") && !weaponLowered _unit;
        if (count (_friends+_objects) == 0 && ("friend" in gestureState _unit || "object" in gestureState _unit)) exitWith {_mode = ""; [_unit] call tsp_fnc_gesture_stop};
        if (count _friends > 0 && _canBeObstructed && isNil "tsp_tactical_delay") exitWith {_mode = "friend"; [] spawn {tsp_tactical_delay = true; sleep 0.5; tsp_tactical_delay = nil}}; 
        if (count _objects > 0 && _canBeObstructed && isNil "tsp_tactical_delay") exitWith {_mode = "object"; [] spawn {tsp_tactical_delay = true; sleep 0.5; tsp_tactical_delay = nil}};      
    };

    //-- The Money Shot - Don't touch this, it's fragile
    if (_mode == "") exitWith {};
    _interupt = [gestureState _unit] call tsp_fnc_gesture_sanitize == "" || ("tsp" in gestureState _unit && gestureState _unit call tsp_fnc_gesture_looped);
    _return = _mode in ["tap","leg","shoulder","door","doorcompress","sprint","over"] || (_mode in ["ready","readycombat","readyalt","compress"] && "cant" in gestureState _unit);
    _returnable = _mode in ["ready","readycombat","readyalt","compress", "cant","friend","over","port","portchill","portmove"];
    if ("MachineGun" in _weapon) then {_style = tsp_cba_animate_style_autorifle}; 
    if ("SniperRifle" in _weapon) then {_style = tsp_cba_animate_style_sniper};
    if ("Shotgun" in _weapon) then {_style = tsp_cba_animate_style_shotgun};
    _loop = "tsp_animate_tactical_"+_style+_mode+"_wnon_"+_level;
    _out = "sprint" in _mode && !("llow" in gestureState _unit) && !("port" in gestureState _unit);  //-- Only do out gesture for high sprint, also dont go it when going sprint -> port
    [_unit, "", _loop, if (_out) then {_loop + "_out"} else {"tsp_common_stop"}, _interupt, true, _return, _returnable, false, false, {[_this#0] call tsp_fnc_animate_effect}] spawn tsp_fnc_gesture_play;
};

tsp_fnc_animate_tactical_stop = {
    params ["_unit", ["_aim", false], ["_others", false], ["_compress", false], ["_cant", false], ["_over", false], ["_gesture", gestureState (_this#0)]];
    if (!("tactical" in _gesture) || (!_compress && "compress" in _gesture) || (!_cant && "cant" in _gesture) || (!_over && "over" in _gesture) || ("friend" in _gesture) || ("object" in _gesture)) exitWith {};
    if (_gesture == gestureState _unit) then {[_unit] call tsp_fnc_gesture_stop; [_unit] call tsp_fnc_animate_effect};  //-- In case changed, compare (used in keyUps)
    if (_aim && cameraView == "INTERNAL") then {_unit switchCamera "GUNNER"}; 
};

tsp_fnc_animate_effect = {
    params ["_unit", ["_shake", 1], ["_sound", "A3\Sounds_F\characters\stances\adjust_short"+str(round random 5 max 1)+".wss"], ["_volume", 0.1]];
    playSound3D [_sound, _unit, true, getPosASL _unit, _volume*tsp_cba_animate_sound, 1];  //concrete_adjust_stand_side//adjust_short//lift_rifle
    [_shake*tsp_cba_animate_shake, 2, 5] remoteExec ["tsp_fnc_shake", _unit];
};

tsp_fnc_animate_sling = {  //-- FUCK FUCK FUCK FUCK I DONT LIKE IT MAKE IT GO AWAY
    params ["_unit", ["_sling", false], ["_holster", false], ["_drawPistol", false], ["_drawLauncher", false], ["_unsling", false], ["_time", 0], ["_slung", (_this#0) getVariable ["tsp_slung", []]]];
    _knife = if (!isNil "tsp_fnc_melee_weapon") then {!([_unit, handGunWeapon _unit] call tsp_fnc_melee_weapon in ["", "pistol"])} else {false};
    if (_sling) then {
        if (_drawPistol && !_knife && tsp_cba_animate_sling_style == "adhd") then {
            [_unit, "tsp_animate_sling_check"] remoteExec ["playActionNow"];
            playSound3D ["A3\Sounds_F\weapons\Other\dry5-rifle.wss", _unit, false, getPosASL _unit, 5, 1, 10];
            _time = 0.2;
        };
        tsp_future pushBack [time + _time, [_unit], {
            params ["_unit"];
            [_unit, primaryWeapon _unit] remoteExec ["selectWeapon"];
            [_unit, "tsp_animate_sling_sling"] remoteExec ["playActionNow"];
        }];
        tsp_future pushBack [time + 0.3 + _time, [_unit, !_drawPistol && !_drawLauncher && !_unsling], {
            params ["_unit", "_unarmed"];
            _rifle = (getUnitLoadout _unit)#0; _holder = [_unit, primaryWeapon _unit, true, false] call tsp_fnc_throw; _holder setDamage 1; 
            [_holder, "lockInventory", "tsp_animate_sling", true] call ace_common_fnc_statusEffect_set;
            _holder attachTo [_unit, tsp_cba_animate_sling_pos#0, "Spine3", true]; [_holder, tsp_cba_animate_sling_pos#1] call BIS_fnc_setObjectRotation;
            if (_unarmed) then {_unit action ["SWITCHWEAPON", _unit, _unit, -1]};
            if (_unarmed && vehicle _unit == _unit) then {[_unit, animationState _unit regexReplace ["wrfl", "wnon"] regexReplace ["sras", "snon"] regexReplace ["slow", "snon"]] remoteExec ["switchMove"]};
            if (_unarmed) then {[_unit, "tsp_common_stop"] remoteExec ["playActionNow"]};
            _unit setVariable ["tsp_slung", [_holder, _rifle]];
        }];
        _time = _time + 0.3;
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
            if (vehicle _unit == _unit) then {[_unit, animationState _unit regexReplace ["wrfl", "wpst"]] remoteExec ["switchMove"]};
            [_unit, handgunWeapon _unit] remoteExec ["selectWeapon"];
            if (_knife) exitWith {[_unit, "ready"] spawn tsp_fnc_melee_action};
            [_unit, "tsp_animate_sling_draw" + (if (tsp_cba_animate_sling_style == "israeli") then {"_israeli"} else {""})] remoteExec ["playActionNow"];
            if (tsp_cba_animate_sling_style == "israeli") then {playSound3D ["A3\Sounds_F\weapons\Other\reload_bolt_1.wss", _unit, false, getPosASL _unit, 5, 1, 10]};
        }];
    };
    if (_drawLauncher) then {
        tsp_future pushBack [time + _time, [_unit], {
            params ["_unit"];
            if (vehicle _unit == _unit) then {[_unit, animationState _unit regexReplace ["wrfl", "wlnr"]] remoteExec ["switchMove"]};
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
            if (vehicle _unit == _unit) then {[_unit, (if (stance _unit == "CROUCH") then {"amovpknlmstpslowwrfldnon_amovpknlmstpsraswrfldnon"} else {"amovpercmstpslowwrfldnon_amovpercmstpsraswrfldnon"})] remoteExec ["switchMove"]};
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

tsp_fnc_animate_clacker = {  //[player, 100, -1, "ShockShort"] spawn tsp_fnc_animate_clacker
    params ["_unit", "_range", "_explosive", "_fuze", "_clacker", ["_exit", {sleep 0.5; true}]];
    if ("shock" in _clacker) then {[_unit, "", "tsp_animate_shock_wnon", "\tsp_breach_shock\shock.p3d", [0.02,0,0], [0,0,-100], _exit, false] spawn tsp_fnc_gesture_item};
    if ("ACE_Clacker" in _clacker) then {[_unit, "", "tsp_animate_clacker", "\z\ace\addons\explosives\data\ace_m57.p3d", [0.02,0,0], [0,0,-100], _exit, false] spawn tsp_fnc_gesture_item};
    sleep 0.2; [_unit, ["OMLightSwitch", 50]] remoteExec ["say3D", 0]; if (_fuze != -1) then {sleep _fuze; _explosive setDamage 1};
};

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
    {[_captive, _x] remoteExec ["disableAI", 0]} forEach ["ANIM", "MOVE"]; [_captive, "amovpercmstpsnonwnondnon"] remoteExec ["switchMove", 0];
    [_captive, "tsp_animate_captive"] remoteExec ["playActionNow", 0]; _captive attachTo [_unit, [-0.15,0.7,0]];  
    waitUntil {isNull attachedTo _captive || stance _unit == "PRONE"};
    _unit allowSprint true; [_unit] call tsp_fnc_gesture_stop; 
    _unit removeEventHandler ["AnimStateChanged", _eh]; 
    {[_captive, _x] remoteExec ["enableAI", 0]} forEach ["ANIM", "MOVE"]; [_captive, "ace_amovpercmstpscapwnondnon"] remoteExec ["switchMove", 0];
    [_captive, "tsp_common_stop"] remoteExec ["playActionNow", 0]; _unit setVariable ["ace_captives_isEscorting", false, true];
};

tsp_fnc_animate_attachment = {
	params ["_unit", "_item", "_mode", "_itemsNew", "_itemsOld", ["_suffix", ""]];
    if (currentWeapon _unit == "" || currentWeapon _unit != tsp_animate_attach#0 || isNull (findDisplay 602) || !(stance _unit in ["STAND", "CROUCH"]) || vehicle _unit != _unit) exitWith {};
    if (currentWeapon _unit == primaryWeapon _unit) then {_itemsNew = primaryWeaponItems _unit; _itemsOld = tsp_animate_attach#1};
    if (currentWeapon _unit == secondaryWeapon _unit) then {_itemsNew = secondaryWeaponItems _unit; _itemsOld = tsp_animate_attach#2};
    if (currentWeapon _unit == handgunWeapon _unit) then {_itemsNew = handgunItems _unit; _itemsOld = tsp_animate_attach#3; _suffix = "pistol"};
	if (_itemsOld#0 isNotEqualTo _itemsNew#0) then {_unit playAction ("gesture" + _mode + "muzzle" + _suffix)};
	if (_itemsOld#1 isNotEqualTo _itemsNew#1) then {_unit playAction (_mode + "side" + _suffix)};
	if (_itemsOld#2 isNotEqualTo _itemsNew#2) then {_unit playAction (_mode + "optic" + _suffix)};
	if (_itemsOld#3 isNotEqualTo _itemsNew#3) then {_unit playAction (_mode + "side" + _suffix)};
	tsp_animate_attach = [currentWeapon _unit, primaryWeaponItems _unit, secondaryWeaponItems _unit, handgunItems _unit];  //-- Update it in case of multipe calls while inventory opened
};

tsp_fnc_animate_walk = {
    params ["_unit", "_anim", ["_speed", -1]]; if (!tsp_cba_animate_walk) exitWith {};
    if (_speed != -1) then {tsp_cba_animate_walk_default = (tsp_cba_animate_walk_default + _speed) min tsp_cba_animate_walk_max max 0.5};  //-- Adjuster
    if ("mwlksras" in _anim) exitWith {tsp_walk_set = true; _unit setAnimSpeedCoef tsp_cba_animate_walk_default};
    if ("mwlkslow" in _anim) exitWith {tsp_walk_set = true; _unit setAnimSpeedCoef tsp_cba_animate_walk_lower};
    if (!("mwlksras" in _anim) && !("mwlkslow" in _anim) && !(isNil "tsp_walk_set")) then {tsp_walk_set = nil; _unit setAnimSpeedCoef 1};
};