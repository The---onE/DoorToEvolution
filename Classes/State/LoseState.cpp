#include "StateList.h"

bool LoseState::checkStateChange() //状态改变返回true，状态未改变返回false，
{
	return false;
}

bool LoseState::entryState()
{
	scene->changeStateLabel("You lose!");
	return true;
}

void LoseState::onUpdate(float dt)
{
	time += dt;
	scene->processBasicController();
}

bool LoseState::exitState()
{
	scene->removeStateLabel();
	return true;
}