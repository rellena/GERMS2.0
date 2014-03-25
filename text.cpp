//text.cpp
//A simple class that draw text on screen using function from freeglut
//For performance, instead of setting color, linewidth, scale... inside this class,
//	it will be set outside of this class, because when we draw a menu, all the text
//	of the menu will be the same, so if we have option for set color inside the class
//	then opengl will need to call function to set each of text object's color, scale... 
//	seperately for each text object, and it is a waste of CPU cycle.
//
//Author: Hao Vo

#include "gameinclude.h"

//Constructor
text::text(const unsigned char* t)
	:strText(t),
	txtPosX(0), txtPosY(0),
	txtScaleX(1), txtScaleY(1), 
	boxR(1), boxB(1), boxG(1), boxA(0.3)
{}

text::text(const unsigned char* t, GLfloat x, GLfloat y, GLfloat sx, GLfloat sy)
	:strText(t),
	txtPosX(x), txtPosY(y),
	txtScaleX(sx), txtScaleY(sy),
	boxR(1), boxB(1), boxG(1), boxA(0.3)
{}

void text::setText(const unsigned char* t)
{
	text::strText = t;}

const unsigned char* text::getText()
{
	return text::strText;}

void text::setTextPos(GLfloat x, GLfloat y)
{
	text::setTextPosX(x);
	text::setTextPosY(y);}

void text::setTextScale(GLfloat x, GLfloat y)
{
	text::setTextScaleX(x);
	text::setTextScaleY(y);}

void text::setTextPosX(GLfloat x)
{
	text::txtPosX = x;}

void text::setTextPosY(GLfloat y)
{
	text::txtPosY = y;}

void text::setTextScaleX(GLfloat sx)
{
	text::txtScaleX = sx;}

void text::setTextScaleY(GLfloat sy)
{
	text::txtScaleY = sy;}

void text::setTextBoxColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
	boxR = r;
	boxG = g;
	boxB = b;
	boxA = a;
}

GLfloat text::getTxtPosX()
{
	return text::txtPosX;}

GLfloat text::getTxtPosY()
{
	return text::txtPosY;}

GLfloat text::getTxtScaleX()
{
	return text::txtScaleX;}

GLfloat text::getTxtScaleY()
{
	return text::txtScaleY;}

void text::drawText()
{
	glPushMatrix();
		glTranslatef(getTxtPosX(), getTxtPosY(), 0.0);
		glScalef(getTxtScaleX(), -getTxtScaleY(), 1.0);
		glutStrokeString(GLUT_STROKE_ROMAN, text::getText());
	glPopMatrix();
}

void text::drawText(GLfloat x, GLfloat y, GLfloat sx, GLfloat sy)
{
	text::setTextPos(x, y);
	text::setTextScale(sx, sy);
	text::drawText();
}

void text::drawTextBox(GLfloat x, GLfloat y, GLfloat w, GLfloat h)
{
	glColor4f(boxR, boxG, boxB, boxA);
	glBegin( GL_QUADS );
		glVertex2f(x, y);
		glVertex2f(x+w, y);
		glVertex2f(x+w, y+h);
		glVertex2f(x, y+h);
	glEnd();
}

