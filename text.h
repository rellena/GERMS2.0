//text.h
//A simple class that draw text on screen using function from freeglut
//For performance, instead of setting color, linewidth, scale... inside this class,
//	it will be set outside of this class, because when we draw a menu, all the text
//	of the menu will be the same, so if we have option for set color inside the class
//	then opengl will need to call function to set each of text object's color, scale... 
//	seperately for each text object, and it is a waste of CPU cycle.
//
//Author: Hao Vo

#pragma once



class text
{
public:
	text(const unsigned char *);	//constructor
	text(const unsigned char*, GLfloat, GLfloat, GLfloat, GLfloat);
	void setText(const unsigned char*);
	const unsigned char* getText();
	void setTextPos(GLfloat x, GLfloat y);
	void setTextScale(GLfloat sx, GLfloat sy);
	void setTextPosX(GLfloat x);
	void setTextPosY(GLfloat y);
	void setTextScaleX(GLfloat sx);
	void setTextScaleY(GLfloat sy);
	void setTextBoxColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
	GLfloat getTxtPosX();
	GLfloat getTxtPosY();
	GLfloat getTxtScaleX();
	GLfloat getTxtScaleY();
	void drawText();
	void drawText(GLfloat x, GLfloat y, GLfloat sx, GLfloat sy);
	void drawTextBox(GLfloat x, GLfloat y, GLfloat w, GLfloat h);

private:
	const unsigned char* strText;
	GLfloat txtPosX, txtPosY, txtScaleX, txtScaleY;
	GLfloat boxR, boxG, boxB, boxA;

};