#pragma once
#include "Particle.h"
#include "Wall.h"
#include <random>

class Canvas
{
public:

	Canvas();
	void drawScene(Graphics& gfx);
	void calcIntersects();
	void updateParticlePos(Vec2 pos_in);
	Vec2 lineIntersection(Vec2 p1, Vec2 p2, Vec2 p3, Vec2 p4);
	

private:
	Particle p;
	static constexpr int walls = 2;
	Wall w[walls];
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_real_distribution<float> xDist;
	std::uniform_real_distribution<float> yDist;

};