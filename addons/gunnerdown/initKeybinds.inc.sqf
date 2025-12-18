#include "\z\GunnerDown\addons\main\data\hpp\defineDIKCodes.hpp"

[
    LSTRING(cba_Name), QGVAR(GrabWeapon),
    [LSTRING(GrabWeapon), LSTRING(GrabWeapon_Tooltit)], {
        [ace_player,cursorTarget] call FUNC(swapPrimaryWeapons);
    }// Default keybind
] call CBA_fnc_addKeybind;
