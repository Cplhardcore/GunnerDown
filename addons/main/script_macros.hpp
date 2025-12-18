// Global toggles for caching/logging
// #define DISABLE_COMPILE_CACHE
// #define DEBUG_MODE_FULL
#define DEBUG_SYNCHRONOUS
#include "\x\cba\addons\main\script_macros_common.hpp"
#include "\x\cba\addons\xeh\script_xeh.hpp"
#include "\a3\ui_f\hpp\defineDIKCodes.inc"

#define QQUOTE(var1) QUOTE(QUOTE(var1))

// QPATHTOF but without a leading slash
#define PATHTOF2(var1) MAINPREFIX\PREFIX\SUBPREFIX\COMPONENT\var1
#define QPATHTOF2(var1) QUOTE(PATHTOF2(var1))

#ifdef SUBCOMPONENT
    #define SUBADDON DOUBLES(ADDON,SUBCOMPONENT)

    // Update PATHTO macros to point to subaddon instead
    #undef PATHTO
    #define PATHTO(var1) \MAINPREFIX\PREFIX\SUBPREFIX\COMPONENT\SUBCOMPONENT\var1.sqf
    #undef PATHTOF
    #define PATHTOF(var1) \MAINPREFIX\PREFIX\SUBPREFIX\COMPONENT\SUBCOMPONENT\var1
    #undef PATHTO2
    #define PATHTO2(var1) MAINPREFIX\PREFIX\SUBPREFIX\COMPONENT\SUBCOMPONENT\var1.sqf
    #undef PATHTOF2
    #define PATHTOF2(var1) MAINPREFIX\PREFIX\SUBPREFIX\COMPONENT\SUBCOMPONENT\var1
#endif

#undef PREP
#ifdef DISABLE_COMPILE_CACHE
    #define LINKFUNC(x) {call FUNC(x)}
    #define PREP(fncName) FUNC(fncName) = compile preprocessFileLineNumbers QPATHTOF(functions\DOUBLES(fnc,fncName).sqf)
    #define PREP_RECOMPILE_START    if (isNil "GunnerDown_fnc_recompile") then {GunnerDown_recompiles = []; GunnerDown_fnc_recompile = {{call _x} forEach GunnerDown_recompiles;}}; private _recomp = {
    #define PREP_RECOMPILE_END      }; call _recomp; GunnerDown_recompiles pushBack _recomp;
#else
    #define LINKFUNC(x) FUNC(x)
    #define PREP(fncName) [QPATHTOF(functions\DOUBLES(fnc,fncName).sqf), QFUNC(fncName)] call CBA_fnc_compileFunction
    #define PREP_RECOMPILE_START ; /* disabled */
    #define PREP_RECOMPILE_END ; /* disabled */
#endif

#define WEAP_XX(WEAP, COUNT) class DOUBLES(_xx,WEAP) { \
    weapon = QUOTE(WEAP); \
    count = COUNT; \
}

#define MAG_XX(MAG, COUNT) class DOUBLES(_xx,MAG) { \
    magazine = QUOTE(MAG); \
    count = COUNT; \
}

#define ITEM_XX(ITEM, COUNT) class DOUBLES(_xx,ITEM) { \
    name = QUOTE(ITEM); \
    count = COUNT; \
}

// ACE Cargo
#define CARGO_XX(ITEM, COUNT) class ITEM { \
    type = QUOTE(ITEM); \
    amount = COUNT; \
}

#define MAG_CSW(var1,var2) class DOUBLES(var1,csw): var1 { \
    scope = var2; \
    type = TYPE_MAGAZINE_PRIMARY_AND_THROW; \
}

// Debug textures, mainly for testing hiddenSelections
#define DBUG_TEX_RED "#(rgb,8,8,3)color(1,0,0,1)"
#define DBUG_TEX_GRN "#(rgb,8,8,3)color(0,1,0,1)"
#define DBUG_TEX_BLU "#(rgb,8,8,3)color(0,0,1,1)"
#define DBUG_TEX_PUR "#(rgb,8,8,3)color(1,0,1,1)"
#define DBUG_TEX_YEL "#(rgb,8,8,3)color(1,1,0,1)"

