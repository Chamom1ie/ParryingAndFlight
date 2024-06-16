#include "Core.h"
#include "Console.h"
#include "Player.h"
Core* Core::m_pInst = nullptr;
Player m_player;
bool Core::Init() //여기서 게임 진행?
{
	Console console{};
	console.Init();
	//system("pause");
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
		m_player.Render();
		// Update()
		// Render()
	}
}