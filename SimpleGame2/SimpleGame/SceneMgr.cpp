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
			my_opject[i] = new Object(count,-1,OBJECT_CHARACTER, x, y, z, CHARACTER_SIZE, 1);
			
			count += 1;
			

			break;
		}
	}	
}

void Scene::Collion()
{
	// 캐릭터, 빌딩, 총알 충돌 체크
	for (int i = 0; i < Max; ++i)
	{
		if (my_opject[i] == nullptr) continue;

		for (int j = 0; j < Max; ++j)
		{
			if (i == j) continue;
			if (my_opject[j] == nullptr) continue;

			if (my_opject[i]->my_objtype == OBJECT_CHARACTER)
			{
				// 캐릭터랑 총알 충돌
				for (auto& d : my_bullet)
				{
					if (my_opject[i]->collision(d.my_pos, d.my_size))
					{
						my_opject[i]->my_life -= d.my_life; // 캐릭터 체력 깍음
						d.my_life = 0.0; // 총알 없앰
					}
				}
			}
			if (my_opject[i]->collision(my_opject[j]->my_pos, my_opject[j]->my_size))
			{
				// 캐릭터랑 빌딩 충돌
				if (my_opject[i]->my_objtype == OBJECT_CHARACTER && my_opject[j]->my_objtype == OBJECT_BUILDING)
				{
					my_opject[i]->my_life -= my_opject[j]->my_life; // 빌딩 체력 깍음
					my_opject[i]->my_life = 0.0; // 캐릭터 없앰
				}

				my_opject[i]->SetColor(0, 1, 0, 1);
				break;
			}
			else
				my_opject[i]->SetColor(1, 1, 1, 1);
		}

	}

	/*for (int i = 1; i < Max; ++i)
	{
		if (my_opject[i] == nullptr) continue;

		for (int j = 1; j < Max; ++j)
		{
			if (i == j) continue;
			if (my_opject[j] == nullptr) continue;

			else if (my_opject[0]->collisionhouse(my_opject[j]->my_pos, my_opject[j]->my_size))
			{
				my_opject[0]->SetColor(0, 1, 0, 1);
				cout << "충돌" << endl;
				break;
			}
			else
			{
				my_opject[0]->SetColor(1, 1, 0, 1);
				cout << "복구" << endl;
				break;
				
			}
		}

	}*/
}



void Scene::Render() //그리기
{


	for (int i = 0; i < Max; ++i)
	{
		if (my_opject[i] != nullptr)
			my_renderer->DrawSolidRect(my_opject[i]->my_pos.x, my_opject[i]->my_pos.y, my_opject[i]->my_pos.z,
				my_opject[i]->my_size, my_opject[i]->my_color.r,
				my_opject[i]->my_color.g, my_opject[i]->my_color.b, my_opject[i]->my_color.a);
	}

	// 총알 그림
	for (auto& d : my_bullet) 
	{
		my_renderer->DrawSolidRect(d.my_pos.x, d.my_pos.y, d.my_pos.z,
			d.my_size, d.my_color.r,
			d.my_color.g, d.my_color.b, d.my_color.a);
	}
}
void Scene::BuildingRender(Renderer& g_Renderer)
{
	
		cout << "하이" << endl;
		g_Renderer.DrawTexturedRect(0,0,0,100,0,0,0,1,my_opject[0]->image);
		
	

		g_Renderer.DrawSolidRect(my_opject[0]->my_pos.x, my_opject[0]->my_pos.y, my_opject[0]->my_pos.z,
			my_opject[0]->my_size, my_opject[0]->my_color.r, my_opject[0]->my_color.g, my_opject[0]->my_color.b, my_opject[0]->my_color.a);
}

void Scene::CreateBullet()
{
	if (my_bulletime + 500 < GetTickCount()) // 총알을 생성한지 0.5초가 경과 됬으면
	{
		my_bullet.push_back(Object(count,-1,OBJECT_BULLET, my_opject[0]->my_pos.x, my_opject[0]->my_pos.y, my_opject[0]->my_pos.z,
			BULLET_SIZE, 1)); // 건물 위치에 총알 생성
		my_bulletime = GetTickCount(); // 현재 시간 다시 저장
	}

	for (int i = 1; i < Max; ++i)
	{
		if (my_opject[i] == nullptr) continue;

		if (my_opject[i]->my_time + 500 < GetTickCount()) { // 총알을 생성한지 0.5초가 경과 됬으면
			my_bullet.push_back(Object(count, my_opject[i]->ownerId, OBJECT_ARROW, my_opject[i]->my_pos.x, my_opject[i]->my_pos.y, my_opject[i]->my_pos.z,
				ARROW_SIZE, 1)); // 건물 위치에 총알 생성
			my_opject[i]->my_time = GetTickCount(); // 현재 시간 다시 저장
		}
	}

	
}
void Scene::update(float elapsedTime)
{
	CreateBullet();
	for (int i = 0; i <Max; ++i) if (my_opject[i] != nullptr) my_opject[i]->update(elapsedTime);
	for (auto& d : my_bullet) d.update(elapsedTime); // 총알 업데이트
	Collion();
	DeleteObject();
}

void Scene::DeleteObject()
{
	for (int i = 0; i < Max; ++i)
	{
		if (my_opject[i] == nullptr) continue;

		//cout << my_opject[i]->my_life << endl;
		if (my_opject[i]->my_life < 0.0001f)
		{
			count--;
			delete my_opject[i];//감소되면 알아서 죽음 으악!
			my_opject[i] = nullptr;
		}
	}

	// 총알 삭제
	vector<Object>::iterator itor = my_bullet.begin();
	while(itor != my_bullet.end())
	{
		if (itor->my_life < 0.0001f)
		{
			itor = my_bullet.erase(itor);
		}
		else ++itor;
	}

}