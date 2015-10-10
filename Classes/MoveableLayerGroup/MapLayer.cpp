#include "MapLayer.h"

bool MapLayer::init()
{
	Layer::init();

	brush= DrawNode::create();
	this->addChild(brush);
	lineWidth = 2.5;
	lineColor = Color4F::BLUE;
	lineColor.a = 0.32f;

	drawLine(1, 2);
	drawLine(2, 3);
	drawLine(3, 4);
	drawLine(4, 1);
	drawLine(1, 3);
	drawLine(2, 4);
	drawLine(5, 6);
	drawLine(6, 7);
	drawLine(7, 8);
	drawLine(8, 5);
	drawLine(5, 7);
	drawLine(6, 8);
	drawLine(9, 10);
	drawLine(10, 11);
	drawLine(11, 12);
	drawLine(12, 9);

	return true;
}

void MapLayer::drawLine(int from, int to)
{
	brush->drawSegment(node[from], node[to], lineWidth, lineColor);
}
