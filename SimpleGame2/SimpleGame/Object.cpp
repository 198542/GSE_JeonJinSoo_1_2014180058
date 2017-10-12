#include"stdafx.h"//무조건 위에 있어야한다.
#include"Object.h"

Object::Object(const Position position, const float size, const Color color)
{
	my_pos = position;
	my_size = size;
	my_col = color;

	my_velocitypos.x = Speed;
	//속도값을 위한 velpos
	//양수 임으로 오른쪽으로 이동
}

void Object::update()
{
	my_pos = my_pos + my_velocitypos * Time;
	//교수님 말씀하신 공식 적용을 위한 수식
	//속도벡터*시간
}
