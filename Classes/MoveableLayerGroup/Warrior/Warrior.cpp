#include "Warrior.h"

int Warrior::teamXKey[KEYS_NUMBER] = { NOTHAVE, NOTHAVE };
int Warrior::teamYKey[KEYS_NUMBER] = { NOTHAVE, NOTHAVE };
int Warrior::teamXWealth = 0;
int Warrior::teamYWealth = 0;

bool Warrior::init()
{
	Node::init();

	index = 0;
	position = -1;

	element = 0;

	health = 0;
	healthMax = 0;
	magic = 0;
	magicMax = 0;

	speed = 0;
	stamina = 0;

	attack = 0;
	defence = 0;

	magicAttack = 0;
	magicDefence = 0;

	privateWealth = 0;

	strongbox = 0;
	bomb = 0;

	runParam = 0.5;

	for (int i = 0; i < KEYS_NUMBER; i++)
	{
		key[i] = NOTHAVE;
	}
	for (int j = 0; j < KEYS_NUMBER; j++)
	{
		falseKey[j] = false;
	}

	changedFlag = true;

	return true;
}

void Warrior::toPosition(int destination)
{
	warrior->setPosition(node[destination]);
}

void Warrior::setWarriorSprite(Sprite* s, float size)
{
	warrior = s;
	SETSIZE(warrior, size);
	addChild(warrior);
}

void Warrior::setIndex(int i)
{
	index = i;
}

int Warrior::getIndex()
{
	return index;
}

void Warrior::setNickName(string name)
{
	nickName = name;
}

string Warrior::getNickName()
{
	return nickName;
}

void Warrior::setElement(int ele)
{
	element = ele;
}

void Warrior::initHealth(int hm)
{
	healthMax = hm;
	health = hm;
}

int Warrior::getHealth()
{
	return health;
}

int Warrior::getHealthMax()
{
	return healthMax;
}

bool Warrior::checkHealthOverflow()
{
	if (health > healthMax)
	{
		health = healthMax;
		return true;
	}
	return false;
}

void Warrior::changeHealth(int delta)
{
	health += delta;
}

void Warrior::initMagic(int mm)
{
	magicMax = mm;
	magic = mm;
}

int Warrior::getMagic()
{
	return magic;
}

int Warrior::getMagicMax()
{
	return magicMax;
}

bool Warrior::checkMagicOverflow()
{
	if (magic > magicMax)
	{
		magic = magicMax;
		return true;
	}
	return false;
}

void Warrior::changeMagic(int delta)
{
	magic += delta;
}

void Warrior::initStamina(int sm)
{
	staminaMax = sm;
	stamina = sm;
}

bool Warrior::checkStaminaOverflow()
{
	if (stamina > staminaMax)
	{
		stamina = staminaMax;
		return true;
	}
	return false;
}

void Warrior::changeStamina()
{
	stamina += speed;
}

void Warrior::changeStamina(int delta)
{
	stamina += delta;
}

void Warrior::setSpeed(int s)
{
	speed = s;
}

int Warrior::getSpeed()
{
	return speed;
}

void Warrior::setPrivateWealth(int w)
{
	privateWealth = w;
}

int Warrior::getPrivateWealth()
{
	return privateWealth;
}

void Warrior::changePrivateWealth(int delta)
{
	privateWealth += delta;
}

int Warrior::getPositionIndex()
{
	return position;
}

void Warrior::setPoisitionIndex(int p)
{
	position = p;
}

float Warrior::moveTo(int destination)
{
	if (exertStamina(position, destination))
	{
		//warrior->setPosition(node[destination]);
		float t = dis[position][destination] * runParam / speed;
		warrior->runAction(MoveTo::create(t, node[destination]));
		position = destination;
		return t;
	}
	return -1;
}

int Warrior::getExertion(int from, int to)
{
	int exertion = dis[from][to] - speed;
	//return (exertion > 0) ? exertion : 0;
	return exertion;
}

bool Warrior::exertStamina(int exertion)
{
	int delta = stamina - exertion;
	if (delta >= 0)
	{
		stamina = delta;
		changedFlag = true;
		return true;
	}
	else
	{
		return false;
	}
}

bool Warrior::exertStamina(int from, int to)
{
	if (from == to)
	{
		return true;
	}
	return exertStamina(getExertion(from, to));
}

bool Warrior::isStaminaEnough(int to)
{
	if (position == to)
	{
		return true;
	}
	else
	{
		int delta = stamina - getExertion(position, to);
		if (delta >= 0)
			return true;
		else
			return false;
	}
}

bool Warrior::isAttributesChanged()
{
	return changedFlag;
}

void Warrior::setAttributesChanged(bool flag)
{
	changedFlag = flag;
}

int* Warrior::getAllAttributes()
{
	int* attribute = new int[ATTRIBUTES];

	attribute[INDEX] = index;
	attribute[HEALTH] = health;
	attribute[HEALTH_MAX] = healthMax;
	attribute[MAGIC] = magic;
	attribute[MAGIC_MAX] = magicMax;
	attribute[SPEED] = speed;
	attribute[STAMINA] = stamina;
	attribute[STAMINA_MAX] = staminaMax;
	attribute[ATTACK] = attack;
	attribute[DEFENCE] = defence;
	attribute[MAGIC_ATTACK] = magicAttack;
	attribute[MAGIC_DEFENCK] = magicDefence;
	attribute[PRIVATE_WEALTH] = privateWealth;
	attribute[PUBLIC_WEALTH] = getPublicWealth();
	attribute[STRONGBOX] = strongbox;
	attribute[BOMB] = bomb;

	return attribute;
}

bool Warrior::isTeamX()
{
	return teamXFlag;
}

void Warrior::changePublicWealth(int delta)
{
	if (isTeamX())
	{
		teamXWealth += delta;
	}
	else
	{
		teamYWealth += delta;
	}
}

int Warrior::getPublicWealth()
{
	if (isTeamX())
	{
		return teamXWealth;
	}
	else
	{
		return teamYWealth;
	}
}

void Warrior::setPublicWealth(int w)
{
	if (isTeamX())
	{
		teamXWealth = w;
	}
	else
	{
		teamYWealth = w;
	}
}

bool Warrior::isTeamXWin()
{
	for (int i = 0; i < KEYS_NUMBER; i++)
	{
		if (teamXKey[i] != HAVE)
		{
			return false;
		}
	}

	return true;
}

bool Warrior::isTeamYWin()
{
	for (int i = 0; i < KEYS_NUMBER; i++)
	{
		if (teamYKey[i] != HAVE)
		{
			return false;
		}
	}

	return true;
}
