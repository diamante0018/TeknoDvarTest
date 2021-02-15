#pragma once
#include "Structs.h"
#include "Detours.h"
#include "Address.h"
#include <stdio.h>

typedef dvar_t* (*Dvar_FindVar_t)(const char* name);
typedef dvar_t* (*Dvar_RegisterVec3_t)(const char* dvarName, float x, float y, float z, float min, float max, unsigned __int16 flags, const char* description);
typedef dvar_t* (*Dvar_RegisterVec4_t)(const char* dvarName, float x, float y, float z, float w, float min, float max, unsigned __int16 flags, const char* description);
typedef dvar_t* (*Dvar_RegisterString_t)(const char* dvarName, const char* value, unsigned __int16 flags, const char* description);
typedef dvar_t* (*Dvar_RegisterColor_t)(const char* dvarName, float r, float g, float b, float a, unsigned __int16 flags, const char* description);
typedef dvar_t* (*Dvar_RegisterInt_t)(const char* dvarName, int value, int min, int max, unsigned __int16 flags, const char* description);
typedef dvar_t* (*Dvar_RegisterBool_t)(const char* dvarName, bool value, unsigned __int16 flags, const char* description);
typedef dvar_t* (*Dvar_RegisterFloat_t)(const char* dvarName, float value, float min, float max, unsigned __int16 flags, const char* description);

void Dvar_LockDvar(const char* name, DvarValue newVal);
void Dvar_LockDvar(dvar_t* dvar, DvarValue newVal);
dvar_t* Dvar_FindDvar(const char* name, bool giveDefault);
dvar_t* __cdecl Dvar_RegisterVec3(const char* dvarName, float x, float y, float z, float min, float max, unsigned __int16 flags, const char* description);
dvar_t* __cdecl Dvar_RegisterVec4(const char* dvarName, float x, float y, float z, float w, float min, float max, unsigned __int16 flags, const char* description);
dvar_t* __cdecl Dvar_RegisterBool(const char* dvarName, bool value, unsigned __int16 flags, const char* description);
dvar_t* __cdecl Dvar_RegisterInt(const char* dvarName, int value, int min, int max, unsigned __int16 flags, const char* description);
dvar_t* __cdecl Dvar_RegisterFloat(const char* dvarName, float value, float min, float max, unsigned __int16 flags, const char* description);
dvar_t* __cdecl Dvar_RegisterString(const char* dvarName, const char* value, unsigned __int16 flags, const char* description);
dvar_t* __cdecl Dvar_RegisterColor(const char* dvarName, float r, float g, float b, float a, unsigned __int16 flags, const char* description);