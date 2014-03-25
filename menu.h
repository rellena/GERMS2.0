//menu.h
//class with global function to draw menu
//Author: Hao Vo


#pragma once
#include "text.h"
#include "sprites.h"

class menu
{
public:
	menu();
	void menuInit();
	void drawMenu();
	void drawHUD();
	void drawRectBorder(int x, int y, int w, int h, float size);
	void drawRectInside(float x, float y, float w, float h, float percent);
private:
	void drawMainMenu();
	void drawLoadMenu();
	void drawExitMenu();
	void drawInGameMenu();
	bool isMouseInside(int x, int y, int w, int h, float xOffset, float yOffset);

	void drawHpBar(float percent);
	void drawMpBar(float percent);

	float xOffset, yOffset;
	const int orgHeight, orgWidth;
	sprites menuLogo, menuBackground;
	sprites hudBack, hudButton;
};