#pragma once

#include "Global.h"

#include "ControllerLayerGroup/ButtonLayer.h"
#include "ControllerLayerGroup/ControlLayer.h"

class ControllerLayerGroup : public Layer
{
protected:
	ControlLayer* control; //控制球层
	ButtonLayer* button; //按钮层

public:
	CREATE_FUNC(ControllerLayerGroup);
	bool init();

	void initControlLayer(); //初始化控制球层
	void initButtonLayer(); //初始化按钮层
	ButtonLayer* getButtonLayer() { return button; } //返回按钮层
	int getAngle() { return control->getAngle(); } //返回控制球角度
};