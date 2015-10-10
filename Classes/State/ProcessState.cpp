#include "StateList.h"

bool ProcessState::checkStateChange() //状态改变返回true，状态未改变返回false，
{
	if (time > 0.8)
	{
		switch (flag)
		{
		case WIN:
			CHANGE_TO_STATE(WinState);
			break;
		case LOSE:
			CHANGE_TO_STATE(LoseState);
			break;
		case DEAD:
			CHANGE_TO_STATE(DieState);
			break;
		default:
			CHANGE_TO_STATE(EffectState);
			break;
		}
	}
	return false;
}

bool ProcessState::entryState()
{
	scene->changeStateLabel("Processing...");
	flag = scene->processAction();
	return true;
}

void ProcessState::onUpdate(float dt)
{
	time += dt;
	scene->processBasicController();
}

bool ProcessState::exitState()
{
	scene->removeStateLabel();
	return true;
}