#include "UI.h"
#include "Console.h"
#include "Core.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <io.h>
UI* UI::m_pInst = nullptr;


void UI::MainUI() {
	Console console;
	COORD Resolution = console.GetConsoleResolution();
	int x = Resolution.X / 2;
	int y = Resolution.Y / 6;

	console.Gotoxy(x + 4, y - 4);
	cout << "좌우 화살표:좌우 움직임" << endl;
	console.Gotoxy(x + 4, y - 3);
	cout << "위화살표 : 총쏘기" << endl;
	console.Gotoxy(x + 4, y - 2);
	cout << "Spacebar : 패링" << endl;
	console.Gotoxy(x + 4, y);
	cout << "스코어 : " << Core::GetInst()->score << endl;
	console.Gotoxy(x + 4, y + 1);
	cout << "시간 : " << Core::GetInst()->time << endl;
	console.Gotoxy(x + 4, y + 2);
	cout << "생명 :" << Core::GetInst()->player._life << endl;
	if (Core::GetInst()->player._life < 10) {
		console.Gotoxy(x + 11, y + 2);
		cout << " ";
	}
	console.Gotoxy(x + 4, y + 3);
	if (Core::GetInst()->player._paringOn)
		cout << "패링: " << "ON " << endl;
	else
		cout << "패링: " << "OFF" << endl;
	console.Gotoxy(x + 4, y + 4);
	cout << "발사 가능 총알 :" << Core::GetInst()->player._canFire;
	if (Core::GetInst()->player._canFire < 10) {
		console.Gotoxy(x + 21, y + 4);
		cout << " ";
	}

}

void UI::GameOver()
{
	Console console;
	COORD Resolution = console.GetConsoleResolution();
	int width = Resolution.X;
	int height = Resolution.Y;
	console.Gotoxy(0, 0);

	console.SetColor((int)COLOR::WHITE, (int)COLOR::WHITE);
	for (int j = 0; j < height; j++)
	{
		for (int k = 0; k < width / 2; ++k)
		{
			cout << "  ";
		}
		cout << endl;
	}

	console.SetColor((int)COLOR::WHITE);
	int dx = 12, dy = 10;
	console.Gotoxy(dx, dy);
	//ㅡ
	for (int i = 0; i < 8; ++i)
	{
		dx++;
		cout << " ";
		Sleep(50);
	}
	console.Gotoxy(dx, dy);
	//ㅣ
	for (int i = 0; i < 5; ++i)
	{
		cout << "  ";
		dy++;
		console.Gotoxy(dx, dy);
		Sleep(50);
	}
	dx += 3;
	dy -= 3;
	console.Gotoxy(dx, dy);
	//ㅡ
	for (int i = 0; i < 3; ++i)
	{
		cout << " ";
		dx++;
	}
	dy -= 5;
	console.Gotoxy(dx, dy);
	//ㅣ
	for (int i = 0; i < 9; ++i)
	{
		cout << "  ";
		dy++;
		console.Gotoxy(dx, dy);
		Sleep(50);
	}
	dx += 3;
	dy -= 10;
	console.Gotoxy(dx, dy);
	//ㅣ
	for (int i = 0; i < 11; ++i)
	{
		cout << "  ";
		dy++;
		console.Gotoxy(dx, dy);
		Sleep(50);
	}

	dx += 5;
	dy -= 15;
	console.Gotoxy(dx, dy);
	//ㅇ
	for (int i = 1; i <= 20; i++)
	{
		for (int j = 1; j <= 10; ++j)
		{
			console.Gotoxy(dx + i, dy + j);
			switch (j)
			{
			case 1:
				if (i >= 7 && i <= 14)
					cout << " ";
				break;
			case 2:
				if (i == 5 || i == 6 || i == 15 || i == 16)
					cout << " ";
				break;
			case 3:
				if (i == 3 || i == 4 || i == 17 || i == 18)
					cout << " ";
				break;
			case 4:
			case 5:
			case 6:
			case 7:
				if (i <= 2 || i >= 19)
					cout << " ";
				break;
			case 8:
				if (i == 3 || i == 4 || i == 17 || i == 18)
					cout << " ";
				break;
			case 9:
				if (i == 5 || i == 6 || i == 15 || i == 16)
					cout << " ";
				break;
			case 10:
				if (i >= 7 && i <= 14)
					cout << " ";
				break;
			}
			Sleep(10);
		}
		cout << endl;
	}
	dx += 20;
	dy += 10;
	dx += 4;
	dy -= 11;
	console.Gotoxy(dx, dy);
	//ㅣ
	for (int i = 0; i < 14; ++i)
	{
		cout << "  ";
		dy++;
		console.Gotoxy(dx, dy);
		Sleep(50);
	}

	dx -= 18;
	console.Gotoxy(dx, dy);
	//ㅁ
	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			console.Gotoxy(dx + i, dy + j);
			if (j == 0 || j == 5)
			{
				if (i > 16) continue;
				cout << " ";
			}
			if (i == 0 || i == 16 || i == 1 || i == 17)
			{
				cout << " ";
			}
			Sleep(10);
		}
		cout << endl;
	}

	console.Gotoxy(dx - 10, dy + 9);
	cout << "오버입니다 ㅋ";
}


void UI::EndUI()
{
	if (_flag == false)
	{
		_flag = true;
		system("cls");
		//게임오버
		GameOver();
	}
}

#pragma region 도넛
		//도넛
		/*float A = 0, B = 0;
		float i, j;
		int k;
		float z[1760];
		char b[1760];
		printf("\x1b[2J");
		for (;;) {
			memset(b, 32, 1760);
			memset(z, 0, 7040);
			for (j = 0; j < 6.28; j += 0.07) {
				for (i = 0; i < 6.28; i += 0.02) {
					float c = sin(i);
					float d = cos(j);
					float e = sin(A);
					float f = sin(j);
					float g = cos(A);
					float h = d + 2;
					float D = 1 / (c * h * e + f * g + 5);
					float l = cos(i);
					float m = cos(B);
					float n = sin(B);
					float t = c * h * g - f * e;
					int x = 40 + 30 * D * (l * h * m - t * n);
					int y = 12 + 15 * D * (l * h * n + t * m);
					int o = x + 80 * y;
					int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
					if (22 > y && y > 0 && x > 0 && 80 > x && D > z[o]) {
						z[o] = D;
						b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
					}
				}
			}
			printf("\x1b[H");
			for (k = 0; k < 1761; k++) {
				putchar(k % 80 ? b[k] : 10);
				A += 0.00004;
				B += 0.00002;
			}
			Sleep(30);
		}
	}*/
#pragma endregion


void UI::Render() {
	if (Core::GetInst()->player._isDie) {
		EndUI();
	}
	else {
		MainUI();
	}
}

