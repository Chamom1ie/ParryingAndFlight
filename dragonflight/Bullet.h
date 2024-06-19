#pragma once

#include"Pos.h"
class Bullet
{
private:
	void Move();
public:
	void Update();
	void Render();
	void Init(Pos currentPos);
	Pos _tPos, _newtpos;
private:
	bool isdie;
};

