#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true); //프레임속도를 60에 고정, 스크린의 재생 속도와 맞춘다.
	
	
	//처음 위치 지정
	bob.pos.x = 200;
	bob.pos.y = 200;

}

//--------------------------------------------------------------
void testApp::update(){
	
	//매 프레임마다 클래스내의 update를 실행
	bob.update();
	marley.update();
}

//--------------------------------------------------------------
void testApp::draw(){
	//bob과 marley를 그린다.
	ofSetColor(100, 200, 0);
	bob.draw();
	
	ofSetColor(200,150,100);
	marley.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}