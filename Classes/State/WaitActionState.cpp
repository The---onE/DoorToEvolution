#include "StateList.h"

bool WaitActionState::checkStateChange() //状态改变返回true，状态未改变返回false，
{
	if (scene->processWarriorController() == ACTION)
		CHANGE_TO_STATE(WaitOtherActionState);
	return false;
}

bool WaitActionState::entryState()
{
	scene->changeStateLabel("Waiting your action...");
	scene->prepareThisRound();
	return true;
}

void WaitActionState::onUpdate(float dt)
{
	time += dt;
	scene->processBasicController();
}

bool WaitActionState::exitState()
{
	scene->removeStateLabel();
	return true;
}