//Unit.cpp

//Again this class is basically done. Edit here where necessary.

//Author: Richard Ellena
#include "gameinclude.h"

//constructors
unit::unit()
:health(100),armor(50),damage(10),speed(5),range(5),energy(100), char_name(""), char_class("")
{
}
unit::unit(float h, float a, float d, float s, float r, float e, string cn, string cc)
{
	health = h;
	armor = a;
	damage = d;
	speed = s;
	range = r;
	energy = e;
	char_name = cn;
	char_class = cc;
}
//getters and setters
float unit::getHealth()
{
	return health;
}
void unit::setHealth(float h)
{
	health = h;
}
float unit::getArmor()
{
	return armor;
}
void unit::setArmor(float a)
{
	armor = a;
}
float unit::getDamage()
{
	return damage;
}
void unit::setDamage(float d)
{
	damage = d;
}
float unit::getSpeed()
{
	return speed;
}
void unit::setSpeed(float s)
{
	speed = s;
}
float unit::getRange()
{
	return range;
}
void unit::setRange(float r)
{
	 range = r;
}
float unit::getEnergy()
{
	return energy;
}
void unit::setEnergy(float e)
{
	energy = e;
}

string unit::getCharName()
{
	return char_name;
}
void unit::setCharName(string cn)
{
	char_name = cn;
}
string unit::getCharClass()
{
	return char_class;
}
void unit::setCharClass(string cc)
{
	char_class = cc;
}
Point unit::getPosition()
{
	return position;
}
void unit::setPosition(float newx, float newy)
{
	position.x = newx;
	position.y = newy;
}

//Okay so this function is vital to the movement of units
//Right now the movement is fairly choppy, if we add in physics that are more realistic
//this will be the function to do it in
Point unit::move(float dirx, float diry)
{
	//dirx, is the direction to move in, it is actually the
	//point that the mouse click occured at, same for diry

	//the ifs just check if the clicked occured above or below the sprite
	//and then moves the sprite accordingly
	float speedx, speedy;
	float angle;

	//cos = adj / hypo // adj = cos *hypo
	angle = abs(diry - position.y);
	angle = angle / (pow((float)(pow((dirx - position.x),2) + pow ((diry - position.y), 2)), (float)0.5));

	speedx = speed * cos(angle);
	speedy = speed * sin(angle);

	if (dirx > position.x)
	{
		if (position.x + speedx <= dirx)
			position.x += speedx;
		else
			position.x = dirx;
	}
	else if (dirx < position.x)
	{
		if (position.x - speedx >= dirx)
			position.x -= speedx;
		else
			position.x = dirx;
	}
	
	if (diry > position.y)
	{
		if (position.y + speedy <= diry)
			position.y += speedy;
		else
			position.y = diry;
	}
	else if (diry < position.y)
	{
		if (position.y - speedy >= diry)
			position.y -= speedy;
		else
			position.y = diry;
	}
	return position;
}	

//radius getter and setter
float unit::getRadius()
{
	return radius;
}

void unit::setRadius(float rad)
{
	radius = rad;
}
