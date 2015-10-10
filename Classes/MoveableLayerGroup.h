#pragma once

#include "Global.h"

#include "MoveableLayerGroup/BackGroundLayer.h"
#include "MoveableLayerGroup/MapLayer.h"
#include "MoveableLayerGroup/RouteLayer.h"
#include "MoveableLayerGroup/WarriorLayer.h"
#include "MoveableLayerGroup/MapDataLayer.h"

class MoveableLayerGroup : public Layer
{
protected:
	BackGroundLayer* backGround; //������
	MapLayer* map; //��ͼ��
	RouteLayer* route; //·�߲�
	WarriorLayer* warrior; //��Ҳ�
	MapDataLayer* mapData; //��ͼ���ݲ�

	Point offset; //��ָ����ƫ����
	Point touchesMidPointInLayer; //˫ָ�������ĵ�
	int touchesQuantity; //������ָ����
	float initialDistance; //˫ָ������ʼ����
	bool touchFlag; //���ر�־
	bool changeToOnePointFlag; //��ָ����
	bool changeToTwoPointsFlag; //˫ָ����

	float focusSpeed;
	Point position;

public:
	CREATE_FUNC(MoveableLayerGroup);
	bool init();
	void onEnter();
	void onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event);
	void onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event);
	void onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event);

	void initBackGroundLayer(); //��ʼ��������
	void initMapLayer(); //��ʼ����ͼ��
	void initRouteLayer(); //��ʼ��·�߲�
	void initWarriorLayer(); //��ʼ����Ҳ�
	void initMapDataLayer(); //��ʼ����ͼ���ݲ�
	void initData(); //��ʼ������

	void focusPoint(bool animeFlag, float xInLayer, float yInLayer, float xInScreen = visibleSize.width / 2, float yInScreen = visibleSize.height / 2); //�۽���ͼ��һ������Ļ��һ��
	void focusPoint(bool animeFlag, Point pInLayer, Point pInScreen = Point(visibleSize.width / 2, visibleSize.height / 2)); //�۽���ͼ��һ������Ļ��һ��
	Point getLocationInLayer(float xInScreen, float yInScreen); //��ȡ��ͼ��һ������Ļ�ϵ�λ��
	Point getLocationInLayer(Point pInScreen); //��ȡ��ͼ��һ������Ļ�ϵ�λ��
	void scale(float factor); //���ŵ�ͼ
	void setSize(float size); //���õ�ͼ�ߴ�

	void addPlayerX(TeamXPlayer* player, int positon) { warrior->addPlayerX(player, positon); arrive(player, positon); }
	void addPlayerY(TeamYPlayer* player, int positon) { warrior->addPlayerY(player, positon); arrive(player, positon); }
	Warrior* getLead() { return warrior->getLead(); } //��������ָ��
	void setLead(Warrior* player) { warrior->setLead(player); } //��������
	int getEndByAngle(int center, int angle) { return route->getEndByAngle(center, angle); } //ͨ���ǶȻ���·��
	void drawLine(int from, int to, Color4F color, float radius = 0) { route->drawLine(from, to, color, radius); } //ͨ����ʼ�����·��
	void routeReset() { route->reset(); } //·������
	void routeClear () { route->clear(); } //·�����
	int getRouteStart() { return route->getStart(); } //����·�����
	int getRouteEnd() { return route->getEnd(); } //����·���յ�
	void addExertionLabel(int from, int to, int exertion, Color3B color) { route->addExertionLabel(from, to, exertion, color); }
	void drawSexangle(int middle, Color4F color) { route->drawSexangle(middle, color); } //�����ĵ����������
	int arrive(Warrior* warrior, int index) { return mapData->arrive(warrior, index); } //�����ͼ�ڵ�
	int leave(Warrior* warrior, int index) { return mapData->leave(warrior, index); } //�뿪��ͼ�ڵ�
	int rest(Warrior* warrior, int index) { return mapData->rest(warrior, index); } //�ڵ�ͼ�ڵ�����
	int processAllMapNode() { return mapData->processAllMapNode(); } //�����ͼ�ڵ�Ļ��๥��
	void roundStart(Warrior* warrior) { mapData->roundStart(warrior); } ///ÿ�غϿ�ʼǰ���нڵ㴦��
	void roundEnd(Warrior* warrior) { mapData->roundEnd(warrior); } ///ÿ�غϽ��������нڵ㴦��
};