#include "BramblesNode.h"

bool BramblesNode::init()
{
	MapNode::init();

	bramblesLevel = 0;
	round = 0;

	healthLoss = 50;
	privateIncome = 50;
	publicIncome = 100;

	font = "fonts/SourceHanSans.otf";
	fontSize = 72;
	size = 0.08f;
	color = Color3B::RED;

	return true;
}

int BramblesNode::attackBrambles(Warrior* warrior)
{
	if (warrior->getHealth() > healthLoss*bramblesLevel)
	{
		warrior->changePrivateWealth(privateIncome*bramblesLevel);
		warrior->changePublicWealth(publicIncome*bramblesLevel);
		warrior->changeHealth(-healthLoss*bramblesLevel);

		bramblesLevel = 0;
	}
	else
	{
		for (int i = 0; i < bramblesLevel; ++i)
		{
			if (warrior->getHealth() < 0)
				break;
			warrior->changePrivateWealth(privateIncome);
			warrior->changePublicWealth(publicIncome);
			warrior->changeHealth(-healthLoss);
			bramblesLevel--;
		}

		return DEAD;
	}

	return NOEVENT;
}

void BramblesNode::showBramblesLevel()
{
	removeChild(bramblesLabel);
	char text[32];
	sprintf(text, "%d", bramblesLevel);
	bramblesLabel = Label::createWithTTF(text, font, fontSize);
	bramblesLabel->setColor(color);
	bramblesLabel->setPosition(position);
	SETSIZE(bramblesLabel, size);
	this->addChild(bramblesLabel);
}

int BramblesNode::arrive(Warrior* warrior)
{
	MapNode::arrive(warrior);

	return attackBrambles(warrior);
}

int BramblesNode::leave(Warrior* warrior)
{
	MapNode::leave(warrior);

	return NOEVENT;
}

int BramblesNode::rest(Warrior* warrior)
{
	MapNode::rest(warrior);

	return attackBrambles(warrior);
}

void BramblesNode::roundStart(Warrior* warrior)
{
	MapNode::roundStart(warrior);
	showBramblesLevel();
}

void BramblesNode::roundEnd(Warrior* warrior)
{
	MapNode::roundEnd(warrior);

	round++;
	if (round >= 2)
	{
		round = 0;
		bramblesLevel++;
	}
	showBramblesLevel();
}