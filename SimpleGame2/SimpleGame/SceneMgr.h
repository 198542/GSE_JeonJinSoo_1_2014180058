#pragma once
#include "newObject.h"
const int Max = 50;
class Scene
{
public:
	Scene();
	void Collion();
	void addObj(float x, float y, float z, float s);
	void update(Renderer *renderer);
private:
	Object *my_opject[Max];
	int count;
};
