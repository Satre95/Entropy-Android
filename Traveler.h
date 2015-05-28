/*
 * Traveler.h
 *
 *  Created on: May 21, 2015
 *      Author: sidatre
 */

#ifndef SRC_TRAVELER_H_
#define SRC_TRAVELER_H_

#include "ofMain.h"

class Traveler {
public:
	//Constructor
	Traveler();

	//Destructor
	virtual ~Traveler();

	//Methods
	void update();
	void draw();
	void moveTo(ofVec2f & newPos);
	void moveTo(float x, float y);
	void applySizeOscillation();
	void applyFadeOscillation();


	//Properties
	ofVec2f position;
	ofVec2f velocity;
	float speed;

	ofColor color;
	float screenWidth, screenHeight;

	float radius, maxRadius;

	float noiseAngle;
	float radiusAngle;
	float colorAlphaAngle;
	float radiusAngleIncrement;
	float colorAlphaAngleIncrement;

	float noiseScale;
	float noiseStrength;



};

#endif /* SRC_TRAVELER_H_ */
