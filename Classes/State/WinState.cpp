#include "StateList.h"

bool WinState::checkStateChange() //״̬�ı䷵��true��״̬δ�ı䷵��false��
{
	return false;
}

bool WinState::entryState()
{
	scene->changeStateLabel("You win!");
	return true;
}

void WinState::onUpdate(float dt)
{
	time += dt;
	scene->processBasicController();
}

bool WinState::exitState()
{
	scene->removeStateLabel();
	return true;
}