#include "HotelNode.h"

bool HotelNode::init()
{
	MapNode::init();

	staminaRecoverParamete = 2.5f;

	font = "fonts/SourceHanSans.otf";
	fontSize = 72;
	size = 0.08f;
	color = Color3B::MAGENTA;

	return true;
}

void HotelNode::recoverStamina(Warrior* warrior)
{
	warrior->changeStamina(warrior->getSpeed() * staminaRecoverParamete);
	warrior->checkStaminaOverflow();
}

void HotelNode::showStaminaRecover(Warrior* warrior)
{
	removeChild(staminaLabel);
	char text[32];
	sprintf(text, "+%d", int(staminaRecoverParamete * warrior->getSpeed()));
	staminaLabel = Label::createWithTTF(text, font, fontSize);
	staminaLabel->setColor(color);
	staminaLabel->setPosition(position);
	SETSIZE(staminaLabel, size);
	this->addChild(staminaLabel);
}

int HotelNode::arrive(Warrior* warrior)
{
	MapNode::arrive(warrior);

	recoverStamina(warrior);

	return NOEVENT;
}

int HotelNode::leave(Warrior* warrior)
{
	MapNode::leave(warrior);

	return NOEVENT;
}

int HotelNode::rest(Warrior* warrior)
{
	MapNode::rest(warrior);

	recoverStamina(warrior);

	return NOEVENT;
}

void HotelNode::roundStart(Warrior* warrior)
{
	MapNode::roundStart(warrior);
	showStaminaRecover(warrior);
}

void HotelNode::roundEnd(Warrior* warrior)
{
	MapNode::roundEnd(warrior);
	showStaminaRecover(warrior);
}