// Statements and conditions
#define CLAMP(var1,lower,upper) (lower max (var1 min upper))

// Weapon types
#define TYPE_WEAPON_PRIMARY 1
#define TYPE_WEAPON_HANDGUN 2
#define TYPE_WEAPON_SECONDARY 4
// Magazine types
#define TYPE_MAGAZINE_HANDGUN_AND_GL 16 // mainly
#define TYPE_MAGAZINE_PRIMARY_AND_THROW 256
#define TYPE_MAGAZINE_SECONDARY_AND_PUT 512 // mainly
#define TYPE_MAGAZINE_MISSILE 768
// More types
#define TYPE_BINOCULAR_AND_NVG 4096
#define TYPE_WEAPON_VEHICLE 65536
#define TYPE_ITEM 131072
// Item types
#define TYPE_DEFAULT 0
#define TYPE_MUZZLE 101
#define TYPE_OPTICS 201
#define TYPE_FLASHLIGHT 301
#define TYPE_BIPOD 302
#define TYPE_FIRST_AID_KIT 401
#define TYPE_FINS 501 // not implemented
#define TYPE_BREATHING_BOMB 601 // not implemented
#define TYPE_NVG 602
#define TYPE_GOGGLE 603
#define TYPE_SCUBA 604 // not implemented
#define TYPE_HEADGEAR 605
#define TYPE_FACTOR 607
#define TYPE_MAP 608
#define TYPE_COMPASS 609
#define TYPE_WATCH 610
#define TYPE_RADIO 611
#define TYPE_GPS 612
#define TYPE_HMD 616
#define TYPE_BINOCULAR 617
#define TYPE_MEDIKIT 619
#define TYPE_TOOLKIT 620
#define TYPE_UAV_TERMINAL 621
#define TYPE_VEST 701
#define TYPE_UNIFORM 801
#define TYPE_BACKPACK 901


// Default versioning level
#define DEFAULT_VERSIONING_LEVEL 2

#define DGVAR(varName)    if(isNil "KAT_DEBUG_NAMESPACE") then { KAT_DEBUG_NAMESPACE = []; }; if(!(QUOTE(GVAR(varName)) in KAT_DEBUG_NAMESPACE)) then { PUSH(KAT_DEBUG_NAMESPACE, QUOTE(GVAR(varName))); }; GVAR(varName)
#define DVAR(varName)     if(isNil "KAT_DEBUG_NAMESPACE") then { KAT_DEBUG_NAMESPACE = []; }; if(!(QUOTE(varName) in KAT_DEBUG_NAMESPACE)) then { PUSH(KAT_DEBUG_NAMESPACE, QUOTE(varName)); }; varName
#define DFUNC(var1) TRIPLES(ADDON,fnc,var1)
#define DEFUNC(var1,var2) TRIPLES(DOUBLES(PREFIX,var1),fnc,var2)

#define SIXES(var1,var2,var3,var4,var5,var6) var1##_##var2##_##var3##_##var4##_##var5##_##var6
#define FOURS(var1,var2,var3,var4) var1##_##var2##_##var3##_##var4##
#define KATPUSHCSTRING(var1,var2,var3) QUOTE(SIXES($STR,ADDON,Push,var1,var2,var3))
#define KATPUSHINGCSTRING(var1,var2,var3) QUOTE(SIXES($STR,ADDON,Pushing,var1,var2,var3))
#define KATDISPLAYCSTRING(var1,var2,var3) QUOTE(SIXES($STR,ADDON,SyringeDisplay,var1,var2,var3))
#define LOC(var1,var2) QUOTE(TRIPLES(STR,ADDON,DOUBLES(var1,var2)))
#define ICON_PATH(name) ADDON##\ui\##name##.paa

#undef QFUNC
#undef QEFUNC
#define QFUNC(var1) QUOTE(DFUNC(var1))
#define QEFUNC(var1,var2) QUOTE(DEFUNC(var1,var2))

#define GETVAR_SYS(var1,var2) getVariable [ARR_2(QUOTE(var1),var2)]
#define SETVAR_SYS(var1,var2) setVariable [ARR_2(QUOTE(var1),var2)]
#define SETPVAR_SYS(var1,var2) setVariable [ARR_3(QUOTE(var1),var2,true)]

