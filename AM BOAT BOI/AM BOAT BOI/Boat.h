#pragma once
#include "glm\common.hpp"
class Boat
{
public:
	glm::vec3 acceleration;
	glm::vec3 velocity;
	glm::vec3 displacement;
	glm::vec3 heading;
	float rotation;
	
	Boat();
	~Boat();
};

