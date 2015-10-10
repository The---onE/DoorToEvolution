#include "BackGroundLayer.h"

bool BackGroundLayer::init()
{
	Layer::init();

	bG = Sprite::create("bg.jpg");
	bG->setAnchorPoint(Point(0, 0));
	bG->setPosition(0, 0);
	this->addChild(bG);

	return true;
}

float BackGroundLayer::getBGHeight()
{
	return bG->getContentSize().height;
}