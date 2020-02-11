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
	Triangulation();
	void drawScene(Graphics& gfx);
	void drawPoint(Graphics& gfx, Vec2 p);
	void drawEdge(Graphics& gfx, Vec2 x, Vec2 y, int i);
	bool lineIntersection(Vec2 p1, Vec2 p2, Vec2 p3, Vec2 p4);
	bool smallerDistance(Vec2 p1, Vec2 p2, Vec2 p3, Vec2 p4);
	void findEdges();
	void Triangulate();
	void SortVector();
	void updatePos();
	void updateVel();


	
private:
	static constexpr int nPoints = 15; 
	std::vector<Vec2> points;
	std::vector<Vei2> edges;
	std::vector<Vec2> vel;
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_real_distribution<float> xDist;
	std::uniform_real_distribution<float> yDist;
	std::uniform_real_distribution<float> vDist;

};