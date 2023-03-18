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
	/*TODO: add some api to add options / keys from the user / programmer
	like :
	options->AddKey("Quality", (default value) Options::HIGH);
	How would that work with the setters and getters?

	options->AddKey(..., ...)
	maybe options has a hash map of all the keys and values?
	hashmap<std::string, Type?> map;
	it should be kinda easy to implement?
	
	we atleast know we have strings and int32_t's or do just store ints with enums as helpers? It's easier... TODO: decide!
	
	std::vector<std::string, int32_t> m_OptionsMap?
	options->GetInt("Fullscreen");
	int GetInt(string) { return value of key in vector? }  
	
	
	
	*/



	return 0;
}

