#include "stdafx.h"
#include "newObject.h"
#include "Renderer.h"
#include <chrono>
#include <Windows.h>

Object::Object() :my_pos(0, 0, 0), my_color(1, 1, 1, 1), my_vector(0, 0, 0)
{
	my_state = false;
	size = 10;
	
}
Object::Object(OBJECTTYPE objtype, float pos_x, float pos_y, float pos_z, float my_size, float r, float g, float b, float a) : my_pos(pos_x, pos_y, pos_z), my_color(r, g, b, a)
{
	my_objtype = objtype;
	my_lifetime = 100000.f;
	size = my_size;
	float speed;

	switch (my_objtype)
	{
	case OBJECT_BUILDING:
		my_life = BUILDING_LIFE;
		speed = BUILDING_SPEED;
		break;

	case OBJECT_CHARACTER:
		my_life = CHARACTER_LIFE;
		speed = CHARACTER_SPEED;
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
	//my_vector.x = 200.f*(((float)std::rand() / (float)RAND_MAX) - 0.5f);
	//my_vector.y = 200.f*(((float)std::rand() / (float)RAND_MAX) - 0.5f);
	/*my_pos.x = my_pos.x + my_vector.x*my_elapsedTimeInSecond;
	my_pos.y = my_pos.y + my_vector.y*my_elapsedTimeInSecond;

	if (my_pos.x > 250)
		my_vector.x = -my_vector.x;
	if (my_pos.x < -250)
		my_vector.x = -my_vector.x;

	if (my_pos.y > 250)
		my_vector.y = -my_vector.y;
	if (my_pos.y < -250)
		my_vector.y = -my_vector.y;
*/
	if (my_life > 0.f)
	{
		//my_life -= 0.5f;
		//cout << my_life << endl;
		//cout << elapsedTime << endl;
		//cout << endl;
		//cout << my_elapsedTimeInSecond << endl;
	}

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

void Object::CollisionCheck()
{
	if ((my_pos.x + (size / 2) >= 500 / 2) || // 오른쪽 검사
		((my_pos.x - (size / 2) <= 500 / 2 * -1.0f))) // 왼쪽 검사
		my_vector.x = -my_vector.x;

	if ((my_pos.y + (size / 2) >= 500 / 2) || // 위 검사
		((my_pos.y - (size / 2) <= 500 / 2 * -1.0f))) // 아래 검사
		my_vector.y = -my_vector.y;
}
bool Object::collision(Position p, float size)
{
	if (my_pos.x + size / 2 > p.x - size / 2 && my_pos.x - size / 2 < p.x + size / 2
		&& my_pos.y + size / 2 > p.y - size / 2 && my_pos.y - size / 2 < p.y + size / 2)
		return true;
	else
		return false;
}
float Object::GetLife()
{
	
	return my_life;
	//여기서 life - time을 해주어서 hp감소를 시켜야함.
}
float Object::GetLifeTime()
{
	return my_lifetime;
}