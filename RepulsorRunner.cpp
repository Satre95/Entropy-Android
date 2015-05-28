/*
 * RepulsorRunner.cpp
 *
 *  Created on: May 26, 2015
 *      Author: sidatre
 */

#include "RepulsorRunner.h"

RepulsorRunner::RepulsorRunner() {
	// TODO Auto-generated constructor stub

}

void RepulsorRunner::setup(float x, float y, float radius, float radiusAngleIncrement, float alphaAngleIncrement, float radiusAngleOffset, float alphaAngleOffset ) {
	theRepulsor = new Repulsor(x, y, radius, radiusAngleIncrement, alphaAngleIncrement, radiusAngleOffset, alphaAngleOffset);
}


void RepulsorRunner::threadedFunction() {
	this->runAnimation();
}

void RepulsorRunner::runAnimation() {
	while( isRunning ) {
		theRepulsor.update();
		theRepulsor.draw();
	}
}

void RepulsorRunner::stopAnimation() {
	isRunning = false;
}


const Repulsor& RepulsorRunner::getRepulsor() const {
	return theRepulsor;
}

void RepulsorRunner::setRepulsor(const Repulsor & theRepulsor) {
	this->theRepulsor = theRepulsor;
}

RepulsorRunner::~RepulsorRunner() {
	// TODO Auto-generated destructor stub
}

