#include "Triangulation.h"

Triangulation::Triangulation()
	:
	rng(rd()),
	xDist(150, 700),
	yDist(150, 500)
	//velDist(-5,5)
{

	for (int i = 0; i < nPoints; ++i)
	{
		points.push_back( std::make_pair(xDist(rng),yDist(rng)));
	}

	//points.push_back(std::make_pair(100, 300));
	//points.push_back(std::make_pair(350, 200));
	//points.push_back(std::make_pair(420, 260));
	//points.push_back(std::make_pair(450, 400));
	//points.push_back(std::make_pair(700, 300));



}

void Triangulation::drawScene(Graphics& gfx)
{
	for (int i = 0; i < nPoints; ++i)
	{
		drawPoint(gfx, points[i].first, points[i].second);
	}

	for (int i = 0; i < edges.size(); ++i)
	{
		drawEdge(gfx, points[edges[i].first], points[edges[i].second]);
	}
}

void Triangulation::drawPoint(Graphics& gfx, int x, int y)
{
	gfx.DrawCircle(x, y, 2, Colors::White);
}


void Triangulation::drawEdge(Graphics & gfx, std::pair<int, int> a, std::pair<int,int> b)
{
	gfx.Drawline({ (float)a.first,(float)a.second }, { (float)b.first, (float)b.second }, Colors::White);
}

bool Triangulation::lineIntersection(int i, int j, int k )
{
	int a = edges[k].first;
	int b = edges[k].second;
	int x = j;
	int y = i;
	Vec2 p1 = { (float)points[a].first, (float)points[a].second };
	Vec2 p2 = { (float)points[b].first, (float)points[b].second };

	Vec2 p3 = { (float)points[j].first, (float)points[j].second };
	Vec2 p4 = { (float)points[i].first, (float)points[i].second };
	
	float tNum = ((p1.x - p3.x)*(p3.y - p4.y) - (p1.y - p3.y)*(p3.x - p4.x));
	float tDen = ((p1.x - p2.x)*(p3.y - p4.y) - (p1.y - p2.y)*(p3.x - p4.x));
	float t = tNum / tDen;

	float uNum = -((p1.x - p2.x)*(p1.y - p3.y) - (p1.y - p2.y)*(p1.x - p3.x));
	float uDen = ((p1.x - p2.x)*(p3.y - p4.y) - (p1.y - p2.y)*(p3.x - p4.x));
	float u = uNum / uDen;

	if (t > 0 && t < 1 && u > 0 && u < 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Triangulation::smallerDistance(int i, int j, int k)
{
	// j -> i, so j has smaller x 
	Vec2 p1 = { (float)points[i].first - (float)points[j].first, (float)points[i].second - (float)points[j].second }; 
	int a = edges[k].first;
	int b = edges[k].second;
	// a -> b, so a has smaller x
	Vec2 p2 = { (float)points[b].first - (float)points[a].first, (float)points[b].second - (float)points[a].second };
	
	if (p1.GetLengthSq() < p2.GetLengthSq())
	{
		return true;
	}

	return false;
}

void Triangulation::makeTriangles()
{
	std::sort(points.begin(), points.end());
	for (int i = 1; i < nPoints; i++)
	{
		edges.push_back(std::make_pair(0, i));
	}

	for (int j = 1; j < nPoints-1; j++) // start at 2 until last minus 1
	{

		for (int i = j + 1; i < nPoints; i++)
		{
			bool newEdge = true;
			bool deleteEdge = false;
			int num = edges.size();

			for (int k = 0; k < num; k++)
			{
				if (lineIntersection(i,j,k) == true && smallerDistance(i,j,k) == false)
				{
					newEdge = false;
					break;
				}
				else if (lineIntersection(i,j,k) == true && smallerDistance(i,j,k) == true)
				{
					newEdge = true;
					edges.erase(edges.begin() + k);
					num -= 1;
					k -= 1;
				}
			}

			if (newEdge == true)
			{
				edges.push_back(std::make_pair(j, i));
			}
		}
	}
}

