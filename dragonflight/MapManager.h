#pragma once
#include"define.h"
#include "Player.h"
#include "Rampart.h"

const int MAP_WIDTH = 21;
const int MAP_HEIGHT = 20;


enum class OBJ_TYPE {
	End = '0', Road, Rampart
};
class MapManager
{
private:
	MapManager() = default;
public:
	void Init();
	void Render();
	char arrMap[MAP_HEIGHT][MAP_WIDTH]{};
public:
	static MapManager* GetInst()
	{
		if (m_pInst == nullptr)
			m_pInst = new MapManager;
		return m_pInst;
	}
	static void DestroyInst()
	{
		SAFE_DELETE(m_pInst);
	}
	int rampartColor[6]{ 0,4,6,2,1,15 };
private:
	static MapManager* m_pInst;
};

