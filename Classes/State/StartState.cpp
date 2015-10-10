#include "StateList.h"

bool StartState::checkStateChange() //状态改变返回true，状态未改变返回false，
{
	if (time > 0.8)
		CHANGE_TO_STATE(InitiationState);
	return false;
}

bool StartState::entryState()
{
	scene->changeStateLabel("Starting...");
	return true;
}

void StartState::onUpdate(float dt)
{
	time += dt;
}

bool StartState::exitState()
{
	scene->removeStateLabel();
	return true;
}