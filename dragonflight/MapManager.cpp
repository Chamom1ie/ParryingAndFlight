#include <fstream>
#include"Core.h"
#include "MapManager.h"
#include"Pos.h"
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
}

void MapManager::Render(Player player)
{
	Console console;
	console.Gotoxy(0, 0);
	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			if (player._tpos.x == j && player._tpos.y == i)
				cout << "A";
			else if (MapManager::GetInst()->arrMap[i][j] == (char)OBJ_TYPE::End)
				cout << "■";
			else if (MapManager::GetInst()->arrMap[i][j] == (char)OBJ_TYPE::Road)
				cout << "  ";
			for (auto& k : Core::GetInst()->bullets) {
				if (k._tPos.x == j && k._tPos.y == i) {
					k.Render();
				}
			}
		}
		cout << endl;
	}
}

