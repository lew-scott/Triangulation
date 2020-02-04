#pragma once
#include "Vec2.h"
#include "Graphics.h"

class Point
{
public:
	void init(Vec2 pos_in);
	Vec2 getPos();
	void draw(Graphics& gfx);

private:

	Vec2 pos;
	bool initialised = false;
};
