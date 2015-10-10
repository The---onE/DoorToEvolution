#include "StateList.h"

bool RebornState::checkStateChange() //状态改变返回true，状态未改变返回false，
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