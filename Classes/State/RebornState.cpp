#include "StateList.h"

bool RebornState::checkStateChange() //״̬�ı䷵��true��״̬δ�ı䷵��false��
{
	return false;
}

bool RebornState::entryState()
{
	return true;
}

void RebornState::onUpdate(float dt)
{
	time += dt;
	scene->processBasicController();
}

bool RebornState::exitState()
{
	return true;
}