#pragma once

/****************************************************************************
//调用 setControler 设置控制球
//调用 setSpeedMax 设置最大速度
//调用 setTouchRect 设置触控区域
//调用 setVibratorTime 设置震动时间
//调用 set4DirectionMode 设置为四方向模式
//调用 set8DirectionMode 设置为八方向模式
//调用 allowControl 设置为允许触控
//调用 notAllowControl 设置为不允许触控
//调用 getSpeedX getSpeedY 获得瞬时速度（应在子类 update 中设置 c->setPositionX(c->getPositionX() + getSpeedX()) c->setPositionY(c->getPositionY() + getSpeedY())）
//将 onTouchBegan onTouchMoved onTouchEnded 添加至子类对应函数中
****************************************************************************/

#include "Global.h"

namespace XMX
{
	class Controller : public virtual Layer
	{
	private:
		int vibratorTime; //震动时间
		float rb; //控制球半径
		float rs; //触控点半径
		Point position;
		int angle; //相对水平方向角度
		Rect touchRect; //响应触控的区域（开始触控）
		Sprite* round; //控制球Sprite
		Sprite* ball; //触控点Sprite
		bool touchFlag; //是否已开始触控
		bool allowControlFlag; //是否允许触控
		bool touchMaxFlag; //是否已拉至边缘
		bool controlerFlag; //是否设置控制球
		bool touchRectFlag; //是否已设置触控区域

		bool checkControler(); //检查控制球是否已被成功设置

	public:
		Controller();
		void setControler(Sprite* round, Sprite* ball, float rb, float rs, int x, int y); //设置控制球
		void setTouchRect(Rect touchRact); //设置触控区域
		void setVibratorTime(int time); //设置震动时间
		void allowControl(); //设置为允许触控
		void notAllowControl(); //设置为不允许触控
		int getAngle(); //获得相对水平方向角度
		bool onTouchBegan(Touch *touch, Event *unused_event);
		void onTouchMoved(Touch *touch, Event *unused_event);
		void onTouchEnded(Touch *touch, Event *unused_event);
	};
}
