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
	
	Label* bramblesLabel; //������ǩ
	std::string font; //����
	float fontSize; //�����С
	float size; //��ǩ��С
	Color3B color; //��ǩ��ɫ

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