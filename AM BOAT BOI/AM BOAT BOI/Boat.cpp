#include "Boat.h"
#  include <GL/glew.h>
#  include <GL/freeglut.h>
#  include <GL/glext.h>
Boat::Boat()
{
	acceleration = glm::vec3(0.0f, 0.0f, 0.0f);
	heading = glm::vec3(0.0f, 0.0f, -1.0f);
	velocity = glm::vec3(1.0f, 0.0f, 0.0f);
	displacement = glm::vec3(0, 0, 0);
	rotation = 0;

}

Boat::~Boat()
{
}

void Boat::motion()
{
	displacement = displacement + velocity;
}

void Boat::drawBoat()
{
	glPushMatrix();
	glTranslatef(-2, 0, 0);
	drawProw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2, 0, 0);
	drawProw();
	glPopMatrix();

	glBegin(GL_TRIANGLE_STRIP);
	
	glVertex3f(-3.5, 1, 0);
	glVertex3f(-2, 1, -7);
	glVertex3f(3.5, 1, 0);
	glVertex3f(2, 1, -7);
	
	
	glEnd();
}

void Boat::drawProw()
{
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-1.5, 1, 0);
	glVertex3f(1.5, 1, 0);
	glVertex3f(-1, 1, 3.5);
	glVertex3f(1, 1, 3.5);
	glVertex3f(-0.8, 1, 4.5);
	glVertex3f(0.8, 1, 4.5);
	glVertex3f(-0.2, 1, 5.5);
	glVertex3f(0.2, 1, 5.5);
	glEnd();
}
