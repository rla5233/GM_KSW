#include "ConsoleScreen.h"

#include <iostream>

#include "ConsoleObject.h"

ConsoleScreen::ConsoleScreen()
{}

ConsoleScreen::~ConsoleScreen()
{
	ReleaseScreen();
}

void ConsoleScreen::CreateScreen(int _ScreenX, int _ScreenY)
{
	ReleaseScreen();

	if (_ScreenX <= 0)
	{
		MsgBoxAssert("Wrong range : ScreenX");
	}

	if (_ScreenY <= 0)
	{
		MsgBoxAssert("Wrong range : ScreenY");
	}

	m_ScreenX = _ScreenX;
	m_ScreenY = _ScreenY;

	if (m_ScreenData != nullptr)
	{
		MsgBoxAssert("Alreay Exist Memory");
	}

	m_ScreenData = new char* [m_ScreenY];

	if (m_ScreenData == nullptr)
	{
		MsgBoxAssert("Failed Create Memory");
	}

	for (int y = 0; y < m_ScreenY; y++)
	{
		m_ScreenData[y] = new char[m_ScreenX + 2] { 0, };

		for (int x = 0; x < m_ScreenX; x++)
		{
			m_ScreenData[y][x] = '*';
		}

		m_ScreenData[y][m_ScreenX] = '\n';
	}

	ClearScreen();

	// 함수가 실행되면 스택에 그 함수 이름의 메모리를 그리면
	// 맴버함수는 실행되면 내부에 this가 있다는것을 기억해야 한다.
}

void ConsoleScreen::ReleaseScreen()
{
	// 지울 때는 역순으로 지운다.
	for (int y = 0; y < m_ScreenY; y++)
	{
		if (m_ScreenData[y] != nullptr)
		{
			delete[] m_ScreenData[y];
			m_ScreenData[y] = nullptr;
		}
	}

	if (m_ScreenData != nullptr)
	{
		delete m_ScreenData;
		m_ScreenData = nullptr;
	}
}

void ConsoleScreen::SetChar(const ConsoleObject& _Object)
{
	SetChar(_Object.GetPos(), _Object.GetRenderChar());
}

void ConsoleScreen::SetChar(const ConsoleObject* _Object)
{
	SetChar(_Object->GetPos(), _Object->GetRenderChar());
}

void ConsoleScreen::SetChar(const int2& _Pos, char _Char)
{
	if (0 > _Pos.Y)
	{
		return;
	}

	if (0 > _Pos.X)
	{
		return;
	}

	if (m_ScreenX <= _Pos.X)
	{
		return;
	}

	if (m_ScreenY <= _Pos.Y)
	{
		return;
	}

	m_ScreenData[_Pos.Y][_Pos.X] = _Char;
}

void ConsoleScreen::ClearScreen()
{
	for (int y = 0; y < m_ScreenY; y++)
	{
		for (int x = 0; x < m_ScreenX; x++)
		{
			m_ScreenData[y][x] = '*';
		}
		m_ScreenData[y][m_ScreenX] = '\n';
	}
}

void ConsoleScreen::PrintScreen()
{
	system("cls");

	for (int y = 0; y < m_ScreenY; y++)
	{
		if (nullptr == m_ScreenData[y])
		{
			MsgBoxAssert("Print Range Error.");
		}

		printf_s(m_ScreenData[y]);
	}

	ClearScreen();
}