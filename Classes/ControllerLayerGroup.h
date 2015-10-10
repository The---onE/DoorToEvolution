#pragma once

#include "Global.h"

#include "ControllerLayerGroup/ButtonLayer.h"
#include "ControllerLayerGroup/ControlLayer.h"

class ControllerLayerGroup : public Layer
{
protected:
	ControlLayer* control; //�������
	ButtonLayer* button; //��ť��

public:
	CREATE_FUNC(ControllerLayerGroup);
	bool init();

	void initControlLayer(); //��ʼ���������
	void initButtonLayer(); //��ʼ����ť��
	ButtonLayer* getButtonLayer() { return button; } //���ذ�ť��
	int getAngle() { return control->getAngle(); } //���ؿ�����Ƕ�
};