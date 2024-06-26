#pragma once
//게임매니저
#include "Console.h"
#include "define.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Pos.h"
#include "TitleScene.h"
#include "Player.h"
#include "MapManager.h"
#include "EnemySpawner.h"
#include "UI.h"
#include <vector>
using std::vector;
class Core
{
private:
	Core() = default;
public:
	bool Init();
	void Run();
	void Update();
	void Render();
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
	std::vector<Bullet> bullets = {};
	std::vector<Enemy> enemies = {};
	std::vector<Rampart> ramparts{};
	Player player = {};
	int score = 0;
	int time = 0;
private:
	static Core* m_pInst;
};