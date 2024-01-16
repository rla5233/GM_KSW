#include "Body.h"
#include "conio.h"

#include "Head.h"

void Body::Update()
{
	if (Front == nullptr)
	{
		return;
	}

	// ���� �� ��ġ�� PrevPos�� ����
	PrevPos = GetPos();

	// �� ���� ��ġ�� �� Part�� PrevPos
	NextPos = Front->GetPrevPos();
	SetPos(NextPos);
}
