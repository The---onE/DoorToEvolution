#pragma once

#include "Global.h"

extern const Point node[];
extern const int dis[][TOTAL_NODE];

class Warrior : public Node
{
protected:
	Sprite* warrior; //��ɫSprite

	int index; //��ɫ���
	string nickName; //����ǳ�

	int position; //��ɫ����λ��

	int element; //��ɫ����

	int health; //��ǰ����ֵ
	int healthMax; //�������ֵ
	int magic; //��ǰ����ֵ
	int magicMax; //�����ֵ

	int speed; //��ɫ�ٶ�
	int stamina; //��ǰ����
	int staminaMax; //�������ֵ

	int attack; //��ɫ������
	int defence; //��ɫ������

	int magicAttack; //��ɫħ��������
	int magicDefence; //��ɫħ��������

	int privateWealth; //��ɫ˽�вƲ�

	int strongbox; //���������
	int bomb; //ը������

	float runParam; //�ƶ�����

	int key[KEYS_NUMBER]; //Я����Կ��
	bool falseKey[KEYS_NUMBER]; //Я���ļ�Կ��

	static int teamXWealth; //X�ӹ��вƲ�
	static int teamXKey[KEYS_NUMBER]; //X��ӵ�е�Կ��
	static int teamXFalseKey[KEYS_NUMBER]; //X��ӵ�еļ�Կ��
	static int teamYWealth; //Y�ӹ��вƲ�
	static int teamYKey[KEYS_NUMBER]; //Y��ӵ�е�Կ��
	static int teamYFalseKey[KEYS_NUMBER]; //Y��ӵ�еļ�Կ��

	bool changedFlag; //�Ƿ���ֵ�ı�
	bool teamXFlag; //�Ƿ�ΪX�ӳ�Ա
	
public:
	bool init();

	void toPosition(int destination); //��ʼ����ɫʱ���ý�ɫλ��

	void setWarriorSprite(Sprite* s, float size); //���ý�ɫSprite;

	void setIndex(int i); //��������
	int getIndex(); //��ȡ����

	void setNickName(string name); //�����ǳ�
	string getNickName(); //��ȡ�ǳ�

	void setElement(int ele); //���ý�ɫ����

	void initHealth(int hm); //��ʼ������ֵ
	int getHealth(); //��ȡ��ǰ����ֵ
	int getHealthMax(); //��ȡ�������ֵ
	bool checkHealthOverflow(); //��鵱ǰ����ֵ�Ƿ񳬹��������ֵ
	void changeHealth(int delta); //�ı�����ֵ

	void initMagic(int mm); //��ʼ������ֵ
	int getMagic(); //��ȡ��ǰ����ֵ
	int getMagicMax(); //��ȡ�����ֵ
	bool checkMagicOverflow(); //��鵱ǰ����ֵ�Ƿ񳬹������ֵ
	void changeMagic(int delta); //�ı䷨��ֵ

	void initStamina(int sm); //��ʼ������
	bool checkStaminaOverflow(); //��鵱ǰ�����Ƿ񳬹��������
	void changeStamina(); //����ʱͨ���ٶȸı�����
	void changeStamina(int delta); //�ı�����

	void setSpeed(int s); //�����ٶ�
	int getSpeed(); //��ȡ�ٶ�

	void setPrivateWealth(int w); //����˽�вƲ�
	int getPrivateWealth(); //��ȡ˽�вƲ�
	void changePrivateWealth(int delta); //�ı�˽�вƲ�

	int getPositionIndex(); //��ȡλ������
	void setPoisitionIndex(int p); //����λ������
	float moveTo(int destination); //�ƶ���Ŀ��λ��
	int getExertion(int from, int to); //��ȡ�ƶ�������
	bool exertStamina(int exertion); //��������
	bool exertStamina(int from, int to); //��������
	bool isStaminaEnough(int to); //�Ƿ������㹻�ƶ�

	bool isAttributesChanged(); //�Ƿ�״̬�ı�
	void setAttributesChanged(bool flag); //����״̬�ı���
	int* getAllAttributes(); //��LabelLayer.cpp��addAllAttributes�����Խ�

	bool isTeamX(); //�Ƿ�ΪX�ӳ�Ա

	void changePublicWealth(int delta); //�ı乫�вƲ�
	int getPublicWealth(); //��ȡ���вƲ�
	void setPublicWealth(int w); //���ù��вƲ�

	static bool isTeamXWin(); //�Ƿ�X��ʤ��
	static bool isTeamYWin(); //�Ƿ�Y��ʤ��
};