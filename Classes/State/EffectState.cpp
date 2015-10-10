#include "StateList.h"

bool EffectState::checkStateChange() //状态改变返回true，状态未改变返回false，
{
	if (time > 0.8)
		CHANGE_TO_STATE(WaitActionState);
	return false;
}

bool EffectState::entryState()
{
	scene->changeStateLabel("Effecting...");
	return true;
}

void EffectState::onUpdate(float dt)
{
	time += dt;
	scene->processBasicController();
}

bool EffectState::exitState()
{
	scene->removeStateLabel();
	scene->prepareNextRound();
	return true;
}