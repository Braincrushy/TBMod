#include "script_component.hpp"
/*
    Part of the TBMod ( https://github.com/TacticalBaconDevs/TBMod )
    Developed by http://tacticalbacon.de
*/
class CfgPatches
{
    class ADDON
    {
        name = "TBMod Spectrum";

        requiredAddons[] = {
            "TBMod_main"
        };

        addonRootClass = "TBMod_main";
    };
};

PRELOAD_ADDONS;

// Configs
#include "configs\CfgFunctions.hpp"
#include "configs\ExtendedEventHandlers.hpp"
