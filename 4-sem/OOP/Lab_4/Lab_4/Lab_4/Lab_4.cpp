#include <iostream>
#include "TaskAndDialogs.h"
#include "MyVector.h"
#include "Stack.h"
//#include <stack>

template<class Iter, typename T>
void My_sum(Iter beg, Iter end, T& res)
{
	res = 0;
	while (beg != end)
	{
		res += *beg;
		++beg;
	}
}

int main()
{
	stack<double> a;
	a.push(1.1);
	a.push(2.1);
	a.push(3.1);
	double ress;
	My_sum(a.begin(), a.end(), ress);


	std::cout << ress << std::endl;




	//TaskAndDialogs<double> prog;
}


//template<typename T>
//class My_List
//{
//	T* cells;
//	void insert(iterator Where, T item);
//public:
//	class iterator
//	{
//		T* iter = nullptr;
//	public:
//		iterator() = default;
//		iterator(T* new_item)
//		{
//			iter = new_item;
//		}
//		iterator& operator = (const iterator& new_item)
//		{
//			iter = new_item.iter;
//			return *this;
//		}
//		iterator operator++ (int)
//		{
//			iterator buf(iter);
//			iter++;
//			return buf;
//		}
//		iterator operator-- (int)
//		{
//			iterator buf(iter);
//			iter--;
//			return buf;
//		}
//		iterator operator++ ()
//		{
//			iter++;
//			return iter;
//		}
//		iterator operator-- ()
//		{
//			iter--;
//			return iter;
//		}
//		iterator operator+ (const int offset)
//		{
//			return iter + offset;
//		}
//		iterator operator- (const int offset)
//		{
//			return iter - offset;
//		}
//		bool operator == (const iterator& new_item)
//		{
//			return iter == new_item.iter;
//		}
//		bool operator != (const iterator& new_item)
//		{
//			return iter != new_item.iter;
//		}
//		int operator - (const iterator& new_item)
//		{
//			return (int)(iter - new_item.iter);
//		}
//	}
//};
