#include "Core.h"
#include "Pos.h"
#include "Console.h"
#include "TitleScene.h"
#include "Player.h"
#include "Enemy.h"
#include "MapManager.h"
#include <vector>
using std::vector;
Core* Core::m_pInst = nullptr;
Player m_player;
//vector<Enemy> m_enemys;
bool Core::Init() //여기서 게임 진행?
{
	Console m_console{};
	TitleScene m_titleScene{};
	m_console.Init();
	m_titleScene.Run();
	//초기화
	MapManager::GetInst()->Init();
	//ObjectMgr::GetInst()->Init();
	m_player.Init();
	return true;
}
void Core::Update()
{
	m_player.Update();
	for (auto& i : bullets) {
		i.Update();
	}
}

void Core::Render()
{
	MapManager::GetInst()->Render(m_player);
	m_player.Render();
}

void Core::Run()
{
	while (true)
	{
		Update();
		Render();
	}
}


