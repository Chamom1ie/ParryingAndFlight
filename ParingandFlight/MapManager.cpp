#include <fstream>
#include <conio.h>
#include <io.h>
#include <fcntl.h>
#include"Core.h"
#include "MapManager.h"
#include "Pos.h"
MapManager* MapManager::m_pInst = nullptr;

void MapManager::Init()
{
	std::fstream readMap("stage.txt");
	if (readMap.is_open()) {
		for (int i = 0;i < MAP_HEIGHT;++i) {
			//다시 getline으로 파일을 읽을때 기존꺼
			//clear해줘야함. 여러 스테이지일 때
			//readMap.clear();
			readMap.getline(arrMap[i], MAP_WIDTH);
			if (readMap.fail()) {
				std::cout << "file error" << endl;
			}
		}
	}

	Rampart fakeRampart;
	fakeRampart._isDie = true;
	Core::GetInst()->ramparts.push_back(fakeRampart);
	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			if (MapManager::GetInst()->arrMap[i][j] == (char)OBJ_TYPE::Rampart)
			{
				Rampart newRampart;
				newRampart._isDie = false;
				Core::GetInst()->ramparts.push_back(newRampart);
			}
		}
	}
}

void MapManager::Render()
{
	if (Core::GetInst()->player._isDie) return;
	Console console;
	console.Gotoxy(0, 0);
	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			Player curPlayer = Core::GetInst()->player;
            std::vector<Bullet> curBullet = Core::GetInst()->bullets;


			if (curPlayer._tpos.x == j && curPlayer._tpos.y == i && curPlayer._isHit)
			{
				console.SetColor((int)COLOR::RED);
				cout << "▲";
			}
			else if (curPlayer._tpos.x == j && curPlayer._tpos.y == i && curPlayer._isparing)
			{
				console.SetColor((int)COLOR::YELLOW);
				cout << "▲";
			}
			else if (curPlayer._tpos.x == j && curPlayer._tpos.y == i)
				cout << "▲";
			else if (MapManager::GetInst()->arrMap[i][j] == (char)OBJ_TYPE::End)
				cout << "■";
			else if (MapManager::GetInst()->arrMap[i][j] == (char)OBJ_TYPE::Rampart)
			{
				if (Core::GetInst()->ramparts[j]._isDie)
				{

 					console.SetColor(0, 0);
					int prevMode = _setmode(_fileno(stdout), _O_U16TEXT);
					wcout << L"　";
					int curmode = _setmode(_fileno(stdout), prevMode);
					console.SetColor((int)COLOR::WHITE);
				}
				else
				{
					console.SetColor(rampartColor[Core::GetInst()->ramparts[j].health]);
					cout << "■";
					console.SetColor((int)COLOR::WHITE);
				}
			}
			else if (MapManager::GetInst()->arrMap[i][j] == (char)OBJ_TYPE::Road)
			{
				int prevMode = _setmode(_fileno(stdout), _O_U16TEXT);
				wcout << L"　";
				int curmode = _setmode(_fileno(stdout), prevMode);
			}
			for (auto& k : Core::GetInst()->bullets) {
				if (k._tPos.x == j && k._tPos.y == i&&!k.isdie){
					k.Render();
				}
			}
			for (auto& e : Core::GetInst()->enemies) {
				if (e._tpos.x == j && e._tpos.y == i && !e._isDie) {
					e.Render();
				}
			}
			console.SetColor((int)COLOR::WHITE);
		}
		cout << endl;
	}
}

