#include "Core.h"
#include "Console.h"
#include "TitleScene.h"
Core* Core::m_pInst = nullptr;
bool Core::Init() //���⼭ ���� ����?
{
	Console m_console{};
	TitleScene m_titleScene{};
	m_console.Init();
	m_titleScene.Run();

	//�ʱ�ȭ
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