#include"stdafx.h"
#include"Object.h"
#include"SceneMgr.h"
#include<random>

void SceneMgr::Init()
{
	for (int i = 0; i < Max; ++i) {

		Position pos;
		pos.x = rand() % (500 / 2);
		pos.y = rand() % (500 / 2);
		if (rand() % 2) pos.x = -pos.x;
		if (rand() % 2) pos.y = -pos.y;

		m_object[i].SetPosition(pos);
		m_object[i].SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));
		m_object[i].SetSize(4);
	}
}
void SceneMgr::Update()
{
	for (int i = 0; i < Max; ++i) m_object[i].update();

}
