#include "Core.h"
#include "Console.h"
Core* Core::m_pInst = nullptr;
bool Core::Init() //���⼭ ���� ����?
{
	Console console{};
	console.Init();
	system("pause");
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