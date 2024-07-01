#pragma once
enum class MENU
{
	FIRST, START, QUIT, END
};
enum class KEY
{
	NONE, UP, DOWN, SPACE
};

class TitleScene {
public:
	void TitleRender();
	bool Title();

	MENU MenuRender();
	void InfoRender();

	KEY KeyController();
	void EnterAnimation();

	bool Run();
};