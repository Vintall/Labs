#pragma once
#include "Map.h"
#include <string>
#include <SFML/Graphics.hpp>

class Prog_Manager
{
public:
	Map map;
	Prog_Manager();
	Prog_Manager(std::string);
	RenderWindow window;
	std::vector <Figure> traccer;
	bool movement_traccer = false;
	std::string file_name;
	void WindowCheck();
	void Draw();
	int Main();
	void Controller();

	int AddingObj();
	int AddingPoly();
	int AddingCircle();
	int AddingStar();
	int AddElseFig();

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

