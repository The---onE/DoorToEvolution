#pragma once

#include "Global.h"
#include "MapNode.h"

class HospitalNode : public MapNode
{
public:
	float healthImproveParam; //����ֵ�ָ�ϵ��
	float magicImproveParam; //����ֵ�ָ�ϵ��

	Label* healthLabel; //������ǩ
	Label* magicLabel; //������ǩ
	std::string font; //����
	float fontSize; //�����С
	float size; //��ǩ��С
	Color3B healthColor; //��ǩ��ɫ
	Color3B magicColor; //��ǩ��ɫ

	CREATE_FUNC(HospitalNode);
	bool init();

	void improveHealth(Warrior* warrior);
	void improveMagic(Warrior* warrior);
	void showImprove(Warrior* warrior);

	int leave(Warrior* warrior);
	int arrive(Warrior* warrior);
	int rest(Warrior* warrior);
	void roundStart(Warrior* warrior);
	void roundEnd(Warrior* warrior);
};