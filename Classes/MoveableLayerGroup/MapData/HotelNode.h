#pragma once

#include "Global.h"
#include "MapNode.h"

class HotelNode : public MapNode
{
public:
	float staminaRecoverParamete; //耐力恢复系数

	Label* staminaLabel; //荆棘标签
	std::string font; //字体
	float fontSize; //字体大小
	float size; //标签大小
	Color3B color; //标签颜色

	CREATE_FUNC(HotelNode);
	bool init();

	void recoverStamina(Warrior* warrior);
	void showStaminaRecover(Warrior* warrior);

	int leave(Warrior* warrior);
	int arrive(Warrior* warrior);
	int rest(Warrior* warrior);
	void roundStart(Warrior* warrior);
	void roundEnd(Warrior* warrior);
};