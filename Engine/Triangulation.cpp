#include "Triangulation.h"

Triangulation::Triangulation()
	:
	rng(rd()),
	xDist(150.0f, 700.0f),
	yDist(150.0f, 500.0f),
	vDist(-2.5,2.5)
{
	for (int i = 0; i < nPoints; ++i)
	{
		Vec2 pPos = { xDist(rng),yDist(rng) };
		Vec2 pVel = { vDist(rng), vDist(rng) };
		pointinfo pInfo = { pPos,pVel };
		P.push_back(pInfo);

	}
}

void Triangulation::Triangulate()
{
	// make triangles
	edges.clear();
	std::sort(P.begin(), P.end(), [](const pointinfo& a, const pointinfo& b) { return a.pos.x < b.pos.x; });
	makeFirstTri();
	findEdges();
	updatePos();
	updateVel();
}

void Triangulation::makeFirstTri()
{
	edges.push_back({ 0, 1 });
	edges.push_back({ 1, 2 });
	edges.push_back({ 2, 0 });
}

void Triangulation::findEdges()
{

	for (int j = 3; j < nPoints; j++) // start at next (3) point outside the first triangle
	{
		for (int i = 0; i < j; i++) // check points before for possible connection
		{
			bool newEdge = true;
			int num = (int)edges.size();

			for (int k = 0; k < num; k++) // test for overlapping lines 
			{
				if (lineIntersection(P[j].pos, P[i].pos, P[edges[k].x].pos, P[edges[k].y].pos) == true)
				{
					newEdge = false;
				}
			}

			if (newEdge == true)
			{
				edges.push_back({ j, i });
			}
		}
	}
}

bool Triangulation::lineIntersection(Vec2 p1, Vec2 p2, Vec2 p3, Vec2 p4)
{
	float tNum = ((p1.x - p3.x)*(p3.y - p4.y) - (p1.y - p3.y)*(p3.x - p4.x));
	float tDen = ((p1.x - p2.x)*(p3.y - p4.y) - (p1.y - p2.y)*(p3.x - p4.x));
	float t = tNum / tDen;

	float uNum = -((p1.x - p2.x)*(p1.y - p3.y) - (p1.y - p2.y)*(p1.x - p3.x));
	float uDen = ((p1.x - p2.x)*(p3.y - p4.y) - (p1.y - p2.y)*(p3.x - p4.x));
	float u = uNum / uDen;

	if (t > 0.00001 && t < 0.99999 && u > 0.00001 && u < 0.99999) //  float causes error which deletes possible connections
	{															  //  setting limits close to 0 and 1 catches it. 
		return true;
	}
	else
	{
		return false;
	}
}

// Point pos code

void Triangulation::updateVel()
{
	// check for collision with boundary, flip velocity accordingly
	for (int i = 0; i < nPoints; i++)
	{
		if (P[i].pos.x < 20)
		{
			P[i].pos.x = 20;
			P[i].vel.x = -P[i].vel.x;
		}
		else if (P[i].pos.x > 780)
		{
			P[i].pos.x = 780;
			P[i].vel.x = -P[i].vel.x;
		}

		if (P[i].pos.y < 20)
		{
			P[i].pos.y = 20;
			P[i].vel.y = -P[i].vel.y;
		}
		else if (P[i].pos.y > 580)
		{
			P[i].pos.y = 580;
			P[i].vel.y = -P[i].vel.y;
		}
	}
}

void Triangulation::updatePos()
{
	for (int i = 0; i < nPoints; i++)
	{
		P[i].pos += P[i].vel;
	}
}

//Drawing Code

void Triangulation::drawScene(Graphics& gfx)
{
	for (int i = 0; i < nPoints; ++i)
	{
		drawPoint(gfx, P[i].pos);
	}

	for (int i = 0; i < edges.size(); ++i)
	{
		drawEdge(gfx, P[edges[i].x].pos, P[edges[i].y].pos, i);
	}
}

void Triangulation::drawPoint(Graphics& gfx, Vec2 p)
{
	gfx.DrawCircle((int)p.x, (int)p.y, 2, Colors::White);
}


void Triangulation::drawEdge(Graphics & gfx, Vec2 a, Vec2 b, int i)
{
	if (i % 2 == 0)
	{
		gfx.Drawline({ a.x, a.y }, { b.x, b.y }, Colors::White);
	}
	else if (i % 2 == 1)
	{
		gfx.Drawline({ a.x, a.y }, { b.x, b.y }, Colors::Green);
	}
	
}
