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
void Boat::increase_Acceleration()
{
	acceleration.x += 0.01;
	acceleration.z += 0.01;
}
void Boat::decrease_Acceleration()
{
	acceleration.x -= 0.01;
	acceleration.z -= 0.01;
}

void Boat::rotate_Left()
{
	rotation += 2.0;
	glRotatef(rotation, 0, 1, 0);
	heading = glm::rotateY(heading, glm::radians(2.0f));

}
void Boat::rotate_Right()
{
	rotation -= 2.0;
	glRotatef(rotation, 0, 1, 0);
	heading = glm::rotateY(heading, glm::radians(-2.0f));
}
void Boat::turning()
{
	if (rotation > 360)
		rotation -= 360;
	else if (rotation < -360)
		rotation += 360;
}

void Boat::motion()
{ 
	//setting maximum acceleration
	if (acceleration.z > 0.03)
	{
		acceleration.x = 0.03;
		acceleration.z = 0.03;
	}

	velocity = velocity + (acceleration*heading);
	//slows down boat when theres no acceleration
	if (velocity.x > 0)
		velocity.x -= ((0.01* velocity.x)+0.1);
	else if (velocity.x < 0)
		velocity.x += ((-0.01* velocity.x)-0.1);
	if (velocity.z > 0)
		velocity.z -= ((0.01* velocity.z)+0.1);
	else if (velocity.z < 0)
		velocity.z += ((-0.01* velocity.z)-0.1);
	//max and min speeds
	if (velocity.x > 2)
		velocity.x = 2;
	else if (velocity.x < -2)
		velocity.x = -2;
	if (velocity.z > 2)
		velocity.z = 2;
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

	glPushMatrix();
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex3d(displacement.x, 5.0f, displacement.z);
	glVertex3d(displacement.x + heading.x, 5.0f, displacement.z + heading.z);
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
