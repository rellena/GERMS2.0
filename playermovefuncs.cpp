#include "gameinclude.h"

extern player mainPlayer;
extern bool _move;
extern Point mouse;
extern int collide_with;
extern Enemy *enemy;
extern int enemy_size;
bool follow;
int chase;
Point P2;

Point movepoint;
bool colmove = false;

void playerMovement () 
{
	int col_flag;
	int mouse_flag;

	Point P1;
	if (_move == true)
	{
		//move until player hits mouse click
		if (follow == true)
		{
			mouse.x = enemy[chase].getPosition().x;
			mouse.y = enemy[chase].getPosition().y;
		}

		if (colmove == true && P2.x != enemy[collide_with].getPosition().x && P2.y != enemy[collide_with].getPosition().y)
			colmove = false;

		P1 = mainPlayer.getPosition();
		mainPlayer.move(mouse.x, mouse.y);

		if (checkCollisionsPlayer() == true && colmove == false)
		{
			mainPlayer.setPosition(P1.x, P1.y);
			//set mouse if necessary
			if (chase == collide_with)
			{
				_move = false;
				follow = false;

				mainPlayer.targetEnemyWithMouse(enemy,mainPlayer.getPosition().x,mainPlayer.getPosition().y);
				
				cout << "enemy1HPbefore = " << enemy[1].getHealth() << endl;
				//mainPlayer.targetEnemyWithMouse(enemy,mouse.x,mouse.y);
				cout << "enemy1HP = " << enemy[1].getHealth() << endl;
				cout << "enemy position = " << enemy[1].getPosition().x <<" "<< enemy[1].getPosition().y << endl;
				cout << "player position = " << mainPlayer.getPosition().x << " " << mainPlayer.getPosition().y << endl;
				cout << "enemy hp 2 = " << enemy[2].getHealth() << endl;
				cout << "player health atm = " << mainPlayer.getHealth() << endl;
			}
			else
			{
				if (mouse.x > enemy[collide_with].getPosition().x + enemy[collide_with].getRadius() && mouse.x < enemy[collide_with].getPosition().x + enemy[collide_with].getRadius()
					+ mainPlayer.getRadius() && mouse.y > enemy[collide_with].getPosition().y - enemy[collide_with].getRadius() - mainPlayer.getRadius() && mouse.y < 
					enemy[collide_with].getPosition().y + enemy[collide_with].getRadius() + mainPlayer.getRadius())
					//set x
					mouse.x = enemy[collide_with].getPosition().x + enemy[collide_with].getRadius() + mainPlayer.getRadius();
				else if (mouse.x < enemy[collide_with].getPosition().x - enemy[collide_with].getRadius() && mouse.x > enemy[collide_with].getPosition().x - enemy[collide_with].getRadius()
					- mainPlayer.getRadius() && mouse.y > enemy[collide_with].getPosition().y - enemy[collide_with].getRadius() - mainPlayer.getRadius() && mouse.y < 
					enemy[collide_with].getPosition().y + enemy[collide_with].getRadius() + mainPlayer.getRadius())
					//set x
					mouse.x = enemy[collide_with].getPosition().x - enemy[collide_with].getRadius() - mainPlayer.getRadius();

				if (mouse.y > enemy[collide_with].getPosition().y + enemy[collide_with].getRadius() && mouse.y < enemy[collide_with].getPosition().y + enemy[collide_with].getRadius()
					+ mainPlayer.getRadius() && mouse.x > enemy[collide_with].getPosition().x - enemy[collide_with].getRadius() - mainPlayer.getRadius() && mouse.x < 
					enemy[collide_with].getPosition().x + enemy[collide_with].getRadius() + mainPlayer.getRadius())
					//set y
					mouse.y = enemy[collide_with].getPosition().y + enemy[collide_with].getRadius() + mainPlayer.getRadius();
				else if (mouse.y < enemy[collide_with].getPosition().y - enemy[collide_with].getRadius() && mouse.y > enemy[collide_with].getPosition().y - enemy[collide_with].getRadius()
					- mainPlayer.getRadius() && mouse.x > enemy[collide_with].getPosition().x - enemy[collide_with].getRadius() - mainPlayer.getRadius() && mouse.x < 
					enemy[collide_with].getPosition().x + enemy[collide_with].getRadius() + mainPlayer.getRadius())
					//set y
					mouse.y = enemy[collide_with].getPosition().y - enemy[collide_with].getRadius() - mainPlayer.getRadius();

				//setting the col_flag
				if (abs(enemy[collide_with].getPosition().x - mainPlayer.getPosition().x) > abs(enemy[collide_with].getPosition().y - mainPlayer.getPosition().y))
				{
					if (enemy[collide_with].getPosition().x - mainPlayer.getPosition().x > 0)
					{
						col_flag = 32;
					}
					else
					{
						col_flag = 31;
					}
				}
				else if (abs(enemy[collide_with].getPosition().x - mainPlayer.getPosition().x) < abs(enemy[collide_with].getPosition().y - mainPlayer.getPosition().y))
				{
					if (enemy[collide_with].getPosition().y - mainPlayer.getPosition().y > 0)
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
					if (enemy[collide_with].getPosition().x - mainPlayer.getPosition().x > 0)
					{
						col_flag = 2;
					}
					else
					{
						col_flag = 1;
					}

					if (enemy[collide_with].getPosition().y - mainPlayer.getPosition().y > 0)
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
				if (mouse.x < enemy[collide_with].getPosition().x - enemy[collide_with].getRadius())
					mouse_flag = 1;
				//right
				else if (mouse.x > enemy[collide_with].getPosition().x + enemy[collide_with].getRadius())
					mouse_flag = 2;
				else
					mouse_flag = 3;

				//set up down
				//above
				if (mouse.y < enemy[collide_with].getPosition().y - enemy[collide_with].getRadius())
					mouse_flag += 10;
				//below
				else if (mouse.y > enemy[collide_with].getPosition().y + enemy[collide_with].getRadius())
					mouse_flag += 20;
				else
					mouse_flag += 30;
				
				switch (col_flag)
				{
					//left top
					case 11:
						if (mouse_flag == 13)
						{
							P1.x = enemy[collide_with].getPosition().x + enemy[collide_with].getRadius() + mainPlayer.getRadius();
							P1.y = enemy[collide_with].getPosition().y - enemy[collide_with].getRadius() - mainPlayer.getRadius();
						}
						else if (mouse_flag == 31 || mouse_flag == 11)
						{
							P1.x = enemy[collide_with].getPosition().x - enemy[collide_with].getRadius() - mainPlayer.getRadius();
							P1.y = enemy[collide_with].getPosition().y + enemy[collide_with].getRadius() + mainPlayer.getRadius();
						}
						else if (mouse_flag == 33)
						{
							P1.x = enemy[collide_with].getPosition().x + enemy[collide_with].getRadius() + mainPlayer.getRadius();
							P1.y = enemy[collide_with].getPosition().y + enemy[collide_with].getRadius() + mainPlayer.getRadius();
						}
						else
						{
							P1.x = mouse.x;
							P1.y = mouse.y;
						}
						break;
					//left bottom
					case 21:
						if (mouse_flag == 23)
						{
							P1.x = enemy[collide_with].getPosition().x + enemy[collide_with].getRadius() + mainPlayer.getRadius();
							P1.y = enemy[collide_with].getPosition().y + enemy[collide_with].getRadius() + mainPlayer.getRadius();
						}
						else if (mouse_flag == 31 || mouse_flag == 21)
						{
							P1.x = enemy[collide_with].getPosition().x - enemy[collide_with].getRadius() - mainPlayer.getRadius();
							P1.y = enemy[collide_with].getPosition().y - enemy[collide_with].getRadius() - mainPlayer.getRadius();
						}
						else if (mouse_flag == 33)
						{
							P1.x = enemy[collide_with].getPosition().x + enemy[collide_with].getRadius() + mainPlayer.getRadius();
							P1.y = enemy[collide_with].getPosition().y - enemy[collide_with].getRadius() - mainPlayer.getRadius();
						}
						else
						{
							P1.x = mouse.x;
							P1.y = mouse.y;
						}
						break;
					//left none
					case 31:
						if ((mouse_flag == 31 && mouse.y <= enemy[collide_with].getPosition().y) || mouse_flag == 13 || mouse_flag == 11 || mouse_flag == 12)
						{
							P1.x = enemy[collide_with].getPosition().x + enemy[collide_with].getRadius() + mainPlayer.getRadius();
							P1.y = enemy[collide_with].getPosition().y - enemy[collide_with].getRadius() - mainPlayer.getRadius();
						}
						else if ((mouse_flag == 31 && mouse.y > enemy[collide_with].getPosition().y) || mouse_flag == 23 || mouse_flag == 21 || mouse_flag == 22)
						{
							P1.x = enemy[collide_with].getPosition().x + enemy[collide_with].getRadius() + mainPlayer.getRadius();
							P1.y = enemy[collide_with].getPosition().y + enemy[collide_with].getRadius() + mainPlayer.getRadius();
						}
						else if (mouse_flag == 33)
						{
							P1.x = enemy[collide_with].getPosition().x + enemy[collide_with].getRadius() + mainPlayer.getRadius();
							P1.y = mouse.y;
						}
						break;
					//right top
					case 12:
						if (mouse_flag == 13)
						{
							P1.x = enemy[collide_with].getPosition().x + enemy[collide_with].getRadius() + mainPlayer.getRadius();
							P1.y = enemy[collide_with].getPosition().y + enemy[collide_with].getRadius() + mainPlayer.getRadius();
						}
						else if (mouse_flag == 32 || mouse_flag == 12)
						{
							P1.x = enemy[collide_with].getPosition().x - enemy[collide_with].getRadius() - mainPlayer.getRadius();
							P1.y = enemy[collide_with].getPosition().y - enemy[collide_with].getRadius() - mainPlayer.getRadius();
						}
						else if (mouse_flag == 33)
						{
							P1.x = enemy[collide_with].getPosition().x - enemy[collide_with].getRadius() - mainPlayer.getRadius();
							P1.y = enemy[collide_with].getPosition().y + enemy[collide_with].getRadius() + mainPlayer.getRadius();
						}
						else
						{
							P1.x = mouse.x;
							P1.y = mouse.y;
						}
						break;
					//right bottom
					case 22:
						if (mouse_flag == 23)
						{
							P1.x = enemy[collide_with].getPosition().x - enemy[collide_with].getRadius() - mainPlayer.getRadius();
							P1.y = enemy[collide_with].getPosition().y + enemy[collide_with].getRadius() + mainPlayer.getRadius();
						}
						else if (mouse_flag == 32 || mouse_flag == 22)
						{
							P1.x = enemy[collide_with].getPosition().x + enemy[collide_with].getRadius() + mainPlayer.getRadius();
							P1.y = enemy[collide_with].getPosition().y - enemy[collide_with].getRadius() - mainPlayer.getRadius();
						}
						else if (mouse_flag == 33)
						{
							P1.x = enemy[collide_with].getPosition().x - enemy[collide_with].getRadius() - mainPlayer.getRadius();
							P1.y = enemy[collide_with].getPosition().y - enemy[collide_with].getRadius() - mainPlayer.getRadius();
						}
						else
						{
							P1.x = mouse.x;
							P1.y = mouse.y;
						}
						break;
					//right none
					case 32:
						if ((mouse_flag == 32 &&  mouse.y >= enemy[collide_with].getPosition().y) || mouse_flag == 13 || mouse_flag == 12 || mouse_flag == 11)
						{
							P1.x = enemy[collide_with].getPosition().x - enemy[collide_with].getRadius() - mainPlayer.getRadius();
							P1.y = enemy[collide_with].getPosition().y - enemy[collide_with].getRadius() - mainPlayer.getRadius();
						}
						else if ((mouse_flag == 32 &&  mouse.y < enemy[collide_with].getPosition().y) || mouse_flag == 23 || mouse_flag == 22 || mouse_flag == 21)
						{
							P1.x = enemy[collide_with].getPosition().x - enemy[collide_with].getRadius() - mainPlayer.getRadius();
							P1.y = enemy[collide_with].getPosition().y + enemy[collide_with].getRadius() + mainPlayer.getRadius();
						}
						else if (mouse_flag == 33)
						{
							P1.x = enemy[collide_with].getPosition().x - enemy[collide_with].getRadius() - mainPlayer.getRadius();
							P1.y = mouse.y;
						}
						else
						{
							P1.x = mouse.x;
							P1.y = mouse.y;
						}
						break;
					//none top
					case 13:
						if ((mouse_flag == 13 && mouse.x >= enemy[collide_with].getPosition().x) || mouse_flag == 32 || mouse_flag == 12 || mouse_flag == 22)
						{
							P1.x = enemy[collide_with].getPosition().x + enemy[collide_with].getRadius() + mainPlayer.getRadius();
							P1.y = enemy[collide_with].getPosition().y + enemy[collide_with].getRadius() + mainPlayer.getRadius();
						}
						else if ((mouse_flag == 13 && mouse.x < enemy[collide_with].getPosition().x) || mouse_flag == 31 || mouse_flag == 11 || mouse_flag == 21)
						{
							P1.x = enemy[collide_with].getPosition().x - enemy[collide_with].getRadius() - mainPlayer.getRadius();
							P1.y = enemy[collide_with].getPosition().y + enemy[collide_with].getRadius() + mainPlayer.getRadius();
						}
						else if (mouse_flag == 33)
						{
							P1.x = mouse.x;
							P1.y = enemy[collide_with].getPosition().y + enemy[collide_with].getRadius() + mainPlayer.getRadius();
						}
						break;
					//none bottom
					case 23:
						if ((mouse_flag == 23 && mouse.x >= enemy[collide_with].getPosition().x) || mouse_flag == 32 || mouse_flag == 22 || mouse_flag == 12)
						{
							P1.x = enemy[collide_with].getPosition().x + enemy[collide_with].getRadius() + mainPlayer.getRadius();
							P1.y = enemy[collide_with].getPosition().y - enemy[collide_with].getRadius() - mainPlayer.getRadius();
						}
						else if ((mouse_flag == 23 && mouse.x < enemy[collide_with].getPosition().x) || mouse_flag == 31 || mouse_flag == 21 || mouse_flag == 11)
						{
							P1.x = enemy[collide_with].getPosition().x - enemy[collide_with].getRadius() - mainPlayer.getRadius();
							P1.y = enemy[collide_with].getPosition().y - enemy[collide_with].getRadius() - mainPlayer.getRadius();
						}
						else if (mouse_flag == 33)
						{
							P1.x = mouse.x;
							P1.y = enemy[collide_with].getPosition().y - enemy[collide_with].getRadius() - mainPlayer.getRadius();
						}
						break;
					default:
						break;
				}

				P2 = enemy[collide_with].getPosition();
				movepoint = P1;
				colmove = true;


			}
		}
		if (colmove == true)
		{
			//mainPlayer.setPosition(P1.x, P1.y);
			mainPlayer.move(movepoint.x, movepoint.y);

			if (mainPlayer.getPosition().x == movepoint.x && mainPlayer.getPosition().y == movepoint.y)
				colmove = false;
		}

		if (mainPlayer.getPosition().x == mouse.x && mainPlayer.getPosition().y == mouse.y)
			_move = false;
	}
}

void drawPlayer()
{
	int x, y, r;
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//get players position
	x = mainPlayer.getPosition().x;
	y = mainPlayer.getPosition().y;
	r = mainPlayer.getRadius();

	glEnable(GL_TEXTURE_2D);
	
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glLoadIdentity();                           
    glTranslatef(0.0f,0.0f, 0.0f);  
	glBindTexture(GL_TEXTURE_2D, mainPlayer.getSprites());
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex2f(x-r, y+r);
    glTexCoord2f(1, 0); glVertex2f(x+r, y+r);
    glTexCoord2f(1, 1); glVertex2f(x+r, y-r);
    glTexCoord2f(0, 1); glVertex2f(x-r, y-r);
	glEnd();
	//glutSwapBuffers();

	/*
	//draw our triangle
	glBegin(GL_TRIANGLES);
		glVertex3f(x,y + 20 ,0);
		glVertex3f(x -20, y-10,0);
		glVertex3f(x+20,y -10,0);
	glEnd();*/
	//glutSwapBuffers();//swap bufferes!!!! Important for animation
	glFlush();
}


