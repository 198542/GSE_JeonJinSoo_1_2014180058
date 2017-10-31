#pragma once
class Renderer;

typedef struct Position
{
	float x, y, z;
	Position(float x_pos, float y_pos, float z_pos)
	{
		x = x_pos, y = y_pos, z = z_pos;
	}

	Position operator+=(const Position& position)
	{
		x = x + position.x;
		y = y + position.y;
		z = z + position.z;
		return Position(x, y, z);
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
	
	Position my_pos;
	Color my_color;
	myvector my_vector;
	float size;
	bool my_state;
	float my_life;
	float my_lifetime;

	float my_elapsedTimeInSecond;
	

	Object();
	Object(bool state, float pos_x, float pos_y, float pos_z, float size, float r, float g, float b, float a, float v_x, float v_y, float v_z);
	void Render(Renderer & g_Renderer, float elapsedTime);
	
	//상태, 포지션x,y,z 색깔rgba, 백터 xyz
	

	void update(float elapsedTime);//업데이트함수

	void SetPosition(float pos_x, float pos_y, float pos_z);
	void SetVector(float v_x, float v_y, float v_z);
	void SetColor(float r, float g, float b, float a);
	void CheckState(bool state);
	void CollisionCheck();
	bool collision(Position p, float size);

<<<<<<< HEAD
	float GetLifeTime();
	float GetLife();
=======
	void LifeTime();
	void ObjectLife();
>>>>>>> 63c415c2a563c0b12046c5ef886f6ecf187b9b50
	



};
