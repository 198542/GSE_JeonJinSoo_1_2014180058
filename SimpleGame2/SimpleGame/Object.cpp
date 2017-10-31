#include"stdafx.h"//무조건 위에 있어야한다.
#include"Object.h"

Object::Object(const Position position, const float size, const Color color)
{
	my_pos = position;
	my_size = size;
	my_col = color;

	my_velocitypos.x = Speed;
	my_velocitypos.y = Speed;
	my_velocitypos.z = Speed;

	//속도값을 위한 velpos
	//양수 임으로 오른쪽으로 이동
}
void Object::Move()
{
	
	if ((my_pos.x + (my_size / 2) > Width / 2) || ((my_pos.x + (my_size / 2) < Width / 2.0*-1.0f)))
		my_velocitypos.x = -my_velocitypos.x;
	if ((my_pos.y + (my_size / 2) > Hight / 2) || (my_pos.y + (my_size / 2) < Hight / 2.0*-1.0f))
		my_velocitypos.y = -my_velocitypos.y;



	my_pos = my_pos + my_velocitypos*(1.0 / Speed);

}
void Object::update()
{
	this->Move();
	//my_pos = my_pos + my_velocitypos * Time;
	//교수님 말씀하신 공식 적용을 위한 수식
	//속도벡터*시간
}

