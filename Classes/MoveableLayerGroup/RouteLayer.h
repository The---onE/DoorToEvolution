#pragma once

#include "Global.h"

extern const Point node[];
extern const int dis[][TOTAL_NODE];

class RouteLayer : public Layer
{
protected:
	DrawNode* brush; //��ˢ
	float lineWidth; //Ĭ���������
	int drawnStart; //�������
	int drawnEnd;//�����յ�
	float circleRadius; //�����ΰ뾶

	int direction[TOTAL_NODE]; //�洢���ĵ��������ڵ�ĽǶ�
	int prevCenter; //��һ�����ĵ�

	Label* exertionLabel; //����������ǩ
	std::string font; //����
	float fontSize; //�����С
	float size; //��ǩ��С

public:
	CREATE_FUNC(RouteLayer);
	bool init();
	void drawLine(int from, int to, Color4F color, float radius = 0); //ͨ����ʼ�㻭��
	void drawSexangle(int middle, Color4F color); //�����Ļ�������
	int getAngle(int center, int edge); //��ȡ���ĵ��������ڵ�ĽǶ�
	int getEndByAngle(int center, int angle); //ͨ�����ĵ�ͽǶȻ�ȡ�յ�
	int getStart(); //��ȡ�������
	int getEnd(); //��ȡ�����յ�
	void addExertionLabel(int from, int to, int exertion, Color3B color); //�������������ǩ
	void removeExertionLabel(); //�Ƴ�����������ǩ
	void reset(); //����ȫ������
	void clear(); //���������������ʼ��
};