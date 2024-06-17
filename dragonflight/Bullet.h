#pragma once

class Bullet
{
private:
	void Move();
public:
	void Update();
	void Render();
	void Init(int currentX,int currentY);
private:
	int _tposX, _tposY;
};

