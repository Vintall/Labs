#include <iostream>
using namespace std;
//variant 8
void Menu();
void AddElem();
void RMElem();
void ShowElem();

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
	Sll* prev = NULL;
	for (int i = 1; i != ind;)
	{
		if (buff->next != NULL)
		{
			prev = buff;
			buff = buff->next;
			i++;
		}
		else
		{
			cout << "������ �������� �� ����������" << endl;
			system("Pause");
			break;
		}
	}
	if (prev == NULL)
	{
		buff = sll->next;
		delete(sll);
		sll = buff;
	}
	else if (buff->next == NULL)
	{
		delete(buff);
		prev->next = NULL;
	}
	else
	{
		prev->next = buff->next;
		delete(buff);
	}
}
void Task()
{
	ShowElem();

	int count = 0;
	Sll* buff = sll;
	for (int i = 1; buff->next!=NULL ; i++)
	{
		buff = buff->next;
		if (i % 3 == 0)
		{ 
			RMElem(i-count);
			count++;
		}
	}
	cout << endl << endl;
	ShowElem();
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
		cout << "1) �������� �������" << endl;
		cout << "2) ������� �������" << endl;
		cout << "3) ������� �������� �� �����" << endl;
		cout << "4) �������� ������" << endl;
		cout << "5) ���. �������" << endl;
		cout << "0) �����" << endl;

		cout << endl;
		cout << "������� ����� ������, � �������� ������ ������� - ";
		int n_; cin >> n_; cout << endl;
		switch (n_)
		{
		default:
			menu_i = 0;
			break;
		case 1:
			cout << "������� ������� (int): ";
			int el; cin >> el;
			AddElem(el);
			system("Pause");
			break;
		case 2:
			cout << "������� ����� ��������: ";
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