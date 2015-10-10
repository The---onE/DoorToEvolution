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

extern const Point node[TOTAL_NODE]; //in Global.cpp �ڵ�����
extern const int dis[TOTAL_NODE][TOTAL_NODE]; //in Global.cpp �ڵ�����

class MapDataLayer : public Layer
{
protected:
	MapNode* mapNode[TOTAL_NODE]; //��ͼ�ڵ�
	
public:
	CREATE_FUNC(MapDataLayer);
	bool init();
	int leave(Warrior* warrior, int index); //����뿪�ڵ�
	int arrive(Warrior* warrior, int index); //��ҽ���ڵ�
	int rest(Warrior* warrior, int index); //����ڽڵ�����
	void roundStart(Warrior* warrior); //ÿ�غϿ�ʼǰ���нڵ㴦��
	void roundEnd(Warrior* warrior); //ÿ�غϽ��������нڵ㴦��

	int processMapNode(int index);
	int processAllMapNode();
};