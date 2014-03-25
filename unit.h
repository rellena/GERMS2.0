//Unit.h

//This class is almost completely done. All units of the game
//will inherit from this class. Add what is necessary if there
//is anything needed.

//Author: Richard Ellena
#pragma once
#include "Point.h"
#include <string>

using namespace std;

class unit
{
public:
	//const
	unit();
	unit(float,float,float,float,float,float,string,string);
	//getters and setters
	float getHealth();
	void setHealth(float);
	float getArmor();
	void setArmor(float);
	float getDamage();
	void setDamage(float);
	float getSpeed();
	void setSpeed(float);
	float getRange();
	void setRange(float);
	float getEnergy();
	void setEnergy(float);
	string getCharName();
	void setCharName(string);
	string getCharClass();
	void setCharClass(string);
	Point getPosition();//units postion gets and sets
	void setPosition(float, float);
	Point move(float, float);//function to move the unit in direction
	float getRadius();
	void setRadius(float);
private:
	float health, armor, damage, speed, range, energy;
	string char_name, char_class;
	Point position;
	float radius;
};
