// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "Dvar.h"

DWORD WINAPI EntryPoint(LPVOID _arguments)
{
    Dvar_LockDvar("cg_crosshairEnemyColor", 1);
    Dvar_LockDvar("cg_drawcrosshairnames", 1);
    Dvar_LockDvar("cg_brass", 1);
    Dvar_LockDvar("r_fog", 1);
    Dvar_LockDvar("r_fastskin", 1);
    Dvar_LockDvar("clientsideeffects", 1);
    Dvar_LockDvar("ragdoll_enable", 1);
    Dvar_LockDvar("cg_blood", 1);
    Dvar_LockDvar("cg_crosshairDynamic", 0);
    Dvar_LockDvar("cg_drawCrosshair", 1);
    Dvar_LockDvar("ui_drawCrosshair", 1);
    Dvar_LockDvar("fx_draw", 0);
    Dvar_LockDvar("cg_drawDamageFlash", 0);
    Dvar_LockDvar("cg_hudGrenadeIconMaxRangeFlash", 1200.0f);
    Dvar_LockDvar("cg_hudGrenadeIconMaxRangeFrag", 1200.0f);
    Dvar_LockDvar("cg_hudGrenadeIconMaxHeight", 200.0f);
    Dvar_LockDvar("perk_footstepVolumeEnemy", 16.0f);
    Dvar_LockDvar("perk_footstepVolumeAlly", 0.0f);
    Dvar_LockDvar("perk_footstepVolumePlayer", 0.0f);
    Dvar_LockDvar("perk_parabolicAngle", 180.0f);

    Dvar_LockDvar("g_hardcore", false);
    Dvar_LockDvar("ui_hud_hardcore", false);
    Dvar_LockDvar("compassPortableRadarRadius", 850.0f);
    Dvar_LockDvar("compassPortableRadarSweepTime", 2000);
    Dvar_LockDvar("compassPortableRadarMinVelocity", 500.0f);
    Dvar_LockDvar("compassRadarPingFadeTime", 4.0f);
    Dvar_LockDvar("ui_debugMode", true);

    dvar_t* dvar_1 = Dvar_FindDvar("cg_fov", true);
    Dvar_LockDvar(dvar_1, 100.0f);
    dvar_t * dvar_3 = Dvar_FindDvar("ragdoll_debug", true);
    dvar_3->current = true;
    dvar_t* dvar_4 = Dvar_FindDvar("radius_damage_debug", true);
    dvar_4->current = true;
    dvar_t* dvar_5 = Dvar_FindDvar("com_maxfps", true);
    dvar_5->current = 125;
    dvar_t* dvar_6 = Dvar_FindDvar("player_debugHealth", true);
    dvar_6->current = 1;

    dvar_t* dvar_2 = Dvar_FindDvar("perk_parabolicRadius", true);
    Dvar_LockDvar(dvar_2, 2400.0f);

    return 0x1337;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        ::CreateThread(0, 0, static_cast<LPTHREAD_START_ROUTINE>(EntryPoint), 0, 0, 0);
        [[fallthrough]];
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}