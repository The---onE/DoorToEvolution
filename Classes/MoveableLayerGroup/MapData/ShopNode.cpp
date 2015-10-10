#include "ShopNode.h"

bool ShopNode::init()
{
	MapNode::init();

	return true;
}

int ShopNode::arrive(Warrior* warrior)
{
	MapNode::arrive(warrior);

	return NOEVENT;
}

int ShopNode::leave(Warrior* warrior)
{
	MapNode::leave(warrior);

	return NOEVENT;
}

int ShopNode::rest(Warrior* warrior)
{
	MapNode::rest(warrior);

	return NOEVENT;
}