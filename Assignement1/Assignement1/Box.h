#pragma once
#include "Vector.h"

class Box
{
public:
	Vector size;
	Vector position;
	void draw();
	void setPosition(Vector position);
	Box();

};

