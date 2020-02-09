#pragma once
#include "Wall.h"
#include <random>
#include <vector>

class Triangulation 
{
public:
	Triangulation();
	void drawScene(Graphics& gfx);
	void drawPoint(Graphics& gfx, int x, int y);
	void drawEdge(Graphics& gfx, std::pair<int,int> x, std::pair<int, int> y);
	bool lineIntersection(int i, int j, int k);
	bool smallerDistance(int i, int j, int k);
	void makeTriangles();

	
private:
	static constexpr int nPoints = 10; 
	std::vector<std::pair<int,int>> points;
	std::vector<std::pair<int,int>> edges; 
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> xDist;
	std::uniform_int_distribution<int> yDist;
	//std::uniform_int_distribution<int> velDist;

};