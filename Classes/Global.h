#pragma once

#include "cocos2d.h"
USING_NS_CC;
#include "./XMX_Controller/XMX_Vibrator.h" //����
#define USING_XMX using namespace XMX
USING_XMX;
using namespace std;

#define VIBRATE_TIME 48 //��ʱ��

extern Size visibleSize;
extern Point origin; //Ӧ��AppDelegate.cpp�ж���ȫ�ֱ���������applicationDidFinishLaunching()�г�ʼ��
//visibleSize = Director::getInstance()->getVisibleSize();
//origin = Director::getInstance()->getVisibleOrigin();

#define WIDTH visibleSize.width //��Ļ���
#define HEIGHT visibleSize.height //��Ļ�߶�

#define DATUM visibleSize.height //���Ȼ�׼
#define SETSIZE(SPRITE,SIZE) ((SPRITE)->setScale(DATUM*(SIZE)/(SPRITE)->getContentSize().height)) //ΪSprite����������ڳ��Ȼ�׼�Ĵ�С
#define DEFAULT_WIDTH 1080 //Ĭ����Ļ���
#define PARAM  (DATUM/DEFAULT_WIDTH) //�ٶȱ�׼������

#define PLAYER 2 //��Ϸ����
#define KEYS_NUMBER PLAYER //Կ�׸���

#define NC 32767 //��ͨ·��
#define D1 32 //·������1
#define D2 45 //·������2
#define D3 64 //·������3

#define NOANGLE -1800 //δȷ���Ƕ�
#define NOCONNECTION 1800 //·����ͨ
#define NOCHOOSE -1 //δѡ��·��

#define TOTAL_NODE 17 //�ܽڵ����

#define ANGLE_OFFSET 8 //�Ƕȵ���ƫ����

#define BIG_MAP 1000 //���ͼģʽ
#define SMALL_MAP 1001 //С��ͼģʽ
#define OK 1002 //ȷ����ťID
#define CANCEL 1003 //ȡ����ťID
#define REST 1004 //������ťID
#define TP 1005 //�سǰ�ťID
#define CHANGE 1006 //�ı����ǰ�ťID

#define ATTRIBUTES 16 //�������Ը���
#define INDEX 0 //���ID
#define HEALTH 1 //����ֵ����ID
#define HEALTH_MAX 2 //�������ֵ����ID
#define MAGIC 3 //ħ��ֵ����ID
#define MAGIC_MAX 4 //���ħ��ֵ����ID
#define SPEED 5 //�ٶ�����ID
#define STAMINA 6 //��������ID
#define STAMINA_MAX 7 //�������ֵ����ID
#define ATTACK 8 //������������ID
#define DEFENCE 9 //�������������ID
#define MAGIC_ATTACK 10 //ħ������������ID
#define MAGIC_DEFENCK 11 //ħ������������ID
#define PRIVATE_WEALTH 12 //˽���ʽ�����ID
#define STRONGBOX 13 //�������������ID
#define BOMB 14 //ը����������ID
#define PUBLIC_WEALTH 15 //�����ʽ�����ID

#define NOTHAVE 0 //δӵ��
#define HAVE 1 //��ӵ��

#define ACTION 5 //ȷ���ж�

#define ERROREVENT -1 //���ִ���
#define NOEVENT 0 //���¼�
#define WIN 1 //ʤ��
#define LOSE 2 //ʧ��
#define DEAD 3 //��������

#define METAL 1 //������
#define WOOD 2 //ľ����
#define EARTH 3 //������
#define WATER 4 //ˮ����
#define FIRE 5 //������
#define LIGHT 11 //������
#define DARK 12 //������

int randNum(int size, int probability[]); //���ݸ���ȷ����ѡ���

/*#define KEYBOARD_FUNCTION void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);\
void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);

#define KEYBOARD_LISTENER(CLASS) EventListenerKeyboard* keyboardListener = EventListenerKeyboard::create();\
keyboardListener->onKeyPressed = CC_CALLBACK_2(CLASS::onKeyPressed, this); \
keyboardListener->onKeyReleased = CC_CALLBACK_2(CLASS::onKeyReleased, this); \
Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);*/
