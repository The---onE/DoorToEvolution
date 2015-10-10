#pragma once

#include "Global.h"
#include "StateMachine.h"

#include "MoveableLayerGroup.h"
#include "ControllerLayerGroup.h"
#include "InformationLayerGroup.h"

class GameScene : public Scene
{
protected:
	StateMachine* stateMachine; //状态机

	int prevAngle; //上次控制球角度
	int prevPosition; //上次主角位置
	int start; //行动线起点
	int end; //行动线终点

	bool restFlag; //是否休养

	Warrior* lead; //主角指针
	std::vector<TeamXPlayer*> x;
	std::vector<TeamYPlayer*> y;
	Sprite* leadRound; //主角光环
	bool xFlag; //是否在控制X队角色

	//////////////////////////////////////////////////////////////////////////
	Warrior* enemy;
	TeamXPlayer* x_1;
	TeamYPlayer* y_1;
	bool rest;
	int r;
	int re;
	//////////////////////////////////////////////////////////////////////////

	Color4F enoughPrepareColor; //等待行动阶段可行动线条/六边形颜色
	Color4F notEnoughPrepareColor; //等待行动阶段不可行动线条/六边形颜色
	Color4F actionColor; //等待其他玩家行动阶段线条/六边形颜色
	Color3B enoughColor; //可行动消耗耐力标签颜色
	Color3B notEnoughColor; //不可行动消耗耐力标签颜色

	MoveableLayerGroup* moveableGroup; //可移动层组(Background、Map、MapData、Route、Warrior)
	ControllerLayerGroup* controllerGroup; //控制器层组(Button、Control)
	InformationLayerGroup* informationGroup; //信息层组(Label)

public:
	CREATE_FUNC(GameScene);
	bool init();

	void initMoveableLayerGroup(); // 初始化可移动层组
	void initControllerLayerGroup(); //初始化控制器层组
	void initInformationLayerGroup(); //初始化信息层组
	void initData(); //初始化数据
	void initStateMachine(); //初始化状态机

	void initPlayer(); //初始化玩家
	void prepareThisRound(); //WaitAction状态开始调用一次，准备本回合
	void cancelAllController(); //撤销所有操作
	int processWarriorController(); //WaitAction状态每帧调用，处理玩家对角色操作
	int processBasicController(); //Act、Die、Effect、Lose、Reborn、WaitOtherAction、Win、WaitAction状态每帧调用，处理玩家基本操作
	int act(); //Act状态调用一次，实施玩家操作
	int processAction(); //Process状态调用一次，处理行动后数据，判断胜负
	void prepareNextRound(); //Effect状态结束调用一次，准备下一回合

	void setLead(Warrior* le); //设置主角
	void setMapSize(float size) { moveableGroup->setSize(size); } //缩放地图(可移动层组)尺寸
	void focusPoint(bool animeFlag, float x, float y) { moveableGroup->focusPoint(animeFlag, x, y); } //聚焦地图上一坐标点至屏幕中心
	void focusPoint(bool animeFlag, int index) { moveableGroup->focusPoint(animeFlag, node[index]); } //聚焦地图上一节点至屏幕中心
	float warriorAct(Warrior* w, int destination, bool rest = false); //角色进行移动
	float leadAct(Warrior* l, int destination, bool rest = false); //主角进行移动
	int warriorProcess(Warrior* w, int destination, bool* rest); //处理玩家行动
	int warriorProcess(Warrior* w, int destination, bool rest = false); //处理玩家行动

	//////////////////////////////////////////////////////////////////////////
	void changeLead();
	void randomMove(Warrior* enemy);
	//////////////////////////////////////////////////////////////////////////

	void changeStateLabel(string s) { informationGroup->changeStateLabel(s); } //修改信息层组中标签层中状态标签文本
	void removeStateLabel() { informationGroup->removeStateLabel(); } //移除信息层组中标签层中状态标签

	StateMachine* getStateMachine() { return stateMachine; } //返回状态机指针
	void update(float dt) { stateMachine->update(dt); } //调用状态机update函数

	void createQuitButton(); //添加关闭按钮
	void quitGame(Ref* pSender); //关闭游戏
};
