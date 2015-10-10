#pragma once

#include "Global.h"
#include "XMX_Controller/XMX_Button.h"


class ButtonLayer : public XMX::Button
{
public:
	CREATE_FUNC(ButtonLayer);
	bool init();
	void onEnter();
};