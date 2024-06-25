#pragma once

#include"Pos.h"
class Bullet
{
private:
	void Move();
	void CheckHit();
public:
	void Update();
	void Render();
	void Init(Pos currentPos);
	Pos _tPos, _newtpos;
	bool isdie;
	bool isEnemyBullet = false;
};

