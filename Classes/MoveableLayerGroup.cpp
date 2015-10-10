#include "MoveableLayerGroup.h"

bool MoveableLayerGroup::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!Layer::init());

		initBackGroundLayer();
		initMapLayer();
		initRouteLayer();
		initWarriorLayer();
		initMapDataLayer();
		initData();

		focusSpeed = 900;
		position = Point::ZERO;

		bRet = true;
	} while (0);
	return bRet;
}

void MoveableLayerGroup::initBackGroundLayer()
{
	backGround = BackGroundLayer::create();
	this->addChild(backGround);
}

void MoveableLayerGroup::initMapLayer()
{
	map = MapLayer::create();
	this->addChild(map);
}

void MoveableLayerGroup::initRouteLayer()
{
	route = RouteLayer::create();
	this->addChild(route);
}

void MoveableLayerGroup::initWarriorLayer()
{
	warrior = WarriorLayer::create();
	this->addChild(warrior);
}

void MoveableLayerGroup::initMapDataLayer()
{
	mapData = MapDataLayer::create();
	this->addChild(mapData);
}

void MoveableLayerGroup::initData()
{
	touchesQuantity = 0;
	initialDistance = -1;
	changeToOnePointFlag = false;
	changeToTwoPointsFlag = false;
}

void MoveableLayerGroup::onEnter()
{
	Layer::onEnter();

	auto listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesBegan = CC_CALLBACK_2(MoveableLayerGroup::onTouchesBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(MoveableLayerGroup::onTouchesMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(MoveableLayerGroup::onTouchesEnded, this);
	listener->onTouchesCancelled = CC_CALLBACK_2(MoveableLayerGroup::onTouchesEnded, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

void MoveableLayerGroup::onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event)
{
	touchesQuantity++;
	if (1 == touchesQuantity)
	{
		changeToOnePointFlag = true;
	}
	else if (2 == touchesQuantity)
	{
		changeToTwoPointsFlag = true;
	}
}

void MoveableLayerGroup::onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event)
{
	if (1 == touchesQuantity)
	{
		if (changeToOnePointFlag)
		{
			Point touchPoint = touches[0]->getLocation();
			offset = touchPoint - this->getPosition();
			changeToOnePointFlag = false;
		}
		else
		{
			Point touchPoint = touches[0]->getLocation();
			position = touchPoint - offset;
			this->setPosition(position);
		}
	}
	else if (2 == touchesQuantity)
	{
		Point p1 = touches[0]->getLocation(), p2 = touches[1]->getLocation();
		if (changeToTwoPointsFlag)
		{
			initialDistance = p1.distance(p2);
			Point touchesMidPointInScreen = p1.getMidpoint(p2);
			touchesMidPointInLayer = getLocationInLayer(touchesMidPointInScreen);
			changeToTwoPointsFlag = false;
		}
		else
		{
			Point touchesMidPointInScreen = p1.getMidpoint(p2);
			float distance = p1.distance(p2);
			this->scale(distance / initialDistance);
			focusPoint(false, touchesMidPointInLayer, touchesMidPointInScreen);
			initialDistance = distance;
		}
	}
}

void MoveableLayerGroup::onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event)
{
	touchesQuantity--;
	if (1 == touchesQuantity)
	{
		changeToOnePointFlag = true;
	}
	else if (2 == touchesQuantity)
	{
		changeToTwoPointsFlag = true;
	}
}

void MoveableLayerGroup::focusPoint(bool animeFlag, float xInLayer, float yInLayer, float xInScreen /* = visibleSize.width/2 */, float yInScreen /* = visibleSize.height/2 */)
{
	float s = this->getScale();
	Point p = Point(xInScreen - xInLayer*s, yInScreen - yInLayer*s);
	if (animeFlag)
	{
		//Point p = Point(xInLayer, xInLayer);
		float d = p.distance(position);
		float t = d / focusSpeed / s;
		this->runAction(MoveTo::create(t, p));
	}
	else
	{
		this->setPosition(p);
	}
	position = p;
}

void MoveableLayerGroup::focusPoint(bool animeFlag, Point pInLayer, Point pInScreen /* = Point(visibleSize.width/2, visibleSize.height/2) */)
{
	this->focusPoint(animeFlag, pInLayer.x, pInLayer.y, pInScreen.x, pInScreen.y);
}

Point MoveableLayerGroup::getLocationInLayer(float xInScreen, float yInScreen)
{
	float s = this->getScale();
	return Point((xInScreen-this->getPositionX())/s, (yInScreen-this->getPositionY())/s);
}

Point MoveableLayerGroup::getLocationInLayer(Point pInScreen)
{
	return this->getLocationInLayer(pInScreen.x, pInScreen.y);
}

void MoveableLayerGroup::scale(float factor)
{
	this->setScale(this->getScale() * factor);
}

void MoveableLayerGroup::setSize(float size)
{
	this->setScale(DATUM*size / backGround->getBGHeight());
}