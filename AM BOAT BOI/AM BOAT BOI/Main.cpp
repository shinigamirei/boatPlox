
#include <iostream>
#include "buoy.h"
#include "Boat.h"

#  include <GL/glew.h>
#  include <GL/freeglut.h>
#  include <GL/glext.h>
#pragma comment(lib, "glew32.lib") 

using namespace std;

#define pi = 3.142
// Globals.
static float square_color[3] = { 1.0, 0.0, 0.0 }; // Color of the square.
Boat player;

// Drawing routine.
void drawScene(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	
	gluLookAt(player.displacement.x, player.displacement.y + 7, player.displacement.z - 15,
		player.displacement.x,0, player.displacement.z,
		0.0, 1.0, 0.0);
	
	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);

	glBegin(GL_POLYGON);
	glVertex3f(-5000.0, 0.0, -5000.0);
	glVertex3f(5000.0, 0.0, -5000.0);
	glVertex3f(5000.0, 0.0, 5000.0);
	glVertex3f(-5000.0, 0.0, 5000.0);
	glEnd();
	glPopMatrix();

	glColor3f(0.0, 1.0, 0.0);
	//for i=0, i <= VAL i++
	/*
	t = 2 *pi *i/VAL
	vert(X +const(t) * r, Y + sin(t)* r,z
	*/

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	
	player.drawBoat();
	buoy start;
	start.draw_Start();

	for (int j = 0;j < 10; j++)
	{
		buoy boip;
		buoy boiq;
		boip.position(-20, 0, j * 40);
		boiq.position(20, 0, j * 40);
		boip.draw();
		boiq.draw();
	}
	std::cout << player.acceleration.z;

	glutSwapBuffers();
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0, 1, 0.01, 1000.0);
	/*
	glMatrixMode(GL_PROJECTION);
	glViewport(0, 0, w, h);
	//glLoadIdentity();
	gluPerspective(100.0,(double)w/(double)h,0.01,1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();	
	*/
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	case int('w') :
		player.increase_Acceleration();
		break;
	case int('s') :
		player.decrease_Acceleration();
		break;
	case int('a') :
		player.rotate_Left();
		break;
	case int('d') :
		player.rotate_Right();
		break;
	default:
		break;
	}
}

// Initialization routine.
void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

void GamLEP()
{
	player.turning();
	player.motion();
	glutPostRedisplay();
}
// Main routine.
int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitContextVersion(4, 2);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Baot");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);
	glutIdleFunc(GamLEP);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}