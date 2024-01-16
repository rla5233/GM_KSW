#pragma once
#include "Part.h"

class Head : public Part
{
public:
	static bool GetIsMove()
	{
		return IsMove;
	}

protected:
	void Update() override;

private:
	int2 PrevDir = { 0, 0 };
	Part* LastPart = this;

	static bool IsMove;
};

