#include "stdsrs.h"
#include "Settings.h"

int main(int argc, char** argv[])
{
	printf("Hello World!\n");
	{
		std::unique_ptr<Options::Options> options;
		options = std::make_unique<Options::Options>("Options.dat");
	}

	std::cin.get();
	return 0;
}
