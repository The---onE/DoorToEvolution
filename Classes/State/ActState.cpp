#include "StateList.h"

bool ActState::checkStateChange() //状态改变返回true，状态未改变返回false，
{
	if (time > 0.8)
		CHANGE_TO_STATE(ProcessState);
	return false;
}

bool ActState::entryState()
{
	scene->changeStateLabel("Acting...");
	scene->act();
	return true;
}

void ActState::onUpdate(float dt)
{
	time += dt;
	scene->processBasicController();
}

bool ActState::exitState()
{
	scene->removeStateLabel();
	return true;
}