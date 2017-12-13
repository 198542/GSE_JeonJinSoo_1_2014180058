#include"stdafx.h"
#include"SceneMgr.h"
#include<random>

void Scene::addObj(TEAM team, float x, float y, float z, float s)
{
	//���콺 Ŭ������ ȣ���.

	for (int i = 0; i < Max; ++i)
	{
		if (my_opject[team][i] == nullptr)
		{
			Color color;
			if (team == RED) color.r = 1.0f;
			else
			{
				// ��� ĳ�� �������� 1�� ������ �ʾ����� ���� ����
				if (my_blueCharacterTime + BLUE_CHARACTER_TIME > GetTickCount()) return;
				
				my_blueCharacterTime = GetTickCount();

				color.b = 1.0f;
				
			}
			my_opject[team][i] = new Object(team, OBJECT_CHARACTER, x, y, z, CHARACTER_SIZE, color.r,color.g,color.b, 1);
			count += 1;
			break;
		}
	}	
}

void Scene::Collion()
{
	for (int j = 0; j < 2; ++j)
	{
		for (int i = 0; i < Max; ++i)
		{
			if (my_opject[j][i] == nullptr) continue;

			if (my_opject[j][i]->my_objtype == OBJECT_BUILDING
				|| my_opject[j][i]->my_objtype == OBJECT_CHARACTER)
			{

				// ����, �Ѿ� �浹
				for (auto& d : my_bullet)
				{
					if (d.my_team != j)
					{
						if (my_opject[j][i]->collision(d.my_pos, d.my_size))
						{
							my_opject[j][i]->my_life -= d.my_life; // ���� ü�� ����
							d.my_life = 0.0; // �Ѿ� ����
						}
					}
				}
				// ����, ȭ�� �浹
				for (auto& d : my_arrow)
				{
					if (d.my_team != j)
					{
						if (my_opject[j][i]->collision(d.my_pos, d.my_size))
						{
							my_opject[j][i]->my_life -= d.my_life; // ���� ü�� ����
							d.my_life = 0.0; // ȭ�� ����
						}
					}
				}
			}

			for (int k = 0; k < Max; ++k)
			{
				if (my_opject[(j + 1) % 2][k] == nullptr) continue;

				if (my_opject[j][i]->collision(my_opject[(j + 1) % 2][k]->my_pos,
					my_opject[(j + 1) % 2][k]->my_size))
				{
					// ĳ���Ͷ� ���� �浹
					if (my_opject[j][i]->my_objtype == OBJECT_CHARACTER && my_opject[(j + 1) % 2][k]->my_objtype == OBJECT_BUILDING)
					{
						my_opject[(j + 1) % 2][k]->my_life -= my_opject[j][i]->my_life; // ���� ü�� ����
						my_opject[j][i]->my_life = 0.0; // ĳ���� ����
					}
				}
			}
		}
	}


}

