#pragma once

#include "Global.h"

extern const Point node[];
extern const int dis[][TOTAL_NODE];

class MapLayer : public Layer
{
protected:
	DrawNode* brush; //画刷
	float lineWidth; //默认线条宽度
	Color4F lineColor; //默认线条颜色

public:
	CREATE_FUNC(MapLayer);
	bool init();
	void drawLine(int from, int to); //绘制线条
};