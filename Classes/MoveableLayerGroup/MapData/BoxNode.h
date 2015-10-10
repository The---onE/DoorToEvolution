#pragma once

#include "Global.h"
#include "MapNode.h"

class BoxNode : public MapNode
{
public:
	CREATE_FUNC(BoxNode);
	bool init();

	int leave(Warrior* warrior);
	int arrive(Warrior* warrior);
	int rest(Warrior* warrior);
};