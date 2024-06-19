#pragma once

#include "Console.h"
#include "define.h"
#include "Enemy.h"

class EnemySpawner
{
private:
	EnemySpawner() = default;
public:
	bool Init();
	void Run();
public:
	static EnemySpawner* GetInst()
	{
		if (m_pInst == nullptr)
			m_pInst = new EnemySpawner;
		return m_pInst;
	}
	static void DestroyInst()
	{
		SAFE_DELETE(m_pInst);
	}
private:
	static EnemySpawner* m_pInst;
};

