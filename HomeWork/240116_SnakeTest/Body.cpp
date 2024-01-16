#include "Body.h"
#include "conio.h"

#include "Head.h"

void Body::Update()
{
	if (Front == nullptr)
	{
		return;
	}

	// 지금 내 위치를 PrevPos로 저장
	PrevPos = GetPos();

	// 내 다음 위치는 앞 Part의 PrevPos
	NextPos = Front->GetPrevPos();
	SetPos(NextPos);
}
