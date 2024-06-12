#include "Core.h"

int main()
{
	if (!Core::GetInst()->Init())
	{
		cout << "Game Init Error" << endl;
		Core::GetInst()->DestroyInst();
		return 0;
	}

	Core::GetInst()->Run();
	Core::GetInst()->DestroyInst();
}