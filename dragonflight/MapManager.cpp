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

void MapManager::Render()
{
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
				cout << "A ";
			}
			else if (curPlayer._tpos.x == j && curPlayer._tpos.y == i && curPlayer._isparing)
			{
				console.SetColor((int)COLOR::YELLOW);
				cout << "A ";
			}
			else if (curPlayer._tpos.x == j && curPlayer._tpos.y == i && curPlayer._isPowerUp)
			{
				console.SetColor((int)COLOR::SKYBLUE);
				cout << "A ";
			}
			else if (curPlayer._tpos.x == j && curPlayer._tpos.y == i)
				cout << "A ";
			else if (MapManager::GetInst()->arrMap[i][j] == (char)OBJ_TYPE::End)
				cout << "■";
			else if (MapManager::GetInst()->arrMap[i][j] == (char)OBJ_TYPE::Road)
				cout << "  ";

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

void MapManager::GameEnd()
{

}

