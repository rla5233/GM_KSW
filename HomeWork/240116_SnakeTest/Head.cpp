#include "Head.h"
#include <iostream>
#include <conio.h>
#include <ConsoleEngine/EngineCore.h>

#include "BodyManager.h"
#include "Body.h"

// 
// 1. ���� Ư�� �������� �����ߴٸ� ���� �Է¶��� �� �ݴ�������δ� ������ ����.
//    ���� �̵��ϴ� ������ �ݴ�������δ� ���� �ȵȴ�.
// 2. ���� �̵��� �ؼ� CurBody�� ȹ���ߴٸ� �� �������� �� �ٵ�� ���� ����;� �Ѵ�.

bool Head::IsMove = false;

void Head::Update()
{
	int InputCount = _kbhit();
	if (0 == InputCount)
	{
		IsMove = false;
		return;
	}

	int Select = _getch();

	// InputCount = _kbhit();

	// X Y
	// 1 0

	switch (Select)
	{
	case 'A':
	case 'a':
	{
		if (PrevDir != Right)
		{
			AddPos(Left);
			PrevDir = Left;
			IsMove = true;
		}
		break;
	}
	case 'S':
	case 's':
	{
		if (PrevDir != Up)
		{
			AddPos(Down);
			PrevDir = Down;
			IsMove = true;
		}
		break;
	}
	case 'W':
	case 'w':
	{
		if (PrevDir != Down)
		{
			AddPos(Up);
			PrevDir = Up;
			IsMove = true;
		}
		break;
	}
	case 'D':
	case 'd':
	{
		if (PrevDir != Left)
		{
			AddPos(Right);
			PrevDir = Right;
			IsMove = true;
		}
		break;
	}
	case '1':
	{
		GetCore()->EngineEnd();
		break;
	}
	default:
		break;
	}

	if (nullptr == BodyManager::GetCurBody())
	{
		MsgBoxAssert("������ �ִ� �ٵ� �������� �ʽ��ϴ�.");
		return;
	}

	PrevPos = GetPos() - PrevDir;
	Body* CurBody = BodyManager::GetCurBody();

	if (CurBody->GetPos() == GetPos())
	{
		CurBody->SetFront(LastPart);
		LastPart = CurBody;

		BodyManager::ResetBody();
	}
}