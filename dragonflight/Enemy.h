#pragma once
#include "Pos.h"
#include"MapManager.h"
#include <vector>
using std::vector;
//const int MAP_WIDTH = 21;
//const int MAP_HEIGHT = 20;

class Enemy
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
	bool _fireTrigger = false;
	Pos _tpos, _newtpos;
};