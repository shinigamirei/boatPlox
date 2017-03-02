#pragma once
#include "glm\common.hpp"
class Boat
{
public:
	glm::vec3 acceleration;
	glm::vec3 velocity;
	glm::vec3 displacement;
	glm::vec3 heading;
	glm::vec3 camera_loc; //camera location
	glm::vec3 camera_rot; //camera location in relation to boat
	float rotation;//for drawing
	
	Boat();
	~Boat();
	void increase_Acceleration();
	void decrease_Acceleration();
	void rotate_Left();
	void rotate_Right();
	void turning();
	void motion();
	void drawBoat();
	void drawProw();
	void drawBody();	
};

