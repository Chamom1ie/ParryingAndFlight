#include "Core.h";
#include "EnemySpawner.h";
#include "Enemy.h";
#include <vector>;
EnemySpawner* EnemySpawner::m_pInst = nullptr;
using std::vector;
int prevTime;
int curTime;

void EnemySpawner::Init()
{
    prevTime = clock();
}

void EnemySpawner::Update()
{
    curTime = clock();
    if (curTime - prevTime >= 6000UL)
    {
        for (int i = 0; i < 20; i++)
        {
            Enemy newEnemy;
            newEnemy.Init(i);
            Core::GetInst()->enemies.push_back(newEnemy);
        }
        prevTime = clock();
    }
}