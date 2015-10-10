#pragma once

#include "Global.h"
#include "MapNode.h"

class DoorNode : public MapNode
{
public:
	CREATE_FUNC(DoorNode);
	bool init();

	int checkWin(Warrior* warrior);

	int leave(Warrior* warrior);
	int arrive(Warrior* warrior);
	int rest(Warrior* warrior);
};