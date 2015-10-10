#include "RouteLayer.h"
#include "XMX_Controller/XMX_Vibrator.h"

USING_XMX;

bool RouteLayer::init()
{
	Layer::init();

	brush = DrawNode::create();
	this->addChild(brush);
	lineWidth = 5.6f;
	circleRadius = 50.0f;

	prevCenter = -1;

	drawnStart = NOCHOOSE;
	drawnEnd = NOCHOOSE;

	font = "fonts/SourceHanSans.otf";
	fontSize = 72;
	size = 0.1f;

	return true;
}

void RouteLayer::drawLine(int from, int to, Color4F color, float radius /* = 0 */)
{
	if (radius == 0)
		radius = lineWidth;

	color.a = 0.72f;
	brush->drawSegment(node[from], node[to], radius, color);
}

void RouteLayer::drawSexangle(int middle, Color4F color)
{
	color.a = 0.72f;
	brush->drawSolidCircle(node[middle], circleRadius, 0, 6, color);
}

int RouteLayer::getAngle(int center, int edge)
{
	return MATH_RAD_TO_DEG(atan2(node[edge].y - node[center].y, node[edge].x - node[center].x));
}

int RouteLayer::getEndByAngle(int center, int angle)
{
	if (prevCenter != center)
	{
		for (int i = 0; i < TOTAL_NODE; i++)
		{
			if (dis[center][i] != NC)
			{
				direction[i] = getAngle(center, i);
			}
			else
			{
				direction[i] = NOCONNECTION;
			}
		}
	}

	for (int j = 0; j < TOTAL_NODE; j++)
	{
		if (direction[j] == NOCONNECTION || center == j)
		{
			continue;
		}
		else if (direction[j]-ANGLE_OFFSET <= angle  &&  angle <= direction[j]+ANGLE_OFFSET)
		{
			if (center != drawnStart || j != drawnEnd)
			{
				drawnStart = center;
				drawnEnd = j;
				Vibrator::vibrate(VIBRATE_TIME);
				break;
			}
		}
		else if (direction[j]+ANGLE_OFFSET >= 180)
		{
			int offset = 180 - direction[j];
			if ((direction[j]-ANGLE_OFFSET <= angle  &&  angle <= 180) || (-180 <= angle  &&  angle <= -180 + offset))
			{
				if (center != drawnStart || j != drawnEnd)
				{
					drawnStart = center;
					drawnEnd = j;
					Vibrator::vibrate(VIBRATE_TIME);
					break;
				}
			}
		}
		else if (direction[j] - ANGLE_OFFSET <= -180)
		{
			int offset = direction[j] + 180;
			if ((-180 <= angle  &&  angle <= direction[j] + ANGLE_OFFSET) || (180 - offset <= angle  &&  angle <= 180))
			{
				if (center != drawnStart || j != drawnEnd)
				{
					drawnStart = center;
					drawnEnd = j;
					Vibrator::vibrate(VIBRATE_TIME);
					break;
				}
			}
		}
	}
	return drawnEnd;
}

int RouteLayer::getStart()
{
	return drawnStart;
}

int RouteLayer::getEnd()
{
	return drawnEnd;
}

void RouteLayer::addExertionLabel(int from, int to, int exertion, Color3B color)
{
	removeChild(exertionLabel);
	char text[32];
	char flag = (exertion > 0) ? '-' : (exertion=-exertion, '+');
	sprintf(text, "%c%d", flag, exertion);
	exertionLabel = Label::createWithTTF(text, font, fontSize);
	exertionLabel->setColor(color);
	Point mid = node[from].getMidpoint(node[to]);
	exertionLabel->setPosition(mid);
	SETSIZE(exertionLabel, size);
	this->addChild(exertionLabel);
}

void RouteLayer::removeExertionLabel()
{
	removeChild(exertionLabel);
}

void RouteLayer::reset()
{
	brush->clear();
	drawnStart = NOCHOOSE;
	drawnEnd = NOCHOOSE;
	removeExertionLabel();
}

void RouteLayer::clear()
{
	brush->clear();
	removeExertionLabel();
}
