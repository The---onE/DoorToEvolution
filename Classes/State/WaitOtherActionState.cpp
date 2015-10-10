#include "StateList.h"

bool WaitOtherActionState::checkStateChange() //状态改变返回true，状态未改变返回false，
{
	if (time > 2)
		CHANGE_TO_STATE(ActState);
	return false;
}

bool WaitOtherActionState::entryState()
{
	scene->changeStateLabel("Waiting other's action...");
	return true;
}

void WaitOtherActionState::onUpdate(float dt)
{
	time += dt;
	scene->processBasicController();
}

bool WaitOtherActionState::exitState()
{
	scene->removeStateLabel();
	return true;
}