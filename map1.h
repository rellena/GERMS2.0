

#pragma once

using namespace std;

class map1
{
public:
	map1();
	void drawMap1();
	int loadMapImage();
	GLuint getMap();

private:
	GLuint mapImage;
};