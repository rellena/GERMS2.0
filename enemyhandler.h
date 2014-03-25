#pragma once
using namespace std;

//setup enemies
//this will be made into a class eventually
void initializeEnemies();
void setEnemy(float, float, float, int, float, float, float, float);
void drawEnemy(float, float, float, int);
void enemyMovement();
void enemyMovementStart();
bool isAttackingThePlayer(player playerUnit, float x, float y);
