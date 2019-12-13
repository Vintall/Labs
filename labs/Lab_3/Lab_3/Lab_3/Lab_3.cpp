#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main();
void ABS();
void Max0();
void AB();
void ABC();
void ABCD();
void HIT();
void HIT2();
void MENU();

void ABS()
{
	cout << "\nВведите число X ?=";
	int x;
	cin >> x;
	cout << '|' << x << '|';
	if (x < 0) x *= -1;
	cout << '=' << x << endl;

	cout << endl << "нажмите ENTER для выхода в главное меню" << endl;
	string aa;
	cin.ignore();
	getline(cin, aa);
}
void Max0()
{
	int a, b;
	cout << endl;
	cout << "Введите А ?= ";
	cin >> a;
	cout << endl;
	cout << "Введите B ?= ";
	cin >> b;
	cout << endl;
	cout << "A= " << a << " B= " << b;
	cout << endl;
	cout << "Max(" << a << "," << b << ")=";
	if (a <= b)
		cout << b;
	else cout << a;
	cout << endl;

	cout << endl << "нажмите ENTER для выхода в главное меню" << endl;
	string aa;
	cin.ignore();
	getline(cin, aa);
}
void AB()
{
	int a, b;
	cout << endl;
	cout << "Введите А ?= ";
	cin >> a;
	cout << endl;
	cout << "Введите B ?= ";
	cin >> b;
	cout << endl;
	cout << "A= " << a << " B= " << b;
	cout << endl;
	if (a > b)
	{
		int c;
		c = a;
		a = b;
		b = c;
	}
	cout << "A= " << a << " B= " << b;
	cout << endl;

	cout << endl << "нажмите ENTER для выхода в главное меню" << endl;
	string aa;
	cin.ignore();
	getline(cin, aa);
}
void ABC()
{
	int a, b, c;
	cout << endl;
	cout << "Введите А ?= ";
	cin >> a;
	cout << endl;
	cout << "Введите B ?= ";
	cin >> b;
	cout << endl;
	cout << "Введите C ?= ";
	cin >> c;
	cout << endl;
	cout << "A= " << a << " B= " << b << " C= " << c;
	cout << endl;

	int i = 1;
	while (i)
	{
		if (a > b)
		{
			int q;
			q = a;
			a = b;
			b = q;
		}
		if (b > c)
		{
			int q;
			q = b;
			b = c;
			c = q;
		}
		if (a <= b && b <= c)
		{
			i = 0;
		}
	}
	cout << "A= " << a << " B= " << b << " C= " << c;
	cout << endl;

	cout << endl << "нажмите ENTER для выхода в главное меню" << endl;
	string aa;
	cin.ignore();
	getline(cin, aa);
}
void ABCD()
{
	int a, b, c, d;
	cout << endl;
	cout << "Введите А ?= ";
	cin >> a;
	cout << endl;
	cout << "Введите B ?= ";
	cin >> b;
	cout << endl;
	cout << "Введите C ?= ";
	cin >> c;
	cout << endl;
	cout << "Введите D ?= ";
	cin >> d;
	cout << endl;
	cout << "A= " << a << " B= " << b << " C= " << c << " D= " << d;
	cout << endl;

	int i = 1;
	while (i)
	{
		if (a > b)
		{
			int q;
			q = a;
			a = b;
			b = q;
		}
		if (b > c)
		{
			int q;
			q = b;
			b = c;
			c = q;
		}
		if (c > d)
		{
			int q;
			q = c;
			c = d;
			d = q;
		}
		if (a <= b && b <= c && c <= d)
		{
			i = 0;
		}
	}

	cout << "A= " << a << " B= " << b << " C= " << c << " D= " << d;
	cout << endl;

	cout << endl << "нажмите ENTER для выхода в главное меню" << endl;
	string aa;
	cin.ignore();
	getline(cin, aa);
}
struct Circle
{
	int x, y, radius;

