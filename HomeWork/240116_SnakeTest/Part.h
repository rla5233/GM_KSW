#pragma once
#include <ConsoleEngine/ConsoleObject.h>

class Part : public ConsoleObject
{
public:
	void SetBack(Part* const _Back);
	void SetFront(Part* const _Front);

	inline int2 GetPrevPos() const { return PrevPos; }

protected:
	Part* Front = nullptr;
	Part* Back = nullptr;

	int2 PrevPos = { 0, 0 };
	int2 NextPos = { 0, 0 };
};

