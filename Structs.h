#pragma once
#include <Windows.h>

typedef enum errorParam_t
{
	ERR_FATAL = 0,
	ERR_DROP = 1,	
};

typedef enum
{
	DVAR_TYPE_BOOL = 0,
	DVAR_TYPE_FLOAT = 1,
	DVAR_TYPE_FLOAT_2 = 2,
	DVAR_TYPE_FLOAT_3_2 = 3,
	DVAR_TYPE_FLOAT_3 = 9,
	DVAR_TYPE_FLOAT_4 = 4,
	DVAR_TYPE_INT = 5,
	DVAR_TYPE_ENUM = 6,
	DVAR_TYPE_STRING = 7,
	DVAR_TYPE_COLOR = 8,
} dvar_type;

typedef enum
{
	DVF_UNK1 = 1,
	DVF_NEEDS_RESTART = 2,
	DVF_CHEAT_PROTECTED = 4,
	DVF_UNK2 = 0x200,
	DVF_SYSTEM = 0x400,
	DVF_WRITE_PROTECTED = 0x800,
	DVF_READ_ONLY = 0x2000,
	DVF_PRINTABLE = 0x10000
} dvarFlags_e;

union DvarValue
{
	bool enabled;
	int integer;
	unsigned int unsignedInt;
	float value;
	float vector[4];
	const char* string;
	char color[4];

	DvarValue(int value);
	DvarValue(bool value);
	DvarValue(float x, float y, float z, float w);
	DvarValue(BYTE r, BYTE g, BYTE b, BYTE a);
	DvarValue(float value);
	DvarValue(char* string);
};

struct enum_limit
{
	int stringCount;
	const char** strings;
};

struct int_limit
{
	int min;
	int max;
};

struct float_limit
{
	float min;
	float max;
};

union DvarLimits
{
	enum_limit enumeration;
	int_limit integer;
	float_limit value;
	float_limit vector;
};

struct dvar_t
{
	const char* name;
	unsigned int flags;
	char type;
	bool modified;
	DvarValue current;
	DvarValue latched;
	DvarValue reset;
	DvarLimits domain;
	bool(__cdecl* domainFunc)(dvar_t*, DvarValue);
	dvar_t* hashNext;
};

#pragma pack()