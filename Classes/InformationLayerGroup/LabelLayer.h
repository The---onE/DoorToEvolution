#pragma once

#include "Global.h"

class LabelLayer : public Layer
{
protected:
	Label* healthLabel; //����ֵ��ǩ
	Label* magicLabel; //����ֵ��ǩ
	Label* speedLabel; //�ٶȱ�ǩ
	Label* staminaLabel; //������ǩ
	Label* physicalAttributesLabel; //����ϵ����ǩ
	Label* magicAttributesLabel; //ħ��ϵ����ǩ
	Label* wealthLabel; //�ʽ��ǩ
	Label* boxAttributesLabel; //�Ĵ���������ǩ
	Label* nickNameLabel; //�ǳƱ�ǩ

	Label* stateLabel; //״̬��ǩ

	std::string font; //����
	float fontSize; //�����С
	float size; //��ǩ��С
	Color3B healthColor; //����ֵ������ϵ����ǩ��ɫ
	Color3B magicColor; //����ֵ��ħ��ϵ����ǩ��ɫ
	Color3B textColor; //һ���ǩ��ɫ

	Point healthPosition; //����ֵ��ǩλ��
	Point magicPosition; //����ֵ��ǩλ��
	Point speedPosition; //�ٶȱ�ǩλ��
	Point staminaPosition; //������ǩλ��
	Point physicalAttributesPosition; //����ϵ����ǩλ��
	Point magicAttributesPosition; //ħ��ϵ����ǩλ��
	Point privateWealthPosition; //�ʽ��ǩλ��
	Point boxAttributesPosition; //�Ĵ���������ǩλ��
	Point nickNameAttributesPosition; //�ǳƱ�ǩλ��

public:
	CREATE_FUNC(LabelLayer);
	bool init();

	void addHealthLabel(int health, int healthMax); //�������ֵ��ǩ
	void addMagicLabel(int magic, int magicMax); //��ӷ���ֵ��ǩ
	void addSpeedLabel(int speed); //����ٶȱ�ǩ
	void addStaminaLabel(int stamina, int staminaMax); //���������ǩ
	void addPhysicalAttributes(int attack, int defence); //�������ϵ����ǩ
	void addMagicAttributes(int magicAttack, int magicDefence); //���ħ��ϵ����ǩ
	void addPrivateWealth(int privateWealth, int publicWealth); //����ʽ��ǩ
	void addBoxAttributes(int strongbox, int bomb); //��ӼĴ���������ǩ
	void addNickNameAttributes(string name); //����ǳƱ�ǩ

	void addAllAttributes(int* attribute); //���ȫ����ǩ����Warrior.cpp getAllAttributes�����Խ�

	void changeStateLabel(std::string s); //����״̬��ǩ
	void removeStateLabel(); //�Ƴ�״̬��ǩ
};