#pragma once
#include "glm\common.hpp"
class buoy
{
public:
	glm::vec3 pos;
	buoy();
	~buoy();
	void draw();
	void draw_Start();
	void draw_course();
	void position(int,int,int);
};

