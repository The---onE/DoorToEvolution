#pragma once

#include "Global.h"
#include "Warrior.h"

class TeamXPlayer : public Warrior
{
public:
	CREATE_FUNC(TeamXPlayer);
	bool init();
};