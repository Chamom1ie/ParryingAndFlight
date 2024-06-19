#pragma once
#include "POS.h"
#include <vector>
using std::vector;
const int MAP_WIDTH = 21;
const int MAP_HEIGHT = 20;

enum class OBJ_TYPE {
	End = '0', Road
};

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
	POS _tpos, _newtpos;
};