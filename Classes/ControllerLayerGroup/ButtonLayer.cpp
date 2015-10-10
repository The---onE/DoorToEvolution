#include "ButtonLayer.h"

USING_XMX;

bool ButtonLayer::init()
{
	Layer::init();

	Button::addButton(BIG_MAP, Sprite::create("buttons/BigMap.png"), 0.1f, visibleSize.width*0.98, visibleSize.height*0.51, 1, 0);
	Button::addButton(SMALL_MAP, Sprite::create("buttons/SmallMap.png"), 0.1f, visibleSize.width*0.98, visibleSize.height*0.49, 1, 1);
	Button::addButton(OK, Sprite::create("buttons/OK.png"), 0.1f, visibleSize.width*0.75, visibleSize.height*0.01, 0, 0);
	Button::addButton(CANCEL, Sprite::create("buttons/Cancel.png"), 0.1f, visibleSize.width*0.98, visibleSize.height*0.01, 1, 0);
	Button::addButton(REST, Sprite::create("buttons/Rest.png"), 0.1f, visibleSize.width*0.02, visibleSize.height*0.44, 0, 1);
	Button::addButton(TP, Sprite::create("buttons/TP.png"), 0.1f, visibleSize.width*0.02, visibleSize.height*0.46, 0, 0);
	Button::addButton(CHANGE, Sprite::create("buttons/Change.png"), 0.1f, visibleSize.width*0.98, visibleSize.height*0.65, 1, 0);
	Button::setVibratorTime(VIBRATE_TIME);
	return true;
}

void ButtonLayer::onEnter()
{
	Layer::onEnter();

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = [&](Touch *touch, Event *unused_event){return Button::onTouchBegan(touch, unused_event); };
	listener->onTouchMoved = [&](Touch *touch, Event *unused_event){Button::onTouchMoved(touch, unused_event); };
	listener->onTouchEnded = [&](Touch *touch, Event *unused_event){Button::onTouchEnded(touch, unused_event); };
	listener->onTouchCancelled = [&](Touch *touch, Event *unused_event){Button::onTouchEnded(touch, unused_event); };
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}