//MAIN
//This main is very basic. Only prints a polygon to the screen.
//This was a test for opengl. Anyone feel free to edit this whole thing.
#include "gameinclude.h"

player mainPlayer;
extern bool ingame, wasclicked_LB, wasclicked_RB, wasclicked_MB, _move;
extern Point mouse;
extern bool en_move;
extern Enemy *enemy;
extern int enemy_size;
menu Menu;
extern bool inMainMenu;
map1 map;

void setStartPlayer(float hp, float armor, float damage, float speed, float range, float energy, string charName, string charClass);
int screenwidth, screenheight;

int main(int argc, char* argv[])
{
	getResolution();//set resolution to screen
	//set intial game variable
	initializeEnemies();
	//setup player
	setStartPlayer(180,70,20,3,50,100,"Paranmosa","tanky");

	ingame = false;
	//setup enemies
	setEnemy(0,0,15,0,100,150,80,80);
	setEnemy(300,500,25,1,100,150,80, 80);
	setEnemy(1000,80,20,2,100,150,80, 80);
	setEnemy(20,555,16,3,100,150,80, 80);
	setEnemy(700,200,18,4,100,150,80, 80);
	
	
	//openGL HANDLES~~~~~~~~~~~~~~~~
	//initialize window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); //disply mode with one buffer and colored
	glutInitWindowPosition(0, 0);//windoww position from upper left corner
	glutInitWindowSize(screenwidth,screenheight);//set size of viewing window
	
	glutCreateWindow("GERMS!");//create window

	map.loadMapImage();
	Menu.menuInit();
	mainPlayer.loadPlayerSprites();
	for (int p=0; p<enemy_size; p++)
	{
		enemy[p].loadEnemySprites("Textures/WhiteBloodCell.png");
		enemy[p].setSpeed(0.7);
	}

	enemyMovementStart();
	
	//funcs to adjust screen and scale to actual pixels of viewing window
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();//unsure what this does?
	gluOrtho2D(0.0f, screenwidth, 0, screenheight);//changes the view to the screen ~ IMPORTANT
	glScalef(1, -1, 1);//inverts the y axis
	glTranslatef(0, -screenheight, 0);//changes the xy scale, in opengl, 0,0 is bottom left, this makes it upper left
	glMatrixMode(GL_MODELVIEW);
	glutFullScreen();

	glutMouseFunc(mouseButton);
	glutPassiveMotionFunc(mousePassive);
	glutKeyboardFunc(keypressed);//allows use of special keys such as arrow keys
	glutDisplayFunc(display);//calls display
	glutIdleFunc(display);//when glut is idle
	glutReshapeFunc(resize);//resize

	glutMainLoop();//start the glut loop

	return 0;
}

void setStartPlayer(float hp, float armor, float damage, float speed, float range, float energy, string charName, string charClass)
{
	mainPlayer.setHealth(hp);
	mainPlayer.setArmor(armor);
	mainPlayer.setDamage(damage);
	mainPlayer.setSpeed(speed);
	mainPlayer.setRange(range);
	mainPlayer.setEnergy(energy);
	mainPlayer.setPosition(screenwidth/2,screenheight/2);//set mainplayer at a positon!
	mainPlayer.setRadius(20);
}