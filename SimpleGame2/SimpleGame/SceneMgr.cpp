#include"stdafx.h"
#include"SceneMgr.h"
#include<random>


Scene::Scene()
{
	
	//private count
	for (int i = 0; i < Max; ++i)
	{
		my_opject[i] = NULL;
	}
}

void Scene::addObj(float x, float y, float z, float s)
{
	//마우스 클릭마다 호출됨.

		if (count < Max)
		{
		//	cout << count << endl;
		//	cout << Max << endl;
			my_opject[count] = new Object(true, x, y, z, s, 1, 1, 1, 1, rand() % 4, rand() % 4, 0);
			//my_opject[count] = addobject;
			//return i;
			count += 1;
		}
		else if(Max>10)
		{
			int newcon = 11;
			my_opject[newcon] = new Object(true, x, y, z, s, 1, 1, 1, 1, rand() % 4, rand() % 4, 0);
			newcon += 1;
		}
	
	cout << count << endl;
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

void Scene::update(Renderer *renderer, float elapsedTime)
{
	
	/*for (int i = 0; i < count; ++i) 
	{
		if (my_opject[i] != NULL)
		{
			my_opject[i]->Render(*renderer, elapsedTime);
			cout << "hello!" << endl;
			if (my_opject[i]->my_life < 0.f)
			{
				delete my_opject[i];
				my_opject[i] = NULL;
			}
		}
	}*/

	for (int i = 0; i <count; ++i)
	{
		
			
			if (my_opject[i]->my_life < 0.0001f)
			{
				delete my_opject[count];//감소되면 알아서 죽음 으악!
			}
			
			
			else
			{	//my_opject[i]->update(elapsedTime);
				my_opject[i]->Render(*renderer, elapsedTime);//여기서 터짐 쉬발
			}
		
	}


	Collion();
}
