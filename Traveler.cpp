/*
 * Traveler.cpp
 *
 *  Created on: May 21, 2015
 *      Author: sidatre
 */

#include "Traveler.h"

Traveler::Traveler() {
	noiseAngle = 0;
	radiusAngle = 0;
	colorAlphaAngle = 0;
	radiusAngleIncrement = 0.05;
	colorAlphaAngleIncrement = 0.05;

	noiseScale = 533;
	noiseStrength = 77;

	//store the width and height of the screen
	screenWidth = ofGetWindowWidth();
	screenHeight = ofGetWindowHeight();

	//set a random color for this traveler.
	color.set( ofRandom(255), ofRandom(255), ofRandom(255) );

	position.set(screenWidth * 0.5, screenHeight * 0.5);

	radius = 20;
	maxRadius = radius;




}

Traveler::~Traveler() {
	// TODO Auto-generated destructor stub
}


void Traveler::update() {
	noiseAngle = ofNoise(position.x / noiseScale, position.y / noiseScale) * noiseStrength;

	//ofLogNotice() << "Noise 2D result: " << oscillationAngle;

	float newX = position.x + cos(noiseAngle);
	float newY = position.y + sin(noiseAngle);

	position.set( newX, newY );

	//update the alpha and the radius
	applyFadeOscillation();
//	applySizeOscillation();
}

void Traveler::moveTo(ofVec2f & newPos ) {
	delete &position;
	position = newPos;
}

void Traveler::moveTo( float x, float y) {
	position.set(x, y);
}

void Traveler:: draw() {
	ofSetColor(color);
	ofFill();
	ofCircle(position.x, position.y, radius);

}

void Traveler::applyFadeOscillation() {
	colorAlphaAngle += colorAlphaAngleIncrement;

	//calculate the new alpha by mapping the sine result to the 8-bit value range
	float newAlpha = ofMap(sin(colorAlphaAngle), -1.0f, 1.0f, 0, 255);

	//The angle needs to be scaled by 255 to match the 8-bit alpha value.
	color.set( color.r, color.g, color.b, newAlpha);
}

void Traveler::applySizeOscillation () {
	radiusAngle += radiusAngleIncrement;

	radius =  ofMap( sin(radiusAngle), -1.0f, 1.0f, 0.0f, maxRadius);
}
