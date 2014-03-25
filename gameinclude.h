//This is the master include header. Any includes and headers
//you want to add to the program, just add here and then include this
//file to the header or cpp that you are writing.

//Author: Richard Ellena
#include <freeglut.h>
#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include <math.h>
#include <thread>
#include "MouseListener.h"
#include "player.h"
#include "sprites.h"
#include "unit.h"
#include "Point.h"
#include "wtypes.h"
#include "keylistener.h"
#include "GLfuncs.h"
#include "playermovefuncs.h"
#include "enemyhandler.h"
#include "collisions.h"
#include "lib/SOIL.h"
#include "text.h"
#include "menu.h"
#include "Enemy.h"
#include "map1.h"

using namespace std;

