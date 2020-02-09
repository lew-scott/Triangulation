#include "Points.h"
#include <assert.h>
#include <Math.h>

void Point::init(Vec2 pos_in)
{
	assert(initialised == false);
	pos = pos_in;
	x = pos_in.x;
	y = pos_in.y;
	initialised = true;
		
}



void Point::draw(Graphics& gfx)
{
	gfx.DrawCircle(int(pos.x), int(pos.y), 2, Colors::White);
}




/*
void Particle::checkPos()
{
	if (pos.x < 5.0f)
	{
		pos.x = 5.0f;
		vel.x = -vel.x;
	}
	else if((pos.x >= 795.0f))
	{
		pos.x = 795.0f;
		vel.x = -vel.x;
	}
	else if ((pos.y < 5.0f))
	{
		pos.y = 5.0f;
		vel.y = -vel.y;
	}
	else if ((pos.y >= 595.0f))
	{
		pos.y = 595.0f;
		vel.y = -vel.y;
	}
}
*/

Vec2 Point::getPos()
{
	return pos;
}

float Point::getX()
{
	return x;
}


