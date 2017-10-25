#include"stdafx.h"
#include"SceneMgr.h"
#include<random>


Scene::Scene()
{
	count = 0;
	//private count
}

void Scene::addObj(float x, float y, float z, float s)
{
	if (count < Max)
	{
		Object* addobject = new Object(true, x, y, z, s, 1, 1, 1, 1, rand() % 25-10, rand() % 25-10, 0);
		my_opject[count] = addobject;
		count += 1;
	}
}
void Scene::Collion()
{
	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < count; ++j)
		{
			if (i == j)
				continue;
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
void Scene::update(Renderer *renderer)
{
	for (int i = 0; i < count; ++i)
		if (my_opject[i])
			my_opject[i]->Render(*renderer);
	
	Collion();
}
