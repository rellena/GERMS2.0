//player.h

//this class is pretty done. 

//Author: Richard Ellena
#pragma once
#include "sprites.h"
#include <string>
#include "Enemy.h"

using namespace std;

class player : public unit
{
public:
	//constructors
	player();
	player(float,float,float,float,float,float,string,string,string);
	~player();//destr
	bool loadPlayerSprites();//stores sprite
	GLuint getSprites();//returns sprite
	bool targetEnemyWithMouse(Enemy *enemyUnit, float x, float y);
	void setPlayerDamage(float pDamage);
	float getPlayerDamage();

private:
	void deletePlayer();
	GLuint playerSprite;
	string playerName;//name of player to be printed to screen for graphics
};
