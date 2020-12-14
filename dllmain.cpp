// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "Dvar.h"

DWORD WINAPI EntryPoint(LPVOID _arguments)
{
    dvar_t* dvar = Dvar_FindDvar("cg_drawGun", true);
    dvar->current = 0;
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

