#pragma once

#include "Global.h"

#include "../Warrior/Warrior.h"

extern const Point node[];
extern const int dis[][TOTAL_NODE];

class MapNode : public Node
{
public:
	//bool restingWarrior[TOTAL_NODE]; //�ڽڵ��ϵ����
	Vector<Warrior*> restingWarrior;
	Point position; //�ڵ�ͼ�ϵ�λ��

	bool init();
	void setNodePosition(Point p); //��ȡ�ڵ��ڵ�ͼ�ϵ�λ��
	virtual int leave(Warrior* warrior); //����뿪�ڵ��Ч��
	virtual int arrive(Warrior* warrior); //��ҽ���ڵ��Ч��
	virtual int rest(Warrior* warrior); //����ڽڵ�������Ч��
	virtual void roundStart(Warrior* warrior); //ÿһ�غϿ�ʼʱ��Ч��
	virtual void roundEnd(Warrior* warrior); //ÿһ�غϽ���ʱ��Ч��
};