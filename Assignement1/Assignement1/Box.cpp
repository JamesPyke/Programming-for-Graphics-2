#include "Box.h"

Box::Box()
{
	size.x = 0.1;
	size.y = 0.1;
	size.z = 0.1;
}

void Box::draw()
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
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
}

void Box::setPosition(Vector position)
{
	this->position = position;
}
