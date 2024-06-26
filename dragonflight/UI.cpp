#include "UI.h"
#include "Console.h"
#include "Core.h"
#include <fcntl.h>
#include <conio.h>
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
	cout << "Spacebar:총쏘기" << endl;
	console.Gotoxy(x + 4, y - 2);
	cout << "위화살표:패링" << endl;
	console.Gotoxy(x + 4, y);
	cout << "스코어 : " << Core::GetInst()->score << endl;
	console.Gotoxy(x + 4, y + 1);
	cout << "시간 : " << Core::GetInst()->time << endl;
	console.Gotoxy(x + 4, y + 2);
	cout << "생명 :" << Core::GetInst()->player._life << endl;
	console.Gotoxy(x + 4, y + 3);
	if (Core::GetInst()->player._paringOn)
		cout << "패링: " << "ON " << endl;
	else
		cout << "패링: " << "OFF" << endl;

}

void UI::EndUI()
{
	
}


void UI::Render() {	
	if (Core::GetInst()->player._isDie) {
		EndUI();
	}
	else {
		MainUI();
	}
}

