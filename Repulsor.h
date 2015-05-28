/*
 * Repulsor.h
 *
 *  Created on: May 23, 2015
 *      Author: sidatre
 */

#ifndef SRC_REPULSOR_H_
#define SRC_REPULSOR_H_

#include "ofMain.h"



class Repulsor {
public:
	Repulsor();
	Repulsor(float x, float y, float radius, float radiusAngleIncrement, float alphaAngleIncrement, float radiusAngleOffset, float alphaAngleOffset );
	Repulsor(ofVec2f & position);
	virtual ~Repulsor();

	//Instance Vars
	//reflects the instantaneous position
	ofVec2f position;
	//the fixed position the point always attempts to return to.
	ofVec2f stationaryPoint;
	ofVec2f velocity;
	ofVec2f netForce;
	float radius, maxRadius;
	ofColor color;

	//The following vars are used when changing the size and alpha of the Repulsors
	float radiusAngle, radiusAngleIncrement;
	float alphaAngle, alphaAngleIncrement;
	float radiusAngleOffset, alphaAngleOffset;


	//Graphics Method
	void draw();
	void applySizeOscillation();
	void applyFadeOscillation();
	void update();
	float getAlphaAngleOffset() const;
	void setAlphaAngleOffset(float alphaAngleOffset);
	float getRadiusAngleOffset() const;
	void setRadiusAngleOffset(float radiusAngleOffset);
};

#endif /* SRC_REPULSOR_H_ */
