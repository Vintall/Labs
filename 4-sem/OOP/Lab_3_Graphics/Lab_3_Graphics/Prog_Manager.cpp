#include "Prog_Manager.h"

#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

/*
CODE LIST

-1 Exit
0 Main()     
1 AddingObj     +
2 SelectingObj  +
3 Save          
4 Load          
5 AddingPoly()  
6 AddingCircle()
7 AddingLine()  

*/

Prog_Manager::Prog_Manager()
{
	map = Map();
	map.AddFigure("First_Poly", Vector2f(100, 100), 5, 30);
	map.obj[0].shape.conv.setPosition(map.obj[0].pos);
	cout << map.obj[0].shape.conv.getPosition().x << " " << map.obj[0].shape.conv.getPosition().y << "Mark 2"<< endl;
	int menu_num = 0;

	window.create(VideoMode(500, 300), "Lab_3_Ilyashenko");
	View view(Vector2f(0.f, 0.f), Vector2f(5000.f, 3000.f));
	window.setView(view);
	window.setFramerateLimit(60);

	while (menu_num != -1)
	{
		if (window.isOpen())
		{
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
			}

			window.clear(Color::Red);
			Draw();
			window.display();
		}

		system("cls");
		switch (menu_num)
		{
		case 0:
			menu_num = Main();
			break;
		case 1:
			menu_num = AddingObj();
			break;
		case 2:
			menu_num = ChoosingObj();
			break;
		case 3:
			menu_num = Save();
			break;
		case 4:
			menu_num = Load();
			break;
		case 5:
			menu_num = AddingPoly();
			break;
		case 6:
			menu_num = AddingCircle();
			break;
		case 7:
			menu_num = AddingLine();
			break;

		default:
			menu_num = -1;
			break;
		}
	}
	exit(1);
}
bool key[256];
bool key_sw[256];
int Prog_Manager::GetKey()
{
	for (int i = 0; i < 256; i++)
	{
		if (GetAsyncKeyState(i))
			key[i] = 1;
		else
			key[i] = 0;
	}
	return 0;
}
int Prog_Manager::GetKeyDown()
{
	for (int i = 37; i <= 40; i++)
	{
		if (!key_sw[i] && GetAsyncKeyState(i))
		{
			key[i] = 1;
			key_sw[i] = 1;
		}
		else if (key_sw[i] && GetAsyncKeyState(i))
		{
			key[i] = 0;
		}
		else if (!GetAsyncKeyState(i))
		{
			key[i] = 0;
			key_sw[i] = 0;
		}
	}
	return 0;
}
void SetColor(int text)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)(0 | text));
}
int ever_color = 14;
int chosen_color = 4;
void MenuPrinter(string text, bool cursor)
{
	if (cursor)
	{
		SetColor(chosen_color);
		cout << text << endl;
		SetColor(ever_color);
	}
	else cout << text << endl;
}
int Prog_Manager::Main()
{
	int choice = 1;
	while (1)
	{
		if (window.isOpen())
		{
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
			}

			window.clear(Color::Red);
			Draw();
			window.display();
		}

		system("cls");

		MenuPrinter("Выйти", choice == 1);
		MenuPrinter("Добавить объект", choice == 2);
		MenuPrinter("Выбрать объект", choice == 3);
		MenuPrinter("Записать в файл", choice == 4);
		MenuPrinter("Считать с файла", choice == 5);
		
		while (1)
		{
			GetKeyDown();
			if (key[38]) // UP
			{
				if (choice != 1) 
					choice--;
				break;
			}
			else if (key[39]) // RIGHT
			{
				if (choice == 1) 
					return -1;
				else if (choice == 2) 
					return 1;
				else if (choice == 3) 
					return 2;
				else if (choice == 4) 
					return 3;
				else if (choice == 5) 
					return 4;
			}
			else if (key[40]) // DOWN
			{ 
				if (choice != 5) 
					choice++; 
				break; 
			}
		}
	}
}
int Prog_Manager::AddingObj()
{
	int choice = 1;
	while (1)
	{
		if (window.isOpen())
		{
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
			}

			window.clear(Color::Red);
			Draw();
			window.display();
		}

		system("cls");

		MenuPrinter("Выйти",					choice == 1);
		MenuPrinter("Назад",					choice == 2);
		MenuPrinter("Добавить Многоугольник",	choice == 3);
		MenuPrinter("Добавить Круг",			choice == 4);
		MenuPrinter("Добавить Отрезок",			choice == 5);

		while (1)
		{
			GetKeyDown();
			if (key[38]) // UP
			{ 
				if (choice != 1) 
					choice--; 
				break; 
			}
			else if (key[39]) // RIGHT
			{
				if (choice == 1) 
					return -1;
				else if (choice == 2) 
					return 0;
				else if (choice == 3) 
					return 5;
				else if (choice == 4) 
					return 6;
				else if (choice == 5) 
					return 7;
			}
			else if (key[40]) // DOWN
			{ 
				if (choice != 5) 
					choice++; 
				break; 
			}
		}
	}
}
int Prog_Manager::AddingPoly()
{
	if (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear(Color::Red);
		Draw();
		window.display();
	}

	int angle_count, radius;
	string name;
	cout << "Введите имя: "; cin >> name;
	cout << endl << endl;
	cout << "Введите кол-во углов (>=3): "; cin >> angle_count; 
	cout << endl << endl;
	cout << "Введите внешний радиус: "; cin >> radius; 
	cout << endl << endl;
	map.AddFigure(name, Vector2f(0, 0), angle_count, radius);
	return 0;
}
int Prog_Manager::AddingCircle()
{
	if (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear(Color::Red);
		Draw();
		window.display();
	}

	int radius;
	string name;
	cout << "Введите имя: "; cin >> name;
	cout << endl << endl;
	cout << "Введите радиус: "; cin >> radius; cout << endl; cout << endl;
	map.AddFigure(name, Vector2f(0, 0), radius);
	return 0;
}
int Prog_Manager::AddingLine()
{
	if (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear(Color::Red);
		Draw();
		window.display();
	}

	Vector2f p1, p2;
	string name;
	cout << "Введите имя: "; cin >> name;
	cout << endl << endl;
	cout << "Введите координаты первой точки:" << endl << "x: "; cin >> p1.x; cout << "y: "; cin >> p1.y; cout << endl; cout << endl;
	cout << "Введите координаты второй точки:" << endl << "x: "; cin >> p2.x; cout << "y: "; cin >> p2.y; cout << endl; cout << endl;
	map.AddFigure(name, p1, p2);
	return 0;
}
int Prog_Manager::ChoosingObj()
{
	if (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear(Color::Red);
		Draw();
		window.display();
	}

	for (int i = 0; i < map.obj.size(); i++)
	{
		cout << i << endl; 
	}
	system("Pause");
	return 0;
}
int Prog_Manager::ObjSettings()
{
	return 0;
}
int Prog_Manager::ChangeColor()
{
	return 0;
}
int  Prog_Manager::Save()
{
	return 0;
}
int  Prog_Manager::Load()
{
	return 0;
}
void Prog_Manager::WindowCheck()
{

}
void Prog_Manager::Draw()
{
	for (int i = 0; i < map.obj.size(); i++)
	{
		window.draw(map.obj[i].shape.conv);
	}
}