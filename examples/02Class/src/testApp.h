#pragma once

#include "ofMain.h"
#include "wony.h" // 우리 wony를 불러오자! 

class testApp : public ofBaseApp{

	public:
		
	wony bob; //첫번쨰 wony이름은 bob 
	wony marley; //친구 말리
		
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
