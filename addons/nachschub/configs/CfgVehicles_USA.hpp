/*
    Part of the TBMod ( https://github.com/TacticalBaconDevs/TBMod )
    Developed by http://tacticalbacon.de
*/
class TB_supply_usa_ammo : WRAPPER_NAME(Box_IND_Wps_F)
{
    PUBLIC_NAME_CAT("Munition",USA);

    class TransportMagazines
    {
        MACRO_ADDMAGAZINE(rhs_mag_30Rnd_556x45_M855A1_EPM_Pull_Tracer_Red,35);  // Standard GewehrMag
        MACRO_ADDMAGAZINE(rhsusf_20Rnd_762x51_SR25_m62_Mag,9);                  // DMRMag7.62 SR25
        MACRO_ADDMAGAZINE(rhsusf_20Rnd_762x51_m993_Mag,9);                      // DMRMag7.62 M14
        MACRO_ADDMAGAZINE(rhsusf_8Rnd_00Buck,7);                                // Schrotflinte
        MACRO_ADDMAGAZINE(rhsusf_8Rnd_Slug,7);                                  // Schrotflinte
        MACRO_ADDMAGAZINE(rhsusf_5Rnd_00Buck,7);                                // Schrotflinte
        MACRO_ADDMAGAZINE(rhsusf_5Rnd_Slug,7);                                  // Schrotflinte
        MACRO_ADDMAGAZINE(rhsusf_200Rnd_556x45_M855_mixed_soft_pouch_coyote,2); // MGMag5.56 Tracer
        MACRO_ADDMAGAZINE(TB_mag_100Rnd_556x45_Mk318_tracer,2);                 // MGMag5.56 C-Mag Tracer
        MACRO_ADDMAGAZINE(rhsusf_100Rnd_762x51_m62_tracer,2);                   // MGMag7.62 AP Tracer
        MACRO_ADDMAGAZINE(TB_mag_100Rnd_338_LS_Tracer,2);                       // MGMag8.6 Tracer
        MACRO_ADDMAGAZINE(TB_mag_40Rnd_45_JHP_Tracer_Red,3);                    // Vector.45 Tracer
    };
};

class TB_supply_usa_ammo_m249_lmg : WRAPPER_NAME(Box_IND_Wps_F)
{
    PUBLIC_NAME_CAT("M249 Munition",USA);

    class TransportMagazines
    {
        MACRO_ADDMAGAZINE(rhsusf_200Rnd_556x45_M855_soft_pouch_coyote,12);       // MGMag5.56
        MACRO_ADDMAGAZINE(rhsusf_200Rnd_556x45_M855_mixed_soft_pouch_coyote,12); // MGMag5.56 Tracer
    };
};

class TB_supply_usa_ammo_m27_lmg : WRAPPER_NAME(Box_IND_Wps_F)
{
    PUBLIC_NAME_CAT("M27 IAR Munition",USA);

    class TransportMagazines
    {
        MACRO_ADDMAGAZINE(TB_mag_100Rnd_556x45_Mk318_tracer,15);                 // MGMag5.56 C-Mag Tracer
        MACRO_ADDMAGAZINE(TB_mag_100Rnd_556x45_Mk318_dim,15);                    // MGMag5.56 C-Mag DIM
    };
};

class TB_supply_usa_ammo_mk48_mmg : WRAPPER_NAME(Box_IND_Wps_F)
{
    PUBLIC_NAME_CAT("Mk48 Munition",USA);

    class TransportMagazines
    {
        MACRO_ADDMAGAZINE(TB_mag_100Rnd_338_LS_Tracer,7);                       // MGMag8.6 Tracer
        MACRO_ADDMAGAZINE(TB_mag_100Rnd_338_LS_DIM,7);                          // MGMag8.6 DIM
    };
};

class TB_supply_usa_ammo_m240_mmg : WRAPPER_NAME(Box_IND_Wps_F)
{
    PUBLIC_NAME_CAT("M240 Munition",USA);

    class TransportMagazines
    {
        MACRO_ADDMAGAZINE(rhsusf_100Rnd_762x51_m62_tracer,15);                   // MGMag7.62 AP Tracer
        MACRO_ADDMAGAZINE(rhsusf_100Rnd_762x51_m61_ap,15);                       // MGMag7.62 AP
    };
};

class TB_supply_usa_ammoSmall : WRAPPER_NAME(Box_East_Support_F)
{
    PUBLIC_NAME_CAT("HandwaffenMunition",USA);

