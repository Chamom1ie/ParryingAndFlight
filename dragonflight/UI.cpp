#include "UI.h"
#include "Console.h"
#include "Core.h"
UI* UI::m_pInst = nullptr;


void UI::MainUI() {
	Console console;
	COORD Resolution = console.GetConsoleResolution();
	int x = Resolution.X / 2;
	int y = Resolution.Y / 6;

	console.Gotoxy(x + 4, y - 4);
	cout << "�¿� ȭ��ǥ:�¿� ������" << endl;
	console.Gotoxy(x + 4, y - 3);
	cout << "Spacebar:�ѽ��" << endl;
	console.Gotoxy(x + 4, y - 2);
	cout << "��ȭ��ǥ:�и�" << endl;
	console.Gotoxy(x + 4, y);
	cout << "���ھ� : " << Core::GetInst()->score << endl;
	console.Gotoxy(x + 4, y + 1);
	cout << "�ð� : " << Core::GetInst()->time << endl;
	console.Gotoxy(x + 4, y + 2);
	cout << "���� :" << Core::GetInst()->player._life << endl;
	if (Core::GetInst()->player._life < 10) {
		console.Gotoxy(x + 11, y + 2);
		cout << " ";
	}
	console.Gotoxy(x + 4, y + 3);
	if (Core::GetInst()->player._paringOn)
		cout << "�и�: " << "ON " << endl;
	else
		cout << "�и�: " << "OFF" << endl;
	console.Gotoxy(x + 4, y + 4);
	cout << "�߻� ���� �Ѿ� :" << Core::GetInst()->player._canFire;
	if (Core::GetInst()->player._canFire < 10) {
		console.Gotoxy(x + 21, y + 4);
		cout << " ";
	}

}

void UI::EndUI()
{
	system("cls");
}


void UI::Render() {
	if (Core::GetInst()->player._isDie) {
		EndUI();
	}
	else {
		MainUI();
	}
}