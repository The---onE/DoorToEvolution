#include "XMX_Controller.h"

using namespace XMX;

Controller::Controller()
{
	rb = 0;
	rs = 0;

	position = Point::ZERO;

	touchRect = Rect();
	round = NULL;
	ball = NULL;

	angle = NOANGLE;

	vibratorTime = VIBRATE_TIME;

	touchRectFlag = false;
	touchFlag = false;
	controlerFlag = false;
	allowControlFlag = true;
	touchMaxFlag = false;
}

bool Controller::checkControler()
{
	if (!controlerFlag)
		return false;
	if (!touchRectFlag)
		return false;

	return true;
}

void Controller::setControler(Sprite* round, Sprite* ball, float rb, float rs, int x, int y)
{
	removeChild(this->round);
	removeChild(this->ball);

	this->round = round;
	this->ball = ball;
	this->rb = rb;
	this->rs = rs;
	this->position = Point(x, y);

	SETSIZE(this->round, this->rb*2);
	SETSIZE(this->ball, this->rs*2);

	this->round->setPosition(this->position);
	this->ball->setPosition(this->position);

	addChild(this->round);
	addChild(this->ball);

	this->controlerFlag = true;
}

void Controller::setVibratorTime(int time)
{
	vibratorTime = time;
}

void Controller::allowControl()
{
	allowControlFlag = true;
}

void Controller::notAllowControl()
{
	allowControlFlag = false;

	touchFlag = false;
	touchMaxFlag = false;
}

void Controller::setTouchRect(Rect touchRact)
{
	this->touchRect = touchRact;

	this->touchRectFlag = true;
}

bool Controller::onTouchBegan(Touch *touch, Event *unused_event)
{
	if (allowControlFlag)
	{
		if (!touchFlag)
		{
			if (checkControler())
			{
				Point touchPoint = Director::getInstance()->convertToGL(touch->getLocationInView());
				if (touchRect.containsPoint(touchPoint))
				{
					Vibrator::vibrate(vibratorTime);

					touchFlag = true;

					return true;
				}
			}
		}
	}
	return false;
}

void Controller::onTouchMoved(Touch *touch, Event *unused_event)
{
	if (allowControlFlag)
	{
		if (touchFlag)
		{
			//Point startPoint = Director::getInstance()->convertToGL(touch->getStartLocationInView());
			//Point sourcePoint = round->getPosition();
			//if (startPoint.equals(sourcePoint))
			//{
				Point touchPoint = Director::getInstance()->convertToGL(touch->getLocationInView());
				int d = position.getDistance(touchPoint);
				float angle = atan2(touchPoint.y - position.y, touchPoint.x - position.x);

				if (d > rb*DATUM)
				{
					d = rb*DATUM;
					if (!touchMaxFlag)
					{
						touchMaxFlag = true;
						Vibrator::vibrate(vibratorTime);
					}
				}
				else
				{
					touchMaxFlag = false;
				}

				ball->setPosition(round->getPositionX()+d*cos(angle), round->getPositionY()+d*sin(angle));
				this->angle = MATH_RAD_TO_DEG(angle);
			//}
		}
	}
}

void Controller::onTouchEnded(Touch *touch, Event *unused_event)
{
	if (allowControlFlag)
	{
		if (touchFlag)
		{
			//Point startPoint = Director::getInstance()->convertToGL(touch->getStartLocationInView());
			//Point sourcePoint = round->getPosition();
			//if (startPoint.equals(sourcePoint))
			//{
				ball->setPosition(position);
				angle = NOANGLE;

				touchFlag = false;
			//}
		}
	}
}

int Controller::getAngle()
{
	return angle;
}
