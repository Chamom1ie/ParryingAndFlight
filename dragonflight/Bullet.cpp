#include"Console.h"
#include "Bullet.h"
#include "MapManager.h"


void Bullet::Move()
{
	_newtpos;
	//if (//_tPos.y == 0) {
	//	
	//}
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
