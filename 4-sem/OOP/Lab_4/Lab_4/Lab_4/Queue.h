#pragma once
#include "Stack.h"
#include <iostream>
namespace none_std
{
	template <typename T>
	class queue
	{
		stack<T> cells;
		stack<T> buff;
	public:
		typename stack<T>::iterator begin()
		{
			return cells.begin();
		}
		typename stack<T>::iterator end()
		{
			return cells.end();
		}
		bool empty()
		{
			return cells.empty();
		}
		int size()
		{
			return cells.size();
		}
		T front()
		{
			return cells.back();
		}
		T back()
		{
			for (int i = 0; i < buff.size(); i++)
				buff.pop();

			for (int i = 0; i < cells.size(); i++)
			{
				buff.push(cells.pop());
			}
			T buff2 = buff.back();
			for (int i = 0; i < buff.size(); i++)
			{
				cells.push(buff.pop());
			}
			return buff2;
		}
		void push(T elem)
		{
			int count = buff.size();
			for (int i = 0; i < count; i++)
				buff.pop();


			count = cells.size();
			for (int i = 0; i < count; i++)
				buff.push(cells.pop());

			buff.push(elem);
			count = buff.size();

			for (int i = 0; i < count; i++)
				cells.push(buff.pop());
		}
		void emplace(T elem)
		{
			for (int i = 0; i < buff.size(); i++)
				buff.pop();

			for (int i = 0; i < cells.size(); i++)
			{
				buff.push(cells.pop());
			}

			buff.push(elem);
			for (int i = 0; i < buff.size(); i++)
			{
				cells.push(buff.pop());
			}
		}
		void pop()
		{
			cells.pop();
		}
	};
}