	Circle(double x,double y,double r)
	{
		this->x = (int)x;
		this->y = (int)y;
		this->radius = (int)r;
	}
};
void HIT()
{
	srand(time(NULL));
	Circle circle = Circle(rand() % 100, rand() % 100, rand() % 50);
	int x, y;
	cout << endl;
	cout << "Введите X ?= ";
	cin >> x;
	cout << endl;
	cout << "Введите Y ?= ";
	cin >> y;
	cout << endl;

	cout << "Точка (" << x << "," << y << ") ";
	
	if (sqrt(pow(x - circle.x, 2) + pow(y = circle.y, 2)) > circle.radius)
	{
		cout << "НЕ ";
	}
	cout << "попадает в круг с центром в точке (" << circle.x << ',' << circle.y << ") радиуса " << circle.radius;
	cout << endl;

	cout << endl << "нажмите ENTER для выхода в главное меню" << endl;
	string aa;
	cin.ignore();
	getline(cin, aa);
}
void HIT2()
{
	struct Point
	{
		Point()
		{
		}
		double x, y;
	};
	Point points[4];
	cout << endl << "Введите X точки А ?= ";			cin >> points[0].x;
	cout << endl << "Введите Y точки А ?= ";			cin >> points[0].y;
	cout << endl << "Введите X точки В ?= ";			cin >> points[1].x;
	cout << endl << "Введите Y точки В ?= ";			cin >> points[1].y;
	cout << endl << "Введите X точки С ?= ";			cin >> points[2].x;
	cout << endl << "Введите Y точки С ?= ";			cin >> points[2].y;
	cout << endl << "Введите X точки O ?= ";			cin >> points[3].x;
	cout << endl << "Введите Y точки O ?= ";			cin >> points[3].y;
	bool is_triangle = true;
	for (int i = 1; i <= 2; i++)
		for (int j = 1; j <= 2; j++)
			if (points[i].x == points[i - 1].x && points[i].y == points[i - 1].y)
				is_triangle = false;

	if (is_triangle)
	{
		double k1, k2, b1, b2;
		k1 = 0;
		b1 = points[3].y;
		int count = 0;
		double x;
		for (int i = 1; i <= 3; i++)
		{
			int k = i - 1;
			int l = i;
			if (l == 3) l = 0;

			if (points[l].x == points[k].x && points[l].x >= points[3].x)
			{
				if (points[l].y < points[k].y && points[3].y >= points[l].y && points[3].y <= points[k].y) 
					count++;
				else if (points[l].y > points[k].y&& points[3].y <= points[l].y && points[3].y >= points[k].y) 
					count++;
			}
			else if ((points[l].y == points[k].y && points[3].y == points[l].y) && (points[k].x > points[3].x || points[l].x > points[3].x))
			{
				count++;
			}
			else
			{
				k2 = (points[l].y - points[k].y) / (points[l].x - points[k].x);
				b2 = points[k].y - ((points[k].x * (points[l].y - points[k].y)) / (points[l].x - points[k].x));
				x = (b2 - b1) / (k1 - k2);
				if (x >= points[3].x)
				if (points[l].x < points[k].x && x >= points[l].x && x <= points[k].x) 
					count++;
				else if (points[l].x > points[k].x&& x <= points[l].x && x >= points[k].x) 
					count++;
			}
		}
		if (count % 2 == 0) cout << endl << "Точка О не входит в треугольник";
		else cout << endl << "Точка О входит в треугольник";
	}

	cout << endl << "нажмите ENTER для выхода в главное меню" << endl;
	string aa;
	cin.ignore();
	getline(cin, aa);
}
void MENU()
{
	cout << endl << "Работает информационная система Лицея Информационных Технологий";
	cout << endl << "    1. Новости дня";
	cout << endl << "    2. Анекдот недели";
	cout << endl << "    3. Автора!!!";
	cout << endl << "Введите соответствующий номер и нажмите ENTER." << endl;
	int n; cin >> n;
	switch (n)
	{
	default:
		system("cls");
		cout << endl << "Ошибка ввода, попробуйте ещё раз";
		MENU();
		break;
	case 1:
		cout << endl << "Новости дня";
		break;
	case 2:
		cout << endl << "Анекдот недели";
		break;
	case 3:
		cout << endl << "Автора!!!" << endl;
		break;
	}

	cout << endl << "нажмите ENTER для выхода в главное меню" << endl;
	string aa;
	cin.ignore();
	getline(cin, aa);
}

void MainMenu()
{
	int ii = 1;
	while (ii)
	{
		system("cls");
		cout << endl << "Выберите программу, после чего введите соответствующий номер и нажмите ENTER." << endl;
		cout << "1.ABS" << endl << "2.Max0" << endl << "3.AB" << endl << "4.ABC" << endl << "5.ABCD" << endl << "6.HIT" << endl << "7.HIT2" << endl << "8.MENU" << endl;
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
			ABS();
			break;
		case 2:
			Max0();
			break;
		case 3:
			AB();
			break;
		case 4:
			ABC();
			break;
		case 5:
			ABCD();
			break;
		case 6:
			HIT();
			break;
		case 7:
			HIT2();
			break;
		case 8:
			MENU();
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