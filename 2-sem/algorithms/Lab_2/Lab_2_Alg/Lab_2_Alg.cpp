#include <iostream>
#include <ctime>

using namespace std;
void Menu();
struct Queue;

Queue qu = Queue();

struct Queue
{
	int elem;
	Queue* next;
};

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	Menu();
	system("Pause");
}

void Menu()
{
	bool menu_i = true;
	while (menu_i)
	{
		system("cls");
		cout << "1) Додати елемент" << endl;
		cout << "2) Видалити елемент" << endl;
		cout << "3) Вивести елементи на екран" << endl;
		cout << "4) Очистити структуру" << endl;
		cout << "5) Вивести кількість елементів, індекс першого та останнього елементу" << endl;
		cout << "6) Сформувати випадковий массив" << endl;
		cout << "7) Парные - непарные" << endl;
		cout << "8) Завершення роботи" << endl;
		cout << endl;
		cout << "Введите номер пункта, к которому хотите перейти - ";
		int n_; cin >> n_; cout << endl;
		switch (n_)
		{
		case 1:
			cout << "Введите элемент" << endl;
			
			system("Pause");
			break;
		case 2:
			
			system("Pause");
			break;
		case 3:
			
			system("Pause");
			break;
		case 4:
			
			system("Pause");
			break;
		case 5:
			
			system("Pause");
			break;
		case 6:
			
			system("Pause");
			break;
		case 7:
			
			system("Pause");
			cout << endl;
			break;
		case 8:
			menu_i = 0;
			break;
		default:
			menu_i = 0;
			break;
		}
	}
}