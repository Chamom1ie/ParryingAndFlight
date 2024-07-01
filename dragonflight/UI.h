#pragma once
#include"define.h"
class UI
{
private:
	UI() = default;
public:
	void EndUI();
	void Render();
	void MainUI();
public:
	static UI* GetInst()
	{
		if (m_pInst == nullptr)
			m_pInst = new UI;
		return m_pInst;
	}
	static void DestroyInst()
	{
		SAFE_DELETE(m_pInst);
	}
private:
	static UI* m_pInst;
};

