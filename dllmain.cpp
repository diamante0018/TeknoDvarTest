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

    //Dvar_LockDvar("compassPortableRadarRadius", ???.0f); //TODO Find default value in case it gets modified by Server Script

    dvar_t* dvar_4 = Dvar_FindDvar("cg_fov", true);
    Dvar_LockDvar(dvar_4, 100.0f);

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

