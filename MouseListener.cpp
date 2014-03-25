//mouselistener.cpp
//This is the setup for mouse listener. Edit where necessary.
//Author: Richard Ellena
#include "gameinclude.h"

//Public Mouse Listener Functions
//Private Mouse Listener Functions
//GLOBAL VARIABLES
bool wasclicked_LB = false, wasclicked_RB = false, wasclicked_MB = false, ingame = false, _move = false;
Point mouse, mouseP;
extern int screenheight;
extern bool follow;
extern Enemy *enemy;
extern int chase;
extern int enemy_size;


void mouseButton(int button, int state, int x, int y)
{
	//choose state of mouse UP or Down
	if (state == GLUT_UP)
	{
		//which button was pressed
		switch (button)
		{
		case GLUT_LEFT_BUTTON:
			break;
		case GLUT_RIGHT_BUTTON:
			wasclicked_RB = false;
			break;
		case GLUT_MIDDLE_BUTTON:
			break;
		default:
			break;
		}
	}
	if (state == GLUT_DOWN)
	{
		switch (button)
		{
		case GLUT_LEFT_BUTTON:
			wasclicked_LB = true;
			break;
		case GLUT_RIGHT_BUTTON:
			//update x and y point to be sent to player
			if (ingame == true)
			{
				mouse.x = x;
				mouse.y = y;
				wasclicked_RB = true;
				_move = true;
				follow = false;
				chase = -1;
			
				for (int x=0; x< enemy_size; x++)
				{
					if (mouse.x <= enemy[x].getPosition().x + enemy[x].getRadius() && mouse.x >= enemy[x].getPosition().x - enemy[x].getRadius()
						&& mouse.y <= enemy[x].getPosition().y + enemy[x].getRadius() && mouse.y >= enemy[x].getPosition().y - enemy[x].getRadius() && follow == false)
					{
						follow = true;
						chase = x;
					}
				}
			}
			break;
		case GLUT_MIDDLE_BUTTON:
			break;
		default:
			break;
		}
	}
}

void mouseActive(int x, int y)
{
	if (wasclicked_LB == true && ingame == true)		
	{
		//update to player while mouse is held
		mouse.x = x;
		mouse.y = y;
	}
}
void mousePassive(int x, int y)
{
	mouseP.x = x;
	mouseP.y = y;
}
