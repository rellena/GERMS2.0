#include "gameinclude.h"

//variables
Enemy *enemy;
bool *en_move;
int enemy_size;
extern int screenheight, screenwidth;
extern int en_collide_with;
extern player mainPlayer;
bool *col_move;
Point *enmovepoint;


//setup the enemies, very basic
void initializeEnemies()
{
	enemy_size = 5;
	enemy = new Enemy[enemy_size];
	en_move = new bool[enemy_size];

	col_move = new bool[enemy_size];
	for (int n=0; n<enemy_size;n++)
		col_move[n] = false;

	enmovepoint = new Point[enemy_size];
}

//set the enemys x, y, radius, enemy num is used
void setEnemy(float x, float y, float r, int en, float armor, float health, float damage, float range)
{
	enemy[en].setPosition(x,y);
	enemy[en].setRadius(r);
	enemy[en].setArmor(armor);
	enemy[en].setHealth(health);
	enemy[en].setDamage(damage);
	enemy[en].setRange(range);
}

//used to draw enemy to screen
void drawEnemy(float x, float y, float r, int p)
{
	enemy[p].getSprites().drawSprites(enemy[p].getPosition().x-(enemy[p].getRadius()),enemy[p].getPosition().y-enemy[p].getRadius(),(enemy[p].getRadius())*2,(enemy[p].getRadius())*2);
}

