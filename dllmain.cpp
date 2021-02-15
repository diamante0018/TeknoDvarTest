// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "Dvar.h"
#include <cstdio>
#include <tchar.h>
#include <iostream>
#include <string>

typedef dvar_t* (*fun_1)(const char* name);

DWORD addressOfFind = CL_DVAR_FINDDVAR_ADDR;
DWORD addressOfSetValue = CL_DVAR_SETVALUE;

/*dvar_t* HK_FINDDVAR(const char* name) 
{
    fun_1 original = (fun_1)addressOfFind;
    return original(name);
}*/

DWORD WINAPI EntryPoint(LPVOID _arguments)
{
    AllocConsole();
    SetConsoleTitle(_T("Console: Dvar Test"));
    FILE* file = nullptr;
    freopen_s(&file, "CONIN$", "r", stdin);
    freopen_s(&file, "CONOUT$", "w", stdout);
    freopen_s(&file, "CONOUT$", "w", stderr);
    std::ios::sync_with_stdio();

    Dvar_LockDvar("cg_crosshairEnemyColor", 1);
    Dvar_LockDvar("cg_drawcrosshairnames", 1);
    Dvar_LockDvar("cg_drawCrosshair", 1);
    Dvar_LockDvar("cg_brass", 1);
    Dvar_LockDvar("r_fog", 0);
    Dvar_LockDvar("r_fastskin", 1);
    Dvar_LockDvar("clientsideeffects", 1);
    Dvar_LockDvar("ragdoll_enable", 1);
    Dvar_LockDvar("cg_blood", 1);
    Dvar_LockDvar("cg_crosshairDynamic", 1);
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
    Dvar_LockDvar("cg_drawFriendlyNames", 1);
    Dvar_LockDvar("cg_drawMaterial", 0);
    Dvar_LockDvar("cg_drawShellshock", 0);
    Dvar_LockDvar("cg_drawpaused", 0);
    Dvar_LockDvar("cl_enableRCon", 1);
    Dvar_LockDvar("cg_weaponCycleDelay", 0);

    Dvar_LockDvar("g_hardcore", false);
    Dvar_LockDvar("ui_hud_hardcore", false);
    Dvar_LockDvar("compassPortableRadarRadius", 850.0f);
    Dvar_LockDvar("compassPortableRadarSweepTime", 2000);
    Dvar_LockDvar("compassPortableRadarMinVelocity", 500.0f);
    Dvar_LockDvar("compassRadarPingFadeTime", 4.0f);
    //Dvar_LockDvar("ui_debugMode", true);
    Dvar_LockDvar("cg_draw2D", 0);

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

    printf("Dvar type guide\n");
    printf("0 = int, 1 = float\n");

    std::string dvarName;
    int value = 0;
    float fvalue = 0.0f;
    int type = 0;

    while (true) 
    {
        std::cout << "Enter Dvar Name: ";
        //std::getline(std::cin, dvarName);
        std::cin >> dvarName;

        std::cout << "Enter Dvar Type: ";
        std::cin >> type;

        std::cout << "Enter Value: ";

        switch (type) 
        {
            case 0:
                std::cin >> value;
                Dvar_LockDvar(dvarName.c_str(), value);
                break;
            case 1:
                std::cin >> fvalue;
                Dvar_LockDvar(dvarName.c_str(), fvalue);
                break;
            default:
                printf("Unknown type: %d\n", type);
        }
        
        fvalue = 0.0f;
        value = 0;
        type = 0;
    }

    


    //Dvar_RegisterBool("Cum", true, 0, "You cum");

    //DetourTransactionBegin();
   //DetourUpdateThread(GetCurrentThread());


    //DetourAttach(&(LPVOID&)addressOfFind, &HK_FINDDVAR);
    //DetourAttach(&(LPVOID&)addressOfSetValue, &HK_SETVALUE);
    //DetourTransactionCommit();
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
        FreeConsole();
        break;
    }
    return TRUE;
}