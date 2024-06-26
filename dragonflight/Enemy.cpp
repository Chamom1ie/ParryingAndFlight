#include <Windows.h>;
#include <algorithm>;
#include "Enemy.h";
#include "Bullet.h";
#include "Core.h";
#include "MapManager.h";
using std::vector;

void Enemy::Movement()
{
    _newtpos = _tpos;
    ++_newtpos.y;

    if (MapManager::GetInst()->arrMap[_newtpos.y][_newtpos.x]
        != (char)OBJ_TYPE::End)
        _tpos = _newtpos;
    else
    {
        _isDie = true;
    }
}

void Enemy::Fire()
{
    Bullet newBullet;
    newBullet.isEnemyBullet = true;
    newBullet.Init(_tpos);
    Core::GetInst()->bullets.push_back(newBullet);
    _canShot = false;
}

void Enemy::Hit()
{
    _isDie = true;
    int increaseValue = rand() % 3 + 1; //1 2 3
    cout << increaseValue;
    Core::GetInst()->score += increaseValue;
}

void Enemy::Update()
{
    _tickCounter = !_tickCounter;
    if (_tickCounter)
        _canMove = !_canMove;

    if (_canMove)
    {
        Movement();
        _canMove = false;
    }

}

void Enemy::Render()
{
    Console console;
    COORD cursorPos = console.CursorPos();
    console.Gotoxy(cursorPos.X - 2, cursorPos.Y);
    cout << "¡ä";
}

void Enemy::Init(int idx)
{
    _tpos.x = idx;
    _tpos.y = MAP_HEIGHT - MAP_HEIGHT + 1;

    Fire();
}