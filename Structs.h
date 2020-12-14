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

union dvar_value_t
{
	char* string;
	int		integer;
	float	value;
	bool	boolean;
	float	vec2[2];
	float	vec3[3];
	float	vec4[4];
	BYTE	color[4];

	dvar_value_t();

	dvar_value_t(int value);
	dvar_value_t(bool value);
	dvar_value_t(float x, float y);
	dvar_value_t(float x, float y, float z);
	dvar_value_t(float x, float y, float z, float w);
	dvar_value_t(BYTE r, BYTE g, BYTE b, BYTE a);
	dvar_value_t(float value);
	dvar_value_t(char* string);
};

union dvar_maxmin_t
{
	int i;
	float f;

	dvar_maxmin_t(int i);
	dvar_maxmin_t(float f);
};

typedef struct dvar_t
{
	const char* name;
	short			flags;
	char			pad1[2];
	char			type;
	char			pad2[3];
	dvar_value_t	current;
	dvar_value_t	latched;
	dvar_value_t	default_value;
	dvar_maxmin_t	min;
	dvar_maxmin_t	max;
	dvar_t* next;
	dvar_t* hashNext;
} dvar_t;		

#pragma pack()