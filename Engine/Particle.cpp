#include "Particle.h"
#include <assert.h>
#include <Math.h>

void Particle::init(Vec2 pos_in, Vec2 vel_in)
{
	assert(initilised == false);
	pos = pos_in;
	vel = vel_in;
	initilised = true;
		
}

void Particle::initRays()
{
	Vec2 dir = { 0.0f ,-1.0f };
	float angle = 0.0f;
	for (int i = 0; i < numRays; ++i)
	{
		angle = float(i * 10.0f) * 3.14159f / 180.0f;
		dir.rotate(angle);
		rays[i] = dir * 30;
		dir = { 0.0f ,-1.0f };
	}
}


void Particle::draw(Graphics& gfx)
{
	for (int i = 0; i < numRays; ++i)
	{
		gfx.Drawline(pos, pos+rays[i], Colors::White);
	}
}

