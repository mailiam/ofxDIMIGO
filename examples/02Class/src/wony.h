#include "ofMain.h"

class wony {
public: //공개
	//변수
	//종류	이름
	ofPoint pos; //위치 ofPoint 변수
	int		size; //크기 정수 변수
	
	wony(){ //클래스 생성자, 클래스가 생성 될때마다 처음에 실행
		age = 0;
		//초기 위치 램덤화
		pos.x = ofRandomWidth(); 
		pos.y = ofRandomHeight();
	}
	
	//함수
	//종류 이름(인자)
	void update(){
		pos.x += ofRandom(-2, 2);  // x를 -2~2 만큼
		pos.y += ofRandom(-2, 2);  // y를 -2~2 만큼
		
		if (pos.x > ofGetWidth()) { //창을 벗어나면 원 위치로
			pos.x = 0; 
		}
		if (pos.y > ofGetHeight()) {
			pos.y = 0; 
		}
		
		age++; // 매 프레임 마다 나이 증가 
	}
	
	void draw(){
		size = min(age/10, 200); // 10살 먹을때 마다 size업! 최대 200으로 고정
		ofCircle(pos,size);
	}
private: //비공개, 클래스 밖에서 접근 불가.
	int     age; //나이 
};