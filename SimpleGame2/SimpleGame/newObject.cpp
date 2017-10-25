#include "stdafx.h"
#include "newObject.h"
#include "Renderer.h"

Object::Object() :my_pos(0, 0, 0), my_color(1, 1, 1, 1), my_vector(0, 0, 0)
{
	my_state = false;
	size = 10;
}
Object::Object(bool state, float pos_x, float pos_y, float pos_z, float my_size, float r, float g, float b, float a, float v_x, float v_y, float v_z) : my_pos(pos_x, pos_y, pos_z), my_color(r, g, b, a), my_vector(v_x, v_y, v_z)
{
	size = my_size;
	my_state = state;
}

void Object::Render(Renderer& g_Renderer)
{
	if (my_state)
	{
		update();
		g_Renderer.DrawSolidRect(my_pos.x, my_pos.y, my_pos.z, size, my_color.r, my_color.g, my_color.b, my_color.a);
	}
}

void Object::update()
{
	CollisionCheck();
	my_pos += my_vector;
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
void Object::CheckState(bool state)
{
	my_state = state;
}
void Object::CollisionCheck()
{
	if (my_vector.x != 0 && my_pos.x + my_vector.x + size / 2 > 250)//백터 x 가 0이 아니고, 포지션x+백터x+size/2가 50보다 크면
		my_vector.x = -my_vector.x; //현재 백터값을 음수로 변경
	else if (my_vector.x != 0 && my_pos.x + my_vector.x + size / 2 <- 250)
		my_vector.x = -my_vector.x; //반대개념
	if (my_vector.y != 0 && my_pos.y + my_vector.y + size / 2 > 250)
		my_vector.y = -my_vector.y;
	else if (my_vector.y != 0 && my_pos.y + my_vector.y + size / 2 <- 250)
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