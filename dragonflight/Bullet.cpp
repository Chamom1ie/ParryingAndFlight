#include"Console.h"
#include "Bullet.h"
#include "MapManager.h"


void Bullet::Move()
{
	if (isdie) {
		return;
	}
	_newtpos.y--;
	if (_newtpos.y == 0) {
		isdie = true;
	}
	/*if (_newtpo) {
		isdie == true;
	}
	Sleep(1);
	if()*/
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
