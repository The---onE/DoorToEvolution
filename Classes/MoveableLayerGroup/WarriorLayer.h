#pragma once

#include "Global.h"
#include "Warrior/TeamXPlayer.h"
#include "Warrior/TeamYPlayer.h"

class WarriorLayer : public Layer
{
protected:
	std::vector<TeamXPlayer*> x; //X�����
	std::vector<TeamYPlayer*> y; //Y�����

	Warrior* lead; //����ָ��

public:
	CREATE_FUNC(WarriorLayer);
	bool init();
	void addPlayerX(TeamXPlayer* player, int positon); //���X�����
	void addPlayerY(TeamYPlayer* player, int positon); //���Y�����
	void setLead(Warrior* player); //��������
	Warrior* getLead(); //��ȡ����
};