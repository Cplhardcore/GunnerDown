class CfgVehicles {
    class Man;
    class CAManBase: Man {
        class ACE_Actions {
            class ACE_MainActions {
                class GunnerDown {
                    displayName = "Gunner Down!";
                    condition = "[_player,_target] call CPL_fnc_canSwapPrimaryWeapons";
                    statement = "[_player, _target] call CPL_fnc_swapPrimaryWeapons";
                };
            };
            class ACE_Weapon {
                class GunnerDown {
                    displayName = "Gunner Down!";
                    condition = "[_player,_target] call CPL_fnc_canSwapPrimaryWeapons";
                    statement = "[_player, _target] call CPL_fnc_swapPrimaryWeapons";
                };
            };
        };
    };
};
