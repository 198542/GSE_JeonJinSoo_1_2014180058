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
}Position, myvector; //���Ͱ� �� ������ �� ������ x,y,z�� �������� ���� ����

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
	
	//����, ������x,y,z ����rgba, ���� xyz
	

	void update(float elapsedTime);//������Ʈ�Լ�

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
