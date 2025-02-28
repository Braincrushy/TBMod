/*
    Part of the TBMod ( https://github.com/TacticalBaconDevs/TBMod )
    Developed by http://tacticalbacon.de
*/
#define PREFIX TBMod

#include "\x\TBMod\addons\common\script_version.hpp"

#define VERSION     MAJOR.MINOR
#define VERSION_STR MAJOR.MINOR.PATCHLVL
#define VERSION_AR  MAJOR,MINOR,PATCHLVL

#define REQUIRED_VERSION 2.06
#define REQUIRED_CBA_VERSION {3,15,6}
#define REQUIRED_ACE_VERSION {3,13,6}

#define DEBUG_MODE_FULL
#define DISABLE_COMPILE_CACHE
#define ENABLE_PERFORMANCE_COUNTERS

/*
    Mod spezifische Makros
*/
#ifdef DISABLE_COMPILE_CACHE
    #define PREP_OTHERFOLDER(fncName,path) DFUNC(fncName) = compile preprocessFileLineNumbers QPATHTOF(path\DOUBLES(fnc,fncName).sqf)
#else
    #define PREP_OTHERFOLDER(fncName,path) [QPATHTOF(path\DOUBLES(fnc,fncName).sqf), QFUNC(fncName)] call CBA_fnc_compileFunction
#endif
