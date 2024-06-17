#pragma once
const int MAP_WIDTH = 21;
const int MAP_HEIGHT = 20;

typedef struct _tagpos
{
	int x;
	int y;
	bool operator ==(const _tagpos& _pos)
	{
		if (x == _pos.x && y == _pos.y)
			return true;
		else
			return false;
	}
}POS, * PPOS;

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
	POS _tpos,_newtpos;
};

