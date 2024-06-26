#pragma once
#include "define.h"
#include "Enemy.h"
#include <time.h>


class EnemySpawner
{
private:
    EnemySpawner() = default;
public:
    void Init();
    void Update();
    void SpawnEnemy();
public:
    static EnemySpawner* GetInst()
    {
        if (m_pInst == nullptr)
            m_pInst = new EnemySpawner;
        return m_pInst;
    }
    static void DestroyInst()
    {
        SAFE_DELETE(m_pInst);
    }
private:
    static EnemySpawner* m_pInst;
};