    class TransportMagazines
    {
        MACRO_ADDMAGAZINE(rhsusf_mag_17Rnd_9x19_JHP,15);
        MACRO_ADDMAGAZINE(rhsusf_mag_7x45acp_MHP,15);
        MACRO_ADDMAGAZINE(rhsusf_mag_15Rnd_9x19_JHP,15);
        MACRO_ADDMAGAZINE(TB_mag_6Rnd_500_FMJ,15);
    };
};

class TB_supply_usa_grena : WRAPPER_NAME(Box_IND_Grenades_F)
{
    PUBLIC_NAME_CAT("Granaten",USA);

    class TransportMagazines
    {
        MACRO_ADDMAGAZINE(SmokeShell,15);
        MACRO_ADDMAGAZINE(SmokeShellRed,5);
        MACRO_ADDMAGAZINE(SmokeShellBlue,5);

        MACRO_ADDMAGAZINE(rhs_mag_mk3a2,20);    // Offensivenade
        MACRO_ADDMAGAZINE(rhs_mag_mk84,10);     // Stannade
        MACRO_ADDMAGAZINE(B_IR_Grenade,6);      // IR-Granate
    };
};

class TB_supply_usa_unterlauf : WRAPPER_NAME(Box_IND_Support_F)
{
    PUBLIC_NAME_CAT("Unterlauf",USA);

    class TransportMagazines
    {
        // Explosiv
        MACRO_ADDMAGAZINE(TB_rhs_mag_40mm_HE,20);
        MACRO_ADDMAGAZINE(TB_rhs_mag_40mm_HEDP,10);

        // AIM Smokes
        MACRO_ADDMAGAZINE(3Rnd_Smoke_Grenade_shell_precise,4);
        MACRO_ADDMAGAZINE(rhs_mag_m714_White_precise,4);
        MACRO_ADDMAGAZINE(rhs_mag_m713_Red_precise,2);
        MACRO_ADDMAGAZINE(rhs_mag_m715_Green_precise,2);
        MACRO_ADDMAGAZINE(rhs_mag_m716_Yellow_precise,2);

        // Flares
        MACRO_ADDMAGAZINE(TB_rhs_mag_M585_white,4);
        MACRO_ADDMAGAZINE(TB_rhs_mag_m661_green,1);
        MACRO_ADDMAGAZINE(TB_rhs_mag_m662_red,1);

        // IR + Slug
        MACRO_ADDMAGAZINE(TB_rhs_mag_40mm_IR_Grenade,2);
        MACRO_ADDMAGAZINE(TB_rhs_mag_40mm_Slugshot,6);
        MACRO_ADDMAGAZINE(ACE_HuntIR_M203,6);

        // 12.7mm UL
        MACRO_ADDMAGAZINE(TB_mag_MPR_10Rnd_Antimateriel,3);
        MACRO_ADDMAGAZINE(TB_mag_MPR_10Rnd_Slug,3);
        MACRO_ADDMAGAZINE(TB_mag_MPR_10Rnd_Buckshot,3);
    };
};

class TB_supply_usa_praezision : WRAPPER_NAME(Box_East_Wps_F)
{
    PUBLIC_NAME_CAT("PräzisionswaffenMunition",USA);

    class TransportMagazines
    {
        // 12.7
        MACRO_ADDMAGAZINE(rhsusf_mag_10Rnd_STD_50BMG_M33,8);
        MACRO_ADDMAGAZINE(rhsusf_mag_10Rnd_STD_50BMG_mk211,8);

        // 8.6
        MACRO_ADDMAGAZINE(TB_mag_10Rnd_338_LS_Tracer,8);
        MACRO_ADDMAGAZINE(TB_mag_10Rnd_338_LS_DIM,8);

        // DMR7.62
        MACRO_ADDMAGAZINE(rhs_mag_20Rnd_SCAR_762x51_m80a1_epr,8);
        MACRO_ADDMAGAZINE(rhsusf_5Rnd_762x51_m118_special_Mag,16);
    };
};

class TB_supply_usa_launcher : WRAPPER_NAME(Box_EAST_WpsLaunch_F)
{
    PUBLIC_NAME_CAT("O-U Werfer",USA);

    class TransportWeapons
    {
        MACRO_ADDWEAPON(rhs_weap_M136,2);
        MACRO_ADDWEAPON(TB_rhs_weap_M136_CS,2);
        MACRO_ADDWEAPON(rhs_weap_M136_hedp,2);
        MACRO_ADDWEAPON(rhs_weap_m72a7,4);
    };
};

class TB_supply_usa_javlinAmmo : WRAPPER_NAME(Box_NATO_WpsLaunch_F)
{
    PUBLIC_NAME_CAT("JavlinMunition",USA);

    class TransportMagazines
    {
        MACRO_ADDMAGAZINE(rhs_fgm148_magazine_AT,5);
    };
};

