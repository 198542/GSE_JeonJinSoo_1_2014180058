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
#include "Object.h" //�ڷ����� ����
#include "SceneMgr.h"
#include "Renderer.h"


vector<Object*> v;
//���Ͱ����ٰ� ���콺 Ŭ���� ���� �����ϱ����� ���� ����
//�����͸� �ذ��� call by value ����� call by referenc

Renderer *g_Renderer = NULL;

SceneMgr g_SceneMgr;

void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);

	// Renderer Test
	for (int i = 0; i < 50; ++i) { //������ �̱� ������ . �̾ƴ϶� -> ����Ŵ
		g_Renderer->DrawSolidRect(g_SceneMgr.Get_object()[i].GetPosition().x, g_SceneMgr.Get_object()[i].GetPosition().y,
			g_SceneMgr.Get_object()[i].GetPosition().z,
			g_SceneMgr.Get_object()[i].GetSize(), g_SceneMgr.Get_object()[i].GetColor().r,
			g_SceneMgr.Get_object()[i].GetColor().g, g_SceneMgr.Get_object()[i].GetColor().b, g_SceneMgr.Get_object()[i].GetColor().a);
	}
	g_SceneMgr.Update();
	//g_Renderer->DrawSolidRect(obj.GetPosition().x, obj.GetPosition().y, obj.GetPosition().z, obj.GetSize(), obj.GetColor().r, obj.GetColor().g, obj.GetColor().b, obj.GetColor().a);
	//obj�� �ִ� ������ Get(������) x��,y��,z��,size,color


	//g_Renderer->DrawSolidRect(100, 100, 0,4, 1, 0, 1, 1);

	glutSwapBuffers();
}

void Idle(void)
{
	RenderScene();
	g_SceneMgr.Update();
}

void MouseInput(int button, int state, int x, int y)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		float w = 500.0;
		float h = 500.0;
		Position pos((float)x - 250.0, 250.0 - (float)y, 0.0f);
		//���콺 ������ ���� ����


		Object* obj = new Object(Position(pos.x, pos.y, pos.z), 4, Color(1, 1, 1, 1));
		//�������ΰ� �ϳ� �ʿ���. �߿���
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
	//���� ���������� ���ʿ䰡 ���°��� ���������� ������ ���Ϳ��ٰ� �������̱� ������ main������ ����


	v.emplace_back(obj);
	//���纻 ���� push back


	// Initialize GL things
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0); //â�� Ʋ������ ��ġ ����
	glutInitWindowSize(500, 500); //â ������
	glutCreateWindow("Game Software Engineering KPU");

	glewInit();
	g_SceneMgr.Init();

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

