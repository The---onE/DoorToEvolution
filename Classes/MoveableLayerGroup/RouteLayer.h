#pragma once

#include "Global.h"

extern const Point node[];
extern const int dis[][TOTAL_NODE];

class RouteLayer : public Layer
{
protected:
	DrawNode* brush; //画刷
	float lineWidth; //默认线条宽度
	int drawnStart; //线条起点
	int drawnEnd;//线条终点
	float circleRadius; //六边形半径

	int direction[TOTAL_NODE]; //存储中心点至其他节点的角度
	int prevCenter; //上一次中心点

	Label* exertionLabel; //消耗耐力标签
	std::string font; //字体
	float fontSize; //字体大小
	float size; //标签大小

public:
	CREATE_FUNC(RouteLayer);
	bool init();
	void drawLine(int from, int to, Color4F color, float radius = 0); //通过起始点画线
	void drawSexangle(int middle, Color4F color); //以中心画六边形
	int getAngle(int center, int edge); //获取中心点至其他节点的角度
	int getEndByAngle(int center, int angle); //通过中心点和角度获取终点
	int getStart(); //获取线条起点
	int getEnd(); //获取线条终点
	void addExertionLabel(int from, int to, int exertion, Color3B color); //添加消耗体力标签
	void removeExertionLabel(); //移除消耗体力标签
	void reset(); //重置全部绘制
	void clear(); //清除线条，保留起始点
};