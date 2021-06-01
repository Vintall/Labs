#pragma once
#include <iostream>

//#define WITH_STD

#ifdef WITH_STD
#include <queue>
using namespace std;
#else
#include "Queue.h"
using namespace none_std;
#endif // WITH_STD

#define cout std::cout
#define cin std::cin
#define endl std::endl

template <typename T>
class TaskAndDialogs
{
	queue<T> container;
public:
	TaskAndDialogs()
	{
		while (1)
		{
			cout << "1) Добавить новый элемент" << endl;
			cout << "2) Очистить очередь" << endl;
			cout << "3) Вывести очередь" << endl;
			cout << "4) Вывести сумму" << endl;
			cout << "5) Выйти" << endl;

			cout << "Выберите пункт меню: ";
			int choice = -1;
			cin >> choice;
			switch (choice)
			{
			case 1:
				AddNewElem();
				break;
			case 2:
				Clear();
				break;
			case 3:
				ShowQueue();
				break;
			case 4:
				cout << Sum() << endl;
				break;
			default:
				exit(0);
				break;
			}
			system("Pause");
			system("cls");
		}
		;
	}
	T Sum()
	{
		queue<T> buf = container;
		T sum = 0;
		int count = container.size();
		for (int i = 0; i < count; i++)
		{
			sum += buf.front();
			buf.pop();
		}
		return sum;
	}
	void ShowQueue()
	{
		int size = container.size();
		for (int i = 0; i < size; i++)
		{
			T buf;
			buf = container.front();
			container.pop();
			cout << buf << endl;
			container.push(buf);
		}
	}
	void AddNewElem()
	{
		cout << "Введите новый элемент: ";
		T new_elem;
		cin >> new_elem;
		cout << endl;
		container.push(new_elem);
	}
	void Clear()
	{
		int size = container.size();
		for (int i = 0; i < size; i++)
			container.pop();
	}
};
