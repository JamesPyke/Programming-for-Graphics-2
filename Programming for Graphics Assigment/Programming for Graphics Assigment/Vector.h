#pragma once
#include <glut.h>

class Vector
{
private:

public:

	GLfloat x;
	GLfloat y;
	GLfloat z;

	Vector(GLfloat x, GLfloat y, GLfloat z);
	Vector operator+ (const Vector &v);
	Vector operator* (const float &scalar);
	Vector();
};

