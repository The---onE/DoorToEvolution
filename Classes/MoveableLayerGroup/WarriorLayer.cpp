#include "WarriorLayer.h"

bool WarriorLayer::init()
{
	Layer::init();

	return true;
}

void WarriorLayer::addPlayerX(TeamXPlayer* player, int positon)
{
	player->setPoisitionIndex(positon);
	player->toPosition(positon);
	this->addChild(player);
	x.push_back(player);
}

void WarriorLayer::addPlayerY(TeamYPlayer* player, int positon)
{
	player->setPoisitionIndex(positon);
	player->toPosition(positon);
	this->addChild(player);
	y.push_back(player);
}

void WarriorLayer::setLead(Warrior* player)
{
	this->lead = player;
}

Warrior* WarriorLayer::getLead()
{
	return lead;
}