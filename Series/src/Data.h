#pragma once
#include <stdint.h>
#include <string>

const char* WINSET_FORMAT_IN =  "{\n\t\
\"WindowWidth\":%d, \n\t \
\"WindowHeight\":%d, \n\t \
\"WindowTitle\":\"%[^\"]\", \n\t \
\"MSAA\":%d, \n\t\
\"IsFullscreen\":%d \n \
}\n";
const char* WINSET_FORMAT_OUT = "{\n\t\
\"WindowWidth\":%d, \n\t\
\"WindowHeight\":%d, \n\t\
\"WindowTitle\":\"%s\", \n\t\
\"MSAA\":%d, \n\t\
\"IsFullscreen\":%d \n\
}\n";

const char* WINSET_FORMAT_IN_OLD =  "{'WindowWidth':'%d', 'WindowHeight':'%d', 'WindowTitle':'%[^ ']', 'IsFullscreen':'%d'}\n";
const char* WINSET_FORMAT_OUT_OLD = "{'WindowWidth':'%d', 'WindowHeight':'%d', 'WindowTitle':'%s', 'IsFullscreen':'%d'}\n";

typedef struct WindowSettings
{
	uint32_t WindowWidth;
	uint32_t WindowHeight;
	char WindowTitle[64];
	uint32_t MSAA;
	int8_t IsFullscreen;
	
} WindowSettings;

