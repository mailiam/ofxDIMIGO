#include "boids.h"


void boids::setup(float _space, float _sight, float _max_foce){
	
	SPACE = _space;
	SIGHT = _sight;
	MAX_FORCE = _max_foce;
	
	for(int i=0; i< NUM_PARTICLES; i++){
		p[i].pos.set(ofRandomWidth(), ofRandomHeight());
		p[i].vec.set(ofRandom(-2, 2), ofRandom(-2, 2));
		p[i].max_vel = 4;
	}
}

void boids::update(){
	for(int i=0; i< NUM_PARTICLES; i++){
		ofPoint sep = separation(p[i]);
		ofPoint ali = alignment(p[i]);
		ofPoint coh = cohesion(p[i]);
		
		p[i].acc = sep*1.5 + ali*1 + coh*1;
		
		p[i].update();
	}
	
}

void boids::draw(){
	for(int i=0; i< NUM_PARTICLES; i++)
		p[i].draw();
}

ofPoint boids::separation(particle current){
	ofPoint vec;
	int count = 0;
	
	for(int i=0; i< NUM_PARTICLES; i++){
		particle other = p[i];
		float distance =current.pos.distance(other.pos);
		if(distance < SPACE && distance > 0){
			vec += (current.pos - other.pos)/distance;
			count++;
		}
	}
	if(count>0) vec/=count;
	vec.normalize();
	vec *= 4;
	if(vec.length()>0) vec -= current.vec;
	vec.limit(MAX_FORCE);
	return vec;
}

ofPoint boids::alignment(particle current){
	ofPoint vec;
	int count = 0;
	
	for(int i=0; i< NUM_PARTICLES; i++){
		particle other = p[i];
		float distance = other.pos.distance(current.pos);
		if(distance < SIGHT && distance > 0){
			vec += other.vec;
			count ++;
		}
	}
	if(count>0) vec /= count;
	vec.normalize();
	vec *= 4;
	if(vec.length()>0) vec -= current.vec;
	vec.limit(MAX_FORCE);
	return vec;
}

ofPoint boids::cohesion(particle current){
	ofPoint vec;
	ofPoint pt;
	int count = 0;
	
	for(int i=0; i< NUM_PARTICLES; i++){
		particle other = p[i];
		float distance = other.pos.distance(current.pos);
		if(distance < SIGHT && distance > 0){
			pt += other.pos;
			count ++;
		}
	}
	if(count>0) pt /= count;
	vec = pt - current.pos;
	vec.normalize();
	vec *= 4;
	if(vec.length()>0) vec -= current.vec;
	vec.limit(MAX_FORCE);
	return vec;
}