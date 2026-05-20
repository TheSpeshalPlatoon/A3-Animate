[Licensing, bug reporting and contact information.](https://github.com/TheSpeshalPlatoon) 

This addon relies on components from tsp_core which can be found in the [Core Repository](https://github.com/TheSpeshalPlatoon/A3-Core).

[<img src="https://core.thespeshalplatoon.com/img/steam_small.png"> Animate](https://steamcommunity.com/sharedfiles/filedetails/?id=3283612524)  
[<img src="https://core.thespeshalplatoon.com/img/steam_small.png"> Animate - Radio](https://steamcommunity.com/sharedfiles/filedetails/?id=3283635033)

## 📕 Content
This mod adds a tactical stance animation system alongside various other animations and gestures to the game.
- Tactical Stance System
↳ Ready (High/Low)
↳ Compress (High/Low)
↳ Port (High/Low)
↳ Sprint (High/Low)
↳ Door (Works with High/Low Ready/Compress)
↳ Shoulder Tap (Requires ACE, Works with High/Low Ready/Compress)
↳ Leg Squeeze (Requires ACE, Works with High/Low Ready/Compress)
↳ Automatic friend/obstruction detection.  
↳ Different Tactical Style sets for different weapons. 
- Sling System
↳ Weapon Slinging (Rifle Only)
↳ 2-point sling, 1-point sling, lanyard
↳ Holster/Quickdraw Animation
- Adjustable Walking Speed
- Weapon Throwing
- Weapon Canting (Rifle Only)
- Weapon Inspection (Rifle/Pistol)
- Suicide Animation (Rifle/Pistol)
- 5 A2 Dances 💃 (Unarmed/Pistols Only)
- 14 Emotes 🤘 (Some only available when Unarmed) 
- 7 Door Signals (Breach/Flashbang/Frag/Shotgun/Ready/Peek/Danger)
- 4 Formation Signals (Halt/Column/Line/Wedge)
- Signals Hints
- Map/Compass/Watch/GPS/UAV Animations
- Shooting from Ladders (Pistol Only)
- Night Vision Animation
- Chemlight Animation
- Grenade Animations
- Various Sounds
- Clacker Animation (Requires ACE)
- Grenade Animation (Requires ACE)
- Captive Animation (Requires ACE)  
- Object Carrying Animations (Requires ACE)  
- Faster Carrying Animation (Requires ACE)  
- Radio Animations (Requires ACRE/TFR/TFAR)  
↳ H198 Handset
↳ Hand-held animation  
↳ Vest animation  
↳ Ear animation  
↳ Wrist animation  
↳ Helmet animation  

## 🔥 Compatibility
✔️ If loaded with [ACE](https://steamcommunity.com/workshop/filedetails/?id=463939057), you will be able to access the animations using ACE interact.  
✔️ If loaded with [Breach](https://steamcommunity.com/sharedfiles/filedetails/?id=3283645995), a unique animation will play for the shock tube detonator.  
✔️ If loaded with [Animate - Radio](https://steamcommunity.com/sharedfiles/filedetails/?id=3283635033), radio animations will work with high/low tactical stances.  
✔️ [Animate - Walk Fix](https://steamcommunity.com/sharedfiles/filedetails/?id=3487944904) will revert walking/jogging animations to default.  
✔️ If loaded with [RHSUSAF](https://steamcommunity.com/sharedfiles/filedetails/?id=843577117), the AN/PRC-152 model from RHS will be used instead.  
✔️ If loaded with [JLTS](https://steamcommunity.com/workshop/filedetails/?id=1940589429), wrist animations will be used for JLTS radios by default.  
✔️ Radio animations require and work with either [ACRE2](https://steamcommunity.com/workshop/filedetails/?id=751965892), [TFR](https://steamcommunity.com/workshop/filedetails/?id=620019431) or [TFAR (Beta)](https://steamcommunity.com/sharedfiles/filedetails/?id=894678801).  
⚠️ [Animated Recoil Coeffect Changer](https://steamcommunity.com/sharedfiles/filedetails/?id=2623341670) will sometimes interrupt certain animatons.  
❓ Optional PBO "tsp_animate_ace" adds ACE features.  
❓ Optional PBO "tsp_animate_walk" adds one handed cool guy walking animations.  
❓ Optional PBO "tsp_animate_limit" will limit weapon movement when lowered.  
❓ Optional PBO "tsp_animate_aim" will allow aiming during gestures.  
❓ Optional PBO "tsp_animate_swim" will increase swimming speed.  
❌ Likely not compatible with other mods that have similar features.  
❌ Not compatible with older versions of this mod. 

## 📝 Scriptadoodle
Quickly adjust sling positioning:
```cpp
tsp_slingClass = "tsp_sling";
tsp_slingPos = ["Spine3", [0.7,0.15,-0.8], [80,130,-20], "tsp_animate_sling_sling", ""];
(player getVariable (tsp_slingClass+"holder")) attachTo [player, tsp_slingPos#1, tsp_slingPos#0, true];
[player getVariable (tsp_slingClass+"holder"), tsp_slingPos#2] call tsp_fnc_rotate;
```