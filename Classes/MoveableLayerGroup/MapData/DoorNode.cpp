#include "DoorNode.h"

bool DoorNode::init()
{
	MapNode::init();

	return true;
}

int DoorNode::checkWin(Warrior* warrior)
{
	bool team = warrior->isTeamX();
	if (team)
	{
		if (Warrior::isTeamXWin())
		{
			return WIN;
		}
	}
	else
	{
		if (Warrior::isTeamYWin())
		{
			return WIN;
		}
	}
	return NOEVENT;
}

int DoorNode::arrive(Warrior* warrior)
{
	MapNode::arrive(warrior);

	return checkWin(warrior);
}

int DoorNode::leave(Warrior* warrior)
{
	MapNode::leave(warrior);

	return NOEVENT;
}

int DoorNode::rest(Warrior* warrior)
{
	MapNode::rest(warrior);

	return checkWin(warrior);
}