#pragma once
//게임매니저
#include "Console.h"
#include "define.h"
class Core
{
private:
	Core() = default;
public:
	bool Init();
	void Run();
public:
	static Core* GetInst()
	{
		if (m_pInst == nullptr)
			m_pInst = new Core;
		return m_pInst;
	}
	static void DestroyInst()
	{
		SAFE_DELETE(m_pInst);
	}
private:
	static Core* m_pInst;
};