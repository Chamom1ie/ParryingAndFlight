#include "Core.h"
#include "Console.h"
#include "TitleScene.h"
Core* Core::m_pInst = nullptr;
bool Core::Init() //여기서 게임 진행?
{
	Console m_console{};
	TitleScene m_titleScene{};
	m_console.Init();
	m_titleScene.Run();

	//초기화
	//MapMgr::GetInst()->Init();
	//ObjectMgr::GetInst()->Init();
	// m_player->Init();
	return true;
}

void Core::Run()
{
	while (true)
	{
		// Update()
		// Render()
	}
}