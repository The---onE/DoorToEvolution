#include "InformationLayerGroup.h"

bool InformationLayerGroup::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!Layer::init());

		initLabelLayer();

		bRet = true;
	} while (0);
	return bRet;
}

void InformationLayerGroup::initLabelLayer()
{
	label = LabelLayer::create();
	this->addChild(label);
}