#include "LabelLayer.h"

bool LabelLayer::init()
{
	Layer::init();

	//font = "fonts/Marker Felt.ttf";
	font = "fonts/SourceHanSans.otf";
	fontSize = 72;
	size = 0.05f;
	healthColor = Color3B::RED;
	magicColor = Color3B::BLUE;
	textColor = Color3B::MAGENTA;

	healthPosition = Point(visibleSize.width*0.5, visibleSize.height*0.93);
	magicPosition = Point(visibleSize.width*0.5, visibleSize.height*0.87);
	speedPosition = Point(visibleSize.width*0.2, visibleSize.height*0.93);
	staminaPosition = Point(visibleSize.width*0.2, visibleSize.height*0.87);
	physicalAttributesPosition = Point(visibleSize.width*0.5, visibleSize.height*0.81);
	magicAttributesPosition = Point(visibleSize.width*0.5, visibleSize.height*0.81);
	privateWealthPosition = Point(visibleSize.width*0.95, visibleSize.height*0.93);
	boxAttributesPosition = Point(visibleSize.width*0.8, visibleSize.height*0.93);
	nickNameAttributesPosition = Point(visibleSize.width*0.5, visibleSize.height*0.99);

	return true;
}

void LabelLayer::addHealthLabel(int health, int healthMax)
{
	removeChild(healthLabel);
	char text[32];
	sprintf(text, "HP:%d/%d", health, healthMax);
	healthLabel = Label::createWithTTF(text, font, fontSize);
	healthLabel->setColor(healthColor);
	healthLabel->setAnchorPoint(Point(0.5, 1));
	healthLabel->setPosition(healthPosition);
	SETSIZE(healthLabel, size);
	this->addChild(healthLabel);
}

void LabelLayer::addMagicLabel(int magic, int magicMax)
{
	removeChild(magicLabel);
	char text[32];
	sprintf(text, "MP:%d/%d", magic, magicMax);
	magicLabel = Label::createWithTTF(text, font, fontSize);
	magicLabel->setColor(magicColor);
	magicLabel->setAnchorPoint(Point(0.5, 1));
	magicLabel->setPosition(magicPosition);
	SETSIZE(magicLabel, size);
	this->addChild(magicLabel);
}

void LabelLayer::addSpeedLabel(int speed)
{
	removeChild(speedLabel);
	char text[32];
	sprintf(text, "SPEED:%d", speed);
	speedLabel = Label::createWithTTF(text, font, fontSize);
	speedLabel->setColor(textColor);
	speedLabel->setAnchorPoint(Point(0, 1));
	speedLabel->setPosition(speedPosition);
	SETSIZE(speedLabel, size);
	this->addChild(speedLabel);
}

void LabelLayer::addStaminaLabel(int stamina, int staminaMax)
{
	removeChild(staminaLabel);
	char text[32];
	sprintf(text, "STAMINA:%d/%d", stamina, staminaMax);
	staminaLabel = Label::createWithTTF(text, font, fontSize);
	staminaLabel->setColor(textColor);
	staminaLabel->setAnchorPoint(Point(0, 1));
	staminaLabel->setPosition(staminaPosition);
	SETSIZE(staminaLabel, size);
	this->addChild(staminaLabel);
}

void LabelLayer::addPhysicalAttributes(int attack, int defence)
{
	removeChild(physicalAttributesLabel);
	char text[32];
	sprintf(text, "ATK:%d DEF:%d ", attack, defence);
	physicalAttributesLabel = Label::createWithTTF(text, font, fontSize);
	physicalAttributesLabel->setColor(healthColor);
	physicalAttributesLabel->setAnchorPoint(Point(1, 1));
	physicalAttributesLabel->setPosition(physicalAttributesPosition);
	SETSIZE(physicalAttributesLabel, size);
	this->addChild(physicalAttributesLabel);
}

void LabelLayer::addMagicAttributes(int magicAttack, int magicDefence)
{
	removeChild(magicAttributesLabel);
	char text[32];
	sprintf(text, " MGK:%d MGD:%d ", magicAttack, magicDefence);
	magicAttributesLabel = Label::createWithTTF(text, font, fontSize);
	magicAttributesLabel->setColor(magicColor);
	magicAttributesLabel->setAnchorPoint(Point(0, 1));
	magicAttributesLabel->setPosition(magicAttributesPosition);
	SETSIZE(magicAttributesLabel, size);
	this->addChild(magicAttributesLabel);
}

void LabelLayer::addPrivateWealth(int privateWealth, int publicWealth)
{
	removeChild(wealthLabel);
	char text[32];
	sprintf(text, "PRI$:%d\nPUB$:%d", privateWealth, publicWealth);
	wealthLabel = Label::createWithTTF(text, font, fontSize);
	wealthLabel->setColor(textColor);
	wealthLabel->setAnchorPoint(Point(1, 1));
	wealthLabel->setPosition(privateWealthPosition);
	SETSIZE(wealthLabel, size*2);
	this->addChild(wealthLabel);
}

void LabelLayer::addBoxAttributes(int strongbox, int bomb)
{
	removeChild(boxAttributesLabel);
	char text[32];
	sprintf(text, "SAFE:%d\nBOMB:%d", strongbox, bomb);
	boxAttributesLabel = Label::createWithTTF(text, font, fontSize);
	boxAttributesLabel->setColor(textColor);
	boxAttributesLabel->setAnchorPoint(Point(1, 1));
	boxAttributesLabel->setPosition(boxAttributesPosition);
	SETSIZE(boxAttributesLabel, size*2);
	this->addChild(boxAttributesLabel);
}

void LabelLayer::addNickNameAttributes(string name)
{
	removeChild(nickNameLabel);
	nickNameLabel = Label::createWithTTF(name, font, fontSize);
	nickNameLabel->setColor(textColor);
	nickNameLabel->setAnchorPoint(Point(0.5, 1));
	nickNameLabel->setPosition(nickNameAttributesPosition);
	SETSIZE(nickNameLabel, size);
	this->addChild(nickNameLabel);
}

void LabelLayer::addAllAttributes(int* attribute)
{
	addHealthLabel(attribute[HEALTH], attribute[HEALTH_MAX]);
	addMagicLabel(attribute[MAGIC], attribute[MAGIC_MAX]);
	addSpeedLabel(attribute[SPEED]);
	addStaminaLabel(attribute[STAMINA], attribute[STAMINA_MAX]);
	addPhysicalAttributes(attribute[ATTACK], attribute[DEFENCE]);
	addMagicAttributes(attribute[MAGIC_ATTACK], attribute[MAGIC_DEFENCK]);
	addPrivateWealth(attribute[PRIVATE_WEALTH], attribute[PUBLIC_WEALTH]);
	addBoxAttributes(attribute[STRONGBOX], attribute[BOMB]);

	delete[] attribute;
}

void LabelLayer::changeStateLabel(std::string s)
{
	removeChild(stateLabel);
	stateLabel = Label::createWithTTF(s, font, 200);
	stateLabel->setColor(Color3B::GREEN);
	stateLabel->setAnchorPoint(Point(1, 0.5));
	stateLabel->setPosition(Point(WIDTH, HEIGHT *0.2));
	SETSIZE(stateLabel, 0.1);
	this->addChild(stateLabel);
}

void LabelLayer::removeStateLabel()
{
	removeChild(stateLabel);
}