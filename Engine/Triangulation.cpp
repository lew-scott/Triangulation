#include "Triangulation.h"

Triangulation::Triangulation()
	:
	rng(rd()),
	xDist(150.0f, 700.0f),
	yDist(150.0f, 500.0f)
	//velDist(-5,5)
{

	for (int i = 0; i < nPoints; ++i)
	{
		Vec2 P = { xDist(rng),yDist(rng) };
		points.push_back(P);
	}

}

void Triangulation::drawScene(Graphics& gfx)
{
	for (int i = 0; i < nPoints; ++i)
	{
		drawPoint(gfx, points[i]);
	}

	for (int i = 0; i < edges.size(); ++i)
	{
		drawEdge(gfx, points[edges[i].x], points[edges[i].y]);
	}
}

void Triangulation::drawPoint(Graphics& gfx, Vec2 p)
{
	gfx.DrawCircle((int)p.x, (int)p.y, 2, Colors::White);
}


void Triangulation::drawEdge(Graphics & gfx, Vec2 a, Vec2 b)
{
	gfx.Drawline({ a.x, a.y }, { b.x, b.y }, Colors::White);
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


bool Triangulation::smallerDistance(Vec2 p1, Vec2 p2, Vec2 p3, Vec2 p4)
{
	Vec2 v1 = { p1.x - p2.x, p1.y - p2.y }; 
	Vec2 v2 = { p3.x - p4.x, p3.y - p4.y };
	
	if (v1.GetLengthSq() < v2.GetLengthSq())
	{
		return true;
	}
	return false;
}


void Triangulation::findEdges()
{
	
	for (int j = 3; j < nPoints; j++) // start at 3 
	{
		for (int i = 0; i < j; i++)
		{
			bool newEdge = true;
			int num = (int)edges.size();

			for (int k = 0; k < num; k++)
			{
				if (lineIntersection(points[j],points[i],points[edges[k].x],points[edges[k].y]) == true )// && lineIntersection(points[edges[k].x], points[edges[k].y], points[j], points[i]) == true)
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

void Triangulation::Triangulate()
{
	SortVector();
	writePos();
	edges.push_back({ 0, 1 });
	edges.push_back({ 1, 2 });
	edges.push_back({ 2, 0 });

	findEdges();
}



void Triangulation::SortVector()
{
	for (int j = 0; j < nPoints; j++)
	{
		for (int i = 0; i < nPoints-1; i++)
		{
			if (points[i].x > points[i + 1].x)
			{
				Vec2 temp = points[i];
				points[i] = points[i + 1];
				points[i + 1] = temp;
			}
		}
	}

}



