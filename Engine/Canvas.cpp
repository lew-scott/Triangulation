#include "Canvas.h"

Canvas::Canvas()
	:
	rng(rd()),
	xDist(0, 770),
	yDist(0, 570)
{
	std::uniform_real_distribution<float> vDist(-2.0f, 2.0f);
	//p.init(Vec2(xDist(rng), yDist(rng)), Vec2(vDist(rng), vDist(rng)));
	p.init({ 600,300, }, { 0,0 });
	p.initRays();

	for (int i = 0; i < walls; ++i)
	{
		w[i].init({ xDist(rng),yDist(rng) }, { xDist(rng),yDist(rng) });
	}


}

void Canvas::drawScene(Graphics& gfx)
{
	p.draw(gfx);
	for (int i = 0; i < walls; i++)
	{
		w[i].draw(gfx);
	}

}

void Canvas::calcIntersects()
{
	Vec2 P = { 0,0 };
	Vec2 Old = { 0,0 };
	Vec2 New = { 0,0 };
	for (int i = 0; i < p.getNumOfRays(); i++)
	{
		p.updatePFound(false);
		
		for (int j = 0; j < walls; j++)
		{
			P = p.getRayDir(i) * 5000;
			P = lineIntersection(p.getPos(), P, w[j].getP1(), w[j].getP2());
			if (P.x != 0 && P.y != 0 && p.pointFound() == false)
			{
				p.updateRayPos(P, i);
				p.updatePFound(true);
			}
			else if (P.x != 0 && P.y != 0 && p.pointFound() == true)
			{
				Old = p.getRayPoint(i) - p.getPos();
				New = P - p.getPos();
				if (New.GetLengthSq() < Old.GetLengthSq())
				{
					p.updateRayPos(P, i);
					p.updatePFound(true);
				}
			}
			else if(p.pointFound() == false)
			{
				p.updateRayPos(p.getPos() + p.getRayDir(i), i);
			}
		}
	}
}

void Canvas::updateParticlePos(Vec2 pos_in)
{
	p.updatePos(pos_in);
}

Vec2 Canvas::lineIntersection(Vec2 p1, Vec2 p2, Vec2 p3, Vec2 p4)
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
