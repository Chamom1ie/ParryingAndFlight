#pragma once
#include"Console.h"
class Bullet
{
private:
	void Move();
public:
	void Update();
	void Render();
	void Init(POS currentPos);
	POS _tPos;
private:
	POS _newtpos;
	bool isdie;
};

