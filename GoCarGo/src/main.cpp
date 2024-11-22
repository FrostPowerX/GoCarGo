#include "GameLoop.h"

using namespace game;

int main()
{
	GameLoop gameLoop;

	GameLoop::Instance().Play();

	return 0;
}