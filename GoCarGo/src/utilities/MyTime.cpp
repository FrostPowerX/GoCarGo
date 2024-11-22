#include "MyTime.h"

float game::MyTime::deltaTime = 0;

game::MyTime::MyTime()
{
	startTime = 0;
	endTime = 0;
}

void game::MyTime::Start()
{
	startTime = static_cast<float>(clock());
}

void game::MyTime::Stop()
{
	endTime = static_cast<float>(clock());

	deltaTime = (endTime - startTime) / CLOCKS_PER_SEC;
}
