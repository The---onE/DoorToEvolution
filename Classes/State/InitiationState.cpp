#include "StateList.h"

bool InitiationState::checkStateChange() //״̬�ı䷵��true��״̬δ�ı䷵��false��
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