//en move, implemented later
void enemyMovement()
{
	Point P1;
	int col_flag;
	int move_flag;

	float cx, cy, cr;
	float mtx, mty;

	for (int x = 0; x<enemy_size; x++)
	{
		if (en_move[x] == true)
		{
			if (col_move[x] == false)
			{
				if (enemy[x].getPosition().x == enemy[x].getMovePattern()[enemy[x].getMoveToPoint()].x && enemy[x].getPosition().y == enemy[x].getMovePattern()[enemy[x].getMoveToPoint()].y)
				{
					enemy[x].setMoveToPoint(enemy[x].getMoveToPoint() + 1);
					if (enemy[x].getMoveToPoint() == enemy[x].getmpSize())
						enemy[x].setMoveToPoint(0);
				}

				P1 = enemy[x].getPosition();
				enemy[x].move(enemy[x].getMovePattern()[enemy[x].getMoveToPoint()].x, enemy[x].getMovePattern()[enemy[x].getMoveToPoint()].y);
			}

			if (checkCollisionsEnemy(x) == true && col_move[x] == false)
			{
				if (en_collide_with == -1)
				{	
					cx = mainPlayer.getPosition().x;
					cy = mainPlayer.getPosition().y;
					cr = mainPlayer.getRadius();
				}
				else
				{
					cx = enemy[en_collide_with].getPosition().x;
					cy = enemy[en_collide_with].getPosition().y;
					cr = enemy[en_collide_with].getRadius();
				}

				mtx = enemy[x].getMovePattern()[enemy[x].getMoveToPoint()].x;
				mty = enemy[x].getMovePattern()[enemy[x].getMoveToPoint()].y;
				enemy[x].setPosition(P1.x, P1.y);
				//set mouse if necessary

				/*if (mtx <= cx + cr && mtx >= cx - cr
					&& mty <= cy + cr && mty >= cy - cr)
					_move = false;
				else if (mtx <= cx + cr && mtx >= cx - cr
					&& mainPlayer.getPosition().y == mty)
					_move = false;
				else if (mty <= cy + cr && mty >= cy - cr
					&& mainPlayer.getPosition().x == mtx)
					_move = false;
				else
				{*/
					//if (mtx > cx + cr && mtx < cx + cr
					//	+ enemy[x].getRadius() && mty > cy - cr - enemy[x].getRadius() && mty < 
					//	cy + cr + enemy[x].getRadius())
					//	//set x
					//	enemy[x].getMovePattern()[enemy[x].getMoveToPoint()].x = cx + cr + enemy[x].getRadius();
					//else if (mtx < cx - cr && mtx > cx - cr
					//	- enemy[x].getRadius() && mty > cy - cr - enemy[x].getRadius() && mty < 
					//	cy + cr + enemy[x].getRadius())
					//	//set x
					//	enemy[x].getMovePattern()[enemy[x].getMoveToPoint()].x = cx - cr - enemy[x].getRadius();

					//if (mty > cy + cr && mty < cy + cr
					//	+ enemy[x].getRadius() && mtx > cx - cr - enemy[x].getRadius() && mtx < 
					//	cx + cr + enemy[x].getRadius())
					//	//set y
					//	enemy[x].getMovePattern()[enemy[x].getMoveToPoint()].y = cy + cr + enemy[x].getRadius();
					//else if (mty < cy - cr && mty > cy - cr
					//	- enemy[x].getRadius() && mtx > cx - cr - enemy[x].getRadius() && mtx < 
					//	cx + cr + enemy[x].getRadius())
					//	//set y
					//	enemy[x].getMovePattern()[enemy[x].getMoveToPoint()].y = cy - cr - enemy[x].getRadius();

					//setting the col_flag
					if (abs(cx - enemy[x].getPosition().x) > abs(cy - enemy[x].getPosition().y))
					{
						if (cx - enemy[x].getPosition().x > 0)
						{
							col_flag = 32;
						}
						else
						{
							col_flag = 31;
						}
					}
					else if (abs(cx - enemy[x].getPosition().x) < abs(cy - enemy[x].getPosition().y))
					{
						if (cy - enemy[x].getPosition().y > 0)
						{
							col_flag = 23;
						}
						else
						{
							col_flag = 13;
						}
					}
					else
					{
						if (cx - enemy[x].getPosition().x > 0)
						{
							col_flag = 2;
						}
						else
						{
							col_flag = 1;
						}

						if (cy - enemy[x].getPosition().y > 0)
						{
							col_flag += 20;
						}
						else
						{
							col_flag += 10;
						}
					}

					//setting the mouse flag
					//set left right
					//left
					if (mtx < cx - cr)
						move_flag = 1;
					//right
					else if (mtx > cx + cr)
						move_flag = 2;
					else
						move_flag = 3;

					//set up down
					//above
					if (mty < cy - cr)
						move_flag += 10;
					//below
					else if (mty > cy + cr)
						move_flag += 20;
					else
						move_flag += 30;
				
					switch (col_flag)
					{
						//left top
						case 11:
							if (move_flag == 13)
							{
								P1.x = cx + cr + enemy[x].getRadius();
								P1.y = cy - cr - enemy[x].getRadius();
							}
							else if (move_flag == 31 || move_flag == 11)
							{
								P1.x = cx - cr - enemy[x].getRadius();
								P1.y = cy + cr + enemy[x].getRadius();
							}
							else if (move_flag == 33)
							{
								P1.x = cx + cr + enemy[x].getRadius();
								P1.y = cy + cr + enemy[x].getRadius();
							}
							else
							{
								P1.x = mtx;
								P1.y = mty;
							}
							break;
						//left bottom
						case 21:
							if (move_flag == 23)
							{
								P1.x = cx + cr + enemy[x].getRadius();
								P1.y = cy + cr + enemy[x].getRadius();
							}
							else if (move_flag == 31 || move_flag == 21)
							{
								P1.x = cx - cr - enemy[x].getRadius();
								P1.y = cy - cr - enemy[x].getRadius();
							}
							else if (move_flag == 33)
							{
								P1.x = cx + cr + enemy[x].getRadius();
								P1.y = cy - cr - enemy[x].getRadius();
							}
							else
							{
								P1.x = mtx;
								P1.y = mty;
							}
							break;
						//left none
						case 31:
							if ((move_flag == 31 && mty <= cy) || move_flag == 13 || move_flag == 11 || move_flag == 12)
							{
								P1.x = cx + cr + enemy[x].getRadius();
								P1.y = cy - cr - enemy[x].getRadius();
							}
							else if ((move_flag == 31 && mty > cy) || move_flag == 23 || move_flag == 21 || move_flag == 22)
							{
								P1.x = cx + cr + enemy[x].getRadius();
								P1.y = cy + cr + enemy[x].getRadius();
							}
							else if (move_flag == 33)
							{
								P1.x = cx + cr + enemy[x].getRadius();
								P1.y = mty;
							}
							break;
						//right top
						case 12:
							if (move_flag == 13)
							{
								P1.x = cx + cr + enemy[x].getRadius();
								P1.y = cy + cr + enemy[x].getRadius();
							}
							else if (move_flag == 32 || move_flag == 12)
							{
								P1.x = cx - cr - enemy[x].getRadius();
								P1.y = cy - cr - enemy[x].getRadius();
							}
							else if (move_flag == 33)
							{
								P1.x = cx - cr - enemy[x].getRadius();
								P1.y = cy + cr + enemy[x].getRadius();
							}
							else
							{
								P1.x = mtx;
								P1.y = mty;
							}
							break;
						//right bottom
						case 22:
							if (move_flag == 23)
							{
								P1.x = cx - cr - enemy[x].getRadius();
								P1.y = cy + cr + enemy[x].getRadius();
							}
							else if (move_flag == 32 || move_flag == 22)
							{
								P1.x = cx + cr + enemy[x].getRadius();
								P1.y = cy - cr - enemy[x].getRadius();
							}
							else if (move_flag == 33)
							{
								P1.x = cx - cr - enemy[x].getRadius();
								P1.y = cy - cr - enemy[x].getRadius();
							}
							else
							{
								P1.x = mtx;
								P1.y = mty;
							}
							break;
						//right none
						case 32:
							if ((move_flag == 32 &&  mty >= cy) || move_flag == 13 || move_flag == 12 || move_flag == 11)
							{
								P1.x = cx - cr - enemy[x].getRadius();
								P1.y = cy - cr - enemy[x].getRadius();
							}
							else if ((move_flag == 32 &&  mty < cy) || move_flag == 23 || move_flag == 22 || move_flag == 21)
							{
								P1.x = cx - cr - enemy[x].getRadius();
								P1.y = cy + cr + enemy[x].getRadius();
							}
							else if (move_flag == 33)
							{
								P1.x = cx - cr - enemy[x].getRadius();
								P1.y = mty;
							}
							else
							{
								P1.x = mtx;
								P1.y = mty;
							}
							break;
						//none top
						case 13:
							if ((move_flag == 13 && mtx >= cx) || move_flag == 32 || move_flag == 12 || move_flag == 22)
							{
								P1.x = cx + cr + enemy[x].getRadius();
								P1.y = cy + cr + enemy[x].getRadius();
							}
							else if ((move_flag == 13 && mtx < cx) || move_flag == 31 || move_flag == 11 || move_flag == 21)
							{
								P1.x = cx - cr - enemy[x].getRadius();
								P1.y = cy + cr + enemy[x].getRadius();
							}
							else if (move_flag == 33)
							{
								P1.x = mtx;
								P1.y = cy + cr + enemy[x].getRadius();
							}
							break;
						//none bottom
						case 23:
							if ((move_flag == 23 && mtx >= cx) || move_flag == 32 || move_flag == 22 || move_flag == 12)
							{
								P1.x = cx + cr + enemy[x].getRadius();
								P1.y = cy - cr - enemy[x].getRadius();
							}
							else if ((move_flag == 23 && mtx < cx) || move_flag == 31 || move_flag == 21 || move_flag == 11)
							{
								P1.x = cx - cr - enemy[x].getRadius();
								P1.y = cy - cr - enemy[x].getRadius();
							}
							else if (move_flag == 33)
							{
								P1.x = mtx;
								P1.y = cy - cr - enemy[x].getRadius();
							}
							break;
						default:
							break;
					}

					enemy[x].move(P1.x,P1.y);
					enmovepoint[x] = P1;
					col_move[x] = true;
				//}
			}
			else if (col_move[x] == true)
			{
				enemy[x].move(enmovepoint[x].x, enmovepoint[x].y);

				if (enemy[x].getPosition().x == enmovepoint[x].x && enemy[x].getPosition().y == enmovepoint[x].y)
					col_move[x] = false;
			}
		}
	}
}

