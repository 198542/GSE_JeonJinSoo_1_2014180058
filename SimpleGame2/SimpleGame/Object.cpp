#include"stdafx.h"//������ ���� �־���Ѵ�.
#include"Object.h"

Object::Object(const Position position, const float size, const Color color)
{
	my_pos = position;
	my_size = size;
	my_col = color;

	my_velocitypos.x = Speed;
	//�ӵ����� ���� velpos
	//��� ������ ���������� �̵�
}

void Object::update()
{
	my_pos = my_pos + my_velocitypos * Time;
	//������ �����Ͻ� ���� ������ ���� ����
	//�ӵ�����*�ð�
}
