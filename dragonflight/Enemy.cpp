#include <Windows.h>
#include <algorithm>
#include <fstream>
#include "Enemy.h"
#include "Console.h"
#include <vector>
using std::vector;

void Enemy::Movement()
{
	_newtpos = _tpos;
	--_newtpos.y;

	if (arrMap[_newtpos.y][_newtpos.x]
		!= (char)OBJ_TYPE::End)
		_tpos = _newtpos;
}

void Enemy::Fire()
{
	if (_fireTrigger)
	{

	}
}

void Enemy::Update()
{
}

void Enemy::Render()
{
}

void Enemy::Init()
{
	
}
