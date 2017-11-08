#include"stdafx.h"
#include"SceneMgr.h"
#include<random>

void Scene::addObj(float x, float y, float z, float s)
{
	//마우스 클릭마다 호출됨.

	for (int i = 1; i < Max; ++i)
	{
		if (my_opject[i] == nullptr)
		{
			my_opject[i] = new Object(OBJECT_CHARACTER, x, y, z, CHARACTER_SIZE, 1, 1, 1, 1);
			count += 1;
			break;
		}
	}
		
}
void Scene::Collion()
{
	for (int i = 1; i < Max; ++i)
	{
		if (my_opject[i] == nullptr) continue;

		for (int j = 1; j < Max; ++j)
		{
			if (i == j) continue;
			if (my_opject[j] == nullptr) continue;

			else if (my_opject[i]->collision(my_opject[j]->my_pos, my_opject[j]->size))
			{
				my_opject[i]->SetColor(0, 1, 0, 1);
				break;
			}
			else
				my_opject[i]->SetColor(1, 1, 1, 1);
		}
	}
}

void Scene::Render()
{
	for (int i = 0; i < Max; ++i)
	{
		if (my_opject[i] != nullptr)
			my_renderer->DrawSolidRect(my_opject[i]->my_pos.x, my_opject[i]->my_pos.y, my_opject[i]->my_pos.z,
				my_opject[i]->size, my_opject[i]->my_color.r, 
				my_opject[i]->my_color.g, my_opject[i]->my_color.b, my_opject[i]->my_color.a);
	}
}

void Scene::update(float elapsedTime)
{

	for (int i = 0; i <Max; ++i) if (my_opject[i] != nullptr) my_opject[i]->update(elapsedTime);
	Collion();
	this->DeleteObject();
}

void Scene::DeleteObject()
{
	for (int i = 0; i < Max; ++i)
	{
		if (my_opject[i] == nullptr) continue;

		if (my_opject[i]->my_life < 0.0001f)
		{
			count--;
			delete my_opject[i];//감소되면 알아서 죽음 으악!
			my_opject[i] = nullptr;
		}
	}

}