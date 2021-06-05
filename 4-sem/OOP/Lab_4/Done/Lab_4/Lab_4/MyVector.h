#pragma once
namespace MyVec
{
	template<class T>
	class vector
	{
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
		vector()
		{
			node = nullptr;
		}
		/*vector(int new_count)
		{
			node = new T[new_count];

			for (int i = 0; i < new_count; ++i)
				node[i] = 0;
		}*/
		~vector()
		{
			delete[] node;
		}
		T& operator[] (int i)
		{
			return node[i];
		}
		void push_back(T new_elem)
		{
			if (node != nullptr)
			{
				count++;
				T* new_node = new T[count];

				int i = 0;
				for (iterator i_i = begin(); i_i != end(); i_i++)
				{
					new_node[i] = node[i];
					i++;
				}
				new_node[count - 1] = new_elem;
				delete[] node;
				node = new_node;
			}
			else
			{
				count++;
				node = new T[count];
				node[count - 1] = new_elem;
			}
		}
		iterator begin()
		{
			return iterator(node);
		}
		iterator end()
		{
			return iterator(node + count);
		}
		int size()
		{
			return count;
		}
		void clear()
		{
			delete[] node;
			node = nullptr;
			count = 0;
		}
		private:
			T* node;
			int count = 0;
	};
}