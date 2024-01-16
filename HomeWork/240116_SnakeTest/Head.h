#pragma once
#include "Part.h"

class Head : public Part
{
public:
	void InputCheck();
	void Move();
	void EatBodyCheck();
	void GameEndCheck();

protected:
	void Update() override;

private:
	int2 PrevDir = { 0, 0 };
	Part* LastPart = this;

};

