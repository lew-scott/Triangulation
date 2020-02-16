#pragma once
#include "Wall.h"
#include "Vec2.h"
#include "Vei2.h"
#include <random>
#include <vector>
#include <iostream>
#include <fstream>

class Triangulation 
{
public:

	struct pointinfo
	{
		Vec2 pos;
		Vec2 vel;
	};

	Triangulation();
	void drawScene(Graphics& gfx);
	void drawPoint(Graphics& gfx, Vec2 p);
	void drawEdge(Graphics& gfx, Vec2 x, Vec2 y, int i);
	bool lineIntersection(Vec2 p1, Vec2 p2, Vec2 p3, Vec2 p4);
	void findEdges();
	void Triangulate();
	void updateVel();
	void updatePos();
	void makeFirstTri();

private:
	static constexpr int nPoints = 15; 
	std::vector<pointinfo> P;
	std::vector<Vei2> edges;
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_real_distribution<float> xDist;
	std::uniform_real_distribution<float> yDist;
	std::uniform_real_distribution<float> vDist;

};