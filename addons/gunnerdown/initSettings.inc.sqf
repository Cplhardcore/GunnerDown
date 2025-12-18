// Can use localize "STR_ACE_Common_Enabled" for name if ACE is required
[
	QGVAR(requireFriendly),
	"CHECKBOX",
	[LSTRING(requireFriendly_name), LSTRING(requireFriendly_tooltip)],
	[CBA_SETTINGS_CAT, LSTRING(cba_Name)],
	[true],
	true
] call CBA_Settings_fnc_init;

[
	QGVAR(grabTime),
    "SLIDER",
    [LLSTRING(grabTime)],
    [CBA_SETTINGS_CAT, LSTRING(cba_Name)],
    [1, 20, 5, 0],
    true
] call CBA_Settings_fnc_init;

[
    QGVAR(enableLauncherTaking), "CHECKBOX",
    LSTRING(takeLauncherSetting),
    [CBA_SETTINGS_CAT, LSTRING(cba_Name)],
    false,
    1
] call CBA_fnc_addSetting;

[
    QGVAR(launcherTime), "SLIDER",
    LSTRING(takeLauncherTime),
    [CBA_SETTINGS_CAT, LSTRING(cba_Name)],
    [1, 20, 5, 0],
    1
] call CBA_fnc_addSetting;
