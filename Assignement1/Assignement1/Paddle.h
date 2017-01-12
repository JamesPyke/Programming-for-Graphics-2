#pragma once
#include <IL/ilut.h>
#include "Vector.h"

class Paddle
{

private:

	int speed;
	GLint giXRes = 800;
	GLint giYRes = 800;
	GLuint myImage;

public:

	Vector size;
	Vector position;
	Paddle();
	void draw();
	void move(Vector velocity);
	Vector Getposition();
	void SetPosition(Vector position);
	void initTextures();

};

