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

void Head::InputCheck()
{
	int Select = _getch();
	switch (Select)
	{
	case 'A':
	case 'a':
	{
		if (PrevDir != Right)
		{
			PrevDir = Left;
		}
		break;
	}
	case 'S':
	case 's':
	{
		if (PrevDir != Up)
		{
			PrevDir = Down;
		}
		break;
	}
	case 'W':
	case 'w':
	{
		if (PrevDir != Down)
		{
			PrevDir = Up;
		}
		break;
	}
	case 'D':
	case 'd':
	{
		if (PrevDir != Left)
		{
			PrevDir = Right;
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
}

void Head::Move()
{
	AddPos(PrevDir);
	PrevPos = GetPos() - PrevDir;
}

void Head::EatBodyCheck()
{
	if (nullptr == BodyManager::GetCurBody())
	{
		MsgBoxAssert("������ �ִ� �ٵ� �������� �ʽ��ϴ�.");
		return;
	}

	Body* CurBody = BodyManager::GetCurBody();
	if (CurBody->GetPos() == GetPos())
	{
		CurBody->SetFront(LastPart);
		LastPart = CurBody;

		BodyManager::ResetBody();
	}
}

void Head::GameEndCheck()
{
	if (GetPos().X < 0 || GetPos().X >= GetCore()->Screen.GetScreenX() ||
		GetPos().Y < 0 || GetPos().Y >= GetCore()->Screen.GetScreenY() )
	{
		GetCore()->EngineEnd();
	}
}

void Head::Update()
{
	Move();
	GameEndCheck();
	EatBodyCheck();

	std::cin.clear();

	int InputCount = _kbhit();
	if (0 == InputCount)
	{
		return;
	}

	InputCheck();
}