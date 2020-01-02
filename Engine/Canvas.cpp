#include "Canvas.h"

Canvas::Canvas()
	:
	rng(rd()),
	xDist(0, 770),
	yDist(0, 570)
{
	std::uniform_real_distribution<float> vDist(-2.0f, 2.0f);
	//p.init(Vec2(xDist(rng), yDist(rng)), Vec2(vDist(rng), vDist(rng)));
	p.init({ 400,300, }, { 0,0 });
	p.initRays();
	w.init({ 500,200 }, { 500,400 });
}

void Canvas::drawScene(Graphics& gfx)
{
	p.draw(gfx);
	w.draw(gfx);
}
