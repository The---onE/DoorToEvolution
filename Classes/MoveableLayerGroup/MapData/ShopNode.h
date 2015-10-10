#pragma once

#include "Global.h"
#include "MapNode.h"

class ShopNode : public MapNode
{
public:
	CREATE_FUNC(ShopNode);
	bool init();

	int leave(Warrior* warrior);
	int arrive(Warrior* warrior);
	int rest(Warrior* warrior);
};