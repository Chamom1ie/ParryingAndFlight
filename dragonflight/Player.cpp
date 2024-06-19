#include <Windows.h>
#include <algorithm>
#include "Player.h"
#include "Bullet.h"
#include "Core.h"
#include "MapManager.h"
void Player::Movement()
{
	_newtpos = _tpos;
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		--_newtpos.y;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		++_newtpos.y;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		--_newtpos.x;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		++_newtpos.x;


	// Clamp 처리
	_newtpos.x = std::clamp(_newtpos.x, 0, MAP_WIDTH - 2);
	_newtpos.y = std::clamp(_newtpos.y, 0, MAP_HEIGHT - 1);


	// 최종 갱신
	if (MapManager::GetInst()->arrMap[_newtpos.y][_newtpos.x]
		!= (char)OBJ_TYPE::Wall)
		_tpos = _newtpos;
}

void Player::Fire()
{
	Bullet newBullet;
	newBullet.Init(_tpos);
	Core::GetInst()->bullets.push_back(newBullet);
}

void Player::Update()
{
	Movement();
	
	if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
		Fire();
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
}
