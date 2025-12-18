#include "..\script_component.hpp"
/*
 * Author: Cplhardcore
 * swap weapons
 *
 * Arguments:
 * 0: Player <OBJECT>
 * 1: Target <OBJECT>
 *
 * Return Value:
 * Bool
 *
 * Example:
 * [player] call gunnerdown_fnc_swapPrimaryWeapons
 *
 * Public: No
 */
 params [
    ["_unitA", objNull, [objNull]],
    ["_unitB", objNull, [objNull]]
];
if !([_unitA, _unitB] call FUNC(canSwapPrimaryWeapons)) exitWith {};
[GVAR(grabTime),
    [_unitA, _unitB],
    {
        params ["_args"];
        _args params ["_unitA", "_unitB"];
        private _getWeaponData = {
    params ["_unit"];

    private _weapon = primaryWeapon _unit;
    if (_weapon isEqualTo "") exitWith {[]};

    [
        _weapon,
        primaryWeaponItems _unit,
        currentMagazine _unit,
        _unit ammo _weapon
    ]
};

private _dataA = [_unitA] call _getWeaponData;
private _dataB = [_unitB] call _getWeaponData;
_unitA removeWeapon (primaryWeapon _unitA);
_unitB removeWeapon (primaryWeapon _unitB);

private _restore = {
    params ["_unit", "_data"];

    if (_data isEqualTo []) exitWith {};

    _data params ["_weapon", "_attachments", "_mag", "_ammo"];
    [_unit, _weapon, true, [[_mag, _ammo]]] call ACEFUNC(common,addWeapon);
    {
        if (_x != "") then {
            _unit addPrimaryWeaponItem _x;
        };
    } forEach _attachments;
};

[_unitA, _dataB] call _restore;
[_unitB, _dataA] call _restore;
 [_unitA, "PutDown"] call EFUNC(common,doGesture);
_unitA selectWeapon (primaryWeapon _unitA);
_unitB selectWeapon (primaryWeapon _unitB);
    },
    {}, "Grabbing Weapon"] call ACEFUNC(common,progressBar);
