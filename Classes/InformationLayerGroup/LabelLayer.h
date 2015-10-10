#pragma once

#include "Global.h"

class LabelLayer : public Layer
{
protected:
	Label* healthLabel; //生命值标签
	Label* magicLabel; //法力值标签
	Label* speedLabel; //速度标签
	Label* staminaLabel; //耐力标签
	Label* physicalAttributesLabel; //物理系数标签
	Label* magicAttributesLabel; //魔法系数标签
	Label* wealthLabel; //资金标签
	Label* boxAttributesLabel; //寄存箱数量标签
	Label* nickNameLabel; //昵称标签

	Label* stateLabel; //状态标签

	std::string font; //字体
	float fontSize; //字体大小
	float size; //标签大小
	Color3B healthColor; //生命值、物理系数标签颜色
	Color3B magicColor; //法力值、魔法系数标签颜色
	Color3B textColor; //一般标签颜色

	Point healthPosition; //生命值标签位置
	Point magicPosition; //法力值标签位置
	Point speedPosition; //速度标签位置
	Point staminaPosition; //耐力标签位置
	Point physicalAttributesPosition; //物理系数标签位置
	Point magicAttributesPosition; //魔法系数标签位置
	Point privateWealthPosition; //资金标签位置
	Point boxAttributesPosition; //寄存箱数量标签位置
	Point nickNameAttributesPosition; //昵称标签位置

public:
	CREATE_FUNC(LabelLayer);
	bool init();

	void addHealthLabel(int health, int healthMax); //添加生命值标签
	void addMagicLabel(int magic, int magicMax); //添加法力值标签
	void addSpeedLabel(int speed); //添加速度标签
	void addStaminaLabel(int stamina, int staminaMax); //添加耐力标签
	void addPhysicalAttributes(int attack, int defence); //添加物理系数标签
	void addMagicAttributes(int magicAttack, int magicDefence); //添加魔法系数标签
	void addPrivateWealth(int privateWealth, int publicWealth); //添加资金标签
	void addBoxAttributes(int strongbox, int bomb); //添加寄存箱数量标签
	void addNickNameAttributes(string name); //添加昵称标签

	void addAllAttributes(int* attribute); //添加全部标签，与Warrior.cpp getAllAttributes函数对接

	void changeStateLabel(std::string s); //更改状态标签
	void removeStateLabel(); //移除状态标签
};