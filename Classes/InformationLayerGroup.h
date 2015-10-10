#pragma once

#include "Global.h"

#include "InformationLayerGroup/LabelLayer.h"

class InformationLayerGroup : public Layer
{
protected:
	LabelLayer* label; //标签层

public:
	CREATE_FUNC(InformationLayerGroup);
	bool init();

	void initLabelLayer(); //初始化标签层
	void addAllAttributes(int* attribute) { label->addAllAttributes(attribute); } //添加全部标签
	void addNickNameAttributes(string name) { label->addNickNameAttributes(name); } //添加全部标签
	void changeStateLabel(string s) { label->changeStateLabel(s); } //修改状态标签
	void removeStateLabel() { label->removeStateLabel(); } //移除状态标签
};