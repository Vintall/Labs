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
	void WindowCheck();
	void Draw();
	int Main();

	int AddingObj();
	int AddingPoly();
	int AddingCircle();
	int AddingLine();

	int ChoosingObj();
	int ObjSettings();

	int ChangeColor();
	
	int GetKey();
	int GetKeyDown();
	int Save();
	int Load();
};

