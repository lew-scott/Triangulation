#pragma once
#include "Vec2.h"
#include "Graphics.h"

class Particle
{
public:
	void init(Vec2 pos_in, Vec2 vel_in);
	void initRays();
	void draw(Graphics& gfx);

private:

	Vec2 pos;
	Vec2 vel;
	bool initilised = false;
	static constexpr int numRays = 360 / 10;
	Vec2 rays[numRays];


};