#undef GETVAR
#define GETVAR(var1,var2,var3) (var1 GETVAR_SYS(var2,var3))
#define GETMVAR(var1,var2) (missionNamespace GETVAR_SYS(var1,var2))
#define GETUVAR(var1,var2) (uiNamespace GETVAR_SYS(var1,var2))
#define GETPRVAR(var1,var2) (profileNamespace GETVAR_SYS(var1,var2))
#define GETPAVAR(var1,var2) (parsingNamespace GETVAR_SYS(var1,var2))

#undef SETVAR
#define SETVAR(var1,var2,var3) var1 SETVAR_SYS(var2,var3)
#define SETPVAR(var1,var2,var3) var1 SETPVAR_SYS(var2,var3)
#define SETMVAR(var1,var2) missionNamespace SETVAR_SYS(var1,var2)
#define SETUVAR(var1,var2) uiNamespace SETVAR_SYS(var1,var2)
#define SETPRVAR(var1,var2) profileNamespace SETVAR_SYS(var1,var2)
#define SETPAVAR(var1,var2) parsingNamespace SETVAR_SYS(var1,var2)

#define GETGVAR(var1,var2) GETMVAR(GVAR(var1),var2)
#define GETEGVAR(var1,var2,var3) GETMVAR(EGVAR(var1,var2),var3)

#define QGETGVAR(var1,var2) QUOTE(GETMVAR(QGVAR(var1),var2))

#define ARR_SELECT(ARRAY,INDEX,DEFAULT) (if (count ARRAY > INDEX) then {ARRAY select INDEX} else {DEFAULT})
#define ANY_OF(ARRAY,CONDITION) (ARRAY findIf {CONDITION} != -1)

#define MACRO_ADDWEAPON(WEAPON,COUNT) class _xx_##WEAPON { \
    weapon = #WEAPON; \
    count = COUNT; \
}

#define MACRO_ADDITEM(ITEM,COUNT) class _xx_##ITEM { \
    name = #ITEM; \
    count = COUNT; \
}

#define MACRO_ADDMAGAZINE(MAGAZINE,COUNT) class _xx_##MAGAZINE { \
    magazine = #MAGAZINE; \
    count = COUNT; \
}

#define MACRO_ADDBACKPACK(BACKPACK,COUNT) class _xx_##BACKPACK { \
    backpack = #BACKPACK; \
    count = COUNT; \
}

// Returns a text config entry as compiled code or variable from missionNamespace
#define GET_FUNCTION(var,cfg) \
    private var = getText (cfg); \
    if (isNil var) then { \
        var = compile var; \
    } else { \
        var = missionNamespace getVariable var; \
    }

// Returns a number config entry with default value of 0
// If entry is a string, will get the variable from missionNamespace
#define GET_NUMBER_ENTRY(cfg) \
    if (isText (cfg)) then { \
        missionNamespace getVariable [getText (cfg), 0]; \
    } else { \
        getNumber (cfg); \
    }

// BEGIN ACE3 reference macros

#define ACE_PREFIX ace

#define ACE_ADDON(component)        DOUBLES(ACE_PREFIX,component)

#define ACEGVAR(module,var)         TRIPLES(ACE_PREFIX,module,var)
#define QACEGVAR(module,var)        QUOTE(ACEGVAR(module,var))
#define QQACEGVAR(module,var)       QUOTE(QACEGVAR(module,var))

#define ACEFUNC(module,function)    TRIPLES(DOUBLES(ACE_PREFIX,module),fnc,function)
#define QACEFUNC(module,function)   QUOTE(ACEFUNC(module,function))

#define ACELSTRING(module,string)   QUOTE(TRIPLES(STR,DOUBLES(ACE_PREFIX,module),string))
#define ACELLSTRING(module,string)  localize ACELSTRING(module,string)
#define ACECSTRING(module,string)   QUOTE(TRIPLES($STR,DOUBLES(ACE_PREFIX,module),string))

#define ACEPATHTOF(component,path) \z\ace\addons\component\path
#define QACEPATHTOF(component,path) QUOTE(ACEPATHTOF(component,path))
