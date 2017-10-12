/*
Copyright 2017 Lee Taek Hee (Korea Polytech University)

This program is free software: you can redistribute it and/or modify
it under the terms of the What The Hell License. Do it plz.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.
*/

#include "stdafx.h"
#include <iostream>
#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"
#include "Object.h" //자료형만 제공

#include "Renderer.h"


vector<Object*> v;
//벡터값에다가 마우스 클릭한 정보 저장하기위한 벡터 선언
//포인터를 준것은 call by value 개념과 call by referenc

Renderer *g_Renderer = NULL;

void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);

	// Renderer Test
	for (auto d : v) { //포인터 이기 때문에 . 이아니라 -> 가리킴
		g_Renderer->DrawSolidRect(d->GetPosition().x, d->GetPosition().y, d->GetPosition().z,
			d->GetSize(), d->GetColor().r, d->GetColor().g, d->GetColor().b, d->GetColor().a);
		d->update();
	}
	//g_Renderer->DrawSolidRect(obj.GetPosition().x, obj.GetPosition().y, obj.GetPosition().z, obj.GetSize(), obj.GetColor().r, obj.GetColor().g, obj.GetColor().b, obj.GetColor().a);
	//obj에 있는 정보를 Get(가져옴) x값,y값,z값,size,color

	
	//g_Renderer->DrawSolidRect(100, 100, 0,4, 1, 0, 1, 1);

	glutSwapBuffers();
}

void Idle(void)
{
	RenderScene();
	for (auto d : v) d->update();
}

void MouseInput(int button, int state, int x, int y)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		float w = 500;
		float h = 500;
		Position pos(x, y, 0.0f);
		//pos.x = (x - w / 2.0f) * (1.0f / (w / 2.0f));
		//pos.y = -(y - h / 2.0f) * (1.0f / (h / 2.0f));

		Object* obj = new Object(Position(pos.x, pos.y, pos.z), 4, Color(1, 0, 1, 1));
		//포괄적인게 하나 필요함. 중요함
		v.emplace_back(obj);
}
	RenderScene();
}

void KeyInput(unsigned char key, int x, int y)
{
	RenderScene();
}

void SpecialKeyInput(int key, int x, int y)
{
	RenderScene();
}

int main(int argc, char **argv)
{
	Object* obj = new Object(Position(0.0, 0.0f, 0.0f), 4, Color(1, 0, 1, 1)); 
	//굳이 전역변수로 할필요가 없는것은 전역변수에 선언한 벡터에다가 넣을것이기 때문에 main문에다 선언

																 
	v.emplace_back(obj);
	//복사본 없는 push back


	// Initialize GL things
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0); //창이 틀어지는 위치 조정
	glutInitWindowSize(500, 500); //창 사이즈
	glutCreateWindow("Game Software Engineering KPU");
	
	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))
	{
		std::cout << " GLEW Version is 3.0\n ";
	}
	else
	{
		std::cout << "GLEW 3.0 not supported\n ";
	}

	// Initialize Renderer
	g_Renderer = new Renderer(500, 500);
	if (!g_Renderer->IsInitialized())
	{
		std::cout << "Renderer could not be initialized.. \n";
	}

	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyInput);

	glutMainLoop();

	delete g_Renderer;

    return 0;
}

