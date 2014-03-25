//Point class, straightforward

//Author: Richard Ellena
#pragma once
using namespace std;

class Point
{
public:
	//operator=
	Point& operator= (const Point&);
	//operator ==
	bool operator== (const Point&);
	//constructors
	Point();
	Point(float, float);
	Point(const Point&);//copy constructor
	float x,y;
private:
	void copyPoint(const Point&);
};
