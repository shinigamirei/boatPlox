#pragma once
#include "glm\common.hpp"
class buoy
{
public:
	glm::vec3 pos;
	int buoyno;
	buoy();
	~buoy();
	void draw();
	void draw_Start();
	void position(int,int,int);
};

