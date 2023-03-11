#include "stdsrs.h"
#include "Data.h"
#include <iostream>

int main ()
{
	printf("Hello World!\n");

	WindowSettings DefaultWindowSettings = {
		1280, 720, "My Window Title", 4, 0
	};
	WindowSettings WindowSettings = {0};

	FILE* file;
	fopen_s(&file, "WindowSettings.json", "r+");

	if (file == nullptr)
	{
		return 1;
	}
	
	//fprintf_s(file, WINSET_FORMAT_OUT, DefaultWindowSettings.WindowWidth, DefaultWindowSettings.WindowHeight, DefaultWindowSettings.WindowTitle, DefaultWindowSettings.MSAA, DefaultWindowSettings.IsFullscreen);
	fseek(file, 0, SEEK_SET);

	fscanf_s(file, WINSET_FORMAT_IN, &WindowSettings.WindowWidth, &WindowSettings.WindowHeight, &WindowSettings.WindowTitle, 64, &WindowSettings.MSAA, &WindowSettings.IsFullscreen);
	std::cout << "window width: " << WindowSettings.WindowWidth << std::endl;
	fclose(file);
	std::cin.get();
	return 0;
}