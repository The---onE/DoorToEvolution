#include "StateList.h"

bool LoseState::checkStateChange() //״̬�ı䷵��true��״̬δ�ı䷵��false��
{
	return false;
}

bool LoseState::entryState()
{
	scene->changeStateLabel("You lose!");
	return true;
}

void LoseState::onUpdate(float dt)
{
	time += dt;
	scene->processBasicController();
}

bool LoseState::exitState()
{
	scene->removeStateLabel();
	return true;
}