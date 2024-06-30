#include "EnemySpawner.h"
#include "Core.h"
EnemySpawner* EnemySpawner::m_pInst = nullptr;
void EnemySpawner::Init()
{
    prevTime = clock();
}

void EnemySpawner::Update()
{
    curTime = clock();
    if (curTime - prevTime >= 2000UL)
    {
        SpawnEnemy();
        /*for (int i = 0; i < 20; i++)
        {
            Enemy newEnemy;
            newEnemy.Init(i);
            Core::GetInst()->enemies.push_back(newEnemy);
        }*/
        prevTime = clock();
    }
}

void EnemySpawner::SpawnEnemy()
{
    int randNum = rand() % 17 + 1;
    int spawnCnt = rand() % 2 + 2;
    if (randNum == 17 && spawnCnt > 2)
        randNum--;
    for (int i = randNum; i < randNum + spawnCnt; ++i)
    {
        Enemy newEnemy;
        newEnemy.Init(i);
        Core::GetInst()->enemies.push_back(newEnemy);
    }
}
