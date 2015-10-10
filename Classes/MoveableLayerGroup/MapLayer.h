#pragma once

#include "Global.h"

extern const Point node[];
extern const int dis[][TOTAL_NODE];

class MapLayer : public Layer
{
protected:
	DrawNode* brush; //��ˢ
	float lineWidth; //Ĭ���������
	Color4F lineColor; //Ĭ��������ɫ

public:
	CREATE_FUNC(MapLayer);
	bool init();
	void drawLine(int from, int to); //��������
};