#include "Prog_Manager.h"

#include <iostream>
#include <Windows.h>
#include <string>
#include "Circle.h"

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

void Prog_Manager::WindowCheck()
{
	if (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear(Color(150, 150, 150, 255));
		Draw();
		window.display();
	}
}

Prog_Manager::Prog_Manager()
{
	map = Map();
	int menu_num = 0;

	window.create(VideoMode(1000, 600), "Lab_3_Ilyashenko");
	View view(Vector2f(0.f, 0.f), Vector2f(5000.f, 3000.f));
	window.setPosition(Vector2i(0, 0));
	window.setView(view);
	window.setFramerateLimit(60);

	//for (int i = 0; i < 2; i++)
	//	map.AddFigure(to_string(i), Vector2f(0, 0), 200);

	while (menu_num != -1)
	{
		WindowCheck();

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
	for (int i = 0; i < 256; i++)
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
void MenuPrinter(string text)
{
	cout << text << endl;
}
int Prog_Manager::Main()
{
	int choice = 1;
	while (1)
	{
		system("cls");

		MenuPrinter("Выйти",			choice == 1);
		MenuPrinter("Добавить объект",	choice == 2);
		MenuPrinter("Выбрать объект",	choice == 3);
		MenuPrinter("Записать в файл",	choice == 4);
		MenuPrinter("Считать с файла",	choice == 5);
		
		while (1)
		{
			WindowCheck();

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
		system("cls");

		MenuPrinter("Выйти",					choice == 1);
		MenuPrinter("Назад",					choice == 2);
		MenuPrinter("Добавить Многоугольник",	choice == 3);
		MenuPrinter("Добавить Круг",			choice == 4);
		MenuPrinter("Добавить Отрезок",			choice == 5);

		while (1)
		{
			WindowCheck();

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
	WindowCheck();

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
	WindowCheck();

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
	WindowCheck();
	
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
	int choice = 1;
	while (1)
	{
		system("cls");
		MenuPrinter("Выйти", choice == 1);
		MenuPrinter("Назад", choice == 2);
		for (int i = 0; i < map.obj.size(); i++)
		{
			MenuPrinter(map.obj[i].name, choice == i+3);
		}

		while (1)
		{
			WindowCheck();

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
				else
				{
					return ObjSettings(choice - 3);
				}
			}
			else if (key[40]) // DOWN
			{
				if (choice != map.obj.size()+2)
					choice++;
				break;
			}
		}
	}
}
//-----------------------
void Prog_Manager::Move(int num)
{
	system("cls");
	Vector2f slider;
	MenuPrinter("Left, Right, Up, Down - Перемещение");
	MenuPrinter("Ctrl - Подтвердить");

	while (1)
	{
		
		GetKey();
		slider = Vector2f(0, 0);

		if (key[37]) // LEFT
		{
			slider.x -= 20;
		}
		if (key[38]) // UP
		{
			slider.y -= 20;
		}
		if (key[39]) // RIGHT
		{
			slider.x += 20;
		}
		if (key[40]) // DOWN
		{
			slider.y += 20;
		}
		if (key[17])
		{
			key[17] = 0;
			key_sw[17] = 0;
			traccer.clear();
			return;
		}
		WindowCheck();
		if (movement_traccer)
		{
			if (slider.x != 0 || slider.y != 0)
			{
				traccer.push_back(Circle("", map.obj[num].shape.getPosition(), 20));
			}
		}

		map.obj[num].Move(slider);

		
	}
}
void Prog_Manager::Scale(int num)
{
	system("cls");
	float slider;
	MenuPrinter("Left, Right, Up, Down - Перемещение");
	MenuPrinter("Ctrl - Подтвердить");


	while (1)
	{
		WindowCheck();
		GetKey();
		slider = 0;

		if (key[37]) // LEFT
		{
			slider -= 0.02;
		}
		if (key[39]) // RIGHT
		{
			slider += 0.02;
		}
		if (key[17])
		{
			key[17] = 0;
			key_sw[17] = 0;
			return;
		}
		map.obj[num].Scale(slider);
	}
}
void Prog_Manager::Agregat(int num)
{
	int choice = 1;
	while (1)
	{
		int second_obj;
		system("cls");
		MenuPrinter("Назад", choice == 1);
		MenuPrinter("Агрегатировать с:");
		for (int i = 0; i < map.obj.size(); i++)
		{
			if (i == num) continue;
			if (i < num)
				MenuPrinter(map.obj[i].name, i + 2 == choice);
			if (i > num)
				MenuPrinter(map.obj[i].name, i + 1 == choice);
		}

		while (1)
		{
			WindowCheck();

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
					return;
				else
				{
					if (choice - 2 < num)
						second_obj = choice - 2;
					if (choice - 1 > num)
						second_obj = choice - 1;

					string name_;
					system("cls");
					cout << "Введите имя нового объекта: ";
					cin >> name_;
					
					Figure buf = Figure();
					buf.is_agregat = true;
					
					if (map.obj[num].is_agregat)
					{
						for (int i = 0; i < map.obj[num].obj.size(); i++)
						{
							buf.obj.push_back(map.obj[num].obj[i]);
							buf.obj[buf.obj.size() - 1].trajectory.clear();
						}
					}
					else
					{
						buf.obj.push_back(map.obj[num]);
						buf.obj[buf.obj.size() - 1].trajectory.clear();
					}

					if (map.obj[second_obj].is_agregat)
					{
						for (int i = 0; i < map.obj[second_obj].obj.size(); i++)
						{
							buf.obj.push_back(map.obj[second_obj].obj[i]);
							buf.obj[buf.obj.size() - 1].trajectory.clear();
						}
					}
					else
					{
						buf.obj.push_back(map.obj[second_obj]);
						buf.obj[buf.obj.size() - 1].trajectory.clear();
					}
					buf.name = name_;
					
					map.obj.push_back(buf);
					return;
				}
			}
			else if (key[40]) // DOWN
			{
				if (choice != map.obj.size())
					choice++;
				break;
			}
		}
	}
}
void Prog_Manager::Delete(int num)
{
	vector<Figure> buf = map.obj;
	map.obj.clear();
	for (int i = 0; i < buf.size(); i++)
	{
		if (i == num) continue;
		map.obj.push_back(buf[i]);
	}
	return;
}
//---------------------------
void Prog_Manager::ChangeColor_(int num)
{
	int choice = 1;
	while (1)
	{
		system("cls");
		int col[3];
		col[0] = map.obj[num].color[0];
		col[1] = map.obj[num].color[1];
		col[2] = map.obj[num].color[2];

		MenuPrinter("Ctrl - Подтвердить");
		MenuPrinter("R (" + to_string(col[0]) + ')', choice == 1);
		MenuPrinter("G (" + to_string(col[1]) + ')', choice == 2);
		MenuPrinter("B (" + to_string(col[2]) + ')', choice == 3);

		while (1)
		{
			WindowCheck();

			GetKeyDown();

			if (key[17])
			{
				key[17] = 0;
				key_sw[17] = 0;
				return;
			}

			if (key[38]) // UP
			{
				if (choice != 1)
					choice--;
				break;
			}
			if (key[40]) // DOWN
			{
				if (choice != 3)
					choice++;
				break;
			}
			const int rgb_slider_iter = 10;
			if (key[37])  // LEFT
			{
				if (choice == 1)
				{
					if (col[0] != 0)
						map.obj[num].ChangeCol(col[0] - rgb_slider_iter, col[1], col[2]);
				}
				else if (choice == 2)
				{
					if (col[1] != 0)
						map.obj[num].ChangeCol(col[0], col[1] - rgb_slider_iter, col[2]);
				}
				else if (choice == 3)
				{
					if (col[2] != 0)
						map.obj[num].ChangeCol(col[0], col[1], col[2] - rgb_slider_iter);
				}
				break;
			}
			if (key[39]) // RIGHT
			{
				if (choice == 1)
				{
					if (col[0] != 250)
						map.obj[num].ChangeCol(col[0] + rgb_slider_iter, col[1], col[2]);
				}
				else if (choice == 2)
				{
					if (col[1] != 250)
						map.obj[num].ChangeCol(col[0], col[1] + rgb_slider_iter, col[2]);
				}
				else if (choice == 3)
				{
					if (col[2] != 250)
						map.obj[num].ChangeCol(col[0], col[1], col[2] + rgb_slider_iter);
				}
				break;
			}
		}
	}
}

int Prog_Manager::ObjSettings(int num)
{
	int choice = 1;
	while (1)
	{
		system("cls");

		MenuPrinter("Выйти", choice == 1);
		MenuPrinter("Назад", choice == 2);
		MenuPrinter("Переместить", choice == 3);
		MenuPrinter("Деформировать (Scale)", choice == 4);
		MenuPrinter("Агрегатировать", choice == 5);
		MenuPrinter("Сменить цвет", choice == 6);
		MenuPrinter("Удалить", choice == 7);
		MenuPrinter("Переключить активность объекта [" + to_string(map.obj[num].is_drowable) + " => " + to_string(!map.obj[num].is_drowable) + ']', choice == 8);
		MenuPrinter("Восстановить изначальное состояние объекта", choice == 9); 
		MenuPrinter("Переключить след при перемещении [" + to_string(movement_traccer) + " => " + to_string(!movement_traccer) + ']', choice == 10);
		MenuPrinter("Повторить траекторию движения", choice == 11); 



		while (1)
		{
			WindowCheck();

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
				{
					return -1;
				}
				else if (choice == 2)
				{
					return 0;
				}
				else if (choice == 3)
				{
					Move(num);
					break;
				}
				else if (choice == 4)
				{
					Scale(num);
					break;
				}
				else if (choice == 5)
				{
					Agregat(num);
					break;
				}
				else if (choice == 6)
				{
					ChangeColor_(num);
					break;
				}
				else if (choice == 7)
				{
					Delete(num);
					return 2;
				}
				else if (choice == 8)
				{
					map.obj[num].is_drowable = !map.obj[num].is_drowable;
					break;
				}
				else if (choice == 9)
				{
					map.obj[num].ResetObject();
					return 2;
				}
				else if (choice == 10)
				{
					movement_traccer = !movement_traccer;
					break;
				}
				else if (choice == 11)
				{
					TrajectoryMovement(num);
					return 2;
				}
			}
			else if (key[40]) // DOWN
			{
				if (choice != 11)
					choice++;
				break;
			}
		}
	}
}
void Prog_Manager::TrajectoryMovement(int num)
{
	int choice = 1;
	int slider = 0; // -1 0 1

	int tr_count = map.obj[num].trajectory.size();
	int tr_cur = tr_count;

	while (1)
	{
		system("cls");
		MenuPrinter("Назад", choice == 1);
		if (slider == -1)
		{
			MenuPrinter("<==", choice == 2);
		}
		else if (slider == 0)
		{
			MenuPrinter("<=>", choice == 2);
		}
		else
		{
			MenuPrinter("==>", choice == 2);
		}

		while (1)
		{
			WindowCheck();
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
				{
					for (int i = tr_cur - 1; i < tr_count; i++)
						map.obj[num].TrajectoryForward(i);
					return;
				}
				else if (choice == 2)
				{
					if (slider == -1)
						tr_cur--;

					if (slider != 1)
						slider++;
					break;
				}
			}
			else if (key[40]) // DOWN
			{
				if (choice != 2)
					choice++;
				break;
			}
			else if (key[37]) // LEFT
			{
				if (choice == 2)
				{
					if (slider == 1)
						tr_cur++;

					if (slider != -1)
						slider--;
				}
				break;
			}
			if (slider == -1)
			{
				if (tr_cur != -1)
					tr_cur--;

				map.obj[num].TrajectoryBack(tr_cur);
			}
			else if (slider == 0)
			{

			}
			else
			{

				if (tr_cur != tr_count)
					tr_cur++;
				map.obj[num].TrajectoryForward(tr_cur);
			}
		}
	}
}

int  Prog_Manager::Save()
{
	return 0;
}
int  Prog_Manager::Load()
{
	return 0;
}

void Prog_Manager::Draw()
{
	for (int i = 0; i < map.obj.size(); i++)
	{
		if (map.obj[i].is_drowable)
			if (map.obj[i].is_agregat)
			{
				for (int j = 0; j < map.obj[i].obj.size(); j++)
					window.draw(map.obj[i].obj[j].shape);
			}
			else
			{
				window.draw(map.obj[i].shape);
			}
	}
	if (movement_traccer)
		for (int i = 0; i < traccer.size(); i++)
			window.draw(traccer[i].shape);
}