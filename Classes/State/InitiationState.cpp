#include "StateList.h"

bool InitiationState::checkStateChange() //状态改变返回true，状态未改变返回false，
{
	if (time > 0.8)
		CHANGE_TO_STATE(WaitActionState);
	return false;
}

bool InitiationState::entryState()
{
	scene->changeStateLabel("Initiating...");
	scene->initPlayer();
	return true;
}

void InitiationState::onUpdate(float dt)
{
	time += dt;
}

bool InitiationState::exitState()
{
	scene->removeStateLabel();
	return true;
}