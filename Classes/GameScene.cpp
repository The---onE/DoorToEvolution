#include "GameScene.h"
#include "State/StateList.h"

bool GameScene::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!Scene::init());

		prevAngle = NOANGLE;
		prevPosition = NOCHOOSE;
		start = NOCHOOSE;
		end = NOCHOOSE;

		restFlag = false;

		lead = NULL;

		enoughPrepareColor = Color4F::MAGENTA;
		notEnoughPrepareColor = Color4F::GRAY;
		actionColor = Color4F::ORANGE;
		enoughColor = Color3B::GREEN;
		notEnoughColor = Color3B::RED;

		initMoveableLayerGroup();
		initControllerLayerGroup();
		initInformationLayerGroup();

		initData();
		createQuitButton();

		initStateMachine();
		scheduleUpdate();

		bRet = true;
	} while (0);
	return bRet;
}

void GameScene::initMoveableLayerGroup()
{
	moveableGroup = MoveableLayerGroup::create();
	moveableGroup->ignoreAnchorPointForPosition(false);
	moveableGroup->setAnchorPoint(Point(0, 0));
	this->addChild(moveableGroup);
	setMapSize(1.2f);
	focusPoint(false, 450, 450);
}

void GameScene::initControllerLayerGroup()
{
	controllerGroup = ControllerLayerGroup::create();
	this->addChild(controllerGroup);
}

void GameScene::initInformationLayerGroup()
{
	informationGroup = InformationLayerGroup::create();
	this->addChild(informationGroup);
}

void GameScene::initData()
{
	prevAngle = NOANGLE;
	prevPosition = NOCHOOSE;

	restFlag = false;
}

void GameScene::initStateMachine()
{
	stateMachine = StateMachine::createWithGameScene(this);
	stateMachine->changeState(StartState::create(this));
}

void GameScene::initPlayer()
{
	x_1 = TeamXPlayer::create();

	Sprite* sx = Sprite::create("players/x_1.png");
	x_1->setWarriorSprite(sx, 0.08f);

	x_1->setIndex(1);
	x_1->setNickName("X Player 1");
	x_1->setElement(METAL);
	x_1->initHealth(450);
	x_1->initMagic(233);
	x_1->setSpeed(37);
	x_1->initStamina(192);
	x_1->setPrivateWealth(500);
	x_1->setPublicWealth(200);
	moveableGroup->addPlayerX(x_1, 3);
	x.push_back(x_1);

	y_1 = TeamYPlayer::create();

	Sprite* sy = Sprite::create("players/x_1.png");
	sy->setFlippedX(true);
	y_1->setWarriorSprite(sy, 0.1f);

	y_1->setIndex(2);
	y_1->setNickName("Y Player 1");
	y_1->setElement(METAL);
	y_1->initHealth(700);
	y_1->initMagic(450);
	y_1->setSpeed(23);
	y_1->initStamina(128);
	y_1->setPrivateWealth(700000);
	y_1->setPublicWealth(0);
	moveableGroup->addPlayerY(y_1, 1);
	y.push_back(y_1);

	setLead(x_1);
	xFlag = true;
	focusPoint(false, 0);
}

void GameScene::prepareThisRound()
{
	moveableGroup->roundStart(lead);
	cancelAllController();
}

void GameScene::cancelAllController()
{
	ButtonLayer* b = controllerGroup->getButtonLayer();
	b->responsed(CHANGE);
	b->responsed(REST);
	b->responsed(CANCEL);
	b->responsed(OK);
}

int GameScene::processWarriorController()
{
	if (!lead)
	{
		return ERROREVENT;
	}

	ButtonLayer* b = controllerGroup->getButtonLayer();

	int angle = controllerGroup->getAngle();
	int position = lead->getPositionIndex();
	if (angle != prevAngle || position != prevPosition)
	{
		prevAngle = angle;
		prevPosition = position;
		int to = moveableGroup->getEndByAngle(position, angle);
		if (to != NOCHOOSE)
		{
			int exertion = lead->getExertion(position, to);
			bool flag = lead->isStaminaEnough(to);
			if (flag)
			{
				moveableGroup->routeClear();
				moveableGroup->drawLine(position, to, enoughPrepareColor);
				moveableGroup->addExertionLabel(position, to, exertion, enoughColor);
			}
			else
			{
				moveableGroup->routeClear();
				moveableGroup->drawLine(position, to, notEnoughPrepareColor);
				moveableGroup->addExertionLabel(position, to, exertion, notEnoughColor);
			}
		}
	}

	if (b->isNeedResponse(CHANGE))
	{
		b->responsed(CHANGE);
		changeLead();
	}
	if (b->isNeedResponse(REST))
	{
		b->responsed(REST);
		restFlag = true;
		moveableGroup->routeReset();
		moveableGroup->drawSexangle(position, enoughPrepareColor);
	}
	if (b->isNeedResponse(CANCEL))
	{
		b->responsed(CANCEL);
		moveableGroup->routeReset();
		restFlag = false;
	}

	if (b->isNeedResponse(OK))
	{
		b->responsed(OK);
		end = moveableGroup->getRouteEnd();
		if (restFlag)
		{
			end = lead->getPositionIndex();
			moveableGroup->routeReset();
			moveableGroup->drawSexangle(position, actionColor);
		}

		if (end == NOCHOOSE || !(lead->isStaminaEnough(end)))
		{
			focusPoint(false, position);
		}
		else
		{
			start = moveableGroup->getRouteStart();
			if (!restFlag)
			{
				moveableGroup->routeReset();
				moveableGroup->drawLine(start, end, actionColor);
			}
			return ACTION;
		}
	}

	return NOEVENT;
}

