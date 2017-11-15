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
Object::Object(int objectId, int ownerId, OBJECTTYPE objtype, float pos_x, float pos_y, float pos_z, float size, int image) : my_pos(pos_x, pos_y, pos_z), my_color(0,0,0,1),image(image)
{
	my_objtype = objtype;
	my_lifetime = 100000.f;
	my_size = size;
	my_time = GetTickCount();
	float speed;

	switch (my_objtype)
	{
	case OBJECT_BUILDING:
		my_life = BUILDING_LIFE;
		speed = BUILDING_SPEED;
		my_color=Color(1, 1, 0, 1);
		break;

	case OBJECT_CHARACTER:
		my_life = CHARACTER_LIFE;
		speed = CHARACTER_SPEED;
		my_color = Color(1, 1, 1, 1);
		break;
	case OBJECT_ARROW:
		my_life = ARROW_LIFE;
		speed = ARROW_SPEED;
		my_color = Color(0, 1, 0, 1);
		break;
	case OBJECT_BULLET:
		my_life = BULLET_LIFE;
		speed = BULLET_SPEED;
		my_color = Color(1, 0, 0, 1);
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

void Object::CollisionCheck() //�� �浹üũ
{
	if ((my_pos.x + (my_size / 2) >= 500 / 2) || // ������ �˻�
		((my_pos.x - (my_size / 2) <= 500 / 2 * -1.0f))) // ���� �˻�
		my_vector.x = -my_vector.x;

	if ((my_pos.y + (my_size / 2) >= 500 / 2) || // �� �˻�
		((my_pos.y - (my_size / 2) <= 500 / 2 * -1.0f))) // �Ʒ� �˻�
		my_vector.y = -my_vector.y;
}
bool Object::collision(Position p, float size)
{
	//��ü ���� �浹üũ
	if (my_pos.x + my_size / 2 > p.x - size / 2 && my_pos.x - my_size / 2 < p.x + size / 2
		&& my_pos.y + my_size / 2 > p.y - size / 2 && my_pos.y - my_size / 2 < p.y + size / 2)
		return true;
	else
		return false;
}

//bool Object::collisionhouse(Position pos, float size)
//{
//	//���� �⵿üũ ������ ���ؾ���
//	//ĳ���Ϳ� ���� �浹
//	if (my_pos.x + (BUILDING_SIZE / 2) > pos.x - size / 2 && my_pos.x - (BUILDING_SIZE / 2 ) < pos.x + size / 2
//		&& my_pos.y + (BUILDING_SIZE / 2) > pos.y - size / 2 && my_pos.y - (BUILDING_SIZE / 2) < pos.y + size / 2)
//		return true;
//	else
//		return false;
//	//������ ����� �浹�ȵ�
//
//}


float Object::GetLife()
{
	
	return my_life;

}
float Object::GetLifeTime()
{
	return my_lifetime;
}