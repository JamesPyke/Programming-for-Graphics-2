#pragma once
#include "Vector.h"
#include <random>

class Ball
{

private:

	Vector velocity;
	Vector startPosition;


public:

	int speed;
	Vector position;
	float radius;
	Ball();
	void draw();
	void setPosition(Vector position);
	void setVelocity(Vector velocity);
	Vector getVelocity();
	void update();
	void reset();
	int getRandomInt(const int &min, const int &max);
};

