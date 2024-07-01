#include <Windows.h>
#include "console.h"

void Console::Init()
{
	system("title DragonFlight | mode con cols=75 lines=55");
	CursorVis(false, 100);
	LockResize();
	SetFontSize(FW_REGULAR, 14, 14);
}

void Console::FullScreen()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
}

void Console::GotoxyDouble(int _x, int _y)
{
	//콘솔창 핸들
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//커서관련 구조체

	COORD Cur = { _x * 2, _y }; //{_x*2, _y}가 더 자연스러울수 있음
	//커서위치 설정 함수
	SetConsoleCursorPosition(hOut, Cur);
}

void Console::Gotoxy(int _x, int _y)
{
	//콘솔창 핸들
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//커서관련 구조체

	COORD Cur = { _x, _y }; //{_x*2, _y}가 더 자연스러울수 있음
	//커서위치 설정 함수
	SetConsoleCursorPosition(hOut, Cur);
}



BOOL Console::GotoPosDouble(int _x, int _y)
{
	//콘솔창 핸들
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//커서관련 구조체

	COORD Cur = { _x * 2, _y }; //{_x*2, _y}가 더 자연스러울수 있음
	//커서위치 설정 함수
	return SetConsoleCursorPosition(hOut, Cur);
}

BOOL Console::GotoPos(int _x, int _y)
{
	//콘솔창 핸들
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//커서관련 구조체

	COORD Cur = { _x, _y }; //{_x*2, _y}가 더 자연스러울수 있음
	//커서위치 설정 함수
	return SetConsoleCursorPosition(hOut, Cur);
}

COORD Console::CursorPos()
{
	CONSOLE_SCREEN_BUFFER_INFO buf;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE)
		, &buf);
	return buf.dwCursorPosition;
}

void Console::CursorVis(bool _vis, DWORD _size)
{
	CONSOLE_CURSOR_INFO curinfo;
	curinfo.dwSize = _size; // 커서굵기
	curinfo.bVisible = _vis; // on off 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE)
		, &curinfo);
}

void Console::SetColor(int _textColor, int _bgColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE)
		, (_bgColor << 4) | _textColor);
}

int Console::GetColor()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE)
		, &info);
	int color = info.wAttributes & 0xf;
	return color;
}

void Console::LockResize()
{
	HWND console = GetConsoleWindow();
	if (nullptr != console)
	{
		LONG style = GetWindowLong(console, GWL_STYLE);
		style &= ~WS_MAXIMIZEBOX & ~WS_SIZEBOX & ~WS_HSCROLL;// &~WS_CAPTION;

		SetWindowLong(console, GWL_STYLE, style);
	}
}

COORD Console::GetConsoleResolution()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE)
		, &info);

	short width = info.srWindow.Right - info.srWindow.Left + 1;
	short height = info.srWindow.Bottom - info.srWindow.Top + 1;

	return COORD{ width, height };
}

void Console::SetFontSize(UINT _weight, UINT _fontx, UINT _fonty)
{
	CONSOLE_FONT_INFOEX font;
	font.cbSize = sizeof(font);

	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	GetCurrentConsoleFontEx(hout, false, &font);
	font.FontWeight = _weight;
	font.dwFontSize.X = _fontx;
	font.dwFontSize.Y = _fonty;

	SetCurrentConsoleFontEx(hout, false, &font);
}
#pragma region 0417
/*SetConsoleDisplayMode
(GetStdHandle(STD_OUTPUT_HANDLE),
	CONSOLE_FULLSCREEN_MODE,
	0);*/
	/*::SendMessage(GetConsoleWindow(),
		WM_SYSKEYDOWN,
		VK_RETURN,
		0x20000000);*/
		//exit(0); 바로종료
#pragma endregion
