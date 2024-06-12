#include <iostream>
#include <Windows.h>
#include <fcntl.h>
#include <conio.h>
#include <io.h>
#include "TitleScene.h"
#include "console.h"
using namespace std;

string TitleText[3] = { "게임 시작", "게임 정보", "게임 종료" };
void TitleScene::TitleRender() {
	Console console{};
	int prevMode = _setmode(_fileno(stdout), _O_U16TEXT);
	COORD resolution = console.GetConsoleResolution();
	wcout << L" _______                                          __                     " << endl;
	wcout << L"/       \                                        /  |                    " << endl;
	wcout << L"$$$$$$$  | ______    ______    ______   __    __ $$/  _______    ______  " << endl;
	wcout << L"$$ |__$$ |/      \  /      \  /      \ /  |  /  |/  |/       \  /      \ " << endl;
	wcout << L"$$    $$/ $$$$$$  |/$$$$$$  |/$$$$$$  |$$ |  $$ |$$ |$$$$$$$  |/$$$$$$  |" << endl;
	wcout << L"$$$$$$$/  /    $$ |$$ |  $$/ $$ |  $$/ $$ |  $$ |$$ |$$ |  $$ |$$ |  $$ |" << endl;
	wcout << L"$$ |     /$$$$$$$ |$$ |      $$ |      $$ \__$$ |$$ |$$ |  $$ |$$ \__$$ |" << endl;
	wcout << L"$$ |     $$    $$ |$$ |      $$ |      $$    $$ |$$ |$$ |  $$ |$$    $$ |" << endl;
	wcout << L"$$/       $$$$$$$/ $$/       $$/        $$$$$$$ |$$/ $$/   $$/  $$$$$$$ |" << endl;
	wcout << L"                                        / \__$$ |               / \__$$ |" << endl;
	wcout << L" __    __                               $$    $$/               $$    $$/ " << endl;
	wcout << L"/  \  /  |                               $$$$$$/                 $$$$$$/  " << endl;
	wcout << L"$$  \ $$ |																" << endl;
	wcout << L"$$$  \$$ |																" << endl;
	wcout << L"$$$$  $$ |																" << endl;
	wcout << L"$$ $$ $$ |																" << endl;
	wcout << L"$$ |$$$$ |																" << endl;
	wcout << L"$$ | $$$ |																" << endl;
	wcout << L"$$/   $$/								                                " << endl;
	wcout << L"									                                        " << endl;
	wcout << L" ________  __  __            __          __                              " << endl;
	wcout << L"/        |/  |/  |          /  |        /  |                             " << endl;
	wcout << L"$$$$$$$$/ $$ |$$/   ______  $$ |____   _$$ |_                            " << endl;
	wcout << L"$$ |__    $$ |/  | /      \ $$      \ / $$   |                           " << endl;
	wcout << L"$$    |   $$ |$$ |/$$$$$$  |$$$$$$$  |$$$$$$/                            " << endl;
	wcout << L"$$$$$/    $$ |$$ |$$ |  $$ |$$ |  $$ |  $$ | __                          " << endl;
	wcout << L"$$ |      $$ |$$ |$$ \__$$ |$$ |  $$ |  $$ |/  |                         " << endl;
	wcout << L"$$ |      $$ |$$ |$$    $$ |$$ |  $$ |  $$  $$/                          " << endl;
	wcout << L"$$/       $$/ $$/  $$$$$$$ |$$/   $$/    $$$$/                           " << endl;
	wcout << L"                  /  \__$$ |                                             " << endl;
	wcout << L"                  $$    $$/                                              " << endl;
	wcout << L"                   $$$$$$/                                               " << endl;
	int curmode = _setmode(_fileno(stdout), prevMode);
}

bool TitleScene::Title()
{
	while (true)
	{
		TitleRender();
		MENU eMenu = MenuRender();
		switch (eMenu)
		{
		case MENU::START:
			EnterAnimation();
			return true;
			break;
		case MENU::INFO:
			InfoRender();
			break;
		case MENU::QUIT:
			return false;
			break;
		}
	}
}

MENU TitleScene::MenuRender()
{
	Console console{};

	COORD resolution = console.GetConsoleResolution();
	int x = resolution.X / 5;
	int y = resolution.Y / 3;


	for (int i = 0; i < 3; i++)
	{
		console.GotoxyDouble(x, y + i);
		cout << TitleText[i];
	}

	MENU goingMenu = MENU::START;
	while (true)
	{
		switch (KeyController())
		{
		case KEY::UP:
		{
			if ((int)goingMenu - 1 == (int)MENU::FIRST) continue;
			goingMenu = MENU(static_cast<int>(goingMenu) - 1);
			console.GotoxyDouble(x - 2, y);
			cout << " ";
			console.GotoxyDouble(x - 2, --y);
			cout << ">";
			Sleep(100);
			break;
		}
		case KEY::DOWN:
		{
			if ((int)goingMenu + 1 == (int)MENU::END) continue;
			goingMenu = MENU(static_cast<int>(goingMenu) + 1);
			console.GotoxyDouble(x - 2, y);
			cout << " ";
			console.GotoxyDouble(x - 2, ++y);
			cout << ">";
			Sleep(100);
			break;
		}
		case KEY::SPACE:
		{
			return goingMenu;
			break;
		}
		}
	}
}

void TitleScene::InfoRender()
{
	cout << "조작";
	while (true)
	{
		if (KeyController() == KEY::SPACE)
			break;
	}
}

KEY TitleScene::KeyController()
{
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		Sleep(100);
		return KEY::SPACE;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		Sleep(100);
		return KEY::UP;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		Sleep(100);
		return KEY::DOWN;
	}
	return KEY::NONE;
}

void TitleScene::EnterAnimation()
{
	system("cls");
	Console console;
	COORD Resolution = console.GetConsoleResolution();
	int width = Resolution.X;
	int height = Resolution.Y;
	int animtime = 20;
	for (int i = 0; i < 5; i++)
	{
		console.Gotoxy(0, 0);
		console.SetColor((int)COLOR::BLACK, (int)COLOR::WHITE);
		system("cls");
		Sleep(animtime);

		system("cls");
		console.Gotoxy(0, 0);
		console.SetColor((int)COLOR::WHITE);
		for (int j = 0; j < height; j++)
		{
			for (int k = 0; k < width / 2; ++k)
			{
				cout << "  ";
			}
			cout << endl;
		}
		Sleep(animtime);
	}

	//크로스
	console.SetColor((int)COLOR::BLACK, (int)COLOR::WHITE);
	for (int i = 0; i < width / 2; ++i)
	{
		for (int j = 0; j < height; j += 2)
		{
			console.Gotoxy(i * 2, j);
			cout << "  ";
		}

		for (int j = 1; j < height; j += 2)
		{
			console.Gotoxy(width - 2 - i * 2, j);
			cout << "  ";
		}
		Sleep(animtime);
	}
	console.SetColor((int)COLOR::WHITE);
	system("cls");
	console.Gotoxy(0, 0);
}

bool TitleScene::Run()
{
	while (true)
	{
		TitleRender();
		MENU eMenu = MenuRender();
		switch (eMenu)
		{
		case MENU::START:
			EnterAnimation();
			return true;
			break;
		case MENU::INFO:
			InfoRender();
			break;
		case MENU::QUIT:
			return false;
			break;
		}
	}
}
