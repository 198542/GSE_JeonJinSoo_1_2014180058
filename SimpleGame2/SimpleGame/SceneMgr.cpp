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
<<<<<<< HEAD
	//���콺 Ŭ������ ȣ���.

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
	
=======
	if (count < Max)
	{
		Object* addobject = new Object(true, x, y, z, s, 1, 1, 1, 1, rand() % 4, rand() % 4, 0);
		//�ڿ� 3���� vector �� �̰��� �ð�����?

		my_opject[count] = addobject;

		count += 1;
		my_lifetest = 10;
		my_lifetest -= 5;
		if (my_lifetest = 0)
		{
			delete addobject;
		}
		else
			return;
	}
>>>>>>> 63c415c2a563c0b12046c5ef886f6ecf187b9b50
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
<<<<<<< HEAD

void Scene::update(Renderer *renderer, float elapsedTime)
{
=======
void Scene::update(Renderer *renderer, float elapsedTime)
{
	//���⿡�� �ð��� ���� �ְ� ������ҰͰ���.
	//cout << "@" << endl;
	for (int i = 0; i < count; ++i)
		if (my_opject[i])
			my_opject[i]->Render(*renderer,elapsedTime);
>>>>>>> 63c415c2a563c0b12046c5ef886f6ecf187b9b50
	
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
				delete my_opject[count];//���ҵǸ� �˾Ƽ� ���� ����!
			}
			
			
			else
			{	//my_opject[i]->update(elapsedTime);
				my_opject[i]->Render(*renderer, elapsedTime);//���⼭ ���� ����
			}
		
	}


	Collion();
}
