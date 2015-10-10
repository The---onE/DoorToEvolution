#pragma once

#include "Global.h"
#include "StateMachine.h"

#include "MoveableLayerGroup.h"
#include "ControllerLayerGroup.h"
#include "InformationLayerGroup.h"

class GameScene : public Scene
{
protected:
	StateMachine* stateMachine; //״̬��

	int prevAngle; //�ϴο�����Ƕ�
	int prevPosition; //�ϴ�����λ��
	int start; //�ж������
	int end; //�ж����յ�

	bool restFlag; //�Ƿ�����

	Warrior* lead; //����ָ��
	std::vector<TeamXPlayer*> x;
	std::vector<TeamYPlayer*> y;
	Sprite* leadRound; //���ǹ⻷
	bool xFlag; //�Ƿ��ڿ���X�ӽ�ɫ

	//////////////////////////////////////////////////////////////////////////
	Warrior* enemy;
	TeamXPlayer* x_1;
	TeamYPlayer* y_1;
	bool rest;
	int r;
	int re;
	//////////////////////////////////////////////////////////////////////////

	Color4F enoughPrepareColor; //�ȴ��ж��׶ο��ж�����/��������ɫ
	Color4F notEnoughPrepareColor; //�ȴ��ж��׶β����ж�����/��������ɫ
	Color4F actionColor; //�ȴ���������ж��׶�����/��������ɫ
	Color3B enoughColor; //���ж�����������ǩ��ɫ
	Color3B notEnoughColor; //�����ж�����������ǩ��ɫ

	MoveableLayerGroup* moveableGroup; //���ƶ�����(Background��Map��MapData��Route��Warrior)
	ControllerLayerGroup* controllerGroup; //����������(Button��Control)
	InformationLayerGroup* informationGroup; //��Ϣ����(Label)

public:
	CREATE_FUNC(GameScene);
	bool init();

	void initMoveableLayerGroup(); // ��ʼ�����ƶ�����
	void initControllerLayerGroup(); //��ʼ������������
	void initInformationLayerGroup(); //��ʼ����Ϣ����
	void initData(); //��ʼ������
	void initStateMachine(); //��ʼ��״̬��

	void initPlayer(); //��ʼ�����
	void prepareThisRound(); //WaitAction״̬��ʼ����һ�Σ�׼�����غ�
	void cancelAllController(); //�������в���
	int processWarriorController(); //WaitAction״̬ÿ֡���ã�������ҶԽ�ɫ����
	int processBasicController(); //Act��Die��Effect��Lose��Reborn��WaitOtherAction��Win��WaitAction״̬ÿ֡���ã�������һ�������
	int act(); //Act״̬����һ�Σ�ʵʩ��Ҳ���
	int processAction(); //Process״̬����һ�Σ������ж������ݣ��ж�ʤ��
	void prepareNextRound(); //Effect״̬��������һ�Σ�׼����һ�غ�

	void setLead(Warrior* le); //��������
	void setMapSize(float size) { moveableGroup->setSize(size); } //���ŵ�ͼ(���ƶ�����)�ߴ�
	void focusPoint(bool animeFlag, float x, float y) { moveableGroup->focusPoint(animeFlag, x, y); } //�۽���ͼ��һ���������Ļ����
	void focusPoint(bool animeFlag, int index) { moveableGroup->focusPoint(animeFlag, node[index]); } //�۽���ͼ��һ�ڵ�����Ļ����
	float warriorAct(Warrior* w, int destination, bool rest = false); //��ɫ�����ƶ�
	float leadAct(Warrior* l, int destination, bool rest = false); //���ǽ����ƶ�
	int warriorProcess(Warrior* w, int destination, bool* rest); //��������ж�
	int warriorProcess(Warrior* w, int destination, bool rest = false); //��������ж�

	//////////////////////////////////////////////////////////////////////////
	void changeLead();
	void randomMove(Warrior* enemy);
	//////////////////////////////////////////////////////////////////////////

	void changeStateLabel(string s) { informationGroup->changeStateLabel(s); } //�޸���Ϣ�����б�ǩ����״̬��ǩ�ı�
	void removeStateLabel() { informationGroup->removeStateLabel(); } //�Ƴ���Ϣ�����б�ǩ����״̬��ǩ

	StateMachine* getStateMachine() { return stateMachine; } //����״̬��ָ��
	void update(float dt) { stateMachine->update(dt); } //����״̬��update����

	void createQuitButton(); //��ӹرհ�ť
	void quitGame(Ref* pSender); //�ر���Ϸ
};
