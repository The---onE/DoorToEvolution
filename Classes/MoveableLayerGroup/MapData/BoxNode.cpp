#include "BoxNode.h"

bool BoxNode::init()
{
	MapNode::init();

	return true;
}

int BoxNode::arrive(Warrior* warrior)
{
	MapNode::arrive(warrior);

	return NOEVENT;
}

int BoxNode::leave(Warrior* warrior)
{
	MapNode::leave(warrior);

	return NOEVENT;
}

int BoxNode::rest(Warrior* warrior)
{
	MapNode::rest(warrior);

	return NOEVENT;
}