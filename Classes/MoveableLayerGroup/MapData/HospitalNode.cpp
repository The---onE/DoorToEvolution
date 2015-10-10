#include "HospitalNode.h"

bool HospitalNode::init()
{
	MapNode::init();

	healthImproveParam = 0.4f;
	magicImproveParam = 0.4f;

	font = "fonts/SourceHanSans.otf";
	fontSize = 72;
	size = 0.12f;
	healthColor = Color3B::GREEN;
	magicColor = Color3B::BLUE;

	return true;
}

void HospitalNode::improveHealth(Warrior* warrior)
{
	warrior->changeHealth(healthImproveParam * warrior->getHealthMax());

	warrior->checkHealthOverflow();
}

void HospitalNode::improveMagic(Warrior* warrior)
{
	warrior->changeMagic(magicImproveParam * warrior->getMagicMax());

	warrior->checkMagicOverflow();
}

void HospitalNode::showImprove(Warrior* warrior)
{
	removeChild(healthLabel);
	char text[32];
	sprintf(text, "+%d", int(healthImproveParam * warrior->getHealth()));
	healthLabel = Label::createWithTTF(text, font, fontSize);
	healthLabel->setColor(healthColor);
	healthLabel->setPosition(position);
	healthLabel->setAnchorPoint(Point(0.5, 0));
	SETSIZE(healthLabel, size*0.5);
	this->addChild(healthLabel);

	removeChild(magicLabel);
	sprintf(text, "+%d", int(magicImproveParam * warrior->getMagicMax()));
	magicLabel = Label::createWithTTF(text, font, fontSize);
	magicLabel->setColor(magicColor);
	magicLabel->setPosition(position);
	magicLabel->setAnchorPoint(Point(0.5, 1));
	SETSIZE(magicLabel, size*0.5);
	this->addChild(magicLabel);
}

int HospitalNode::arrive(Warrior* warrior)
{
	MapNode::arrive(warrior);

	improveHealth(warrior);

	return NOEVENT;
}

int HospitalNode::leave(Warrior* warrior)
{
	MapNode::leave(warrior);

	return NOEVENT;
}

int HospitalNode::rest(Warrior* warrior)
{
	MapNode::rest(warrior);

	improveHealth(warrior);

	return NOEVENT;
}

void HospitalNode::roundStart(Warrior* warrior)
{
	MapNode::roundStart(warrior);
	showImprove(warrior);
}

void HospitalNode::roundEnd(Warrior* warrior)
{
	MapNode::roundEnd(warrior);
	showImprove(warrior);
}