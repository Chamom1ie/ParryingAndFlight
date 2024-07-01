#include "Core.h"
#include "TitleScene.h"
#include "EnemySpawner.h"
#include "UI.h"
Core* Core::m_pInst = nullptr; 
int secPrevTime;
int secCurTime;
//vector<Enemy> m_enemys;
bool Core::Init() //여기서 게임 진행?
{
    srand(11123);
    secPrevTime = clock();
	Console m_console{};
	TitleScene m_titleScene{};
	m_console.Init();
	m_titleScene.Run();
	//초기화
	MapManager::GetInst()->Init();
	//ObjectMgr::GetInst()->Init();
	player.Init();
	return true;
}
void Core::Update()
{
    player.Update();
    EnemySpawner::GetInst()->Update();
    if (enemies.size() > 0)
    {
        auto new_end = std::remove_if(
            enemies.begin(),
            enemies.end(),
            [](Enemy enemy) {return enemy._isDie; });
        enemies.erase(new_end, enemies.end());
    }
    if (bullets.size() > 0)
    {
        auto new_end = std::remove_if(
            bullets.begin(),
            bullets.end(),
            [](Bullet bullet) {return bullet.isdie; });
        bullets.erase(new_end, bullets.end());
    }
    for (auto& r : ramparts)
    {
        if (r._isDie) continue;
        if (r.health <= 0)
            r._isDie = true;
    }
    for (auto& i : bullets) {
        i.Update();
     }
    for (auto& e : enemies) {
        e.Update();
    }
}

void Core::Render()
{
	MapManager::GetInst()->Render();
	UI::GetInst()->Render();
}

void Core::Run()
{
	while (true)
	{
		Update();
		Render();

        secCurTime = clock();
        if (secCurTime - secPrevTime >= 1000UL)
        {
            Core::GetInst()->time++;
            secPrevTime = clock();
        }
	}
}


