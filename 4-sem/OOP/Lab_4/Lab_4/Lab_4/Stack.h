#pragma once
namespace none_std
{
	template <typename T>
	class stack
	{
		T* cells;
		int length = 0;
	public:
		class iterator
		{
			T* iter = nullptr;
		public:
			iterator() = default;
			iterator(T* new_item)
			{
				iter = new_item;
			}
			iterator& operator = (const iterator& new_item)
			{
				iter = new_item.iter;
				return *this;
			}
			iterator operator++ (int)
			{
				iterator buf(iter);
				iter++;
				return buf;
			}
			iterator operator-- (int)
			{
				iterator buf(iter);
				iter--;
				return buf;
			}
			iterator operator++ ()
			{
				iter++;
				return iter;
			}
			iterator operator-- ()
			{
				iter--;
				return iter;
			}
			iterator operator+ (const int offset)
			{
				return iter + offset;
			}
			iterator operator- (const int offset)
			{
				return iter - offset;
			}
			bool operator == (const iterator& new_item)
			{
				return iter == new_item.iter;
			}
			bool operator != (const iterator& new_item)
			{
				return iter != new_item.iter;
			}
			int operator - (const iterator& new_item)
			{
				return (int)(iter - new_item.iter);
			}
			T& operator* ()
			{
				return *iter;
			}
		};
		bool empty()
		{
			return length == 0;
		}
		int	size()
		{
			return length;
		}
		T back()
		{
			return cells[length - 1];
		}
		iterator begin()
		{
			return iterator(cells);
		}
		iterator end()
		{
			return iterator(cells + length);
		}
		void push(T elem)
		{
			T* buf = cells;
			if (buf != nullptr)
			{
				cells = new T[++length];


				int i_i = 0;
				for (iterator i = begin(); i != end(); i++)
				{

					cells[i_i] = buf[i_i];
					i_i++;
				}
				cells[length - 1] = elem;
			}
			else
			{
				cells = new T[++length];
				cells[length - 1] = elem;
			}
			//for (int i = 0; i < length - 1; i++)
			//	cells[i] = buf[i];
		}
		T pop()
		{
			T* buf = cells;
			cells = new T[--length];

			int i_i = 0;
			for (iterator i = begin(); i != end(); i++)
			{
				cells[i_i] = buf[i_i];
				i_i++;
			}

			//for (int i = 0; i < length; i++)
			//	cells[i] = buf[i];

			return buf[length];
		}
		~stack()
		{
			delete[] cells;
			length = 0;
		}
	};
}