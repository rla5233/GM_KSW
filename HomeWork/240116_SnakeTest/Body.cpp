#include "Body.h"
#include "conio.h"

#include "Head.h"

void Body::Update()
{
	if (Front == nullptr)
	{
		return;
	}

	PrevPos = GetPos();
	NextPos = Front->GetPrevPos();
	SetPos(NextPos);
}
