#include "Wall.h"
#include <assert.h>

void Wall::init(Vec2 p1_in, Vec2 p2_in)
{
	assert(initilised == false);
	p1 = p1_in;
	p2 = p2_in;
	initilised = true;
}

void Wall::draw(Graphics & gfx)
{
	gfx.Drawline(p1, p2, Colors::Gray);
}
