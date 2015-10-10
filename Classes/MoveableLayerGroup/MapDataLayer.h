#pragma once

#include "Global.h"
#include "MapData/MapNode.h"
#include "MapData/BoxNode.h"
#include "MapData/BramblesNode.h"
#include "MapData/DoorNode.h"
#include "MapData/HospitalNode.h"
#include "MapData/HotelNode.h"
#include "MapData/ShopNode.h"

#include "Warrior/Warrior.h"

extern const Point node[TOTAL_NODE]; //in Global.cpp 节点坐标
extern const int dis[TOTAL_NODE][TOTAL_NODE]; //in Global.cpp 节点间距离

class MapDataLayer : public Layer
{
protected:
	MapNode* mapNode[TOTAL_NODE]; //地图节点
	
public:
	CREATE_FUNC(MapDataLayer);
	bool init();
	int leave(Warrior* warrior, int index); //玩家离开节点
	int arrive(Warrior* warrior, int index); //玩家进入节点
	int rest(Warrior* warrior, int index); //玩家在节点休养
	void roundStart(Warrior* warrior); //每回合开始前所有节点处理
	void roundEnd(Warrior* warrior); //每回合结束后所有节点处理

	int processMapNode(int index);
	int processAllMapNode();
};