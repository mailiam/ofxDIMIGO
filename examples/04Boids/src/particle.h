#pragma once

#include "ofMain.h"

class particle {
public:
	ofPoint pos;
	ofPoint acc;
	ofPoint vec;
	
	float max_vel;
	
	void update(){
		vec += acc;
		vec.limit(max_vel);
		pos += vec;
		
		int r = 3;
		
		if (pos.x < -r) pos.x = ofGetWidth()+r;
		if (pos.y < -r) pos.y = ofGetHeight()+r;
		if (pos.x > ofGetWidth()+r) pos.x = -r;
		if (pos.y > ofGetHeight()+r) pos.y = -r;
	}
	
	void draw(){
		float angle = ofRadToDeg(-(float)atan2(-vec.y, vec.x))+90;
		ofPushMatrix();
		ofTranslate(pos);
		ofRotate(angle);
			ofTriangle(0,0, -5,10, 5,10);
		ofPopMatrix();
	}
};