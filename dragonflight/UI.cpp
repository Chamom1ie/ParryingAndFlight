#include "UI.h";
#include "Console.h";
#include "Core.h";
UI* UI::m_pInst = nullptr;

void UI::Description()
{
	cout << "�¿� ȭ��ǥ:�¿� ������"<<endl;
	cout << "Spacebar:�ѽ��"<<endl;
	cout << "��ȭ��ǥ:�и�" << endl;
}

void UI::Score() {
	Console console;
	COORD Resolution = console.GetConsoleResolution();
	int x = Resolution.X / 2;
	int y = Resolution.Y / 6;

	console.Gotoxy(x+4, y);
	cout << "���ھ� : " << Core::GetInst()->score<<endl;
	console.Gotoxy(x+4, y + 1);
	cout << "�ð� : " << Core::GetInst()->time<<endl;
	console.Gotoxy(x+4, y + 2);
	cout << "���� :" << Core::GetInst()->player._life<<endl;
}

void UI::Render() {
	Description();
	Score();
}
