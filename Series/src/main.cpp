#include "stdsrs.h"
#include "Settings.h"
#include "Timer.h"

int main(int argc, char** argv[])
{
	printf("Hello World!\n");
	Timer timer;
	{
		std::unique_ptr<Options::Options> options;
		options = std::make_unique<Options::Options>("Options.dat");
		std::cout << timer.Time() << std::endl;
	}

	return 0;
}

