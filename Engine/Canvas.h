#pragma once
#include "Particle.h"
#include "Wall.h"
#include <random>

class Canvas
{
public:

	Canvas();
	void drawScene(Graphics& gfx);

private:
	Particle p;
	Wall w;
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_real_distribution<float> xDist;
	std::uniform_real_distribution<float> yDist;

};