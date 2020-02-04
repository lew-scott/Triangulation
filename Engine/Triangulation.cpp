#include "Triangulation.h"

Triangulation::Triangulation()
	:
	rng(rd()),
	xDist(0, 770),
	yDist(0, 570)
{
	p.init(Vec2(xDist(rng), yDist(rng)));
}

void Triangulation::drawScene(Graphics& gfx)
{


}



Vec2 Triangulation::lineIntersection(Vec2 p1, Vec2 p2, Vec2 p3, Vec2 p4)
{
	float tNum = ((p1.x - p3.x)*(p3.y - p4.y) - (p1.y - p3.y)*(p3.x - p4.x));
	float tDen = ((p1.x - p2.x)*(p3.y - p4.y) - (p1.y - p2.y)*(p3.x - p4.x));
	float t = tNum / tDen;

	float uNum = -((p1.x - p2.x)*(p1.y - p3.y) - (p1.y - p2.y)*(p1.x - p3.x));
	float uDen = ((p1.x - p2.x)*(p3.y - p4.y) - (p1.y - p2.y)*(p3.x - p4.x));
	float u = uNum / uDen;
	if (t > 0 && t < 1 && u > 0 && u < 1)
	{
		return { p1.x + t * (p2.x - p1.x), p1.y + t * (p2.y - p1.y) };
	}
	else
	{
		return { 0,0 };
	}
}
