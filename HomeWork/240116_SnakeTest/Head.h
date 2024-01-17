#pragma once
#include "Part.h"

class Head : public Part
{
public:
	void InputCheck();
	void Move();
	void EatBodyCheck();

	void MapOutCheck();
	void BodyCollisionCheck();

protected:
	void Update() override;

private:
	int2 PrevDir = { 0, 0 };
	Part* LastBody = this;

	int BodyCount = 0;
};

