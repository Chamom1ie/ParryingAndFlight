#include "Core.h"
#include "UI.h"
#include "EnemySpawner.h"
#include "TitleScene.h"

int main()
{
	if (!Core::GetInst()->Init())
	{
		cout << "Game Init Error" << endl;
		Core::GetInst()->DestroyInst();
		return 0;
	}

	Core::GetInst()->Run();
	EnemySpawner::GetInst()->DestroyInst();
	MapManager::GetInst()->DestroyInst();
	UI::GetInst()->DestroyInst();
	Core::GetInst()->DestroyInst();
}