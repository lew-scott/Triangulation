#pragma once
#include "Vec2.h"
#include "Graphics.h"

class Point
{
public:
	void init(Vec2 pos_in);
	Vec2 getPos();
	float getX();
	void draw(Graphics& gfx);

private:
	Vec2 pos;
	float x;
	float y; 
	bool initialised = false;
};
