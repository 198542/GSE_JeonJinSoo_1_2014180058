#pragma once
#include"stdafx.h"
#include"Object.h"
const int Max = 50;
class SceneMgr
{
private:
	int count = 0;
	Object m_object[Max];

public:

	Object* Get_object() { return m_object; }

	void Init();
	void Update();


};