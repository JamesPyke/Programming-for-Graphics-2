#include "Rectangle.h"

Rect::Rect()
{
	left = 0;
	top = 0;
	width = 0;
	height = 0;
}

Rect::Rect(float left, float top, float width, float height)
{
	this->left = left;
	this->top = top;
	this->width = width;
	this->height = height;
}

// Returns true if the rectangles intersect
bool Rect::intersects(Rect a, Rect b)
{
	return (a.left < b.left + b.width, a.left + a.width > b.left && a.top < b.top + b.height && a.top + a.height > b.top);
}