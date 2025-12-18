#include "\z\GunnerDown\addons\main\data\hpp\defineDIKCodes.hpp"

[
    LSTRING(cba_Name), QGVAR(GrabWeapon),
    LSTRING(GrabWeapon), {
        [ace_player,cursorTarget] call FUNC(swapPrimaryWeapons);
    }// Default keybind
] call CBA_fnc_addKeybind;

[
    LSTRING(cba_Name), QGVAR(GrabLauncher),
    LSTRING(GrabLauncher), {
        [ace_player,cursorTarget,(secondaryWeapon cursorTarget)] call FUNC(takeLauncher);
    }// Default keybind
] call CBA_fnc_addKeybind;
