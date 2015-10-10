#include "StateList.h"

bool ActState::checkStateChange() //״̬�ı䷵��true��״̬δ�ı䷵��false��
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