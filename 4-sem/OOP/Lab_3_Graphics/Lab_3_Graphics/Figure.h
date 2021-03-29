#pragma once
#include <SFML/Graphics.hpp>
#include "MyShape.h"
using namespace sf;
class Figure
{
public:
	MyShape shape;
	Figure();
	int type;
	bool is_drowable = true;
	bool is_agregat = false;
	Vector2f pos;
	float angle;
	Color color;
	String name;
	std::vector <Figure> obj;
	virtual void ChangeCol(int r, int g, int b)
	{
		color = Color(r, g, b, 1);
	}
	virtual void Move(Vector2f dir)
	{
		pos += dir;
	}
};