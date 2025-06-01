if (ace_gestures_showOnInteractionMenu == 0) exitWith {false};
if !([ACE_player, objNull, ["isNotSwimming"]] call ace_common_fnc_canInteractWith) exitWith {false};  //-- I wanna do signals in vehicles and while swimming!!!

private _gesture = if ((_this select [0,2]) == "BI") then {_this select [2]} else {
    if (((animationState ACE_player) select [0, 12]) in ["amovpercmstp", "amovpercmwlk", "amovpercmtac"] && weaponLowered ACE_player) then {
        format ["%1StandLowered", _this]
    } else {_this};
};

[ACE_player, _gesture] call ace_common_fnc_doGesture;
true