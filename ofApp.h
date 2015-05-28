#pragma once

#include "ofMain.h"
#include "ofxAndroid.h"
#include "Repulsor.h"
#include "Traveler.h"


class ofApp : public ofxAndroidApp{
	
	public:
		
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void windowResized(int w, int h);

		void touchDown(int x, int y, int id);
		void touchMoved(int x, int y, int id);
		void touchUp(int x, int y, int id);
		void touchDoubleTap(int x, int y, int id);
		void touchCancelled(int x, int y, int id);
		void swipe(ofxAndroidSwipeDir swipeDir, int id);

		void pause();
		void stop();
		void resume();
		void reloadTextures();

		bool backPressed();
		void okPressed();
		void cancelPressed();

		//Animation Vars
		Traveler explorer;
		int numX, numY;
		float deltaX, deltaY;
		int resX, resY;
		float pointRad;
		//The array of Repulsors to display.
		vector<Repulsor> points;
		//The array of Travellers
		vector <Traveler> travelers;
		//the number of Travelers and Repulsors
		int travelerNum, repulsorNumX, repulsorNumY;
		//The background color
		ofColor background;
		//This is used to control the wave-like fade effect of the repulsors
		float oscillationOffset;



};