int GameScene::processBasicController()
{
	ButtonLayer* b = controllerGroup->getButtonLayer();

	if (b->isNeedResponse(BIG_MAP))
	{
		b->responsed(BIG_MAP);
		setMapSize(2.4f);
		focusPoint(false, lead->getPositionIndex());
	}
	if (b->isNeedResponse(SMALL_MAP))
	{
		b->responsed(SMALL_MAP);
		setMapSize(1);
		focusPoint(false, 0);
	}
	return NOEVENT;
}

int GameScene::act()
{
	leadAct(lead, end, restFlag);
	moveableGroup->routeReset();

	//////////////////////////////////////////////////////////////////////////
	if (xFlag)
		enemy = y_1;
	else
		enemy = x_1;
	randomMove(enemy);
	//////////////////////////////////////////////////////////////////////////

	return NOEVENT;
}

int GameScene::processAction()
{
	int flag;

	flag = warriorProcess(lead, end, &restFlag);

	//////////////////////////////////////////////////////////////////////////
	warriorProcess(enemy, re, rest);
	//////////////////////////////////////////////////////////////////////////

	informationGroup->addAllAttributes(lead->getAllAttributes());
	lead->setAttributesChanged(false);

	moveableGroup->processAllMapNode();

	return flag;
}

void GameScene::prepareNextRound()
{
	moveableGroup->roundEnd(lead);
}

void GameScene::setLead(Warrior* le)
{
	moveableGroup->setLead(le);

	informationGroup->addAllAttributes(le->getAllAttributes());
	informationGroup->addNickNameAttributes(le->getNickName());
	le->setAttributesChanged(false);

	lead = le;

	moveableGroup->removeChild(leadRound);
	leadRound = Sprite::create("players/lead.png");
	SETSIZE(leadRound, 0.11);
	leadRound->setPosition(node[le->getPositionIndex()]);
	moveableGroup->addChild(leadRound);

	focusPoint(true, lead->getPositionIndex());
}

float GameScene::warriorAct(Warrior* w, int destination, bool rest/* =false */)
{
	float t = 0;
	if (!rest)
	{
		moveableGroup->leave(w, w->getPositionIndex());
		float t = w->moveTo(destination);
	}
	else
	{
		w->moveTo(w->getPositionIndex());
	}
	return t;
}

float GameScene::leadAct(Warrior* l, int destination, bool rest /* = false */)
{
	float t = 0;
	if (!rest)
	{
		moveableGroup->leave(l, l->getPositionIndex());
		float t = l->moveTo(destination);
		leadRound->runAction(MoveTo::create(t, node[end]));
	}
	else
	{
		l->moveTo(l->getPositionIndex());
	}
	focusPoint(true, end);
	return t;

}

int GameScene::warriorProcess(Warrior* w, int destination, bool* rest)
{
	int flag;
	if (*rest)
	{
		destination = w->getPositionIndex();
		flag = moveableGroup->rest(w, destination);
		*rest = false;
	}
	else
	{
		flag = moveableGroup->arrive(w, destination);
	}

	return flag;
}

int GameScene::warriorProcess(Warrior* w, int destination, bool rest /* = false */)
{
	int flag;
	if (rest)
	{
		destination = w->getPositionIndex();
		flag = moveableGroup->rest(w, destination);
		rest = false;
	}
	else
	{
		flag = moveableGroup->arrive(w, destination);
	}

	return flag;
}

void GameScene::changeLead()
{
	if (lead == x_1)
	{
		setLead(y_1);
		xFlag = false;
	}
	else
	{
		setLead(x_1);
		xFlag = true;
	}
}

void GameScene::randomMove(Warrior* enemy)
{
	int pos = enemy->getPositionIndex();
	int pro[TOTAL_NODE];
	int n[TOTAL_NODE];
	int c = 0;
	for (int i = 0; i < TOTAL_NODE; ++i)
	{
		if (dis[pos][i] >= NC)
			continue;
		else if (!enemy->isStaminaEnough(i))
			continue;
		else
		{
			pro[c] = dis[pos][i] + 1;
			n[c] = i;
			c++;
		}
	}

	r = 0;
	rest = false;
	if (c > 0)
	{
		r = randNum(c, pro);
		if (n[r] == enemy->getPositionIndex())
			rest = true;
	}
	else
	{
		rest = true;
	}
	re = n[r];
	warriorAct(enemy, re, rest);
}

void GameScene::createQuitButton()
{
	auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(GameScene::quitGame, this));
	closeItem->setPosition(Point(visibleSize.width / 2, 0));
	closeItem->setAnchorPoint(Point(0.5f, 0));
	SETSIZE(closeItem, 0.1);
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 1);
}

void GameScene::quitGame(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
	return;
#endif

	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}