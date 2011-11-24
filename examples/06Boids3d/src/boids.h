#pragma once

#include "ofMain.h"
#include "particle.h"

#define NUM_PARTICLES	1000

class boids {
public:
	
	float SPACE;
	float SIGHT;
	float MAX_FORCE;
	
	void setup(float _space = 20, float _sight = 25, float _max_force = 0.1);
	void update();
	void draw();
	
	ofPoint separation(particle current);
	ofPoint alignment(particle current);
	ofPoint cohesion(particle current);
	
private:
	particle p[NUM_PARTICLES];				//particle 배열 [배열크기]
};
