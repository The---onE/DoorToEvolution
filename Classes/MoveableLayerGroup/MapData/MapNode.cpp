#include "MapNode.h"

bool MapNode::init()
{
	Node::init();

// 	for (int i = 0; i < TOTAL_NODE; i++)
// 	{
// 		restingWarrior[i] = false;
// 	}

	return true;
}

void MapNode::setNodePosition(Point p)
{
	position = p;
}

int MapNode::leave(Warrior* warrior)
{
	//restingWarrior[warrior->getIndex()] = false;
	restingWarrior.eraseObject(warrior);

	return NOEVENT;
}

int MapNode::arrive(Warrior* warrior)
{
	//restingWarrior[warrior->getIndex()] = true;
	if (restingWarrior.find(warrior) == restingWarrior.end())
		restingWarrior.pushBack(warrior);

	warrior->checkStaminaOverflow();

	return NOEVENT;
}

int MapNode::rest(Warrior* warrior)
{
	//restingWarrior[warrior->getIndex()] = true;
	if (restingWarrior.find(warrior) == restingWarrior.end())
		restingWarrior.pushBack(warrior);

	warrior->changeStamina();
	warrior->checkStaminaOverflow();

	return NOEVENT;
}

void MapNode::roundStart(Warrior* warrior)
{

}

void MapNode::roundEnd(Warrior* warrior)
{

}