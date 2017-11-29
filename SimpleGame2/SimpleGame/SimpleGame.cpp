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
#include "newObject.h"
#include "SceneMgr.h"
#include "Renderer.h"
#include <chrono>
Scene *g_Scene = NULL;
DWORD g_prevTime = 0;
bool mousecheck = false;
void RenderScene(void)
{
	DWORD currTime = timeGetTime();
	DWORD elapsedTime = currTime - g_prevTime; //g_prevTime 를 빼주어야함
	g_prevTime = currTime;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Renderer Test
	//g_Renderer->DrawSolidRect(0, 0, 0, 4, 1, 0, 1, 1);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	g_Scene->update((float)elapsedTime);
	g_Scene->Render();
	glutSwapBuffers();
	
	//g_prevTime = currTime;
}

void Idle(void)
{
	RenderScene();
}

void MouseInput(int button, int state, int x, int y)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		mousecheck = true;
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		if (mousecheck)
		{
			if (400 - y > 0) return;
			g_Scene->addObj(BLUE, x - 250, 400 - y, 0, 20);
		}
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
	
	// Initialize GL things
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0); //창이 틀어지는 위치 조정
	glutInitWindowSize(500, 800); //창 사이즈
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
	//g_Renderer = new Renderer(500, 500);
	/*
	if (!g_Renderer->IsInitialized())
	{
		std::cout << "Renderer could not be initialized.. \n";
	}
	*/
	g_Scene = new Scene();

	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyInput);


	g_prevTime = timeGetTime();
	glutMainLoop();

	delete g_Scene;
	return 0;
}

