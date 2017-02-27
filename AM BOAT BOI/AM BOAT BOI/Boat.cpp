#include "Boat.h"
#  include <GL/glew.h>
#  include <GL/freeglut.h>
#  include <GL/glext.h>
#  include <glm\gtx\rotate_vector.hpp>
Boat::Boat()
{
	acceleration = glm::vec3(0.0f, 0.0f, 0.0f); //glutget(GLUT_ELAPSED_TIME);
	heading = glm::vec3(0.0f, 0.0f, 1.0f);
	velocity = glm::vec3(0.0f, 0.0f, 0.0f);
	displacement = glm::vec3(0, 0, 0);
	rotation = 0;

}

Boat::~Boat()
{
}

void Boat::increase_acceleration()
{
	
}

void Boat::decrease_acceleration()
{

}

void Boat::turning()
{
	if (rotation > 360)
		rotation -= 360;
	else if (rotation < -360)
		rotation += 360;
	glRotatef(rotation, 0, 1, 0);
	heading = glm::rotateY(heading, glm::radians(rotation));
}

void Boat::motion()
{ 
	if (acceleration.z > 0.01)
		acceleration.z = 0.01;
	velocity = velocity + acceleration;
	if (velocity.z > 5)
		velocity.z = 5;
	else if (velocity.z < -2)
		velocity.z = -2;
	displacement = displacement + velocity;
}

void Boat::drawBoat()
{
	glPushMatrix();
	glTranslatef(displacement.x, displacement.y, displacement.z);
	glRotatef(rotation, 0, 1, 0);
	glTranslatef(-2, 0, 0);
	
	drawProw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(displacement.x, displacement.y, displacement.z);
	glRotatef(rotation, 0, 1, 0);
	glTranslatef(2, 0, 0);
	
	drawProw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(displacement.x, displacement.y, displacement.z);

	glRotatef(rotation, 0, 1, 0);

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-3.5, 1, 0);
	glVertex3f(-2, 1, -7);
	glVertex3f(3.5, 1, 0);
	glVertex3f(2, 1, -7);	
	glEnd();

	glPopMatrix();
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
