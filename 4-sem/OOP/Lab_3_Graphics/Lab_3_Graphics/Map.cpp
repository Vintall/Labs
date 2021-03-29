#include "Map.h"
#include "Polygon.h"
#include "Circle.h"
//#include "Line.h"

Map::Map()
{

}
void Map::AddFigure(std::string name, Vector2f pos, int count, float radius)
{
	obj.push_back(Polygon(name, pos, radius, count)); 
}
void Map::AddFigure(std::string name, Vector2f pos, float radius)
{
	//obj.push_back(Circle());
}
void Map::AddFigure(std::string name, Vector2f p1, Vector2f p2)
{
	//obj.push_back(Line());
}