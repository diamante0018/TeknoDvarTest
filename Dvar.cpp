#include "Dvar.h"
#include "Address.h"
#include "Functions.h"

Com_Error_Internal_t CL_Error_Internal = (Com_Error_Internal_t)CL_ERROR_ADDR;

Dvar_FindVar_t CL_Dvar_FindDvar_Internal = (Dvar_FindVar_t)CL_DVAR_FINDDVAR_ADDR;
Dvar_RegisterInt_t CL_Dvar_RegisterInt_Internal = (Dvar_RegisterInt_t)CL_DVAR_REGISTERINT_ADDR;
Dvar_RegisterFloat_t CL_Dvar_RegisterFloat_Internal = (Dvar_RegisterFloat_t)CL_DVAR_REGISTERFLOAT_ADDR;
Dvar_RegisterBool_t CL_Dvar_RegisterBool_Internal = (Dvar_RegisterBool_t)CL_DVAR_REGISTERBOOL_ADDR;
Dvar_RegisterString_t CL_Dvar_RegisterString_Internal = (Dvar_RegisterString_t)CL_DVAR_REGISTERSTRING_ADDR;
Dvar_RegisterVec3_t CL_Dvar_RegisterVec3_Internal = (Dvar_RegisterVec3_t)CL_DVAR_REGISTERVEC3_ADDR;
Dvar_RegisterVec4_t CL_Dvar_RegisterVec4_Internal = (Dvar_RegisterVec4_t)CL_DVAR_REGISTERVEC4_ADDR;
Dvar_RegisterColor_t CL_Dvar_RegisterColor_Internal = (Dvar_RegisterColor_t)CL_DVAR_REGISTERCOLOR_ADDR;

#define FLT_MAX 3.402823466e+38F 

dvar_t* Dvar_FindDvar(const char* name, bool giveDefault)
{
		dvar_t* res = CL_Dvar_FindDvar_Internal(name);
		if (res)
			return res;
		if (giveDefault)
			return CL_Dvar_RegisterString_Internal("sv_undefined", "<undefined>", 0, "default dvar returned for undefined dvars");
	return NULL;
}

dvar_t* __cdecl Dvar_RegisterVec3(const char* dvarName, float x, float y, float z, float min, float max, unsigned __int16 flags, const char* description)
{
	return CL_Dvar_RegisterVec3_Internal(dvarName, x, y, z, min, max, flags, description);
	return NULL;
}

dvar_t* __cdecl Dvar_RegisterVec4(const char* dvarName, float x, float y, float z, float w, float min, float max, unsigned __int16 flags, const char* description)
{	
    return CL_Dvar_RegisterVec4_Internal(dvarName, x, y, z, w, min, max, flags, description);
	return NULL;
}

dvar_t* __cdecl Dvar_RegisterBool(const char* dvarName, bool value, unsigned __int16 flags, const char* description)
{
	return CL_Dvar_RegisterBool_Internal(dvarName, value, flags, description);
	return NULL;
}

dvar_t* __cdecl Dvar_RegisterInt(const char* dvarName, int value, int min, int max, unsigned __int16 flags, const char* description)
{	
	return CL_Dvar_RegisterInt_Internal(dvarName, value, min, max, flags, description);
    return NULL;
}

dvar_t* __cdecl Dvar_RegisterFloat(const char* dvarName, float value, float min, float max, unsigned __int16 flags, const char* description)
{
	return CL_Dvar_RegisterFloat_Internal(dvarName, value, min, max, flags, description);
	return NULL;
}

dvar_t* __cdecl Dvar_RegisterString(const char* dvarName, const char* value, unsigned __int16 flags, const char* description)
{
    return CL_Dvar_RegisterString_Internal(dvarName, value, flags, description);
	return NULL;
}

dvar_t* __cdecl Dvar_RegisterColor(const char* dvarName, float r, float g, float b, float a, unsigned __int16 flags, const char* description)
{
	return CL_Dvar_RegisterColor_Internal(dvarName, r, g, b, a, flags, description);
	return NULL;
}

dvar_value_t::dvar_value_t(int value)
{
	this->integer = value;
}

dvar_value_t::dvar_value_t(bool value)
{
	this->boolean = value;
}

dvar_value_t::dvar_value_t(float x, float y)
{
	this->vec2[0] = x;
	this->vec2[1] = y;
}

dvar_value_t::dvar_value_t(float x, float y, float z)
{
	this->vec3[0] = x;
	this->vec3[1] = y;
	this->vec3[2] = z;
}

dvar_value_t::dvar_value_t(BYTE r, BYTE g, BYTE b, BYTE a)
{
	this->color[0] = r;
	this->color[1] = g;
	this->color[2] = b;
	this->color[3] = a;
}

dvar_value_t::dvar_value_t(float x, float y, float z, float w)
{
	this->vec4[0] = x;
	this->vec4[1] = y;
	this->vec4[2] = z;
	this->vec4[3] = w;
}

dvar_value_t::dvar_value_t(float value)
{
	this->value = value;
}

dvar_value_t::dvar_value_t(char* string)
{
	this->string = string;
}

dvar_maxmin_t::dvar_maxmin_t(int i)
{
	this->i = i;
}

dvar_maxmin_t::dvar_maxmin_t(float f)
{
	this->f = f;
}

void Dvar_LockDvar(const char* name, dvar_value_t newVal)
{
	dvar_t* dvar = Dvar_FindDvar(name, false);

	if (dvar == NULL)
	{
		CL_Error_Internal(ERR_DROP, "Tried to lock a NULL dvar");
		return;
	}

	if (dvar->type | DVAR_TYPE_FLOAT)
	{
		dvar->max = dvar_maxmin_t((float)newVal.value);
		dvar->min = dvar_maxmin_t((float)newVal.value);
	}

	else if (dvar->type | DVAR_TYPE_INT)
	{
		dvar->max = dvar_maxmin_t((int)newVal.integer);
		dvar->min = dvar_maxmin_t((int)newVal.integer);
	}

	else if (dvar->type | DVAR_TYPE_BOOL)
	{
		dvar->max = dvar_maxmin_t((int)newVal.boolean);
		dvar->min = dvar_maxmin_t((int)newVal.boolean);
	}

	dvar->default_value = newVal;
	dvar->current = newVal;
}

void Dvar_LockDvar(dvar_t* dvar, dvar_value_t newVal)
{
	if (dvar == NULL)
	{
		CL_Error_Internal(ERR_DROP, "Tried to lock a NULL given dvar");
		return;
	}

	if (dvar->type | DVAR_TYPE_FLOAT)
	{
		dvar->max = dvar_maxmin_t((float)newVal.value);
		dvar->min = dvar_maxmin_t((float)newVal.value);
	}

	else if (dvar->type | DVAR_TYPE_INT)
	{
		dvar->max = dvar_maxmin_t((int)newVal.integer);
		dvar->min = dvar_maxmin_t((int)newVal.integer);
	}

	else if (dvar->type | DVAR_TYPE_BOOL)
	{
		dvar->max = dvar_maxmin_t((int)newVal.boolean);
		dvar->min = dvar_maxmin_t((int)newVal.boolean);
	}

	dvar->default_value = newVal;
	dvar->current = newVal;
}