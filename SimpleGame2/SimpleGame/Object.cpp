#include"stdafx.h"//������ ���� �־���Ѵ�.
#include"Object.h"

Object::Object(const Position position, const float size, const Color color)
{
	my_pos = position;
	my_size = size;
	my_col = color;

	switch (rand() % 8)
	{
	case 0: my_velocitypos.x = Speed; break;
	case 1: my_velocitypos.x = -Speed; break;
	case 2: my_velocitypos.y = Speed; break;
	case 3: my_velocitypos.y = -Speed; break;
	case 4: my_velocitypos.x = Speed; my_velocitypos.y = Speed; break;
	case 5: my_velocitypos.x = -Speed; my_velocitypos.y = -Speed; break;
	case 6: my_velocitypos.y = Speed; my_velocitypos.y = Speed; break;
	case 7: my_velocitypos.y = -Speed; my_velocitypos.y = -Speed; break;

	}

	//�ӵ����� ���� velpos
	//��� ������ ���������� �̵�
}
void Object::Move()
{
	if ((my_pos.x + (my_size / 2) > Width / 2) || ((my_pos.x + (my_size / 2) < Width / 2.0*-1.0f)))
		my_velocitypos.x = -my_velocitypos.x;
	if ((my_pos.y + (my_size / 2) > Hight / 2) || (my_pos.y + (my_size / 2) < Hight / 2.0*-1.0f))
		my_velocitypos.y = -my_velocitypos.y;

	my_pos = my_pos + my_velocitypos * (1.0 / 1000);

}
void Object::update()
{
	this->Move();
	//my_pos = my_pos + my_velocitypos * Time;
	//������ �����Ͻ� ���� ������ ���� ����
	//�ӵ�����*�ð�
}

