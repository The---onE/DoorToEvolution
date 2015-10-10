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
	BackGroundLayer* backGround; //背景层
	MapLayer* map; //地图层
	RouteLayer* route; //路线层
	WarriorLayer* warrior; //玩家层
	MapDataLayer* mapData; //地图数据层

	Point offset; //单指操作偏移量
	Point touchesMidPointInLayer; //双指操作中心点
	int touchesQuantity; //触控手指数量
	float initialDistance; //双指操作初始距离
	bool touchFlag; //触控标志
	bool changeToOnePointFlag; //单指操作
	bool changeToTwoPointsFlag; //双指操作

	float focusSpeed;
	Point position;

public:
	CREATE_FUNC(MoveableLayerGroup);
	bool init();
	void onEnter();
	void onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event);
	void onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event);
	void onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event);

	void initBackGroundLayer(); //初始化背景层
	void initMapLayer(); //初始化地图层
	void initRouteLayer(); //初始化路线层
	void initWarriorLayer(); //初始化玩家层
	void initMapDataLayer(); //初始化地图数据层
	void initData(); //初始化数据

	void focusPoint(bool animeFlag, float xInLayer, float yInLayer, float xInScreen = visibleSize.width / 2, float yInScreen = visibleSize.height / 2); //聚焦地图上一点至屏幕上一点
	void focusPoint(bool animeFlag, Point pInLayer, Point pInScreen = Point(visibleSize.width / 2, visibleSize.height / 2)); //聚焦地图上一点至屏幕上一点
	Point getLocationInLayer(float xInScreen, float yInScreen); //获取地图上一点在屏幕上的位置
	Point getLocationInLayer(Point pInScreen); //获取地图上一点在屏幕上的位置
	void scale(float factor); //缩放地图
	void setSize(float size); //设置地图尺寸

	void addPlayerX(TeamXPlayer* player, int positon) { warrior->addPlayerX(player, positon); arrive(player, positon); }
	void addPlayerY(TeamYPlayer* player, int positon) { warrior->addPlayerY(player, positon); arrive(player, positon); }
	Warrior* getLead() { return warrior->getLead(); } //返回主角指针
	void setLead(Warrior* player) { warrior->setLead(player); } //设置主角
	int getEndByAngle(int center, int angle) { return route->getEndByAngle(center, angle); } //通过角度绘制路线
	void drawLine(int from, int to, Color4F color, float radius = 0) { route->drawLine(from, to, color, radius); } //通过起始点绘制路线
	void routeReset() { route->reset(); } //路线重置
	void routeClear () { route->clear(); } //路线清除
	int getRouteStart() { return route->getStart(); } //返回路线起点
	int getRouteEnd() { return route->getEnd(); } //返回路线终点
	void addExertionLabel(int from, int to, int exertion, Color3B color) { route->addExertionLabel(from, to, exertion, color); }
	void drawSexangle(int middle, Color4F color) { route->drawSexangle(middle, color); } //以中心点绘制六边形
	int arrive(Warrior* warrior, int index) { return mapData->arrive(warrior, index); } //到达地图节点
	int leave(Warrior* warrior, int index) { return mapData->leave(warrior, index); } //离开地图节点
	int rest(Warrior* warrior, int index) { return mapData->rest(warrior, index); } //在地图节点休养
	int processAllMapNode() { return mapData->processAllMapNode(); } //处理地图节点的互相攻击
	void roundStart(Warrior* warrior) { mapData->roundStart(warrior); } ///每回合开始前所有节点处理
	void roundEnd(Warrior* warrior) { mapData->roundEnd(warrior); } ///每回合结束后所有节点处理
};