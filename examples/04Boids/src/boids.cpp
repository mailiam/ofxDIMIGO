#include "boids.h"


void boids::setup(float _space, float _sight, float _max_foce){
	
	SPACE = _space;
	SIGHT = _sight;
	MAX_FORCE = _max_foce;
	
	for(int i=0; i< NUM_PARTICLES; i++){					//배열 크기 만큼 
		p[i].pos.set(ofRandomWidth(), ofRandomHeight());	//파티클의 위치와 속도를 랜덤하게 지정
		p[i].vec.set(ofRandom(-2, 2), ofRandom(-2, 2));
		p[i].max_vel = 4;
	}
}

void boids::update(){										//각 파티클에 대하여 이동방향 계산 수행
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

//분리
ofPoint boids::separation(particle current){
	ofPoint vec;
	int count = 0;
	
	for(int i=0; i< NUM_PARTICLES; i++){					//다른 각 파티클에 대하여
		particle other = p[i];
		float distance =current.pos.distance(other.pos);	//다른 파티클과의 거리
		if(distance < SPACE && distance > 0){				//가 0보다 크고 SPACE보다 작으면 (거리가 0이면 자기 자신)
			vec += (current.pos - other.pos)/distance;		//방향에 반대 방향을 더한다.
			count++;
		}
	}
	if(count>0) vec/=count;									//평균화
	vec.normalize();										//평준화
	vec *= current.max_vel;
	if(vec.length()>0) vec -= current.vec;					//방향이 있을시에만 현재 향하는 곳의 중간을 구한다.
	vec.limit(MAX_FORCE);
	return vec;
}


//일치
ofPoint boids::alignment(particle current){
	ofPoint vec;
	int count = 0;
	
	for(int i=0; i< NUM_PARTICLES; i++){					
		particle other = p[i];
		float distance = other.pos.distance(current.pos);	
		if(distance < SIGHT && distance > 0){				//거리가 0보다 크고 SIGHT보다 작으면
			vec += other.vec;								//방향에 다른 파티클의 방향을 더한다.
			count ++;
		}
	}
	if(count>0) vec /= count;							
	vec.normalize();
	vec *= current.max_vel;
	if(vec.length()>0) vec -= current.vec;
	vec.limit(MAX_FORCE);
	return vec;
}

//응집
ofPoint boids::cohesion(particle current){
	ofPoint vec;
	ofPoint pt;
	int count = 0;
	
	for(int i=0; i< NUM_PARTICLES; i++){
		particle other = p[i];
		float distance = other.pos.distance(current.pos);
		if(distance < SIGHT && distance > 0){				//거리가 0보다 크고 SIGHT보다 작으면
			pt += other.pos;								//pt에 다른 파티클의 위치를 더한다.
			count ++;
		}
	}
	if(count>0) pt /= count;								//pt 평균화
	vec = pt - current.pos;									//pt까지의 방향을 계산한다.
	vec.normalize();										//평준화
	vec *= current.max_vel;
	if(vec.length()>0) vec -= current.vec;
	vec.limit(MAX_FORCE);
	return vec;
}