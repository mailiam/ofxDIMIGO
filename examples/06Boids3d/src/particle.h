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
	}
	
	ofVec3f axis;
	int coneResolution;

	void draw(){
		
		// 각도 계산   
		ofVec3f up( 0, 1, 0 );						//기준이 되는 점
		//ofVec3f axis;
		axis = up.crossed( vec );					//vec과 기준의 수직을 구한다.		
		float angle = up.angle(vec);				//기준점과 이동 방향의 각도 계산 
		
		glEnable(GL_NORMALIZE);						//glScale 이용시 노말도 같이 스케일 시킨다. (빛의 세기를 유지 한다.)
		
		ofPushMatrix();
		ofTranslate(pos);		
		ofRotate( angle, axis.x, axis.y, axis.z);  //기준점에 대하여 각도만큼 회전시킨다.
		glScalef(3.0f, 10.0f, 3.0f);

		ofSphere(1);

		/*///////////////////////////////////////////////////////////////////////
		//콘 그리기 
		glBegin(GL_TRIANGLE_FAN);
		glVertex3f(0.0f, 0.5f, 0.0f);				//꼭지점
		coneResolution = 16;					//해상도 (디테일)
		float x,y,z;
		for(int i=0; i<coneResolution; i++){				//원을 그리는 루프이다.
			angle = (float)i / (coneResolution-1) * TWO_PI; //각도를 구하여 
			x = sin(angle);									//해당 각도의 x 좌표 
			y = -0.5f;
			z = cos(angle);									//해당 각도의 z 좌표
			glNormal3f(x/2, 0.0f, z/2);						//노말을 계산한다, 꼭지점과 현재 점의 사이에 위치하도록.
			glVertex3f(x, y, z);							//점 찍기 
		}
		glEnd();
		//
		//밑바닥
		glBegin(GL_TRIANGLE_FAN);
		glNormal3f(0.0f, -1.0f, 0.0f);
		glVertex3f(0.0f, -0.5f, 0.0f);
		for(int i=0; i<coneResolution; i++){
			angle = (float)i /( coneResolution-1) * TWO_PI;
			x = sin(angle);
			y = -0.5f;
			z = cos(angle);
			glVertex3f(x, y, z);
		}
		glEnd();
		//
		*///////////////////////////////////////////////////////////////////////
		
		ofPopMatrix();
	}
	
	//중심으로 이동
	void pullToCenter(ofPoint center){
		
		ofPoint dirToCenter = pos - center;				//중심까지의 방향을 구한다.
		float distToCenter = dirToCenter.length();		//중심까지의 거리를 구하여 
		float distThresh = 50.0f;						
		
		if( distToCenter > distThresh ){				//이 거리 이하이면 
			dirToCenter.normalize();
			float pullStrength = 0.0005f;
			acc -= dirToCenter * ( ( distToCenter - distThresh ) * pullStrength );	//이동
		}
		
	}
};