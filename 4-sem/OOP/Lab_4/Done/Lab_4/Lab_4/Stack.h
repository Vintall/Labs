#pragma once
namespace none_std
{
	template <typename T>
	class stack
	{
		T* cells;
		int length = 0;
	public:
		bool empty()
		{
			return length == 0 ? true : false;
		}
		int	size()
		{
			return length;
		}
		T back()
		{
			return cells[length - 1];
		}
		void push(T elem)
		{
			T* buf = cells;
			cells = new T[++length];
			for (int i = 0; i < length - 1; i++)
				cells[i] = buf[i];
			cells[length - 1] = elem;
		}
		T pop()
		{
			
			T* buf = cells;
			cells = new T[--length];
			for (int i = 0; i < length; i++)
				cells[i] = buf[i];
			return buf[length];
		}
	};
}