class TB_supply_usa_MAAWSAmmo : WRAPPER_NAME(Box_East_WpsSpecial_F)
{
    PUBLIC_NAME_CAT("MAAWSMunition",USA);

    class TransportMagazines
    {
        MACRO_ADDMAGAZINE(rhs_mag_maaws_HEAT,5);
        MACRO_ADDMAGAZINE(rhs_mag_maaws_HEDP,4);
        MACRO_ADDMAGAZINE(rhs_mag_maaws_HE,4);
    };
};

class TB_supply_usa_SMAWAmmo : WRAPPER_NAME(Box_NATO_WpsSpecial_F)
{
    PUBLIC_NAME_CAT("SMAWMunition",USA);

    class TransportMagazines
    {
        MACRO_ADDMAGAZINE(rhs_mag_smaw_HEAA,6);
        MACRO_ADDMAGAZINE(rhs_mag_smaw_HEDP,6);
        MACRO_ADDMAGAZINE(rhs_mag_smaw_SR,4);
    };
};

class TB_supply_usa_FIM92Ammo : WRAPPER_NAME(Box_NATO_WpsSpecial_F)
{
    PUBLIC_NAME_CAT("StingerMunition",USA);

    class TransportMagazines
    {
        MACRO_ADDMAGAZINE(rhs_fim92_mag,12);
    };
};

class TB_supply_usa_notfall : WRAPPER_NAME(Box_NATO_Wps_F)
{
    PUBLIC_NAME_CAT("Notfall",USA);

    class TransportWeapons
    {
        MACRO_ADDWEAPON(rhs_weap_mk17_CQC,2);
    };

    class TransportMagazines
    {
        MACRO_ADDMAGAZINE(rhs_mag_30Rnd_556x45_M855A1_EPM_Pull,12);
        MACRO_ADDMAGAZINE(SmokeShellBlue,1);
        MACRO_ADDMAGAZINE(SmokeShell,2);
    };

    class TransportItems
    {
        MACRO_ADDITEM(ACE_IR_Strobe_Item,2);
        MACRO_ADDITEM(ACE_Chemlight_HiRed,2);

        MACRO_ADDITEM(ACE_quikclot,20);
        MACRO_ADDITEM(ACE_tourniquet,8);
        MACRO_ADDITEM(ACE_adenosine,4);

        MACRO_ADDITEM(TFAR_anprc152,1);

        MACRO_ADDITEM(Binocular,1);
        MACRO_ADDITEM(ItemCompass,1);
        MACRO_ADDITEM(ItemMap,1);
        MACRO_ADDITEM(rhsusf_acc_aac_762sdn6_silencer,2);
    };
};

class TB_supply_usa_night : WRAPPER_NAME(Box_East_Support_F)
{
    PUBLIC_NAME_CAT("Nachtkiste",USA);
    hiddenSelectionsTextures[] = {
        QPATHTOEF(skins,pictures\statics\AmmoBox_signs_CA_0_1.paa),
        QPATHTOEF(skins,pictures\statics\Box_T_East_Wps_F_co_1.paa)
    };

    class TransportItems
    {
        MACRO_ADDITEM(rhsusf_ANPVS_14,20);
        MACRO_ADDITEM(rhsusf_ANPVS_15,20);

        MACRO_ADDITEM(ACE_IR_Strobe_Item,20);
        MACRO_ADDITEM(ACE_Flashlight_KSF1,20);

        MACRO_ADDITEM(ACE_Chemlight_HiYellow,40);
        MACRO_ADDITEM(ACE_Chemlight_HiRed,40);
    };
};

class TB_supply_usa_airdrop : WRAPPER_NAME(B_supplyCrate_F)
{
    PUBLIC_NAME_CAT("Airdrop",USA);

    class TransportWeapons
    {
        MACRO_ADDWEAPON(TB_rhs_weap_M136_CS,3);
        MACRO_ADDWEAPON(launch_NLAW_F,1);
    };

    class TransportMagazines
    {
        // Explosiv
        MACRO_ADDMAGAZINE(TB_rhs_mag_40mm_HE,20);
        MACRO_ADDMAGAZINE(TB_rhs_mag_40mm_HEDP,10);

        // AIM Smokes
        MACRO_ADDMAGAZINE(3Rnd_Smoke_Grenade_shell_precise,2);
        MACRO_ADDMAGAZINE(rhs_mag_m714_White_precise,2);
        MACRO_ADDMAGAZINE(rhs_mag_m713_Red_precise,2);
        MACRO_ADDMAGAZINE(rhs_mag_m715_Green_precise,2);

        // HuntIR
        MACRO_ADDMAGAZINE(ACE_HuntIR_M203,4);

