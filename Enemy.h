#pragma once
#include "sprites.h"
#include <string>
#include "unit.h"
#include "lib/SOIL.h"
using namespace std;

class Enemy : public unit
{
public:
	//constructors
	Enemy();
	Enemy(float,float,float,float,float,float,string,string,string);
	~Enemy();//destr
	bool loadEnemySprites(string filename);//stores sprite
	sprites& getSprites();//returns sprite
	Point*& getMovePattern();
	int getmpSize();
	void setmpSize(int);
	int getMoveToPoint();
	void setMoveToPoint(int);

private:
	void deleteEnemy();
	sprites enSprite;
	string enName;//name of player to be printed to screen for graphics
	Point *movepattern;
	int mpsize, moveto;
};