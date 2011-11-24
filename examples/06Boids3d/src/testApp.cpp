#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
	ofSetSphereResolution(4);
	
	b.setup();
	ofSetGlobalAmbientColor(ofColor(10,30,20));
}

//--------------------------------------------------------------
void testApp::update(){
	b.update();
}

//--------------------------------------------------------------
void testApp::draw(){
	
	cam.begin();
	ofDrawAxis(50);
	
	ofSphere(pointLight.getPosition(), 30);
	
	ofEnableLighting();
	pointLight.enable();
		b.draw();
	pointLight.disable();
	ofDisableLighting();
	cam.end();
	
	
	ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 20, 20);
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