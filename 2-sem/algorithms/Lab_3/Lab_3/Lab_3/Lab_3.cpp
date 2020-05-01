#include <iostream>
using namespace std;
//variant 8
void Menu();
void AddElem();
void RMElem();

struct Sll  //Singly linked list
{
	int elem;
	Sll* next;
};
Sll *sll;

void AddElem(int elem_)
{
	Sll* x = new Sll;
	x->elem = elem_;
	x->next = sll;
	
	Sll* buff = x;
	x = sll;
	sll = buff;
}


void RMElem(int ind)
{
	Sll* buff = sll;
	for (int i = 0; i < ind; i++)
	{
		if (buff->next == NULL)
		{
			cout << "Такого элемента не существует" << endl;
			system("Pause");
			break;
		}
		else
		{
			if (i == ind - 1 && buff->next->next != NULL)
			{
				buff->next = buff->next->next;
				break;
			}
			else
				buff = buff->next;
		}
	}
}
void Task()
{
	int count = 0;
	Sll* buff = sll;
	for (int i = 1; buff->next!=NULL ; i++)
	{
		buff = buff->next;
		if (i % 3 == 0)
		{ 
			count++;
			RMElem(i-count);
		}
	}
}
void ShowElem()
{
	Sll* buff = sll;
	for (int i = 0; buff->next != NULL; i++)
	{
		cout << buff->elem << endl;
		buff = buff->next;
	}
}
void RMSll()
{
	Sll* buff1 = sll->next;
	Sll* buff2 = buff1->next;
	if (buff1 != NULL)
		for (; buff2->next != NULL;)
		{
			delete(buff1);
			buff1 = buff2;
			buff2 = buff2->next;
		}
	delete(buff2);
	sll->next = NULL;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	sll = new Sll;
	sll->next = NULL;
	Menu();
	system("Pause");
}

void Menu()
{
	bool menu_i = true;
	while (menu_i)
	{
		system("cls");
		cout << "1) Добавить элемент" << endl;
		cout << "2) Удалить элемент" << endl;
		cout << "3) Вывести элементы на экран" << endl;
		cout << "4) Очистить список" << endl;
		cout << "5) Инд. задание" << endl;
		cout << "0) Выход" << endl;

		cout << endl;
		cout << "Введите номер пункта, к которому хотите перейти - ";
		int n_; cin >> n_; cout << endl;
		switch (n_)
		{
		default:
			menu_i = 0;
			break;
		case 1:
			cout << "Введите элемент (int): ";
			int el; cin >> el;
			AddElem(el);
			system("Pause");
			break;
		case 2:
			cout << "Введите номер элемента: ";
			int ind; cin >> ind;
			
			RMElem(ind);
			system("Pause");
			break;
		case 3:
			ShowElem();
			system("Pause");
			break;
		case 4:
			RMSll();
			system("Pause");
			break;
		case 5:
			Task();
			system("Pause");
			break;
		case 0:
			menu_i = 0;
			system("Pause");
			break;

		}
	}
}