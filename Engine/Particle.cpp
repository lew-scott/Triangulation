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
		angle = float(i * degrees) * 3.14159f / 180.0f;
		dir.rotate(angle);
		Dir[i] = dir; 
		rays[i] = pos + dir;
		dir = { 0.0f ,-1.0f };
	}
}


void Particle::draw(Graphics& gfx)
{
	for (int i = 0; i < numRays; ++i)
	{
		gfx.Drawline(pos, rays[i], Colors::White);
	}
}

Vec2 Particle::getRayDir(int i )
{
	return Dir[i];
}

Vec2 Particle::getRayPoint(int i)
{
	return rays[i];
}

void Particle::updateRayPos(Vec2 position, int i)
{
	rays[i] = position;
}

void Particle::updatePos(Vec2 pos_in)
{
	pos = pos_in;
}

void Particle::updatePFound(bool pfound)
{
	pFound = pfound;
}

Vec2 Particle::getPos()
{
	return pos;
}

bool Particle::pointFound()
{
	return pFound;
}

int Particle::getNumOfRays()
{
	return numRays;
}

