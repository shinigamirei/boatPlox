#include "buoy.h"
#  include <GL/glew.h>
#  include <GL/freeglut.h>
#  include <GL/glext.h>

buoy::buoy()
{
}


buoy::~buoy()
{
}

void buoy::draw()
{
	glPushMatrix();
	glTranslatef (pos.x,pos.y,pos.z);
	glutSolidSphere(5,10,10);
	glPopMatrix();
}