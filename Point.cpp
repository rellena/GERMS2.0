//point.cpp
//the cpp for the point header, straightforward
#include "gameinclude.h"

//Constructors
Point::Point()
:x(0),y(0)
{}
Point::Point(float otherx, float othery)
{
	x = otherx;
	y = othery;
}
Point::Point(const Point &other)
{
	copyPoint(other);
}

//Operators
Point& Point::operator= (const Point &other)
{
	copyPoint(other);
	return *this;
}
bool Point::operator== (const Point& other)
{
	if (other.x == x && other.y == y)
		return true;
	else
		return false;
}
//Private functions
void Point::copyPoint(const Point &other)
{
	x = other.x;
	y = other.y;
}
