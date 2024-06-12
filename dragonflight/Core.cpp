#include "Core.h"
#include "Console.h"
Core* Core::m_pInst = nullptr;
bool Core::Init() //여기서 게임 진행?
{
	Console console{};
	console.Init();
	system("pause");
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