#pragma once
#include "newObject.h"
const int Max = 10;
class Scene
{
public:
	Scene();
	void Collion();
	void addObj(float x, float y, float z, float s);
	void update(Renderer *renderer, float elapsedTime);


private:
	Object *my_opject[Max];
	int count = 0;
	int my_lifetest;
};
