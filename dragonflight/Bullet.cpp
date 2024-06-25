#include "MapManager.h"
#include "Bullet.h"
#include "Core.h";
void Bullet::Move()
{
    if (isdie) {
        return;
    }
    if (isEnemyBullet)
    {
        _newtpos = _tPos;
        ++_newtpos.y;
        if (MapManager::GetInst()->arrMap[_newtpos.y][_newtpos.x]
            != (char)OBJ_TYPE::End)
            _tPos = _newtpos;
        else
            isdie = true;
    }
    else
    {
        _newtpos = _tPos;

        --_newtpos.y;

        if (_newtpos.y == 0) {
            isdie = true;
        }
        else {
            _tPos = _newtpos;
        }
    }
}

void Bullet::CheckHit()
{
    if (isEnemyBullet)
    {
        if (Core::GetInst()->player._tpos == _tPos&& Core::GetInst()->player._paringOn) {
            isEnemyBullet = false;
        }
        else if (Core::GetInst()->player._tpos == _tPos) {
            Core::GetInst()->player.Hit();
        }
    }
    else 
    {
        for (auto& enemys : Core::GetInst()->enemies) {
            enemys.Hit();
        }
    }
}

void Bullet::Update()
{
    Move();
    CheckHit();
}

void Bullet::Render()
{
    Console console;
    COORD cursorPos = console.CursorPos();
    console.Gotoxy(cursorPos.X - 2, cursorPos.Y);
    cout << "* ";
}

void Bullet::Init(Pos currentPos)
{
    _tPos = currentPos;
    isdie = false;
}