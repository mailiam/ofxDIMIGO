#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(255,255,255);
	ofSetVerticalSync(true);

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	ofFill();
	ofSetColor(255, 255, 255);
	
	//Lake
	ofSetColor(0, 0, 170);
	ofEllipse(600, 600, 800, 300);
	
	//Tree
	ofSetColor(0, 255, 0);
	ofTriangle(100, 0, 0, 200, 200, 200);
	ofTriangle(100, 50, 0, 250, 200, 250);
	ofTriangle(100, 100, 0, 300, 200, 300);
	ofSetColor(255, 200, 0);
	ofRect(75, 300, 50, 200);
	
	//Exclamation Mark
	ofSetColor(255, 0, 255);
	glPushMatrix();
	glTranslated(300, 200, 0);
	ofBeginShape();
		ofVertex(-10, 0);
		ofVertex(10, 0);
		ofVertex(5, 50);
		ofVertex(-5, 50);	
	ofEndShape();
	ofCircle(0, 60, 5);
	glPopMatrix();
	
	//Human
	ofNoFill();
	ofSetColor(0, 0, 0);
	ofPushMatrix();
	ofTranslate(300, 300);
		ofCircle(0, 0, 25);
		ofLine(0, 25, 0, 60);
		ofLine(-25, 40, 25, 40);
		ofLine(-25, 90, 0, 60);
		ofLine(25, 90, 0, 60);
	ofPopMatrix();
	
	//Bubbles
	int w = 300;
	int h = 100;
	int s = 30;
	ofFill();
	ofSetColor(255, 255, 255);
	ofPushMatrix();
	ofTranslate(600, 600);
	for(int i=0; i<30; i++)
		ofCircle(ofRandom(-w/2, w/2), ofRandom(-h/2, h/2),  ofRandom(s));
	ofPopMatrix();
	
	

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