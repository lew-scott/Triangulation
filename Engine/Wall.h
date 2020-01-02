#pragma once
#include "Vec2.h"
#include "Graphics.h"


class Wall
{

public:
	void init(Vec2 p1_in, Vec2 p2_in);
	void draw(Graphics& gfx);



private:
	Vec2 p1;
	Vec2 p2;
	bool initilised = false;

};