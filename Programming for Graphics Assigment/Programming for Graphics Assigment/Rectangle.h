#pragma once
class Rect
{

public:

	Rect();
	Rect(float left, float top, float width, float height);

	float left;
	float top;
	float width;
	float height;

	static bool intersects(Rect a, Rect b);
};