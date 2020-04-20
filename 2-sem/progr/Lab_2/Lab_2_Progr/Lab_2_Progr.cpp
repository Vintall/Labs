#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

int** a, ** b, ** c, n = 0;

void FillArray();
void Task1();
void Task2();
void Task3();
void Menu();
void ShowArray();

//ofstream out("H:\\IT\Mine\\Labs\2_semester\\Lab_2_Progr\\Out.txt", ios::out);


void ShowArray()
{
	if (n > 5)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << a[i][j] << " ";
			cout << "| ";
			for (int k = 0; k < n; k++)
				cout << b[i][k] << " ";
			cout << endl << endl;
		}
	}
}

void FillArray()
{
	
	short k1;
	cout << "Выберите способ ввода:" << endl;
	cout << "1) С консоли" << endl;
	cout << "2) С файла" << endl;
	cin >> k1;
	n = 0;
	
	if (k1 == 1)
	{
		cout << "Введите n (Порядок квадратной матрицы) (n>=6) - "; cin >> n; cout << endl;
		if (n < 6)
		{
			cout << "Ошибка ввода. Для выхода в главное меню нажмите ENTER";
			system("Pause");
			return;
		}
		a = new int* [n];
		b = new int* [n];
		for (int i = 0; i < n; i++)
		{
			a[i] = new int[n];

			for (int j = 0; j < n; j++)
				cin >> a[i][j];
		}
		for (int i = 0; i < n; i++)
		{
			b[i] = new int[n];

			for (int j = 0; j < n; j++)
				cin >> b[i][j];
		}
	}
	else if(k1 == 2)
	{
		ifstream in("C:\\Users\\Vintall\\Desktop\\Lab_2_Progr\\In.txt");
		cout << "Нажмите ENTER, чтобы считать информацию с файла (In.txt)" << endl;
		system("Pause");
		in >> n;
		if (n < 6)
		{
			cout << "Ошибка ввода. Для выхода в главное меню нажмите ENTER";
			system("Pause");
			return;
		}
		a = new int* [n];
		b = new int* [n];

		for (int i = 0; i < n; i++)
			a[i] = new int[n];

		for (int i = 0; i < n; i++)
			b[i] = new int[n];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				in >> a[i][j];
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				in >> b[i][j];
		
	}
	else
	{
		cout << "Ошибка ввода" << endl;
		return;
	}
	ShowArray();

	cout << "Для выхода в главное меню нажмите ENTER" << endl;
	system("Pause");
}
void Task1()
{
	ShowArray();
	if (n > 5)
	{
		int max_a = a[0][0], max_b = b[0][0], min_a = max_a, min_b = max_b;
		for (int i = 0; i < n; i++)
		{
			if (max_a < a[i][i]) max_a = a[i][i];
			if (max_b < b[i][i]) max_b = b[i][i];
			if (min_a > a[i][i]) min_a = a[i][i];
			if (min_b > b[i][i]) min_b = b[i][i];

		}
		cout << "Максимальный элемент диагонали матрицы А - " << max_a << endl;
		cout << "Минимальный элемент диагонали матрицы А - " << min_a << endl;

		cout << "Максимальный элемент диагонали матрицы B - " << max_b << endl;
		cout << "Минимальный элемент диагонали матрицы B - " << min_b << endl;

		cout << endl << "Для выхода в главное меню нажмите ENTER" << endl;
		system("Pause");
	}
	else
	{
		cout << "Вы не ввели массив. Для выхода в главное меню нажмите ENTER" << endl;
		system("Pause");
	}
}
void Task2()
{
	if (n > 5)
	{
		c = new int* [n];
		for (int i = 0; i < n; i++)
			c[i] = new int[n];
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				c[i][j] = a[j][i];
		cout << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << a[i][j] << " ";
			
			cout << "| ";

			for (int j = 0; j < n; j++)
				cout << c[i][j] << " ";
			cout << endl;
		}
		cout << endl << "Для выхода в главное меню нажмите ENTER" << endl;
		system("Pause");
	}
	else
	{
		cout << "Вы не ввели массив. Для выхода в главное меню нажмите ENTER" << endl;
		system("Pause");
	}
}
void Task3()
{
	if (n > 5)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << a[i][j] << " ";
			cout << endl;
		}
		cout << endl;

		int min_ind[2] = { 0,0 };
		for (int j = 0; j < n; j++)
			for (int i = 0; i < n; i++)
				if (a[min_ind[0]][min_ind[1]] > a[i][j])
				{
					min_ind[0] = i;
					min_ind[1] = j;
				}
		for (int i = 1; i < n; i++)
		{
			if (a[i - 1][min_ind[1]] > a[i][min_ind[1]])
			{
				int buf = a[i - 1][min_ind[1]];
				a[i - 1][min_ind[1]] = a[i][min_ind[1]];
				a[i][min_ind[1]] = buf;
				i = 0;
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << a[i][j] << " ";
			cout << endl;
		}
		cout << endl;

		cout << endl << "Для выхода в главное меню нажмите ENTER" << endl;
		system("Pause");
	}
	else
	{
		cout << "Вы не ввели массив. Для выхода в главное меню нажмите ENTER" << endl;
		system("Pause");
	}
}
void Menu()
{
	system("cls");
	cout << "---------МЕНЮ---------" << endl;
	cout << "0) Выйти из программы" << endl;
	cout << "1) Заполнить массив"<< endl;
	cout << "2) Задача 1" << endl;
	cout << "3) Задача 2" << endl;
	cout << "4) Задача 3" << endl;
	cout << "Перейти к номеру - ";
	int n; cin >> n; cout << endl;
	switch (n)
	{
	case 0:
		exit(0);
		break;
	case 1:
		FillArray();
		Menu();
		break;
	case 2:
		Task1();
		system("cls");
		Menu();
		break;
	case 3:
		Task2();
		system("cls");
		Menu();
		break;
	case 4:
		Task3();
		system("cls");
		Menu();
		break;

	default:
		cout << "Ошибка ввода. Нажмите любую клавишу" << endl;
		system("Pause");
		system("cls");
		Menu();
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	Menu();
	return 0;
}