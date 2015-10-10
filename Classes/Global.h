#pragma once

#include "cocos2d.h"
USING_NS_CC;
#include "./XMX_Controller/XMX_Vibrator.h" //震动器
#define USING_XMX using namespace XMX
USING_XMX;
using namespace std;

#define VIBRATE_TIME 48 //震动时间

extern Size visibleSize;
extern Point origin; //应在AppDelegate.cpp中定义全局变量，并在applicationDidFinishLaunching()中初始化
//visibleSize = Director::getInstance()->getVisibleSize();
//origin = Director::getInstance()->getVisibleOrigin();

#define WIDTH visibleSize.width //屏幕宽度
#define HEIGHT visibleSize.height //屏幕高度

#define DATUM visibleSize.height //长度基准
#define SETSIZE(SPRITE,SIZE) ((SPRITE)->setScale(DATUM*(SIZE)/(SPRITE)->getContentSize().height)) //为Sprite等设置相对于长度基准的大小
#define DEFAULT_WIDTH 1080 //默认屏幕宽度
#define PARAM  (DATUM/DEFAULT_WIDTH) //速度标准化参数

#define PLAYER 2 //游戏人数
#define KEYS_NUMBER PLAYER //钥匙个数

#define NC 32767 //不通路径
#define D1 32 //路径长度1
#define D2 45 //路径长度2
#define D3 64 //路径长度3

#define NOANGLE -1800 //未确定角度
#define NOCONNECTION 1800 //路径不通
#define NOCHOOSE -1 //未选择路径

#define TOTAL_NODE 17 //总节点个数

#define ANGLE_OFFSET 8 //角度单侧偏移量

#define BIG_MAP 1000 //大地图模式
#define SMALL_MAP 1001 //小地图模式
#define OK 1002 //确定按钮ID
#define CANCEL 1003 //取消按钮ID
#define REST 1004 //休整按钮ID
#define TP 1005 //回城按钮ID
#define CHANGE 1006 //改变主角按钮ID

#define ATTRIBUTES 16 //人物属性个数
#define INDEX 0 //编号ID
#define HEALTH 1 //生命值属性ID
#define HEALTH_MAX 2 //最大生命值属性ID
#define MAGIC 3 //魔法值属性ID
#define MAGIC_MAX 4 //最大魔法值属性ID
#define SPEED 5 //速度属性ID
#define STAMINA 6 //耐力属性ID
#define STAMINA_MAX 7 //耐力最大值属性ID
#define ATTACK 8 //物理攻击力属性ID
#define DEFENCE 9 //物理防御力属性ID
#define MAGIC_ATTACK 10 //魔法攻击力属性ID
#define MAGIC_DEFENCK 11 //魔法防御力属性ID
#define PRIVATE_WEALTH 12 //私有资金属性ID
#define STRONGBOX 13 //保险箱个数属性ID
#define BOMB 14 //炸弹个数属性ID
#define PUBLIC_WEALTH 15 //公有资金属性ID

#define NOTHAVE 0 //未拥有
#define HAVE 1 //已拥有

#define ACTION 5 //确定行动

#define ERROREVENT -1 //出现错误
#define NOEVENT 0 //无事件
#define WIN 1 //胜利
#define LOSE 2 //失败
#define DEAD 3 //人物死亡

#define METAL 1 //金属性
#define WOOD 2 //木属性
#define EARTH 3 //土属性
#define WATER 4 //水属性
#define FIRE 5 //火属性
#define LIGHT 11 //光属性
#define DARK 12 //暗属性

int randNum(int size, int probability[]); //根据概率确定所选序号

/*#define KEYBOARD_FUNCTION void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);\
void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);

#define KEYBOARD_LISTENER(CLASS) EventListenerKeyboard* keyboardListener = EventListenerKeyboard::create();\
keyboardListener->onKeyPressed = CC_CALLBACK_2(CLASS::onKeyPressed, this); \
keyboardListener->onKeyReleased = CC_CALLBACK_2(CLASS::onKeyReleased, this); \
Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);*/
