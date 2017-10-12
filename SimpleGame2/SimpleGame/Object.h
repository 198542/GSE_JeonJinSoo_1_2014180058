#pragma once
#include<iostream>
#include<vector>

using namespace std;

static float Speed = 3000.0f;

struct Position
{
	float x, y, z;

	Position() { x = 0.0, y = 0.0, z = 0.0; }
	Position(float X, float Y, float Z) :x(X), y(Y), z(Z) {};

	Position operator*(float n)
	{
		 Position postion(x*n, y*n, z*n);
		 return postion;
	}

	Position operator+(Position position)
	{
		Position returnpos(x + position.x, y + position.y, z + position.z);
		return returnpos;
	}
};


class Object
{
public:

	void mydata(const Position position,const float size);
	void update();


	//Get
	const Position& GetPosition() { return my_pos; }
	const float& GetSize() { return my_size; }


	//Set
	void SetPosition(const Position position) { my_pos = position; }
	void SetSize(const float size) { my_size = size; }

private:
	Position my_pos;
	Position my_velocitypos;
	float my_size;
};
