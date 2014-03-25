#include "gameinclude.h"

//player constructors
Enemy::Enemy()
:unit(), enName("")
{}

Enemy::Enemy(float h, float a,float d,float s,float r,float e, string cn, string cc, string en)
{
	//see unit decl, for const details
	unit(h,a,d,s,r,e,cn,cc);
	enName = en;
}
Enemy::~Enemy()
{
	deleteEnemy();
}

bool Enemy::loadEnemySprites(string filename)
{
	enSprite.loadTexture(filename.c_str());
    return true;
}

sprites& Enemy::getSprites()
{
	return enSprite;
}
//player operators

void Enemy::deleteEnemy()
{
}

Point*& Enemy::getMovePattern()
{
	return movepattern;
}

int Enemy::getmpSize()
{
	return mpsize;
}

void Enemy::setmpSize(int size)
{
	mpsize = size;
}

int Enemy::getMoveToPoint()
{
	return moveto;
}

void Enemy::setMoveToPoint(int to)
{
	moveto = to;
}
