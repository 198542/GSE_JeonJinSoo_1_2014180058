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
<<<<<<< HEAD
	int count = 0;
=======
	int count;
>>>>>>> 63c415c2a563c0b12046c5ef886f6ecf187b9b50
	int my_lifetest;
};
