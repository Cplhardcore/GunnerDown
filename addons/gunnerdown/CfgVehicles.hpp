class CfgVehicles {
    class Man;
    class CAManBase: Man {
        class ACE_Actions {
            class ACE_MainActions {
                class Gunnerdown_GunnerDown {
                    displayName = CSTRING(GunnerDownAction);
                    condition = QUOTE([ARR_2(_player,_target)] call FUNC(canSwapPrimaryWeapons));
                    statement = QUOTE([ARR_2(_player,_target)] call FUNC(swapPrimaryWeapons));
                };
                class Gunnerdown_TakeLauncher {
                    displayName = CSTRING(takeLauncher);
                    condition = QUOTE([ARR_2(_player,_target)] call FUNC(canTakeLauncher));
                    statement = QUOTE([ARR_3(_player,_target,(secondaryWeapon _target))] call FUNC(takeLauncher));
                    exceptions[] = {"isNotSwimming"};
                    showDisabled = 0;
                };
            };
            class ACE_Weapon {
                class Gunnerdown_GunnerDown {
                    displayName = CSTRING(GunnerDownAction);
                    condition = QUOTE([ARR_2(_player,_target)] call FUNC(canSwapPrimaryWeapons));
                    statement = QUOTE([ARR_2(_player,_target)] call FUNC(swapPrimaryWeapons));
                };
            };
        };
    };
};
