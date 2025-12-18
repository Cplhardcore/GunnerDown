#include "..\script_component.hpp"
/*
 * Author: Cplhardcore
 * Condition Check to swap weapons
 *
 * Arguments:
 * 0: Player <OBJECT>
 * 1: Target <OBJECT>
 *
 * Return Value:
 * Bool
 *
 * Example:
 * [player] call gunnerdown_fnc_canSwapPrimaryWeapons
 *
 * Public: No
 */
params ["_player", "_target"];

(_target getVariable ["ACE_isUnconscious", false] || (!alive _target)) &&
(
    !GVAR(requireFriendly) ||
    (side (group _target) == side (group _player))
);
