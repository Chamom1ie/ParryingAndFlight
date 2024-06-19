#pragma once
const int MAP_WIDTH = 21;
const int MAP_HEIGHT = 20;
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
	char arrMap[MAP_HEIGHT][MAP_WIDTH]{};
private:
	Pos _tpos,_newtpos;
};