
#include "gameinclude.h"

map1::map1()
{}

extern int screenheight, screenwidth;

int map1::loadMapImage()
{
	mapImage = SOIL_load_OGL_texture("Textures/bloodvessel.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    //if(playerSprite[0] == 0) return false;
   // glBindTexture(GL_TEXTURE_2D, playerSprite[0]);
   // glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
   // glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    return true;
}

GLuint map1::getMap()
{
	return mapImage;
}

void map1::drawMap1()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);
	
	glPushMatrix();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();                           
    glTranslatef(0.0f,0.0f, 0.0f);
	glBindTexture(GL_TEXTURE_2D, getMap());
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex2f(0, 0);
	glTexCoord2f(0, 1); glVertex2f(0, screenheight);
	glTexCoord2f(1, 1); glVertex2f(screenwidth, screenheight);
    glTexCoord2f(1, 0); glVertex2f(screenwidth, 0);
    
    
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();

	glFlush();
}