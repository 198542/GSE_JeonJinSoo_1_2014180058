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

#include "Renderer.h"


vector<Object*> v;
//���Ͱ����ٰ� ���콺 Ŭ���� ���� �����ϱ����� ���� ����
//�����͸� �ذ��� call by value ����� call by referenc

Renderer *g_Renderer = NULL;

void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);

	// Renderer Test
	for (auto d : v) { //������ �̱� ������ . �̾ƴ϶� -> ����Ŵ
		g_Renderer->DrawSolidRect(d->GetPosition().x, d->GetPosition().y, d->GetPosition().z,
			d->GetSize(), d->GetColor().r, d->GetColor().g, d->GetColor().b, d->GetColor().a);
		d->update();
	}
	//g_Renderer->DrawSolidRect(obj.GetPosition().x, obj.GetPosition().y, obj.GetPosition().z, obj.GetSize(), obj.GetColor().r, obj.GetColor().g, obj.GetColor().b, obj.GetColor().a);
	//obj�� �ִ� ������ Get(������) x��,y��,z��,size,color

	
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

