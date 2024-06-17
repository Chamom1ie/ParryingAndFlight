#pragma once
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
class Bullet
{
private:
	POS _tPos,_newtPos;
	void Move();
public:
	void Update();
	void Render();
	void Init(POS currentPos);
};

