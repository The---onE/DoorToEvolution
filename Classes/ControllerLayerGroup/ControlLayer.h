#pragma once

#include "Global.h"
#include "XMX_Controller/XMX_Controller.h"

class ControlLayer : public XMX::Controller
{
public:
	CREATE_FUNC(ControlLayer);
	bool init();
	void onEnter();

	int getAngle();
};