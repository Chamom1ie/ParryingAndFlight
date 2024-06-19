#pragma once
#include"Console.h"
#include "Pos.h"


enum class OBJ_TYPE {
	Wall = '0',Road
};

class Player
{
private:
	void Movement();
	void Fire();
public:
	void Update();
	void Render();
	void Init();
	Pos _tpos,_newtpos;
};

