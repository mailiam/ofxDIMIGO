#include "ofMain.h"
#include "wony.h"

class wonyCluster {
	public :
	
	wony main;
	int row, col;  //열과 행 선언.
	ofEasyCam cam;
	
	wonyCluster() { // 생성자: 만들어지자 마자 실행되는 함수.
		row = col = 1; //초기화
	}
	
	
	void keyInput(int key) {
		//switch 조건문 
		switch (key) { //key를 받아서
			case '-': // '-'와 일치하면 
				row--; // row 감소
				break; //여기 까지 실행
			case '=':
				row++;
				break;
			case '[':
				col--;
				break;
			case ']':
				col++;
				break;
				
			default:
				break;
		}
	}
	
	void draw() {
		cam.begin();
		for (int k=0; k< 10; k++)
		for(int i=0; i< row; i++){ // i가 0~row까지 
			for (int j=0; j< col; j++){ // j가 0~col까지
				ofSetColor(i*10, j*10, k*10);
				ofCircle(j*20, i*20, k*20, 10); // i*20 , j*20 의 자리에 점을 찍는다.
			}
		}
		cam.end();
	}
	
};

