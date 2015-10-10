#include "ControllerLayerGroup.h"

bool ControllerLayerGroup::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!Layer::init());

		initControlLayer();
		initButtonLayer();

		bRet = true;
	} while (0);
	return bRet;
}

void ControllerLayerGroup::initControlLayer()
{
	control = ControlLayer::create();
	this->addChild(control);
}

void ControllerLayerGroup::initButtonLayer()
{
	button = ButtonLayer::create();
	this->addChild(button);
}