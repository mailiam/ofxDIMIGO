#pragma once

#include "ofMain.h"

class particle {
public:
	ofPoint pos;	//위치
	ofPoint acc;	//가속도
	ofPoint vec;	//속도 (속도는 방향을 포함한다...고 알고 있음ㅎㅎ, 참고로 속력은 방향을 제외한 스피드 그 자체)
					//더 재미없는 참고는, 속도에서 속력을 구하려면 피타고라스를 응용하여 대각선을 구하면 오키!
	
	float max_vel;
	
	void update(){
		vec += acc;
		vec.limit(max_vel);
		pos += vec;
		
		int r = 3; //3은 임의적인 숫자
		
		//무한 공간
		if (pos.x < -r) pos.x = ofGetWidth()+r;
		if (pos.y < -r) pos.y = ofGetHeight()+r;
		if (pos.x > ofGetWidth()+r) pos.x = -r;
		if (pos.y > ofGetHeight()+r) pos.y = -r;
	}
	
	void draw(){
		float angle = ofRadToDeg(-(float)atan2(-vec.y, vec.x))+90; //방향으로 radian을 구하는 공식. 굳이 외울 필요는 없다.
		ofPushMatrix();
		ofTranslate(pos);
		ofRotate(angle);
			ofTriangle(0,0, -5,10, 5,10);
		ofPopMatrix();
	}
};