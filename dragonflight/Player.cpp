#include <Windows.h>
#include <algorithm>
#include <fstream>
#include "Player.h"
#include "Console.h"

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
	if (arrMap[_newtpos.y][_newtpos.x]
		!= (char)OBJ_TYPE::Wall)
		_tpos = _newtpos;
}

void Player::Fire()
{

}

void Player::Update()
{
	Movement();
	
	Sleep(100);
}

void Player::Render()
{
	Console console;
	console.Gotoxy(0, 0);
	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			if (_tpos.x == j && _tpos.y == i)
				cout << "A";
			else if (arrMap[i][j] == (char)OBJ_TYPE::Wall)
				cout << "■";
			else if (arrMap[i][j] == (char)OBJ_TYPE::Road)
				cout << "  ";
		}
		cout << endl;
	}
}

void Player::Init()
{
	_tpos.x = MAP_WIDTH / 2;
	_tpos.y = MAP_HEIGHT-2;

	std::fstream readMap("stage.txt");
	if (readMap.is_open()) {
		for (int i = 0;i < MAP_HEIGHT;++i) {
			//다시 getline으로 파일을 읽을때 기존꺼
			//clear해줘야함. 여러 스테이지일 때
			//readMap.clear();
			readMap.getline(arrMap[i], MAP_WIDTH);
			if (readMap.fail()) {
				std::cout << "file error" << endl;
			}
		}
	}
}
