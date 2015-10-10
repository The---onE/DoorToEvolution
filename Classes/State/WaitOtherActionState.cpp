#include "StateList.h"

bool WaitOtherActionState::checkStateChange() //״̬�ı䷵��true��״̬δ�ı䷵��false��
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