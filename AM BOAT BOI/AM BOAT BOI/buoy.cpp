#include "buoy.h"
#  include <GL/glew.h>
#  include <GL/freeglut.h>
#  include <GL/glext.h>

buoy::buoy()
{
	buoyno = 120;
}


buoy::~buoy()
{
}

void buoy::position(int x, int y, int z)
{
	pos.x = x;
	pos.y = y;
	pos.z = z;
}

void buoy::draw_Start()
{
	glBegin(GL_POLYGON);
	glVertex3f(-40,3,0);
	glVertex3f(-40, 6, 0);
	glVertex3f(40, 6, 0);
	glVertex3f(40, 3, 0);
	glEnd();
}

void buoy::draw()
{
	glPushMatrix();
	glTranslatef (pos.x,pos.y,pos.z);
	//buoy base square
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-3, 0, -3);//1
	glVertex3f(-3, 3, -3);//2
	glVertex3f(3, 0, -3);//3
	glVertex3f(3, 3, -3);//4
	glVertex3f(3, 0, 3);//5
	glVertex3f(3, 3, 3);//6
	glVertex3f(-3, 0, 3);//7
	glVertex3f(-3, 3, 3);//8
	glVertex3f(-3, 0, -3);//9
	glVertex3f(-3, 3, -3);
	glVertex3f(-3, 0, 3);
	glVertex3f(3, 0, 3);
	glVertex3f(3, 0, -3);
	glVertex3f(-3, 0, -3);
	glEnd();

	//boi pole
	glColor3f(1, 0, 0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-1, 3, -1);
	glVertex3f(-1, 10, -1);
	glVertex3f(1, 3, -1);
	glVertex3f(1, 10, -1);
	glVertex3f(1, 3, 1);
	glVertex3f(1, 10, 1);
	glVertex3f(-1, 3, 1);
	glVertex3f(-1, 10, 1);
	glVertex3f(-1, 3, -1);
	glVertex3f(-1, 10, -1);
	glEnd();
	glPopMatrix();

	//boui bell/end
	glPushMatrix();
	glTranslatef(pos.x, pos.y, pos.z);
	glTranslatef(0,10,0);
	glutSolidSphere(2, 10, 10);
	glPopMatrix();

}