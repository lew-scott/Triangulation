#pragma once
#include "Vec2.h"
#include "Graphics.h"

class Particle
{
public:
	void init(Vec2 pos_in, Vec2 vel_in);
	void initRays();
	void draw(Graphics& gfx);
	Vec2 getRayDir(int i);
	Vec2 getRayPoint(int i);
	Vec2 getPos();
	bool pointFound();
	void updateRayPos(Vec2 position, int i);
	void updatePos(Vec2 pos_in);
	void updatePFound(bool pfound);
	int getNumOfRays();
	

private:

	Vec2 pos;
	Vec2 vel;
	bool initilised = false;
	static constexpr int degrees = 5;
	static constexpr int numRays = 360 / degrees;
	Vec2 Dir[numRays];
	Vec2 rays[numRays];
	bool pFound = false;

};
