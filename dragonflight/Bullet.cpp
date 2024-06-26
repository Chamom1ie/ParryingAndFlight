#include "MapManager.h"
#include "Bullet.h"
#include "Core.h"
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
        if (Core::GetInst()->player._tpos.x - 1 <= _tPos.x && Core::GetInst()->player._tpos.x + 1 >= _tPos.x && Core::GetInst()->player._tpos.y - 1 == _tPos.y && Core::GetInst()->player._isparing) {
            isEnemyBullet = false;
        }
        else if (Core::GetInst()->player._tpos == _tPos) {
            Core::GetInst()->player.Hit();
        }
    }
    else 
    {
        for (auto& enemy : Core::GetInst()->enemies) {
            if (enemy._tpos.x == _tPos.x && enemy._tpos.y == _tPos.y)
                enemy.Hit();
        }
    }
}

void Bullet::Update()
{
    CheckHit();
    Move();
    CheckHit();
}

void Bullet::Render()
{
    Console console;
    COORD cursorPos = console.CursorPos();
    console.Gotoxy(cursorPos.X - 2, cursorPos.Y);
    cout << "£ª";
}

void Bullet::Init(Pos currentPos)
{
    _tPos = currentPos;
    isdie = false;
}