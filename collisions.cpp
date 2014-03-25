#include "gameinclude.h"

extern Enemy *enemy;
extern int enemy_size;
extern bool *en_move;
extern player mainPlayer;
extern bool _move;

int collide_with, en_collide_with;

//collisons.cpp


//CODES FOR COLLISION POINT MODIFIER(X && Y)
bool checkCollidePlayer(int x)
{
	int distance = pow((float)(pow(mainPlayer.getPosition().x - enemy[x].getPosition().x, 2) + pow(mainPlayer.getPosition().y - enemy[x].getPosition().y, 2)), 0.5f);

	if (distance - (mainPlayer.getRadius() + enemy[x].getRadius()) <= 0)
		return true;
	else
		return false;
}

bool checkCollisionsPlayer()
{
	bool collide = false;
	float x, y;
	if (_move == true)
	{
		for (int x=0; x < enemy_size; x++)
		{
			collide = checkCollidePlayer(x);
			if (_move == true && collide == true)
			{
				collide_with = x;
				x = enemy_size;
			}
		}
	}

	return collide;
}

bool checkCollideEnemy(int en, int x)
{
	int distance = pow((float)(pow(enemy[en].getPosition().x - enemy[x].getPosition().x, 2) + pow(enemy[en].getPosition().y - enemy[x].getPosition().y, 2)), 0.5f);

	if (distance - (enemy[en].getRadius() + enemy[x].getRadius()) <= 0)
		return true;
	else
		return false;
}

bool checkCollisionsEnemy(int en)
{
	bool collide = false;
	float x, y;
	if (en_move[en] == true)
	{
		for (int x=0; x < enemy_size; x++)
		{
			if (x != en)
			{
				collide = checkCollideEnemy(en, x);
				if (collide == true)
				{
					en_collide_with = x;
					x = enemy_size;
				}
			}
		}

		if (checkCollidePlayer(en) == true)
		{
			collide = true;
			en_collide_with = -1;
		}

	}
	return collide;
}


