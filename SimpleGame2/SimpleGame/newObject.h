#pragma once

#include <vector>



class Renderer;

enum OBJECTTYPE { OBJECT_BUILDING, OBJECT_CHARACTER, OBJECT_BULLET, OBJECT_ARROW };
enum TEAM{RED, BLUE};

const float LEVEL_GOD = 0;
const float LEVEL_SKY = 0.1f;
const float LEVEL_GROUND = 0.2f;
const float LEVEL_UNDERGROUND = 0.3f;

#define RED_CHARACTER_TIME 5000
#define BLUE_CHARACTER_TIME 7000

#define CHARACTER_LIFE 100
#define CHARACTER_SPEED 300
#define CHARACTER_SIZE 30

#define BUILDING_LIFE 500
#define BUILDING_SPEED 0
#define BUILDING_SIZE 100

#define BULLET_TIME 5000
#define BULLET_LIFE 15
#define BULLET_SPEED 600
#define BULLET_SIZE 4

#define ARROW_TIME 3000
#define ARROW_LIFE 10
#define ARROW_SPEED 100
#define ARROW_SIZE 4

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
	Color()
	{
		r = 0, g = 0, b = 0, a = 1.0;
	}
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
	float my_size;
	bool my_state;
	float my_life;
	float my_lifetime;

	float my_elapsedTimeInSecond;
	DWORD my_arrowtime;
	TEAM my_team;
	DWORD my_bulletime; // 총알을 일정 시간 마다 생성하기 위한 시간 변수

	Object();
	Object(TEAM team, OBJECTTYPE objtype, float pos_x, float pos_y, float pos_z, float size, float r, float g, float b, float a);
	
	//상태, 포지션x,y,z 색깔rgba, 백터 xyz
	

	void update(float elapsedTime);//업데이트함수

	void SetPosition(float pos_x, float pos_y, float pos_z);
	void SetVector(float v_x, float v_y, float v_z);
	void SetColor(float r, float g, float b, float a);
	void CollisionCheck();
	bool collision(Position p, float size);

	bool collisionhouse(Position p, float size);
	
	float GetLifeTime();
	float GetLife();
	Object CreateArrow();
	Object CreateBullet();



};
