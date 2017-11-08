#pragma once
class Renderer;

enum OBJECTTYPE { OBJECT_BUILDING, OBJECT_CHARACTER, OBJECT_BULLET, OBJECT_ARROW };

#define CHARACTER_LIFE 10
#define CHARACTER_SPEED 100
#define CHARACTER_SIZE 10

#define BUILDING_LIFE 500
#define BUILDING_SPEED 0
#define BUILDING_SIZE 50

#define BULLET_LIFE 20
#define BULLET_SPEED 300
#define BULLET_SIZE 2


typedef struct Position
{
	float x, y, z;
	Position()
	{
		x = 0.0;
		y = 0.0;
		z = 0.0;
	};
	Position(float x_pos, float y_pos, float z_pos)
	{
		x = x_pos, y = y_pos, z = z_pos;
	}

	Position operator+=(const Position& position)
	{
		float x1 = x + position.x;
		float y1 = y + position.y;
		float z1 = z + position.z;
		return Position(x1, y1, z1);
	}
	Position operator+(const Position& position)
	{
		float x1 = x + position.x;
		float y1 = y + position.y;
		float z1 = z + position.z;
		return Position(x1, y1, z1);
	}
	Position operator*(float time)
	{
		float x1 = x * time;
		float y1 = y * time;
		float z1 = z * time;
		return Position(x1, y1, z1);
	}
}Position, myvector; //벡터값 및 포지션 값 받을때 x,y,z로 받음으로 같이 선언

struct Color
{
	float r, g, b, a;
	Color(float red, float green, float blue, float alpha)
	{
		r = red, g = green, b = blue, a = alpha;
	}

};
class Object
{

public:
	OBJECTTYPE my_objtype;
	Position my_pos;
	Color my_color;
	myvector my_vector;
	float size;
	bool my_state;
	float my_life;
	float my_lifetime;

	float my_elapsedTimeInSecond;
	

	Object();
	Object(OBJECTTYPE objtype, float pos_x, float pos_y, float pos_z, float size, float r, float g, float b, float a);
	
	//상태, 포지션x,y,z 색깔rgba, 백터 xyz
	

	void update(float elapsedTime);//업데이트함수

	void SetPosition(float pos_x, float pos_y, float pos_z);
	void SetVector(float v_x, float v_y, float v_z);
	void SetColor(float r, float g, float b, float a);
	void CollisionCheck();
	bool collision(Position p, float size);

	float GetLifeTime();
	float GetLife();
	



};
