#include"Console.h"
#include "Bullet.h"
#include "MapManager.h"

void Bullet::Move()
{
	_newtpos.y--;
	//if (//_tPos.y == 0) {
	//	
	//}
	if (_newtpos.y == 0) {
		isdie == true;
	}
	Sleep(1);
	if()
}

void Bullet::Update()
{
	Move();
}

void Bullet::Render()
{
	cout << "£ª";
}

void Bullet::Init(POS currentPos)
{
	_tPos = currentPos;
	isdie = false;
}
