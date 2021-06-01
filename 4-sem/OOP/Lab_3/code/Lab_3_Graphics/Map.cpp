#include "Map.h"
#include "Polygon.h"
#include "Circle.h"
#include "Star.h"
#include <vector>
#include "ElseFigure.h"
//#include "Line.h"
using namespace sf;
Map::Map()
{

}
void Map::AddFigure(std::string name, Vector2f pos, int count, float radius)
{
	obj.push_back(&Polygon(name, pos, radius, count)); 
}
void Map::AddFigure(std::string name, Vector2f pos, float radius)
{
	obj.push_back(&Circle(name, pos, radius));
}
void Map::AddFigure(std::string name, int ray_count, float r1, float r2)
{
	obj.push_back(&Star(name, ray_count, r1, r2));
}
void Map::AddFigure(std::string name, std::vector<float> angles)
{
	obj.push_back(&ElseFigure(name, angles));
}