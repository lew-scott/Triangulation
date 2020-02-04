#pragma once
#include "Points.h"
#include "Wall.h"
#include <random>

class Triangulation 
{
public:

	Triangulation();
	void drawScene(Graphics& gfx);
	Vec2 lineIntersection(Vec2 p1, Vec2 p2, Vec2 p3, Vec2 p4);
	

private:
	static constexpr int nPoints = 4;
	Point p[nPoints];
	Point p[4];
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_real_distribution<float> xDist;
	std::uniform_real_distribution<float> yDist;

};