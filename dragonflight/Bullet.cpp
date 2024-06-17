#include"Console.h"
#include "Core.h"
#include "Bullet.h"

void Bullet::Move()
{
	_tPos.y--;
	if (_tPos.y == 0) {
		
	}
	Sleep(100);
}

void Bullet::Update()
{
	Move();
}

void Bullet::Render()
{
}

void Bullet::Init(POS currentPos)
{
	
	_tPos = currentPos;
}
