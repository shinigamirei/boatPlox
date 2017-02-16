
#include <iostream>

#  include <GL/glew.h>
#  include <GL/freeglut.h>
#  include <GL/glext.h>
#pragma comment(lib, "glew32.lib") 

using namespace std;


// Globals.
static float square_color[3] = { 1.0, 0.0, 0.0 }; // Color of the square.
double forwa = 0.0;
double boattopz[20] = {-4,-2,-2,-1,1,2,2,4,6,2,1,-1,-2,-4,-6,-3,1,0,6,3};
double boattopx[20] = {4,12,4,4,4,4,12,4,-2,4,-2,4,-2,4,-2,-12,-2,-12,-2,-12};
// Drawing routine.
void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 0.0, 1.0);

	glBegin(GL_POLYGON);
	glVertex3f(-500.0, 0.0, -500.0);
	glVertex3f(500.0, 0.0, -500.0);
	glVertex3f(500.0, 0.0, 500.0);
	glVertex3f(-500.0, 0.0, 500.0);
	glEnd();

	glColor3f(0.0, 1.0, 0.0);
	/*	glBegin(GL_POLYGON);
		glVertex3f(forwa-10.0, 0.0, -10.0);
		glVertex3f(forwa+10.0, 0.0, -10.0);
		glVertex3f(forwa+10.0, 0.0, 10.0);
		glVertex3f(forwa+-10.0, 0.0, 10.0);
		glEnd();
	*/



	glBegin(GL_TRIANGLE_STRIP);
	for (int i = 0;i < 20;i++)
	{
		glVertex3f(boattopx[i], 1, boattopz[i]);
	}
	glEnd();

	glutSwapBuffers();
	glutPostRedisplay();

}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0,(double)w/(double)h,0.01,100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(-10.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
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
		forwa += 1;
		break;
	default:
		break;
	}
}

// Initialization routine.
void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);

	// Make menu.
	//makeMenu();
}

void GamLEP()
{
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
	//glutIdleFunc(GamLEP);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}