        // Grenades
        MACRO_ADDMAGAZINE(SmokeShell,20);
        MACRO_ADDMAGAZINE(SmokeShellRed,4);
        MACRO_ADDMAGAZINE(SmokeShellBlue,4);

        MACRO_ADDMAGAZINE(rhs_mag_mk3a2,20);    // Offensivenade
        MACRO_ADDMAGAZINE(B_IR_Grenade,4);      // IR-Granate

        // 5.56
        MACRO_ADDMAGAZINE(rhs_mag_30Rnd_556x45_M855A1_EPM_Pull_Tracer_Red,40);  // Standard GewehrMag

        // MGs
        MACRO_ADDMAGAZINE(rhsusf_200Rnd_556x45_M855_mixed_soft_pouch_coyote,3); // MGMag5.56 Tracer
        MACRO_ADDMAGAZINE(rhsusf_200Rnd_556x45_M855_soft_pouch_coyote,3);       // MGMag5.56
        MACRO_ADDMAGAZINE(TB_mag_100Rnd_556x45_Mk318_tracer,6);                 // MGMag5.56 C-Mag Tracer
        MACRO_ADDMAGAZINE(TB_mag_100Rnd_338_LS_Tracer,6);                       // MGMag8.6 Tracer
        MACRO_ADDMAGAZINE(TB_mag_100Rnd_338_LS_DIM,6);                          // MGMag8.6 DIM
        MACRO_ADDMAGAZINE(rhsusf_100Rnd_762x51_m62_tracer,6);                  // MGMag7.62 AP Tracer
        MACRO_ADDMAGAZINE(rhsusf_100Rnd_762x51_m61_ap,6);                      // MGMag7.62 AP

        // Secondary
        MACRO_ADDMAGAZINE(rhsusf_mag_17Rnd_9x19_JHP,15);
        MACRO_ADDMAGAZINE(rhsusf_mag_7x45acp_MHP,15);
        MACRO_ADDMAGAZINE(rhsusf_mag_15Rnd_9x19_JHP,15);
        MACRO_ADDMAGAZINE(TB_mag_6Rnd_500_FMJ,15);

        // 12.7
        MACRO_ADDMAGAZINE(rhsusf_mag_10Rnd_STD_50BMG_M33,6);
        MACRO_ADDMAGAZINE(rhsusf_mag_10Rnd_STD_50BMG_mk211,6);

        // 8.6
        MACRO_ADDMAGAZINE(TB_mag_10Rnd_338_LS_Tracer,6);
        MACRO_ADDMAGAZINE(TB_mag_10Rnd_338_LS_DIM,6);

        // DMR7.62
        MACRO_ADDMAGAZINE(rhs_mag_20Rnd_SCAR_762x51_m80a1_epr,8);               // SCAR TPR
        MACRO_ADDMAGAZINE(rhsusf_5Rnd_762x51_m118_special_Mag,32);              // M24
        MACRO_ADDMAGAZINE(rhsusf_20Rnd_762x51_SR25_m62_Mag,8);                  // DMRMag7.62 SR25
        MACRO_ADDMAGAZINE(rhsusf_20Rnd_762x51_m993_Mag,8);                      // DMRMag7.62 M14

        // Shotgun
        MACRO_ADDMAGAZINE(rhsusf_8Rnd_00Buck,7);                                // Schrotflinte
        MACRO_ADDMAGAZINE(rhsusf_8Rnd_Slug,7);                                  // Schrotflinte
        MACRO_ADDMAGAZINE(rhsusf_5Rnd_00Buck,7);                                // Schrotflinte
        MACRO_ADDMAGAZINE(rhsusf_5Rnd_Slug,7);                                  // Schrotflinte

        // 12.7mm UL
        MACRO_ADDMAGAZINE(TB_mag_MPR_10Rnd_Antimateriel,5);
        MACRO_ADDMAGAZINE(TB_mag_MPR_10Rnd_Slug,5);
        MACRO_ADDMAGAZINE(TB_mag_MPR_10Rnd_Buckshot,5);

        // .45
        MACRO_ADDMAGAZINE(TB_mag_40Rnd_45_JHP_Tracer_Red,10);                    // Vector.45 Tracer
    };

    class TransportItems
    {
        MACRO_ADDITEM(ACE_quikclot,50);
        MACRO_ADDITEM(ACE_elasticBandage,50);
        MACRO_ADDITEM(ACE_packingBandage,50);

        MACRO_ADDITEM(ACE_plasmaIV_500,6);

        MACRO_ADDITEM(ACE_morphine,20);
        MACRO_ADDITEM(ACE_epinephrine,10);
        MACRO_ADDITEM(TB_med_venenkatheter,10);
    };
};
