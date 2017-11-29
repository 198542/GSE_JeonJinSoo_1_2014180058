#include "stdafx.h"
#include "newObject.h"
#include "Renderer.h"
#include <chrono>
#include <Windows.h>

Object::Object() :my_pos(0, 0, 0), my_color(1, 1, 1, 1), my_vector(0, 0, 0)
{
	my_state = false;
	my_size = 10;
	
}
Object::Object(TEAM team, OBJECTTYPE objtype, float pos_x, float pos_y, float pos_z, float size, float r, float g, float b, float a) : my_pos(pos_x, pos_y, pos_z), my_color(r, g, b, a)
{
	my_objtype = objtype;
	my_lifetime = 100000.f;
	my_size = size;
	float speed;
	my_team = team;
	switch (my_objtype)
	{
	case OBJECT_BUILDING:
		my_life = BUILDING_LIFE;
		speed = BUILDING_SPEED;
		my_bulletime = GetTickCount(); 
		break;

	case OBJECT_CHARACTER:
		my_life = CHARACTER_LIFE;
		speed = CHARACTER_SPEED;
		my_arrowtime = GetTickCount();
		break;
	case OBJECT_ARROW:
		my_life = ARROW_LIFE;
		speed = ARROW_SPEED;
		break;
	case OBJECT_BULLET:
		my_life = BULLET_LIFE;
		speed = BULLET_SPEED;
		break;
		
	}

	switch (rand() % 8) 
	{
	case 0: my_vector.x = speed; break;
	case 1: my_vector.x = -speed; break;
	case 2: my_vector.y = speed; break;
	case 3: my_vector.y = -speed; break;
	case 4: my_vector.x = speed; my_vector.y = speed; break;
	case 5: my_vector.x = speed; my_vector.y = -speed; break;
	case 6: my_vector.x = -speed; my_vector.y = speed; break;
	case 7: my_vector.x = -speed; my_vector.y = -speed; break;
	}

}

Object Object::CreateArrow()
{
	Color color;
	if (my_team == RED)
	{
		color.r = 0.5f, color.g = 0.2f, color.b = 0.7f;
	}
	else
	{
		color.r = 1.0f, color.g = 1.0f;
	}

	if (my_arrowtime + ARROW_TIME < GetTickCount()) { // 총알을 생성한지 0.5초가 경과 됬으면
		Object obj(my_team, OBJECT_ARROW, my_pos.x, my_pos.y, my_pos.z,
			ARROW_SIZE, color.r, color.g, color.b, color.a); // 건물 위치에 총알 생성
		my_arrowtime = GetTickCount(); // 현재 시간 다시 저장
		obj.my_life = ARROW_LIFE;
		return obj;
	}
	Object obj;
	obj.my_life = 1.0f;
	return obj;
}

Object Object::CreateBullet()
{

	Color color;
	if (my_team == RED) color.r = 1.0f;
	else color.b = 1.0f;

	if (my_bulletime + BULLET_TIME < GetTickCount()) { // 총알을 생성한지 0.5초가 경과 됬으면
		Object obj(my_team, OBJECT_BULLET, my_pos.x, my_pos.y, my_pos.z,
			BULLET_SIZE, color.r, color.g, color.b, color.a); // 건물 위치에 총알 생성
		my_bulletime = GetTickCount(); // 현재 시간 다시 저장
		obj.my_life = BULLET_LIFE;
		return obj;
	}

	Object obj; // 리턴용
	obj.my_life = 1.0f;
	return obj;
}

void Object::update(float elapsedTime)//float elapsedTime
{
	/*
	if (my_life > 0.f)
	{
		my_life -= 0.05f;
	}
	*/
	CollisionCheck();
	my_pos = my_pos + my_vector * (elapsedTime / 1000.0f);

}

void Object::SetPosition(float pos_x, float pos_y, float pos_z)
{
	my_pos.x = pos_x;
	my_pos.y = pos_y;
	my_pos.z = pos_z;
}
void Object::SetVector(float v_x, float v_y, float v_z)
{
	my_vector.x = v_x;
	my_vector.y = v_y;
	my_vector.z = v_z;
}
void Object::SetColor(float r, float g, float b, float a)
{
	my_color.r = r;
	my_color.g = g;
	my_color.b = b;
	my_color.a = a;
}

void Object::CollisionCheck() //맵 충돌체크
{
	if ((my_pos.x + (my_size / 2) >= 500 / 2) || // 오른쪽 검사
		((my_pos.x - (my_size / 2) <= 500 / 2 * -1.0f))) // 왼쪽 검사
		my_vector.x = -my_vector.x;

	if ((my_pos.y + (my_size / 2) >= 800 / 2) || // 위 검사
		((my_pos.y - (my_size / 2) <= 800 / 2 * -1.0f))) // 아래 검사
		my_vector.y = -my_vector.y;
}
bool Object::collision(Position p, float size)
{
	//객체 서로 충돌체크
	if (my_pos.x + my_size / 2 > p.x - size / 2 && my_pos.x - my_size / 2 < p.x + size / 2
		&& my_pos.y + my_size / 2 > p.y - size / 2 && my_pos.y - my_size / 2 < p.y + size / 2)
		return true;
	else
		return false;
}

bool Object::collisionhouse(Position pos, float size)
{
	//빌딩 출동체크 사이즈 구해야함
	//캐릭터와 빌딩 충돌
	if (my_pos.x + (BUILDING_SIZE / 2) > pos.x - size / 2 && my_pos.x - (BUILDING_SIZE / 2 ) < pos.x + size / 2
		&& my_pos.y + (BUILDING_SIZE / 2) > pos.y - size / 2 && my_pos.y - (BUILDING_SIZE / 2) < pos.y + size / 2)
		return true;
	else
		return false;
	//사이즈 제대로 충돌안됨

}


float Object::GetLife()
{
	
	return my_life;

}
float Object::GetLifeTime()
{
	return my_lifetime;
}