#include "MapDataLayer.h"

bool MapDataLayer::init()
{
	Layer::init();

	mapNode[0] = DoorNode::create();

	mapNode[1] = ShopNode::create();
	mapNode[3] = ShopNode::create();

	mapNode[2] = HospitalNode::create();
	mapNode[4] = HospitalNode::create();

	mapNode[5] = BramblesNode::create();
	mapNode[6] = BramblesNode::create();
	mapNode[7] = BramblesNode::create();
	mapNode[8] = BramblesNode::create();

	mapNode[9] = BoxNode::create();
	mapNode[10] = BoxNode::create();
	mapNode[11] = BoxNode::create();
	mapNode[12] = BoxNode::create();

	mapNode[13] = HotelNode::create();
	mapNode[14] = HotelNode::create();
	mapNode[15] = HotelNode::create();
	mapNode[16] = HotelNode::create();

	for (int i = 0; i < TOTAL_NODE; i++)
	{
		mapNode[i]->setNodePosition(node[i]);
		this->addChild(mapNode[i]);
	}

	return true;
}

int MapDataLayer::leave(Warrior* warrior, int index)
{
	return mapNode[index]->leave(warrior);
}

int MapDataLayer::arrive(Warrior* warrior, int index)
{
	return mapNode[index]->arrive(warrior);
}

int MapDataLayer::rest(Warrior* warrior, int index)
{
	return mapNode[index]->rest(warrior);
}

void MapDataLayer::roundStart(Warrior* warrior)
{
	for (int i = 0; i < TOTAL_NODE; i++)
	{
		mapNode[i]->roundStart(warrior);
	}
}

void MapDataLayer::roundEnd(Warrior* warrior)
{
	for (int i = 0; i < TOTAL_NODE; i++)
	{
		mapNode[i]->roundEnd(warrior);
	}
}

int MapDataLayer::processMapNode(int index)
{
	int count = mapNode[index]->restingWarrior.size();
	if (count > 0)
	{
		if (count > 1)
		{
			Warrior* w = mapNode[index]->restingWarrior.at(0);
		}
		else
		{
			Warrior* w = mapNode[index]->restingWarrior.at(0);
		}
	}

	return NOEVENT;
}

int MapDataLayer::processAllMapNode()
{
	for (int i = 0; i < TOTAL_NODE; i++)
	{
		processMapNode(i);
	}

	return NOEVENT;
}