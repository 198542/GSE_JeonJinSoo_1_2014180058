#include"Object.h"
#include"stdafx.h"
class Object;
struct Position;


void Object::mydata(const Position position, const float size)
{
	my_pos = position;
	my_size = size;
}

void Object::update()
{
	
	my_pos=my_pos+my_velocitypos*Speed;
}
