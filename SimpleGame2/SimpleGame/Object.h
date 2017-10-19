#pragma once
#include"stdafx.h"
#include<iostream>
#include<vector>
#include<random>
#include<memory>

using namespace std;

static float Speed = 5000.0f;
static float Time = 1.0f / 1000.0f;
const float Width = 500.0;
const float Hight = 500.0;

struct Position
{
	float x, y, z;

	Position() { x = 0.0, y = 0.0, z = 0.0; }
	Position(float X, float Y, float Z) :x(X), y(Y), z(Z) {};

	Position operator*(float n) //�ϳ��� �������Ѿ� ������ 
	{
		Position postion(x* n, y * n, z * n);
		return postion;
	}

	Position operator*(Position n) //�ϳ��� �������Ѿ� ������ 
	{
		Position postion(x*n.x, y*n.y, z*n.z);
		return postion;
	}

	Position operator+(Position position)
	{
		Position returnpos(x + position.x, y + position.y, z + position.z);
		return returnpos;
	}
};

struct Color
{
	float r, g, b, a;
	Color() { r = 0.0, g = 0.0, b = 0.0, a = 1; }//a=���İ�, 1������� ������
	Color(float red, float green, float blue, float alpha) :r(red), g(green), b(blue), a(alpha) {};

};
class Object
{
private:
	Position my_pos;
	Position my_velocitypos;
	Color my_col;
	float my_size;

public:
	Object() {};
	Object(const Position position, const float size, const Color color);
	void update();
	void Move();


	//Get
	const Position& GetPosition() { return my_pos; }
	const Color& GetColor() { return my_col; }
	const float& GetSize() { return my_size; } //&�� �Ⱥ��̸� ���纻�� ���޵�. ���̸� �ּҰ��� ���޵ȴ�.


											   //Set
	void SetPosition(const Position position) { my_pos = position; }
	void SetColor(const Color color) { my_col = color; }
	void SetSize(const float size) { my_size = size; }

	shared_ptr<Object> newobject(const Position position, const float size, const Color colr);

};
