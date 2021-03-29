#pragma once
class MyVector
{ 
public:
	float x;
	float y;

	MyVector(float _x, float _y);
	MyVector();
	MyVector(const MyVector& temp);
	void RotateVector(float angle);
};

