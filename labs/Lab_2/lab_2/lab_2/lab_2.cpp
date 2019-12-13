#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>

using namespace std;

string str1[10];
string str2[10];


void ANKETA2();
void Guess();
void HELLO2();
void HELLO3();
void Parrot();
void SWAP3();
void SWAP4();
void InitProgram();
void MainMenu();


int main()
{
	InitProgram();
	MainMenu();
	system("pause");
	return 0;
}


void ANKETA2()
{
	cout << "Задача ANKETA2\n";

	str2[0] = "Фамилия = ";
	str2[1] = "Имя = ";
	str2[2] = "Отчество = ";
	str2[3] = "Пол = ";
	str2[4] = "Дата рождения = ";
	str2[5] = "Адрес = ";
	str2[6] = "Номер телефона = ";
	str2[7] = "Место учебы = ";
	str2[8] = "Класс = ";
	str2[9] = "Хобби = ";

	for (int i = 0; i < 10; i++)
	{
		cout << str2[i]; cin >> str1[i]; cout << endl;
	}
	cout << "================================" << endl << endl;
	cout << "                    А Н К Е Т А\n";
	cout << "Фамилия                 Имя                  Отчество\n";
	cout << "-------                 ---                  --------\n";
	cout << str1[0] + "                 " + str1[1] + "                 " + str1[2] + "\n\n";
	cout << "Пол                     Дата рождения        Номер телефона\n";
	cout << "---                     -------------        --------------\n";
	cout << str1[3] + "                 " + str1[4] + "                 " + str1[6] + "\n";
}

void Guess()
{
	cout << "\n\nЗадача Guess\n\n";
	cout << "Загадайте число в пределах от 0 до 10000\n";
	double num; cin >> num;
	if (num < 0 && num>10000)
	{
		system("csl");
		cout << "Ошибка ввода. Попробуйте ещё раз\n";
		Guess();
	}
	else
	{
		cout << "Проведите данные операции\n";
		cout << "((x*5 + x)/3 + 4) /2 - 2 \n";
		Sleep(2000);
		double num2 = (num * 6 / 3 + 4) / 2 - 2;
		cout << "Это ваше число? = ";
		cout << num2;
	}
}

void HELLO2()
{
	cout << "\n\nЗадача HELLO2\n\n";

	cout << "Как вас зовут? = ";
	string name;
	cin >> name;
	cout << "\nЗдравствуйте, " + name;
}
void HELLO3()
{
	cout << "\n\nЗадача HELLO3\n\n";
	string name, study;
	int years;
	cout << "Как Вас зовут ? = ";
	cin >> name;
	cout << "\nСколько Вам лет ? = ";
	cin >> years;
	cout << "\nГде Вы учитесь ? = ";
	cin >> study;

	cout << "\n\nЗдравствуйте, " + name + '!' << endl;
	cout << "Поздравляем Вас, Вам всего " << years << " года, а Вы уже ведёте диалог с компьютером!\n";
	cout << study +" будeт гордиться Вами!";
}
void Parrot()
{
	cout << "\n\nЗадача Parrot\n\n";
	cout << "Введите строку.\n";
	string str;
	cin.ignore();
	getline(cin, str);
	cout << str;
}
void SWAP3()
{
	cout << "\n\nЗадача SWAP3\n\n";
	string a, b, c;
	cout << "Введите A = ";
	cin >> a;
	cout << "\nВведите B = ";
	cin >> b;
	cout << "\nВведите C = ";
	cin >> c;
	cout << endl;
	cout << "A = " + a + " B = " + b + " C = " + c << endl;

	swap(a, b);
	swap(a, c);

	cout << "A = " + a + " B = " + b + " C = " + c;
}
void SWAP4()
{
	cout << "\n\nЗадача SWAP4\n\n";
	string a, b, c, d;
	cout << "Введите A = ";
	cin >> a;
	cout << "\nВведите B = ";
	cin >> b;
	cout << "\nВведите C = ";
	cin >> c;
	cout << "\nВведите D = ";
	cin >> d;
	cout << endl;
	cout << "A = " + a + " B = " + b + " C = " + c + " D = " + d << endl;

	swap(a, b);
	swap(a, d);
	swap(c, d);

	cout << "A = " + a + " B = " + b + " C = " + c + " D = " + d;

}
void InitProgram()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Лабораторная работа #2\n\n";
}
void MainMenu()
{
	int n;
	cout << "Выберите программу:\n0 - exit\n1 - ANKETA2\n2 - Guess\n3 - HELLO2\n4 - HELLO3\n5 - Parrot\n6 - SWAP3\n7 - SWAP4\n";
	
	cin >> n;
	
	switch (n)
	{
	case 0: exit;
		break;

	case 1: ANKETA2();
		break;

	case 2: Guess();
		break;

	case 3: HELLO2();
		break;

	case 4: HELLO3();
		break;

	case 5: Parrot();
		break;

	case 6: SWAP3();
		break;

	case 7: SWAP4();
		break;

	default:
	{
		system("cls");
		cout << "Ошибка ввода. Попробуйте ещё раз.\n";
		MainMenu();
	}
	break;
	}
}


