#include "Paddle.h"
#include "Rectangle.h"
#include <iostream>

Paddle::Paddle()
{
	size.x = 32;
	size.y = 128;
	size.z = 32;
	speed = 2;
}

void Paddle::initTextures()
{
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);

	ilInit();
	iluInit();
	ilutInit();
	ilutRenderer(ILUT_OPENGL);

	myImage = ilutGLLoadImage("Red.bmp");
}

Rect Paddle::getRect()
{
	return Rect();
}

void Paddle::draw()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, myImage);
	glBegin(GL_QUADS);
		//Front face
		glTexCoord2f(0, 0); // top left
		glVertex3f(position.x, position.y, position.z);
		glTexCoord2f(0, 1); // bottom left
		glVertex3f(position.x, position.y + size.y, position.z);
		glTexCoord2f(1, 1); // bottom right
		glVertex3f(position.x + size.x, position.y + size.y, position.z);
		glTexCoord2f(1, 0);	 // top right
		glVertex3f(position.x + size.x, position.y, position.z);

		//Top
		glTexCoord2f(0, 0); // top left
		glVertex3f(position.x, position.y, -position.z);
		glTexCoord2f(0, 1); // bottom left
		glVertex3f(position.x, position.y + size.y, position.z);
		glTexCoord2f(1, 1); // bottom right
		glVertex3f(position.x + size.x, position.y + size.y, position.z);
		glTexCoord2f(1, 0);	 // top right
		glVertex3f(position.x + size.x, position.y, -position.z);

		//Bottom
		glTexCoord2f(0, 0); // top left
		glVertex3f(position.x, position.y + size.y, -position.z);
		glTexCoord2f(0, 1); // bottom left
		glVertex3f(position.x, position.y + size.y, -position.z);
		glTexCoord2f(1, 1); // bottom right
		glVertex3f(position.x + size.x, position.y + size.y, position.z);
		glTexCoord2f(1, 0);	 // top right
		glVertex3f(position.x + size.x, position.y + size.y, position.z);

		//Right
		glTexCoord2f(0, 0); // top left
		glVertex3f(position.x + size.x, position.y, position.z);
		glTexCoord2f(0, 1); // bottom left
		glVertex3f(position.x + size.x, position.y + size.y, position.z);
		glTexCoord2f(1, 1); // bottom right
		glVertex3f(position.x + size.x, position.y + size.y, -position.z);
		glTexCoord2f(1, 0);	 // top right
		glVertex3f(position.x + size.x, position.y, -position.z);

		//Left
		glTexCoord2f(0, 0); // top left
		glVertex3f(position.x, position.y, position.z);
		glTexCoord2f(0, 1); // bottom left
		glVertex3f(position.x, position.y + size.y, position.z);
		glTexCoord2f(1, 1); // bottom right
		glVertex3f(position.x, position.y + size.y, -position.z);
		glTexCoord2f(1, 0);	 // top right
		glVertex3f(position.x, position.y, -position.z);

		//Back
		glTexCoord2f(0, 0); // top left
		glVertex3f(position.x, position.y, -position.z);
		glTexCoord2f(0, 1); // bottom left
		glVertex3f(position.x, position.y + size.y, -position.z);
		glTexCoord2f(1, 1); // bottom right
		glVertex3f(position.x + size.x, position.y + size.y, -position.z);
		glTexCoord2f(1, 0);	 // top right
		glVertex3f(position.x + size.x, position.y, -position.z);

	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void Paddle::move(Vector velocity)
{
	Vector nextPos(position.x += velocity.x*speed, position.y + velocity.y*speed, position.z + velocity.z*speed);

	if (nextPos.y + size.y < 500 && nextPos.y > 0)
	{
		position.x += velocity.x*speed;
		position.y += velocity.y*speed;
	}

}

Vector Paddle::Getposition(){

	return position;
}

void Paddle::SetPosition(Vector position)
{
	this->position = position;
}