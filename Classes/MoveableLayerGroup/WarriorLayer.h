#pragma once

#include "Global.h"
#include "Warrior/TeamXPlayer.h"
#include "Warrior/TeamYPlayer.h"

class WarriorLayer : public Layer
{
protected:
	std::vector<TeamXPlayer*> x; //X队玩家
	std::vector<TeamYPlayer*> y; //Y队玩家

	Warrior* lead; //主角指针

public:
	CREATE_FUNC(WarriorLayer);
	bool init();
	void addPlayerX(TeamXPlayer* player, int positon); //添加X队玩家
	void addPlayerY(TeamYPlayer* player, int positon); //添加Y队玩家
	void setLead(Warrior* player); //设置主角
	Warrior* getLead(); //获取主角
};