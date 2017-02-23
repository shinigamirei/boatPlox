#include "Boat.h"


Boat::Boat()
{
	acceleration = glm::vec3(0.0f, 0.0f, 0.0f);
	heading = glm::vec3(0.0f, 0.0f, -1.0f);
	velocity = glm::vec3(0.0f, 0.0f, 0.0f);
	rotation = 0;

}

Boat::~Boat()
{
}
