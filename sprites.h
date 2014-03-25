//sprites.h
//very simple, just an interface to store and load sprites
//need to include i file read and image reader into this class

//this needs a sprite array which will be an array of stored images

//author: Richard Ellena
#pragma once
using namespace std;

class sprites
{
public:
	sprites& operator= (const sprites&);
	//constructors
	sprites();
	sprites(const sprites&);//copy const
	~sprites();
	void setSpriteCount(int);//set the #ofimages
	int getSpriteCount();//get #images
	void getSprites();//get the image arry
	void setSprites();//place the array of images into the obj
	GLuint getSpriteTex();	//return sprite texture
	void drawSprites();
	void drawSprites(GLfloat, GLfloat);	//draw sprite at position x, y
	void drawSprites(GLfloat, GLfloat, GLfloat, GLfloat);	//position x, y; scale x, y
	void loadTexture(const char*);	//load an image to opengl texture
	void setSpritePos(GLfloat, GLfloat);	//set sprite position x, y
	void setSpriteScale(GLfloat, GLfloat);	//scale sprite x, y
private:
	void deleteSprites();
	void copySprites(const sprites&);
	
	int spritecount;
	GLuint spriteTexture;
	GLfloat pos_x, pos_y, scale_x, scale_y;
};
