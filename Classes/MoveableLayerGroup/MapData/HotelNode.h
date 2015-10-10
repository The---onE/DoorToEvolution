#pragma once

#include "Global.h"
#include "MapNode.h"

class HotelNode : public MapNode
{
public:
	float staminaRecoverParamete; //�����ָ�ϵ��

	Label* staminaLabel; //������ǩ
	std::string font; //����
	float fontSize; //�����С
	float size; //��ǩ��С
	Color3B color; //��ǩ��ɫ

	CREATE_FUNC(HotelNode);
	bool init();

	void recoverStamina(Warrior* warrior);
	void showStaminaRecover(Warrior* warrior);

	int leave(Warrior* warrior);
	int arrive(Warrior* warrior);
	int rest(Warrior* warrior);
	void roundStart(Warrior* warrior);
	void roundEnd(Warrior* warrior);
};