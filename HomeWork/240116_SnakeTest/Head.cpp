#include "Head.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ConsoleEngine/EngineCore.h>

#include "BodyManager.h"
#include "Body.h"

// 
// 1. 내가 특정 방향으로 진행했다면 다음 입력때는 그 반대방향으로는 갈수가 없다.
//    내가 이동하는 방향의 반대방향으로는 가면 안된다.
// 2. 내가 이동을 해서 CurBody를 획득했다면 그 다음부터 그 바디는 나를 따라와야 한다.

void Head::Update()
{
	EatBodyCheck();
	GameEndCheck();
	Move();
	
	InputCheck();
}

void Head::InputCheck()
{
	int InputCount = _kbhit();
	if (0 == InputCount)
	{
		return;
	}	

	//if (GetAsyncKeyState('A'))
	//{
	//	if (PrevDir != Right)
	//	{
	//		PrevDir = Left;
	//	}
	//}
	//else if (GetAsyncKeyState('S'))
	//{
	//	if (PrevDir != Up)
	//	{
	//		PrevDir = Down;
	//	}
	//}
	//else if (GetAsyncKeyState('W'))
	//{
	//	if (PrevDir != Down)
	//	{
	//		PrevDir = Up;
	//	}
	//}
	//else if (GetAsyncKeyState('D'))
	//{
	//	if (PrevDir != Left)
	//	{
	//		PrevDir = Right;
	//	}			
	//}
	//else if (GetAsyncKeyState('1'))
	//{
	//	GetCore()->EngineEnd();
	//}

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
		MsgBoxAssert("먹을수 있는 바디가 존재하지 않습니다.");
		return;
	}

	// 바디 획득
	Body* CurBody = BodyManager::GetCurBody();
	if (CurBody->GetPos() == GetPos())
	{
		int2 BodyStartPos = LastBody->GetPrevPos();

		CurBody->SetFront(LastBody);
		CurBody->SetPos(BodyStartPos);
		LastBody = CurBody;
		BodyManager::ResetBody();
	}
}

void Head::GameEndCheck()
{
	// 화면 이탈 체크
	if (GetPos().X < 1 || GetPos().X >= GetCore()->Screen.GetScreenX() - 1 ||
		GetPos().Y < 1 || GetPos().Y >= GetCore()->Screen.GetScreenY() - 1 )
	{
		GetCore()->EngineEnd();
	}

	// 충돌 체크
	ConsoleObject* Object = Collision(0);
	if (Object != nullptr)
	{
		GetCore()->EngineEnd();
	}
}

