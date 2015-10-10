#include "StateList.h"

bool WaitActionState::checkStateChange() //״̬�ı䷵��true��״̬δ�ı䷵��false��
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