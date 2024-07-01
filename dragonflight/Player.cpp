#include <algorithm>
#include "define.h"
#include "MapManager.h"
#include "Player.h"
#include "Bullet.h"
#include "Core.h"
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
	if (_canFire == 0) return;
	--_canFire;
	Bullet newBullet;
	newBullet.Init(_tpos);
	Core::GetInst()->bullets.push_back(newBullet);
}

void Player::Paring()
{
	paringTime = clock();
	if (paringTime - paringStartTime >= 750UL)
	{
		_isparing = false;
		cooldownStartTime = clock();
		_paringOn = false;
	}
}

void Player::CoolDown()
{
	cooldownTime = clock();
	if (cooldownTime - cooldownStartTime >= 1000UL)
	{
		_paringOn = true;
	}
}

void Player::Hit()
{
	if (_life == 0) {
		_isDie = true;
	}
	--_hitTime;
	if (_hitTime <= 0) {
		_isHit = false;
		_hitTime = 10;
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
	if (GetAsyncKeyState(VK_UP) & 0x8000 && _paringOn) {
		_isparing = true;
	}
	Sleep(75);
}

void Player::Render()
{
	Console console;
	COORD cursorPos = console.CursorPos();
	console.Gotoxy(cursorPos.X - 1, cursorPos.Y);
	cout << "▲";
}

void Player::Init()
{
	_tpos.x = MAP_WIDTH / 2;
	_tpos.y = MAP_HEIGHT-2;
}
