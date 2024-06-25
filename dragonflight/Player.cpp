#include <Windows.h>
#include <algorithm>
#include "Player.h"
#include "Bullet.h"
#include "Core.h"
#include "MapManager.h"
void Player::Movement()
{
	_newtpos = _tpos;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		--_newtpos.x;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		++_newtpos.x;


	// Clamp 처리
	_newtpos.x = std::clamp(_newtpos.x, 0, MAP_WIDTH - 2);


	// 최종 갱신
	if (MapManager::GetInst()->arrMap[_newtpos.y][_newtpos.x]
		!= (char)OBJ_TYPE::End)
		_tpos = _newtpos;
}

void Player::Fire()
{
	Bullet newBullet;
	newBullet.Init(_tpos);
	Core::GetInst()->bullets.push_back(newBullet);
}

void Player::Paring()
{
	paringTime = clock(); 
	if (paringTime - paringStartTime >= 3000UL)
	{
		_isparing = false;
		cooldownStartTime = clock();
		_paringOn = false;
	}
}

void Player::CoolDown()
{
	cooldownTime = clock();
	if (cooldownTime - cooldownStartTime >= 6000UL)
	{
		_paringOn = true;
	}
}

void Player::Hit()
{
	if (!_isHit) return;

	--_hitTime;
	if (_hitTime <= 0) {
		_isHit = false;
		--_life;
		_hitTime = 10;
		/*if (_life == 0) {
			MapManager::
		}*/
	}
}

void Player::Update()
{
	Movement();

	Hit();
	if (!_paringOn) {
		CoolDown();
	}
	if (_isparing) {
		Paring();
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
		Fire();
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000&&_paringOn) {
		_isparing = true;
	}

	Sleep(100);
}

void Player::Render()
{
	cout << "A";
}

void Player::Init()
{
	_tpos.x = MAP_WIDTH / 2;
	_tpos.y = MAP_HEIGHT-2;
	_paringOn = true;
}
