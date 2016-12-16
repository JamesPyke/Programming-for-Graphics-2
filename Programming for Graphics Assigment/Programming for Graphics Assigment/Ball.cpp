#define _USE_MATH_DEFINES
#include "Ball.h"
#include <math.h>
#include "Paddle.h"

Ball::Ball()
{
	radius = 15;
	speed = 2;
}

void Ball::draw()
{
	GLfloat twicePi = 2.0f * M_PI;
	int triAmount = 20;

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(position.x, position.y);
	for (int i = 0; i <= triAmount; i++){
		glVertex2f(position.x + (radius * cos(i * twicePi / triAmount)),
				   position.y + (radius * sin(i * twicePi / triAmount)));
	}
	glEnd();
}

void Ball::setPosition(Vector position)
{
	this->position = position;
}


void Ball::setVelocity(Vector velocity)
{
	this->velocity = velocity;
}

Vector Ball::getVelocity()
{
	return velocity;
}

void Ball::update()
{
	position = position + (velocity * speed);
}

void Ball::reset()
{
	if (position.x > 1000 || position.x < 0) {
		position = Vector(getRandomInt(100, 500), getRandomInt(100, 400),0);
	}
}

int Ball::getRandomInt(const int & min, const int & max)
{
	std::uniform_int_distribution<int> intDistribution(min, max);
	std::random_device randomDevice;
	return int(intDistribution(randomDevice));
}