void enemyMovementStart()
{
	srand(time(NULL));

	for (int x=0; x<enemy_size; x++)
	{
		enemy[x].setmpSize(3);
		enemy[x].getMovePattern() = new Point[3];
		enemy[x].setMoveToPoint(0);

		for (int y=0; y<3; y++)
		{
			enemy[x].getMovePattern()[y].x = rand() % (screenwidth - (int)enemy[x].getRadius()) + (int)enemy[x].getRadius();
			enemy[x].getMovePattern()[y].y = rand() % (screenheight - (int)enemy[x].getRadius()) + (int)enemy[x].getRadius();
		}

		en_move[x] = true;
	}

}

bool isAttackingThePlayer(player playerUnit, float x, float y)
{
	bool enemyAttacksPlayer = false;
	for( int i = 0; i < enemy_size; i++)
	{//for begin
		float enemyDistanceX = enemy[i].getPosition().x - playerUnit.getPosition().x;// x = x2 - x1
		float distanceX = enemyDistanceX * enemyDistanceX;//x^2
		float enemyDistanceY = enemy[i].getPosition().y - playerUnit.getPosition().y;//y = y2-y1
		float distanceY = enemyDistanceY * enemyDistanceY;// y^2
		float distanceTotal = sqrt(distanceX + distanceY);//sqrt(x^2 + y^2)

		//if the distance from player to enemy is less than or same as enemy's range
		if(distanceTotal <= enemy[i].getRange() )
		{// if in for begin
			enemyAttacksPlayer = true;
			float damageCalculation = enemy[i].getDamage() - ( (enemy[i].getDamage())/playerUnit.getArmor() );
			float player_health = playerUnit.getHealth() - damageCalculation;
			playerUnit.setHealth(player_health);
			cout << "player health atm = " << playerUnit.getHealth() << endl;
			if(playerUnit.getHealth() <= 0)	//enemy died
			{//if hp start
					glClear(GL_DEPTH_BUFFER_BIT);//get rid of the player
			}//if hp end

		}//if in loop end
	enemyAttacksPlayer = false;
	}// for end
	
	return enemyAttacksPlayer;

}
