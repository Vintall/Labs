#include <iostream>
#include <string>
#include <windows.h>
#include <ctime>;
using namespace std;

int main();
void SUM();
void PRODUCT();
void MAX();
void CountOdd();
void Parrot2();
void Fibonacci();
void HIT2();
void Factorial();

void SUM()
{
	int a, sum = 0;
	cout << endl << "Вводите целые числа одно за другим, признак конца - 0" << endl;
	cin >> a;
	while (a != 0)
	{
		sum += a;
		cin >> a;
	}
	cout << "Sum = " << sum;

	cout << endl << "нажмите ENTER для выхода в главное меню" << endl;
	string aa;
	cin.ignore();
	getline(cin, aa);
}

void PRODUCT()
{
	int a, pr = 1;
	cout << endl << "Вводите целые числа одно за другим, признак конца - 0" << endl;
	cin >> a;
	while (a != 0)
	{
		if (a % 2 == 0)
			pr *= a;
		cin >> a;
	}
	cout << "Произведение = " << pr;

	cout << endl << "нажмите ENTER для выхода в главное меню" << endl;
	string aa;
	cin.ignore();
	getline(cin, aa);
}

void MAX()
{
	int a, max;
	cout << endl << "Вводите целые числа одно за другим, признак конца - 0" << endl;
	cin >> a;
	max = a;
	while (a != 0)
	{
		if (a > max)
			max = a;
		cin >> a;
	}
	cout << "Max = " << max;

	cout << endl << "нажмите ENTER для выхода в главное меню" << endl;
	string aa;
	cin.ignore();
	getline(cin, aa);
}

void CountOdd()
{
	int a, n = 0;
	cout << endl << "Вводите целые числа одно за другим, признак конца - 0" << endl;
	cin >> a;
	while (a != 0)
	{
		if (a % 2 != 0)
			n++;
		cin >> a;
	}
	cout << "Встретилось " << n << " нечётных чисел";

	cout << endl << "нажмите ENTER для выхода в главное меню" << endl;
	string aa;
	cin.ignore();
	getline(cin, aa);
}

void Parrot2()
{
	while (1)
	{
		cout << "Введите строку.\n";
		
		string str;
		cin.ignore();
		getline(cin, str);
		if (str == "") break;
		cout << endl << str;
	}
	cout << endl << "нажмите ENTER для выхода в главное меню" << endl;
	string aa;
	cin.ignore();
	getline(cin, aa);
}

void Fibonacci()
{
	int f_0 = 0, f_1 = 1, f_2;
	int n;
	cout << "Введите n = ";
	cin >> n;
	cout << endl;
	if (n >= 2)
	{
		for (int i = 2; i <= n; i++)
		{
			f_2 = f_0 + f_1;
			f_0 = f_1;
			f_1 = f_2;
		}

		cout << "F(" << n << ") = " << f_2;

		cout << endl << "нажмите ENTER для выхода в главное меню" << endl;
		string aa;
		cin.ignore();
		getline(cin, aa);
	}
	else
	{
		cout << "N может быть только >= 2";
		Fibonacci();
	}
	
}

void HIT2()
{
	srand(time(NULL));

	srand(time(NULL));
	
	double c_x, c_y, c_r, x, y;
	double length;
	c_x = rand() % 100;
	c_y = rand() % 100;
	c_r = rand() % 49 + 1;

	cout << endl << "Попробуйте попасть в случайно заданую окружность." << endl << "Координаты окружности ((0, 100),(0, 100)) Радиус (1, 50)";

	cout << endl;
	cout << "Введите X ?= ";
	cin >> x;
	cout << endl;
	cout << "Введите Y ?= ";
	cin >> y;
	cout << endl;


	length = sqrt(pow(x - c_x, 2) + pow(y - c_y, 2));
	if (length > c_r)
	{
		cout << "Мимо. Попробуйте ещё раз";

		cout << endl;
		cout << "Введите X ?= ";
		cin >> x;
		cout << endl;
		cout << "Введите Y ?= ";
		cin >> y;
		cout << endl;

		while (1)
		{
			double length1 = sqrt(pow(x - c_x, 2) + pow(y - c_y, 2));
			if (length1 < c_r)
			{
				cout << "Поздравляем! Вы попали в окружность. С координатой (" << c_x << ", " << c_y << ") и радиусом " << c_r << endl;
				break;
			}
			else if(length1 < length)
			{
				cout << "Теплее" << endl;

				length = length1;
			}
			else if (length1 > length)
			{
				cout << "Холоднее" << endl;
				
				length = length1;
			}
			if(length1 == length)
			{
				
			}
			cout << endl;
			cout << "Введите X ?= ";
			cin >> x;
			cout << endl;
			cout << "Введите Y ?= ";
			cin >> y;
			cout << endl;
		}
	}
	else
	{
		cout << "Поздравляем! Вы попали в окружность. С координатой (" << c_x << ", " << c_y << ") и радиусом " << c_r << "с первой попытки" << endl;
	}
	
	cout << endl << "нажмите ENTER для выхода в главное меню" << endl;
	string aa;
	cin.ignore();
	getline(cin, aa);
}

void Factorial()
{
	int n, fak = 1;
	cout << endl << "Для вычисления N! введите:" << endl << "N = ";
	cin >> n;
	while (n != 0)
	{
		fak *= n;
		n--;
	}
	cout << endl << "N! = " << fak;
	cout << endl << "нажмите ENTER для выхода в главное меню" << endl;
	string aa;
	cin.ignore();
	getline(cin, aa);
}
int ii = 1;
void MainMenu()
{
	while (ii)
	{
		system("cls");
		cout << endl << "Выберите программу, после чего введите соответствующий номер и нажмите ENTER." << endl;
		cout << "1.SUM" << endl << "2.PRODUCT" << endl << "3.MAX" << endl << "4.CountOdd" << endl << "5.Parrot2" << endl << "6.Fibonacci" << endl << "7.HIT2" << endl << "8.Factorial" << endl;
		cout << "Для выхода из программы введите 0" << endl;
		int n;
		cin >> n;
		switch (n)
		{
		default:
			ii = 0;
			break;
		case 0:
			ii = 0;
			break;
		case 1:
			SUM();
			break;
		case 2:
			PRODUCT();
			break;
		case 3:
			MAX();
			break;
		case 4:
			CountOdd();
			break;
		case 5:
			Parrot2();
			break;
		case 6:
			Fibonacci();
			break;
		case 7:
			HIT2();
			break;
		case 8:
			Factorial();
			break;
		}
		MainMenu();
	}
}


int main()
{
	system("cls");
	setlocale(LC_ALL, "Russian");

	MainMenu();
}