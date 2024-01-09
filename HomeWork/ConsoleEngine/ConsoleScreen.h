#pragma once
#include "EngineDebug.h"
#include "ConsoleMath.h"

// 기존에는 화면의 크기를 정적바인딩으로 설정하였다.
// 

class ConsoleScreen
{
public:
	ConsoleScreen();
	virtual ~ConsoleScreen();

	void CreateScreen(int _ScreenX, int _ScreenY);
	void ReleaseScreen();
	void PrintScreen();
	void ClearScreen();

	void SetChar(const class ConsoleObject& _Object);
	void SetChar(const class ConsoleObject* _Object);
	void SetChar(const int2& _Pos, char _Char);

	inline int GetScreenX() const
	{
		return m_ScreenX;
	}

	inline int GetScreenY() const
	{
		return m_ScreenY;
	}

private:
	// 클래스가 생성되면
	//int Value; // -> 곧바로 생성된다.
	//char* Ptr; // new int(); -> 이걸 언제할지를 프로그래머가 정할 수 있다.

	int m_ScreenX = -1;
	int m_ScreenY = -1;

	char** m_ScreenData = nullptr;
};

