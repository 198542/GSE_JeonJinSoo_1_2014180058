#pragma once
#include "newObject.h"
#include "Renderer.h"

const int Max = 11;

class Scene
{
public:
	void InitRenderer() { my_renderer = new Renderer(500, 500); }
	Scene()
	{
		for (int i = 0; i < Max; ++i)
		{
			my_opject[i] = nullptr;
		}

		this->InitRenderer();
		if (!my_renderer->IsInitialized())
		{
			std::cout << "Renderer could not be initialized.. \n";
		}

		buildingpicture = my_renderer->CreatePngTexture(".\\Resource\\castle.png");
		
		
		my_opject[0] = new Object(count,-1,OBJECT_BUILDING, 0, 0, 0, BUILDING_SIZE, buildingpicture);


		count += 1;
		my_bulletime = GetTickCount(); // 현재시간 저장

	}	
	~Scene() { delete my_renderer; } // 할당한 메모리 해제
	void Collion();
	void addObj(float x, float y, float z, float s);
	void update(float elapsedTime);
	void Render();
	void CreateBullet();
	void DeleteObject();

	void BuildingRender(Renderer& g_Renderer);

	int loadImage(char* path) { return my_renderer->CreatePngTexture(path); }
private:
	Object *my_opject[Max];
	int count = 0;

	int buildingpicture;
	
	int my_lifetest;
	Renderer* my_renderer;
	std::vector<Object> my_bullet; // 총알을 담을 객체
	DWORD my_bulletime; // 총알을 일정 시간 마다 생성하기 위한 시간 변수
};
