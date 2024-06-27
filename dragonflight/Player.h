#pragma once
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
	int _life = 10,_hitTime = 10,_canFire = 0;
	bool _isDie,_paringOn,_isparing,_isHit,_isPowerUp;
private:
	int cooldownStartTime, cooldownTime, paringStartTime, paringTime;
};

