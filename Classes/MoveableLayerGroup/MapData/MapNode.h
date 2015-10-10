#pragma once

#include "Global.h"

#include "../Warrior/Warrior.h"

extern const Point node[];
extern const int dis[][TOTAL_NODE];

class MapNode : public Node
{
public:
	//bool restingWarrior[TOTAL_NODE]; //在节点上的玩家
	Vector<Warrior*> restingWarrior;
	Point position; //在地图上的位置

	bool init();
	void setNodePosition(Point p); //获取节点在地图上的位置
	virtual int leave(Warrior* warrior); //玩家离开节点的效果
	virtual int arrive(Warrior* warrior); //玩家进入节点的效果
	virtual int rest(Warrior* warrior); //玩家在节点休养的效果
	virtual void roundStart(Warrior* warrior); //每一回合开始时的效果
	virtual void roundEnd(Warrior* warrior); //每一回合结束时的效果
};