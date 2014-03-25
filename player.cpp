//player.cpp
//cpp file for the player

//Author: Richard Ellena

//This class will handle the main player. Only one istance of this class will
//be created into an object in the main and then all other copies will be
//referenced to it

//Add to this class if needed but player is pretty much done

#include "gameinclude.h"
extern Point mouse;
extern int enemy_size;
//player constructors
player::player()
:unit(), playerName("")
{}

player::player(float h, float a,float d,float s,float r,float e, string cn, string cc, string pn)
{
	//see unit decl, for const details
	unit(h,a,d,s,r,e,cn,cc);
	playerName = pn;
}
player::~player()
{
	deletePlayer();
}
//player member functions
bool player::loadPlayerSprites()
{
	playerSprite = SOIL_load_OGL_texture("Textures/Demo1.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    //if(playerSprite[0] == 0) return false;
   // glBindTexture(GL_TEXTURE_2D, playerSprite[0]);
   // glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
   // glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    return true;
}

GLuint player::getSprites()
{
	return playerSprite;
}
//player operators

void player::deletePlayer()
{
}


bool player::targetEnemyWithMouse(Enemy *enemyUnit, float x, float y)
{
	x = mouse.x;
	y = mouse.y;
	bool isAttack = false;
	//3/18/2014 ok so the calculations work but...all wrong as in if they colide damage is death, but the clicking issue is still there


	for( int i = 0; i < enemy_size; i++)
	{//for begin
		//distance calculations
		float enemyDistanceX = enemyUnit[i].getPosition().x - this->getPosition().x;// x = x2 - x1
		float distanceX = enemyDistanceX * enemyDistanceX;//x^2
		float enemyDistanceY = enemyUnit[i].getPosition().y - this->getPosition().y;//y = y2-y1
		float distanceY = enemyDistanceY * enemyDistanceY;// y^2
		float distanceTotal = sqrt(distanceX + distanceY);//sqrt(x^2 + y^2)

		//if the distance from player to enemy is less than or same as player's range
		if(distanceTotal <= this->getRange() )
		{// if in for begin
			isAttack = true;
			float damageCalculation = getPlayerDamage() - ( (getPlayerDamage())/enemyUnit[i].getArmor() );
			float enemy_health = enemyUnit[i].getHealth() - damageCalculation;
			enemyUnit[i].setHealth(enemy_health);

		}//if in loop end
	isAttack = false;
	}// for end
	
	return isAttack;

}



void player::setPlayerDamage(float pDamage)
{
	this->setDamage(pDamage);

}
float player::getPlayerDamage()
{
	return this->getDamage();
}