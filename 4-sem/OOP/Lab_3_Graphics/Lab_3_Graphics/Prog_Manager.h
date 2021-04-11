#pragma once
#include "Map.h"
#include <string>
#include <SFML/Graphics.hpp>

class Prog_Manager
{
public:
	Map map;
	Prog_Manager();
	RenderWindow window;
	std::vector <Figure> traccer;
	bool movement_traccer = false;
	void WindowCheck();
	void Draw();
	int Main();

	int AddingObj();
	int AddingPoly();
	int AddingCircle();
	int AddingLine();

	int ChoosingObj();
	void Move(int num);
	void Scale(int num);
	void Agregat(int num);
	void Delete(int num);
	int ObjSettings(int num);
	void TrajectoryMovement(int num);

	void ChangeColor_(int num);
	
	int GetKey();
	int GetKeyDown();
	int Save();
	int Load();
};

