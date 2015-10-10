#pragma once

#include "Global.h"

class BackGroundLayer : public Layer
{
protected:
	Sprite* bG; //±³¾°Í¼Æ¬

public:
	CREATE_FUNC(BackGroundLayer);
	bool init();
	float getBGHeight();
};