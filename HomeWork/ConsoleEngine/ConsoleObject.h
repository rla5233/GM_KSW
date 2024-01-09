#pragma once
#include "ConsoleMath.h"

class ConsoleObject
{
public:
	ConsoleObject();
	ConsoleObject(const int2& _StartPos, char _RenderChar);
	~ConsoleObject();

	inline int2 GetPos() const
	{
		return m_Pos;
	}

	inline char GetRenderChar() const
	{
		return m_RenderChar;
	}

	inline void SetRenderChar(char _Ch)
	{
		m_RenderChar = _Ch;
	}

	inline void SetPos(const int2& _Pos)
	{
		m_Pos = _Pos;
	}

	inline void AddPos(const int2& _Dir)
	{
		m_Pos += _Dir;
	}

private:
	int2 m_Pos = { 0,0 };
	char m_RenderChar = 'A';
};

