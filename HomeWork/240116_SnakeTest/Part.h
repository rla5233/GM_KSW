#pragma once
#include <ConsoleEngine/ConsoleObject.h>

class Part : public ConsoleObject
{
public:
	void SetBack(Part* const _Back);
	void SetFront(Part* const _Front);

	void SetCurPos(int2 _Pos);

protected:
	Part* Front = nullptr;
	Part* Back = nullptr;

	//int2 NextPos = { 0, 0 };
	int2 CurPos = { 0, 0 };
};

