#pragma once

#include "Global.h"

class BackGroundLayer : public Layer
{
protected:
	Sprite* bG; //����ͼƬ

public:
	CREATE_FUNC(BackGroundLayer);
	bool init();
	float getBGHeight();
};