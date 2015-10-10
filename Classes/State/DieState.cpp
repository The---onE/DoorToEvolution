#include "StateList.h"

bool DieState::checkStateChange() //״̬�ı䷵��true��״̬δ�ı䷵��false��
{
	CHANGE_TO_STATE(EffectState);
	return false;
}

bool DieState::entryState()
{
	scene->changeStateLabel("You die!");
	return true;
}

void DieState::onUpdate(float dt)
{
	time += dt;
	scene->processBasicController();
}

bool DieState::exitState()
{
	scene->removeStateLabel();
	return true;
}