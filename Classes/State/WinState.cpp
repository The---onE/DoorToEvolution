#include "StateList.h"

bool WinState::checkStateChange() //状态改变返回true，状态未改变返回false，
{
	return false;
}

bool WinState::entryState()
{
	scene->changeStateLabel("You win!");
	return true;
}

void WinState::onUpdate(float dt)
{
	time += dt;
	scene->processBasicController();
}

bool WinState::exitState()
{
	scene->removeStateLabel();
	return true;
}