#include "Core.h"
#include "Console.h"
#include "TitleScene.h"
#include "Player.h"
#include "MapManager.h"
Core* Core::m_pInst = nullptr;
Player m_player;
bool Core::Init() //여기서 게임 진행?
{
	Console m_console{};
	TitleScene m_titleScene{};
	m_console.Init();
	m_titleScene.Run();
	MapManager::GetInst()->Init();

	//초기화
	//MapMgr::GetInst()->Init();
	//ObjectMgr::GetInst()->Init();
	m_player.Init();
	return true;
}

void Core::Run()
{
	while (true)
	{
		m_player.Update();
		for (auto& i : bullets) {
			i.Update();
		}
		MapManager::GetInst()->Render(m_player);
		// Update()
		// Render()
	}
}