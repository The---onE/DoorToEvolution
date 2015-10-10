#pragma once

#include "Global.h"

#include "InformationLayerGroup/LabelLayer.h"

class InformationLayerGroup : public Layer
{
protected:
	LabelLayer* label; //��ǩ��

public:
	CREATE_FUNC(InformationLayerGroup);
	bool init();

	void initLabelLayer(); //��ʼ����ǩ��
	void addAllAttributes(int* attribute) { label->addAllAttributes(attribute); } //���ȫ����ǩ
	void addNickNameAttributes(string name) { label->addNickNameAttributes(name); } //���ȫ����ǩ
	void changeStateLabel(string s) { label->changeStateLabel(s); } //�޸�״̬��ǩ
	void removeStateLabel() { label->removeStateLabel(); } //�Ƴ�״̬��ǩ
};