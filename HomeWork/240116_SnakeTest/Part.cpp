#include "Part.h"
#include <ConsoleEngine/EngineDebug.h>

void Part::SetBack(Part* const _Back)
{
	if (_Back == nullptr)
	{
		MsgBoxAssert("Nullptr Error");
	}

	Back = _Back;
}

void Part::SetFront(Part* const _Front)
{
	if (_Front == nullptr)
	{
		MsgBoxAssert("Nullptr Error");
	}

	Front = _Front;
}