#include <iostream>
#include <ctime>

using namespace std;
void Menu();
const int n_max = 150;
struct Queue
{
private:
	int n;
	int mass[n_max];

public:
	Queue()
	{
		n = 0;
	}
	int Take_N()
	{
		return n;
	}
	int AddElem(int elem)
	{
		if (n != n_max)
		{
			mass[n] = elem;
			n++;
			return 0;
		}
		return -1;
	}
	int TakeElem()
	{
		if (n != 0)
		{
			int out = mass[0];
			for (int i = 0; i < n-1; i++)
				mass[i] = mass[i + 1];
			n--;
			return out;
		}
		return -1;
	}
};

Queue qu = Queue();




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
			int k; cin >> k; cout << endl;
			if (qu.AddElem(k) == -1)
				cout << "Ошибка ввода" << endl;
			system("Pause");
			break;
		case 2:
			if (qu.TakeElem() == -1)
				cout << "Очередь пустая" << endl;
			system("Pause");
			break;
		case 3:
			int buff;
			for (int i = 0; i < qu.Take_N(); i++)
			{
				buff = qu.TakeElem();
				qu.AddElem(buff);
				cout << "elem[" << i << "]= " << buff << endl;
			}
			system("Pause");
			break;
		case 4:
			int i_max; i_max = qu.Take_N();
			for (int i = 0; i < i_max; i++)
				qu.TakeElem();
			system("Pause");
			break;
		case 5:
			cout << "Кол-во элементов - " << qu.Take_N() << endl;
			cout << "Индекс минимального - 0" << endl;
			cout << "Индекс максимального - " << qu.Take_N() - 1 << endl;
			system("Pause");
			break;
		case 6:
			cout << "Введите n(кол-во элементов очереди) (0, " << n_max << ") - ";
			int n_test; cin >> n_test; cout << endl;

			cout << "Введите 2 границы случайного числа:" << endl;
			cout << "Введите А (>0)- ";
			int a; cin >> a; cout << endl;
			cout << "Введите B (>0)- ";
			int b; cin >> b; cout << endl;
			if (a > b)
			{
				int c = a;
				a = b;
				b = c;
			}
			if (a < 0) a *= -1;
			if (b < 0) b *= -1;
			
			if (n_test > 0 && n_test <= n_max)
			{
				for (int i = 0; i < qu.Take_N(); i++)
					qu.TakeElem();

				for (int i = 0; i < n_test; i++)
					qu.AddElem(rand() % (b - a + 1) + a);
				
			}
			system("Pause");
			break;
		case 7:
			int i_maxx; i_maxx = qu.Take_N();
			for (int i = 0; i < i_maxx; i++)
			{
				int elem_cur = qu.TakeElem();
				if (elem_cur % 2 == 0)
				{
					cout << elem_cur << endl;
				}
				else
				{
					qu.AddElem(elem_cur);
				}
			}
			i_maxx = qu.Take_N();
			for (int i = 0; i < i_maxx; i++)
			{
				cout << qu.TakeElem() << endl;
			}
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