void Scene::Render() //�׸���
{
	for (int j = 0; j < 2; ++j)
	{
		for (int i = 0; i < Max; ++i)
		{
			if (my_opject[j][i] != nullptr && my_opject[j][i]->my_objtype == OBJECT_BUILDING) {
				my_renderer->DrawTexturedRect(my_opject[j][i]->my_pos.x, my_opject[j][i]->my_pos.y, my_opject[j][i]->my_pos.z,
					my_opject[j][i]->my_size, my_opject[j][i]->my_color.r, my_opject[j][i]->my_color.g, my_opject[j][i]->my_color.b,
					my_opject[j][i]->my_color.a, my_buildingImg[0], LEVEL_SKY);

				my_renderer->DrawSolidRectGauge(my_opject[j][i]->my_pos.x, my_opject[j][i]->my_pos.y + my_opject[j][i]->my_size, my_opject[j][i]->my_pos.z,
					my_opject[j][i]->my_size, my_opject[j][i]->my_size / 10.0f, my_opject[j][i]->my_color.r, my_opject[j][i]->my_color.g, my_opject[j][i]->my_color.b,
					my_opject[j][i]->my_color.a, my_opject[j][i]->my_life / BUILDING_LIFE, LEVEL_GOD);
			}
			else if (my_opject[j][i] != nullptr && my_opject[j][i]->my_objtype != OBJECT_BUILDING)
			{
				if (my_opject[j][i]->my_team == RED)
				{
					my_renderer->DrawTexturedRectSeq(my_opject[j][i]->my_pos.x, my_opject[j][i]->my_pos.y, my_opject[j][i]->my_pos.z,
						my_opject[j][i]->my_size, my_opject[j][i]->my_color.r, my_opject[j][i]->my_color.g, my_opject[j][i]->my_color.b, my_opject[j][i]->my_color.a,
						my_characterImg[RED], my_opject[j][i]->my_row, my_opject[j][i]->my_col, 6, 4, LEVEL_GROUND);
				}
				else
				{
					my_renderer->DrawTexturedRectSeq(my_opject[j][i]->my_pos.x, my_opject[j][i]->my_pos.y, my_opject[j][i]->my_pos.z,
						my_opject[j][i]->my_size, my_opject[j][i]->my_color.r, my_opject[j][i]->my_color.g, my_opject[j][i]->my_color.b, my_opject[j][i]->my_color.a,
						my_characterImg[BLUE], my_opject[j][i]->my_row, my_opject[j][i]->my_col, 6, 4, LEVEL_GROUND);
				}
				my_renderer->DrawSolidRectGauge(my_opject[j][i]->my_pos.x, my_opject[j][i]->my_pos.y + my_opject[j][i]->my_size, my_opject[j][i]->my_pos.z,
					my_opject[j][i]->my_size, my_opject[j][i]->my_size / 2.0f, my_opject[j][i]->my_color.r, my_opject[j][i]->my_color.g, my_opject[j][i]->my_color.b,
					my_opject[j][i]->my_color.a, my_opject[j][i]->my_life / CHARACTER_LIFE, LEVEL_GOD);
			}
			}
	}
	// �Ѿ� �׸�
	for (auto& d : my_bullet) {
		my_renderer->DrawSolidRect(d.my_pos.x, d.my_pos.y, d.my_pos.z,
			d.my_size, d.my_color.r,
			d.my_color.g, d.my_color.b, d.my_color.a, LEVEL_UNDERGROUND);
		
		// ��ƼŬ �׸�
		my_renderer->DrawParticle(d.my_pos.x, d.my_pos.y, d.my_pos.z,
			d.my_size, d.my_color.r,
			d.my_color.g, d.my_color.b, d.my_color.a, 0, 0, my_bulletParticle, 1000);
			
	}

	// ȭ�� �׸�
	for (auto& d : my_arrow) {
		my_renderer->DrawSolidRect(d.my_pos.x, d.my_pos.y, d.my_pos.z,
			d.my_size, d.my_color.r,
			d.my_color.g, d.my_color.b, d.my_color.a, LEVEL_UNDERGROUND);
	}

	// ��� �׸�

	my_renderer->DrawTexturedRect(0.0f,0.0f,0.0f, 800, 1.0f,1.0f,1.0f,0.5f,my_backImg, LEVEL_UNDERGROUND);
	my_renderer->DrawText(150, 300, GLUT_BITMAP_9_BY_15, 1, 1, 1, "Red King");
	my_renderer->DrawText(-10, 300, GLUT_BITMAP_9_BY_15, 1, 1, 1, "Red King");
	my_renderer->DrawText(-160, 300, GLUT_BITMAP_9_BY_15, 1, 1, 1, "Red King");

	my_renderer->DrawText(150, -310, GLUT_BITMAP_9_BY_15, 1, 1, 1, "Blue King");
	my_renderer->DrawText(-10, -310, GLUT_BITMAP_9_BY_15, 1, 1, 1, "Blue King");
	my_renderer->DrawText(-160, -310, GLUT_BITMAP_9_BY_15, 1, 1, 1, "Blue King");
}



void Scene::update(float elapsedTime)
{

	Collion();
	if (my_redCharacterTime + RED_CHARACTER_TIME < GetTickCount())
	{
		Position pos;
		pos.x = rand() % 500 / 4.0f;
		pos.y = rand() % 800 / 4.0f;
		if (rand() % 3 == 1) pos.x = -pos.x;
		addObj(RED, pos.x, pos.y, pos.z, CHARACTER_SIZE);
		my_redCharacterTime = GetTickCount();
	}

	for (int j = 0; j < 2; ++j)
	{
		for (int i = 0; i < Max; ++i) {
			if (my_opject[j][i] != nullptr) {
				my_opject[j][i]->update(elapsedTime);
				if (my_opject[j][i]->my_objtype == OBJECT_CHARACTER) {
					Object obj = my_opject[j][i]->CreateArrow();
					if (obj.my_life != 1.0f) my_arrow.push_back(obj);
				}
				else if (my_opject[j][i]->my_objtype == OBJECT_BUILDING) {
					Object obj = my_opject[j][i]->CreateBullet();
					if (obj.my_life != 1.0f) my_bullet.push_back(obj);
				}
			}
		}
	}
	for (auto& d : my_bullet) d.update(elapsedTime); // �Ѿ� ������Ʈ
	for (auto& d : my_arrow) d.update(elapsedTime); // ȭ�� ������Ʈ
	DeleteObject();
}

void Scene::DeleteObject()
{
	for (int j = 0; j < 2; ++j)
	{
		for (int i = 0; i < Max; ++i)
		{
			if (my_opject[j][i] == nullptr) continue;

			if (my_opject[j][i]->my_life < 0.0001f)
			{
				count--;
				delete my_opject[j][i];//���ҵǸ� �˾Ƽ� ���� ����!
				my_opject[j][i] = nullptr;
			}
		}
	}
	// �Ѿ� ����
	vector<Object>::iterator itor = my_bullet.begin();
	while(itor != my_bullet.end())
	{
		if (itor->my_life < 0.0001f)
		{
			itor = my_bullet.erase(itor);
		}
		else ++itor;
	}

	// ȭ�� ����
	itor = my_arrow.begin();
	while (itor != my_arrow.end())
	{
		if (itor->my_life < 0.0001f)
		{
			itor = my_arrow.erase(itor);
		}
		else ++itor;
	}
}