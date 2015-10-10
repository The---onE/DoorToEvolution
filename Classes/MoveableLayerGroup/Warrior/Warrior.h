#pragma once

#include "Global.h"

extern const Point node[];
extern const int dis[][TOTAL_NODE];

class Warrior : public Node
{
protected:
	Sprite* warrior; //角色Sprite

	int index; //角色编号
	string nickName; //玩家昵称

	int position; //角色所在位置

	int element; //角色属性

	int health; //当前生命值
	int healthMax; //最大生命值
	int magic; //当前法力值
	int magicMax; //最大法力值

	int speed; //角色速度
	int stamina; //当前耐力
	int staminaMax; //耐力最大值

	int attack; //角色攻击力
	int defence; //角色防御力

	int magicAttack; //角色魔法攻击力
	int magicDefence; //角色魔法防御力

	int privateWealth; //角色私有财产

	int strongbox; //保险箱个数
	int bomb; //炸弹个数

	float runParam; //移动参数

	int key[KEYS_NUMBER]; //携带的钥匙
	bool falseKey[KEYS_NUMBER]; //携带的假钥匙

	static int teamXWealth; //X队公有财产
	static int teamXKey[KEYS_NUMBER]; //X队拥有的钥匙
	static int teamXFalseKey[KEYS_NUMBER]; //X队拥有的假钥匙
	static int teamYWealth; //Y队公有财产
	static int teamYKey[KEYS_NUMBER]; //Y队拥有的钥匙
	static int teamYFalseKey[KEYS_NUMBER]; //Y队拥有的假钥匙

	bool changedFlag; //是否数值改变
	bool teamXFlag; //是否为X队成员
	
public:
	bool init();

	void toPosition(int destination); //初始化角色时设置角色位置

	void setWarriorSprite(Sprite* s, float size); //设置角色Sprite;

	void setIndex(int i); //设置属性
	int getIndex(); //获取属性

	void setNickName(string name); //设置昵称
	string getNickName(); //获取昵称

	void setElement(int ele); //设置角色属性

	void initHealth(int hm); //初始化生命值
	int getHealth(); //获取当前生命值
	int getHealthMax(); //获取最大生命值
	bool checkHealthOverflow(); //检查当前生命值是否超过最大生命值
	void changeHealth(int delta); //改变生命值

	void initMagic(int mm); //初始化法力值
	int getMagic(); //获取当前法力值
	int getMagicMax(); //获取最大法力值
	bool checkMagicOverflow(); //检查当前法力值是否超过最大法力值
	void changeMagic(int delta); //改变法力值

	void initStamina(int sm); //初始化耐力
	bool checkStaminaOverflow(); //检查当前耐力是否超过最大耐力
	void changeStamina(); //休养时通过速度改变耐力
	void changeStamina(int delta); //改变耐力

	void setSpeed(int s); //设置速度
	int getSpeed(); //获取速度

	void setPrivateWealth(int w); //设置私有财产
	int getPrivateWealth(); //获取私有财产
	void changePrivateWealth(int delta); //改变私有财产

	int getPositionIndex(); //获取位置坐标
	void setPoisitionIndex(int p); //设置位置坐标
	float moveTo(int destination); //移动至目标位置
	int getExertion(int from, int to); //获取移动的消耗
	bool exertStamina(int exertion); //消耗耐力
	bool exertStamina(int from, int to); //消耗耐力
	bool isStaminaEnough(int to); //是否耐力足够移动

	bool isAttributesChanged(); //是否状态改变
	void setAttributesChanged(bool flag); //设置状态改变标记
	int* getAllAttributes(); //与LabelLayer.cpp中addAllAttributes函数对接

	bool isTeamX(); //是否为X队成员

	void changePublicWealth(int delta); //改变公有财产
	int getPublicWealth(); //获取公有财产
	void setPublicWealth(int w); //设置公有财产

	static bool isTeamXWin(); //是否X队胜利
	static bool isTeamYWin(); //是否Y队胜利
};