#include "UI.h";
#include "Console.h";
#include "Core.h";
UI* UI::m_pInst = nullptr;

void UI::Description()
{
	cout << "좌우 화살표:좌우 움직임"<<endl;
	cout << "Spacebar:총쏘기"<<endl;
	cout << "위화살표:패링" << endl;
}

void UI::Score() {
	Console console;
	COORD Resolution = console.GetConsoleResolution();
	int x = Resolution.X / 2;
	int y = Resolution.Y / 6;

	console.Gotoxy(x+4, y);
	cout << "스코어 : " << Core::GetInst()->score<<endl;
	console.Gotoxy(x+4, y + 1);
	cout << "시간 : " << Core::GetInst()->time<<endl;
	console.Gotoxy(x+4, y + 2);
	cout << "생명 :" << Core::GetInst()->player._life<<endl;
}

void UI::Render() {
	Description();
	Score();
}
