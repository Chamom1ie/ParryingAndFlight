#pragma once
#include "Pos.h"
#include"MapManager.h"
#include <vector>

class Enemy
{
private:
    void Movement();
    void Fire();
public:
    void Update();
    void Render();
    void Init();
    void Hit();
    Pos _tpos, _newtpos;
    bool _isDie = false;
private:
    bool _canShot = false;
    bool _canMove = false;
    bool _tickCounter = false;
};