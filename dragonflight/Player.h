#pragma once
const int MAP_WIDTH = 21;
const int MAP_HEIGHT = 20;
enum class OBJ_TYPE {
	Wall = '0',Road
};
class Player
{
private:
	void Movement();
public:
	void Update();
	void Render();
	bool Init();
	char arrMap[MAP_HEIGHT][MAP_WIDTH]{};
private:
	int x=0, y=0;
	int newX=0, newY=0;
};

