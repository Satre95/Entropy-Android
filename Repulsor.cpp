/*
 * Repulsor.cpp
 *
 *  Created on: May 23, 2015
 *      Author: sidatre
 */

#include "Repulsor.h"


Repulsor::Repulsor(ofVec2f & position) {
	this->position = position;
	this->stationaryPoint = position;
}

Repulsor::Repulsor(float x, float y, float radius, float radiusAngleIncrement, float alphaAngleIncrement, float radiusAngleOffset, float alphaAngleOffset ) {
	this->position = ofVec2f(x, y);
	this->stationaryPoint = ofVec2f(x, y);
	this->radius = radius;
	this->maxRadius = radius;
	this->radiusAngleIncrement = radiusAngleIncrement;
	this->alphaAngleIncrement = alphaAngleIncrement;
	this->radiusAngleOffset = radiusAngleOffset;
	this->alphaAngleOffset = alphaAngleOffset;

	//Make the radius and alpha angles equal to their offsets.
	this->radiusAngle = radiusAngleOffset;
	this->alphaAngle = alphaAngleOffset;

//	draw();
}

Repulsor::~Repulsor() {}

float Repulsor::getAlphaAngleOffset() const {
	return alphaAngleOffset;
}

void Repulsor::setAlphaAngleOffset(float alphaAngleOffset) {
	this->alphaAngleOffset = alphaAngleOffset;
}

float Repulsor::getRadiusAngleOffset() const {
	return radiusAngleOffset;
}

void Repulsor::setRadiusAngleOffset(float radiusAngleOffset) {
	this->radiusAngleOffset = radiusAngleOffset;
}

//Graphics methods

void Repulsor::update() {
	applyFadeOscillation();
	applySizeOscillation();
}


void Repulsor::draw() {
	ofFill();
	ofSetColor(color);
	ofCircle(position.x, position.y, radius);
}

void Repulsor::applyFadeOscillation() {
	alphaAngle += alphaAngleIncrement;

	//calculate the new alpha by mapping the sine result to the 8-bit value range
	float newAlpha = ofMap(sin(alphaAngle), -1.0f, 1.0f, 0, 255);

	//The angle needs to be scaled by 255 to match the 8-bit alpha value.
	color.set( color.r, color.g, color.b, newAlpha);
}

void Repulsor::applySizeOscillation() {
	radiusAngle += radiusAngleIncrement;

	radius =  ofMap( sin(radiusAngle), -1.0f, 1.0f, 0.0f, maxRadius);
}
