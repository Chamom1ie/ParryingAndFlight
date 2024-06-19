#pragma once
#include"Console.h"
#include"Pos.h"
class Bullet
{
private:
	void Move();
public:
	void Update();
	void Render();
	void Init(Pos currentPos);
	Pos _tPos;
private:
	Pos _newtpos;
	bool isdie;
};

