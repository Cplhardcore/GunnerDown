class CfgVehicles {
    class Man;
    class CAManBase: Man {
        class ACE_Actions {
            class ACE_MainActions {
                class GunnerDown {
                    displayName = CSTRING(GunnerDownAction);
                    condition = QUOTE([ARR_2(_player,_target)] call FUNC(canSwapPrimaryWeapons));
                    statement = QUOTE([ARR_2(_player,_target)] call FUNC(swapPrimaryWeapons));
                };
            };
            class ACE_Weapon {
                class GunnerDown {
                    displayName = CSTRING(GunnerDownAction);
                    condition = QUOTE([ARR_2(_player,_target)] call FUNC(canSwapPrimaryWeapons));
                    statement = QUOTE([ARR_2(_player,_target)] call FUNC(swapPrimaryWeapons));
                };
            };
        };
    };
};
