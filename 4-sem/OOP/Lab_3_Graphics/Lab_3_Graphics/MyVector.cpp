#include "MyVector.h"
#include <iostream>

MyVector::MyVector(float _x, float _y)
{
	x = _x;
	y = _y;
}
MyVector::MyVector()
{
	x = 0;
	y = 0;
}
MyVector::MyVector(const MyVector& temp)
{
	x = temp.x;
	y = temp.y;
}
void MyVector::RotateVector(float angle)
{
	MyVector res = MyVector();
	res.x = x * cos(angle) + y * sin(angle);
	res.y = -1 * x * sin(angle) + y * cos(angle);
	x = res.x;
	y = res.y;
}