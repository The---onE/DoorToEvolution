#pragma once

#include "Global.h"
#include "MapNode.h"

class HospitalNode : public MapNode
{
public:
	float healthImproveParam; //生命值恢复系数
	float magicImproveParam; //法力值恢复系数

	Label* healthLabel; //荆棘标签
	Label* magicLabel; //荆棘标签
	std::string font; //字体
	float fontSize; //字体大小
	float size; //标签大小
	Color3B healthColor; //标签颜色
	Color3B magicColor; //标签颜色

	CREATE_FUNC(HospitalNode);
	bool init();

	void improveHealth(Warrior* warrior);
	void improveMagic(Warrior* warrior);
	void showImprove(Warrior* warrior);

	int leave(Warrior* warrior);
	int arrive(Warrior* warrior);
	int rest(Warrior* warrior);
	void roundStart(Warrior* warrior);
	void roundEnd(Warrior* warrior);
};