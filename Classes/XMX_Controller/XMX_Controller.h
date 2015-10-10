#pragma once

/****************************************************************************
//���� setControler ���ÿ�����
//���� setSpeedMax ��������ٶ�
//���� setTouchRect ���ô�������
//���� setVibratorTime ������ʱ��
//���� set4DirectionMode ����Ϊ�ķ���ģʽ
//���� set8DirectionMode ����Ϊ�˷���ģʽ
//���� allowControl ����Ϊ������
//���� notAllowControl ����Ϊ��������
//���� getSpeedX getSpeedY ���˲ʱ�ٶȣ�Ӧ������ update ������ c->setPositionX(c->getPositionX() + getSpeedX()) c->setPositionY(c->getPositionY() + getSpeedY())��
//�� onTouchBegan onTouchMoved onTouchEnded ����������Ӧ������
****************************************************************************/

#include "Global.h"

namespace XMX
{
	class Controller : public virtual Layer
	{
	private:
		int vibratorTime; //��ʱ��
		float rb; //������뾶
		float rs; //���ص�뾶
		Point position;
		int angle; //���ˮƽ����Ƕ�
		Rect touchRect; //��Ӧ���ص����򣨿�ʼ���أ�
		Sprite* round; //������Sprite
		Sprite* ball; //���ص�Sprite
		bool touchFlag; //�Ƿ��ѿ�ʼ����
		bool allowControlFlag; //�Ƿ�������
		bool touchMaxFlag; //�Ƿ���������Ե
		bool controlerFlag; //�Ƿ����ÿ�����
		bool touchRectFlag; //�Ƿ������ô�������

		bool checkControler(); //���������Ƿ��ѱ��ɹ�����

	public:
		Controller();
		void setControler(Sprite* round, Sprite* ball, float rb, float rs, int x, int y); //���ÿ�����
		void setTouchRect(Rect touchRact); //���ô�������
		void setVibratorTime(int time); //������ʱ��
		void allowControl(); //����Ϊ������
		void notAllowControl(); //����Ϊ��������
		int getAngle(); //������ˮƽ����Ƕ�
		bool onTouchBegan(Touch *touch, Event *unused_event);
		void onTouchMoved(Touch *touch, Event *unused_event);
		void onTouchEnded(Touch *touch, Event *unused_event);
	};
}
