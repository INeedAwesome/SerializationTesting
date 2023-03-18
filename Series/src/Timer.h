#pragma once
#include <chrono>

#define MILLISECOND_IN_SECOND 1000

struct Timer
{
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration = std::chrono::duration<float>(0);

	Timer()
	{
		start = std::chrono::high_resolution_clock::now();
	}
	float Time()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = (end - start) * MILLISECOND_IN_SECOND;
		return duration.count();
	}

};
