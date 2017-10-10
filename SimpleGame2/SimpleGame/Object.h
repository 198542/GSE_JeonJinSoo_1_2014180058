#pragma once


struct Position
{
	float x, y, z;
	Position() { x = 0.0, y = 0.0, z = 0.0; }//√ ±‚»≠
	Position(float X, float Y, float Z) :x(X), y(Y), z(Z) {};
};

struct Color
{
	float red, green, blue;
	Color() { red = 0.0, green = 0.0, blue = 0.0; }
	Color(float r, float g, float b) :red(r), green(g) {}
};

class Object
{
private:
	Position my_pos;
	Color my_col;
	float my_size;
public:
	Object(const Position position, const Color color, const float size) {};
	
	const Position& GetPosition() { return my_pos; }
	const Color& GetColor() { return my_col; }
	const float& GetSize() { return my_size; }

	void SetPosition(const Position position) { my_pos = position; }
	void SetColor(const Color color) { my_col = color; }
	void SetSize(const float size) { my_size = size; }


};