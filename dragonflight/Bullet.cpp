#include "MapManager.h"
#include "Bullet.h"


void Bullet::Move()
{
	if (isdie) {
		return;
	}
	_newtpos.y--;
	if (_newtpos.y == 0) {
		isdie = true;
	}
	Sleep(1);
}

void Bullet::Update()
{
	Move();
}

void Bullet::Render()
{
	cout << "£ª";
}

void Bullet::Init(Pos currentPos)
{
	_tPos = currentPos;
	isdie = false;
}
