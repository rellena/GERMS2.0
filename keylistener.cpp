#include "gameinclude.h"
extern player mainPlayer;
extern bool _move;
extern Enemy *enemy;

//keys pressed
//chooses a key based on the flag and then does a process for each key
//so far arrows move and thats it
void keypressed(unsigned char key, int x, int y)
{
    switch (key){
        case GLUT_KEY_RIGHT:
            _move = true;
			mainPlayer.move((mainPlayer.getPosition().x)+mainPlayer.getSpeed(), mainPlayer.getPosition().y);
			_move = false;
            break;

        case GLUT_KEY_LEFT:
            _move = true;
			mainPlayer.move((mainPlayer.getPosition().x)-mainPlayer.getSpeed(), mainPlayer.getPosition().y);
			_move = false;
        break;

        case GLUT_KEY_UP:
            _move = true;
			mainPlayer.move((mainPlayer.getPosition().x), mainPlayer.getPosition().y-mainPlayer.getSpeed());
			_move = false;
            break;

        case GLUT_KEY_DOWN:
            _move = true;
			mainPlayer.move((mainPlayer.getPosition().x), mainPlayer.getPosition().y+mainPlayer.getSpeed());
			_move = false;
        break;

		case 27: // Escape key
			glutLeaveMainLoop();
			exit (0);
			break;

		case 'a':
		break;

        default:
         break;
    }
    glutPostRedisplay();
}
