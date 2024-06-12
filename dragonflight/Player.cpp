#include <Windows.h>
#include <algorithm>
#include "Player.h"
#include "Console.h"

void Player::Movement()
{
	newX = x;
	newY = y;
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		--newY;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		++newY;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		--newX;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		++newX;


	newX = std::clamp(newX,0,MAP_WIDTH - 2);
	newY = std::clamp(newY,0,MAP_HEIGHT - 1);

	if (arrMap[newY][newX] != (char)OBJ_TYPE::Wall) {
		x = newX;
		y = newY;
	}
}

void Player::Update()
{
	Movement();
	
	Sleep(100);
}

void Player::Render()
{
	for (int i = 0;i < MAP_HEIGHT;++i) {
		for (int j = 0;j < MAP_WIDTH;++j) {
			if (x == j && y == i) {
				cout << "A";
			}
			else if (arrMap[j][i] == (char)OBJ_TYPE::Wall) {
				cout << "¡ß";
			}
			else if (arrMap[j][i] == (char)OBJ_TYPE::Road) {
				cout << " ";
			}
		}
		cout << endl;
	}
}

bool Player::Init()
{
	x = MAP_WIDTH / 2;
	y = MAP_HEIGHT;

	strcpy_s(arrMap[0], "00000000000000000000");
	strcpy_s(arrMap[1], "01111111111111111110");
	strcpy_s(arrMap[2], "01111111111111111110");
	strcpy_s(arrMap[3], "01111111111111111110");
	strcpy_s(arrMap[4], "01111111111111111110");
	strcpy_s(arrMap[5], "01111111111111111110");
	strcpy_s(arrMap[6], "01111111111111111110");
	strcpy_s(arrMap[7], "01111111111111111110");
	strcpy_s(arrMap[8], "01111111111111111110");
	strcpy_s(arrMap[9], "01111111111111111110");
	strcpy_s(arrMap[10],"01111111111111111110");
	strcpy_s(arrMap[11],"01111111111111111110");
	strcpy_s(arrMap[12],"01111111111111111110");
	strcpy_s(arrMap[13],"01111111111111111110");
	strcpy_s(arrMap[14],"01111111111111111110");
	strcpy_s(arrMap[15],"01111111111111111110");
	strcpy_s(arrMap[16],"01111111111111111110");
	strcpy_s(arrMap[17],"01111111111111111110");
	strcpy_s(arrMap[18],"01111111111111111110");
	strcpy_s(arrMap[19],"00000000000000000000");
	return false;
}
