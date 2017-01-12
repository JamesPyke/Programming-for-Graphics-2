#include "Vector.h"


Vector::Vector(GLfloat x, GLfloat y, GLfloat z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector Vector::operator+(const Vector & v)
{
	return Vector(x + v.x, y + v.y, z + v.z);
}

Vector Vector::operator*(const float & scalar)
{
	return Vector(x * scalar, y * scalar, z * scalar);
}

Vector::Vector()
{
	x = 0;
	y = 0;
	z = 0;
}
