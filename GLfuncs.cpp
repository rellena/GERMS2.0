#include "gameinclude.h"

extern int screenwidth;
extern int screenheight;
extern player mainPlayer;
extern bool _move;
extern Point mouse;
extern Enemy *enemy;
extern bool *en_move;
extern int enemy_size;
extern sprites spr;
extern bool ingame;
extern menu Menu;
extern map1 map;
extern bool follow;
extern int chase;

void resize(int width, int height)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();//unsure what this does?
	gluOrtho2D(0.0f, screenwidth, 0, screenheight);//changes the view to the screen ~ IMPORTANT
	
	glScalef(1, -1, 1);//inverts the y axis
	glTranslatef(0, -height, 0);//changes the xy scale, in opengl, 0,0 is bottom left, this makes it upper left
	glViewport(0, 0, width, height);
	glMatrixMode(GL_MODELVIEW);
	
	screenwidth = width;
	screenheight = height;
}

void getResolution()
{
   RECT desktop;
   // Get a handle to the desktop window
   const HWND hDesktop = GetDesktopWindow();
   // Get the size of screen to the variable desktop
   GetWindowRect(hDesktop, &desktop);
   // The top left corner will have coordinates (0,0)
   // and the bottom right corner will have coordinates
   // (horizontal, vertical)
   screenwidth = desktop.right;
   screenheight = desktop.bottom;
}

void display(void)
{
	if (!ingame )
	{
		Menu.drawMenu();
	}
	else 
	{
		for (int x=0; x<enemy_size; x++)
		{
			if(enemy[x].getHealth() <= 0)	//enemy died
			{//if hp start
				if (chase == x)
				{
					chase = -1;
					follow = false;
				}
				//get "rid" of a dead enemy
				Enemy temp = enemy[x];
				
				enemy[x] = enemy[enemy_size-1];
					
				enemy[enemy_size - 1] = temp;

				enemy_size --;//decrement the amount of enemies
				//you killed everything
				if(enemy_size == 0 )
					cout << "you win" << endl;

			}//if hp end
		}
		//movements handling
		enemyMovement();
		playerMovement();//player collisons handled inside this function

		//player drawing
		//glPushAttrib(GL_CURRENT_BIT);//keeps players color from changing
		glColor4f(1.0,1.0,1.0,1.0);
		map.drawMap1();

		drawPlayer();
		for (int p =0; p < enemy_size; p++)
		{
			drawEnemy(enemy[p].getPosition().x, enemy[p].getPosition().y, enemy[p].getRadius(), p);
		}
		//glColor3f(0.0, 1.0, 0.0); 
	}

	glutSwapBuffers();//swap bufferes!!!! Important for animation
	glFlush();

	Sleep(10);
}