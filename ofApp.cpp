#include "ofApp.h"


float x = 0.0;

//--------------------------------------------------------------
void ofApp::setup(){
	ofRegisterTouchEvents((ofxAndroidApp*)this);

	//set the background color
	background = ofColor(0,0,0);

	//set the oscillationOffset
	this->oscillationOffset = 0;

	//set the number of Travelers and Repulsors.
	this->travelerNum = 3;
	this->repulsorNumX = 40;
	this->repulsorNumY = 40;

	ofBackground(0);
	ofEnableSmoothing();
	ofSetFrameRate(30);

	//store the screen resolution
	resX = ofGetWindowWidth();
	resY = ofGetWindowHeight();

	//set the radius of the grid points
	pointRad = 3;

	//Calculate the spacing between points.
	deltaX = resX / (repulsorNumX + 1);
	deltaY = resY / (repulsorNumY + 1);

	//Init the points.
	for(int i = 1; i <= repulsorNumX; i++ ) {
		for( int j = 1; j <= repulsorNumY; j++ ) {
			points.push_back(*( new Repulsor(i * deltaX, j * deltaY, pointRad, 0.03f, 0.05f, oscillationOffset, oscillationOffset  ) ) );
			oscillationOffset += 0.001;
		}
	}

	//Init the Travelers
	for( int i = 0; i < travelerNum; i++) {
		travelers.push_back(*(new Traveler() ) );
	}





	//move the origin to the center of the screen.
//	ofTranslate( ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
}

//--------------------------------------------------------------
void ofApp::update(){
	//move the origin to the center of the screen.
//	ofTranslate( ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);

	//update the Travelers
	for(vector<Traveler>::iterator it = travelers.begin(); it != travelers.end(); ++it){
		(*it).update();
	}

	//update the grid points
	for(vector<Repulsor>::iterator it = points.begin(); it != points.end(); ++it){
		  (*it).update();
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
//	ofBackgroundGradient(ofColor::gray,ofColor(30,10,30), OF_GRADIENT_CIRCULAR);
	ofBackground(background);

	//Draw the Travelers
	for(vector<Traveler>::iterator it = travelers.begin(); it != travelers.end(); ++it){
		(*it).draw();
	}

	//Draw the Repulsors
	for(vector<Repulsor>::iterator it = points.begin(); it != points.end(); ++it){
	  (*it).draw();
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){ 
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){ 
	
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

void ofApp::touchDown(int x, int y, int id){
	ofLogNotice() << "touch down " << x << "," << y << ":" << id;

}

void ofApp::touchMoved(int x, int y, int id){
	ofLogNotice() << "touch moved " << x << "," << y << ":" << id;

}

void ofApp::touchUp(int x, int y, int id){
	ofLogNotice() << "touch up " << x << "," << y << ":" << id;

}

void ofApp::touchDoubleTap(int x, int y, int id){
	ofLogNotice() << "touch double " << x << "," << y << ":" << id;

}

void ofApp::touchCancelled(int x, int y, int id){
	ofLogNotice() << "touch cacelled " << x << "," << y << ":" << id;

}

void ofApp::swipe(ofxAndroidSwipeDir swipeDir, int id){
	ofLogNotice() << "swipes " << swipeDir << id;
}

//--------------------------------------------------------------
void ofApp::pause(){
	ofLogNotice() << "ofApp::pause() Called";
}

//--------------------------------------------------------------
void ofApp::stop(){

}

//--------------------------------------------------------------
void ofApp::resume(){

}

//--------------------------------------------------------------
void ofApp::reloadTextures(){

}

//--------------------------------------------------------------
bool ofApp::backPressed(){
	return false;
}

//--------------------------------------------------------------
void ofApp::okPressed(){

}

//--------------------------------------------------------------
void ofApp::cancelPressed(){

}
