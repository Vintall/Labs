#pragma once
#include <SFML/Graphics.hpp>
#include "MyShape.h"
using namespace sf;
class Figure
{
public:
	ConvexShape shape;
	Figure();
	std::vector<Vector2f> trajectory;
	bool is_drowable = true;
	bool is_agregat = false;
	int color[3] = { 0, 0, 0 };
	std::string name;
	std::vector <Figure> obj;
	virtual void ResetObject()
	{
		if (!is_agregat)
		{
			shape.setScale(Vector2f(1, 1));
			shape.setRotation(0);
			for (int k = 0; k < trajectory.size(); k++)
			{
				shape.move(-trajectory[k]);
			}
		}
		else
		{
			for (int i = 0; i < obj.size(); i++)
			{
				obj[i].ResetObject();
			}
			for (int k = 0; k < trajectory.size(); k++)
			{
				shape.move(-trajectory[k]);
			}
		}
		trajectory.clear();
		is_drowable = true;
		ChangeCol(0, 255, 0);
	}
	virtual void ChangeCol(int r, int g, int b)
	{
		color[0] = r;
		color[1] = g;
		color[2] = b;
		if (is_agregat)
		{
			for (int i = 0; i < obj.size(); i++)
				obj[i].shape.setFillColor(Color(r, g, b, 255));
		}
		else
		shape.setFillColor(Color(r, g, b, 255));
	}
	virtual void Move(Vector2f dir)
	{
		if (is_agregat)
		{
			for (int i = 0; i < obj.size(); i++)
			{
				obj[i].Move(dir);
			}
		}
			shape.move(dir);

		if (dir.x != 0 || dir.y != 0)
			trajectory.push_back(dir);
	}
	virtual void TrajectoryForward(int i)
	{
		if (i >= 0 && i < trajectory.size())
		{
			if (is_agregat)
			{
				for (int j = 0; j < obj.size(); j++)
					obj[j].TrajectoryForward(i);
			}
			shape.move(trajectory[i]);
		}
	}
	virtual void TrajectoryBack(int i)
	{
		if (i >= 0 && i < trajectory.size())
		{
			if (is_agregat)
			{
				for (int j = 0; j < obj.size(); j++)
					obj[j].TrajectoryBack(i);
			}
			shape.move(-trajectory[i]);
		}
	}
	virtual void Scale(float scaler)
	{
		if (is_agregat)
		{
			bool can_resize = true;
			for (int i = 0; i < obj.size(); i++)
			{
				if (obj[i].shape.getScale().x <= 0.2 && scaler < 0) can_resize = false;
			}
			if (can_resize)
			for (int i = 0; i < obj.size(); i++)
			{
				if (scaler != 0)
				{
					obj[i].Scale(scaler);
				}
			}
		}
		else
		{
			if (shape.getScale().x <= 0.2 && scaler < 0) return;
			shape.setScale(scaler+shape.getScale().x, scaler + shape.getScale().x);
		}
	}
};