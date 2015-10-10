#include "ControlLayer.h"

USING_XMX;

bool ControlLayer::init()
{
	Layer::init();

	Controller::setControler(Sprite::create("round.png"), Sprite::create("ball.png"), 0.1f, 0.025f, DATUM*0.125, DATUM*0.125);
	Controller::setTouchRect(Rect(0, 0, DATUM*0.25, DATUM*0.25));

	return true;
}

void ControlLayer::onEnter()
{
	Layer::onEnter();

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = [&](Touch *touch, Event *unused_event){return Controller::onTouchBegan(touch, unused_event); };
	listener->onTouchMoved = [&](Touch *touch, Event *unused_event){Controller::onTouchMoved(touch, unused_event); };
	listener->onTouchEnded = [&](Touch *touch, Event *unused_event){Controller::onTouchEnded(touch, unused_event); };
	listener->onTouchCancelled = [&](Touch *touch, Event *unused_event){Controller::onTouchEnded(touch, unused_event); };
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

int ControlLayer::getAngle()
{
	return Controller::getAngle();
}