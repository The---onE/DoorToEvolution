#pragma once

#include "Global.h"
#include "MapNode.h"

class BramblesNode : public MapNode
{
public:
	int healthLoss;
	int privateIncome;
	int publicIncome;

	int bramblesLevel;
	int round;
	
	Label* bramblesLabel; //荆棘标签
	std::string font; //字体
	float fontSize; //字体大小
	float size; //标签大小
	Color3B color; //标签颜色

	CREATE_FUNC(BramblesNode);
	bool init();

	int attackBrambles(Warrior* warrior);
	void showBramblesLevel();

	int leave(Warrior* warrior);
	int arrive(Warrior* warrior);
	int rest(Warrior* warrior);
	void roundStart(Warrior* warrior);
	void roundEnd(Warrior* warrior);
};