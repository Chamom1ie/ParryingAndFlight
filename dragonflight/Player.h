#pragma once
#include"Console.h"
#include "Pos.h"


class Player
{
private:
	void Movement();
	void Fire();
	void CoolDown();
public:
	void Paring();
	void Update();
	void Render();
	void Init();
	void Hit();
	Pos _tpos, _newtpos;
	int _life = 1,_hitTime = 10;
	bool _isDie,_paringOn,_isparing,_isHit,_isPowerUp;
private:
	int cooldownStartTime, cooldownTime, paringStartTime, paringTime;
};

