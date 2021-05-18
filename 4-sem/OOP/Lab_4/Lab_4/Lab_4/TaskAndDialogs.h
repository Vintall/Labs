#pragma once
#include <iostream>

#define WITH_STD

#ifdef WITH_STD
#include <queue>
using namespace std;
#else
#include "Queue.h"
using namespace none_std;
#endif // WITH_STD


class TaskAndDialogs
{
	queue<int> container;
public:
	TaskAndDialogs()
	{
		container.push(1);
		container.push(2);
		container.push(3);
		container.push(4);
		container.push(5);
		container.push(6);

		Sum();
	}
	int Sum()
	{
		queue<int> buf = container;
		int sum = 0;
		int count = container.size();
		for (int i = 0; i < count; i++)
		{
			sum += buf.front();
			buf.pop();
			std::cout << sum << std::endl;
		}
		//std::cout << sum << std::endl;
		return sum;
	}

	void AddNewElem()
	{

	}
	void Clear()
	{

	}
};

