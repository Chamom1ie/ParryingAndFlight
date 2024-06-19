class Pos
{
public:
	int x;
	int y;
	bool operator ==(const Pos& _pos)
	{
		if (x == _pos.x && y == _pos.y)
			return true;
		else
			return false;
	}
}POS, * PPOS;
