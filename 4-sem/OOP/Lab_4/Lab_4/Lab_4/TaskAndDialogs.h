#pragma once
#include <iostream>
#include "MyVector.h"
#include <algorithm>
//#define WITH_STD

#ifdef WITH_STD
#include <queue>
#include <vector>
using namespace std;
#else
#include "Queue.h"
using namespace none_std;
#endif


template <typename T>
class TaskAndDialogs
{
	queue<T> container;
	MyVec::vector<T> vec;

public:
	TaskAndDialogs()
	{
		while (1)
			MainMenu();
	}
	void MainMenu()
	{
		std::cout << "1) queue (2 stack's)" << std::endl;
		std::cout << "2) vector (iterator)" << std::endl;
		std::cout << "3) Exit" << std::endl;
		std::cout << "Choose a menu item: ";

		int choice = -1;
		std::cin >> choice;
		system("cls");
		if (choice == 1)
		{
			QueueMenu();
		}
		else if (choice == 2)
		{
			VectorMenu();
		}
		else 
			exit(0);
	}
	void VectorMenu()
	{
		int while_checker = 1;
		while (while_checker)
		{
			std::cout << "1) Add new element" << std::endl;
			std::cout << "2) Clear vector" << std::endl;
			std::cout << "3) Show vector" << std::endl;
			std::cout << "4) Go back to Main Menu" << std::endl;

			std::cout << "Choose a menu item: ";
			int choice = -1;
			std::cin >> choice;
			switch (choice)
			{
			case 1:
				T elem;
				std::cout << "Enter element: ";
				std::cin >> elem; 
				std::cout << std::endl;
				vec.push_back(elem);
				break;
			case 2:
				vec.clear();
				break;
			case 3:
			{
				typename MyVec::vector<T> ::iterator iter = vec.begin();
				while (iter != vec.end())
				{
					std::cout << *iter << std::endl;
					iter++;
				}
				system("Pause");
				break;
			}
			default:
				while_checker = 0;
				break;
			}
			system("cls");
		};
	}
	void QueueMenu()
	{
		int while_checker = 1;
		while (while_checker)
		{
			std::cout << "1) Add new element" << std::endl;
			std::cout << "2) Clear queue" << std::endl;
			std::cout << "3) Show queue" << std::endl;
			std::cout << "4) Sum of elements" << std::endl;
			std::cout << "5) Go back to Main Menu" << std::endl;

			std::cout << "Choose a menu item: ";
			int choice = -1;
			std::cin >> choice;
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
				system("Pause");
				break;
			case 4:
				std::cout << Sum() << std::endl;
				system("Pause");
				break;
			default:
				while_checker = 0;
				break;
			}
			system("cls");
		};
	}
	T Sum()
	{
		
		if (container.begin() != container.end())
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
		else
			return 0;
	}
	void ShowQueue()
	{
		int size = container.size();
		typename stack<T>::iterator i;
		typename stack<T>::iterator i_end=container.end();


		for (i = container.begin(); i != i_end; i++)
		{
			T buf;
			buf = container.front();
			container.pop();
			std::cout << buf << std::endl;
			container.push(buf);
		}


		//for (int i = 0; i < size; i++)
		//{
		//	T buf;
		//	buf = container.front();
		//	container.pop();
		//	std::cout << buf << std::endl;
		//	container.push(buf);
		//}
	}
	void AddNewElem()
	{
		std::cout << "Elter element: ";
		T new_elem;
		std::cin >> new_elem;
		std::cout << std::endl;
		container.push(new_elem);
	}
	void Clear()
	{
		int size = container.size();
		typename stack<T>::iterator i;
		typename stack<T>::iterator i_end = container.end();
		//for (int i = 0; i < size; i++)
		//	container.pop();

		for (i = container.begin(); i != i_end; i++)
			container.pop();
	}
};
