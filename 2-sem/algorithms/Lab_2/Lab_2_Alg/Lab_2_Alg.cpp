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
		cout << "1) ������ �������" << endl;
		cout << "2) �������� �������" << endl;
		cout << "3) ������� �������� �� �����" << endl;
		cout << "4) �������� ���������" << endl;
		cout << "5) ������� ������� ��������, ������ ������� �� ���������� ��������" << endl;
		cout << "6) ���������� ���������� ������" << endl;
		cout << "7) ������ - ��������" << endl;
		cout << "8) ���������� ������" << endl;
		cout << endl;
		cout << "������� ����� ������, � �������� ������ ������� - ";
		int n_; cin >> n_; cout << endl;
		switch (n_)
		{
		case 1:
			cout << "������� �������" << endl;
			
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