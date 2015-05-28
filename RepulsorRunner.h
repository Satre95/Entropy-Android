/*
 * RepulsorRunner.h
 *
 *  Created on: May 26, 2015
 *      Author: sidatre
 */

#ifndef SRC_REPULSORRUNNER_H_
#define SRC_REPULSORRUNNER_H_

class RepulsorRunner: public ofThread {
private:
	Repulsor theRepulsor;

public:
	RepulsorRunner();
	virtual ~RepulsorRunner();

	//This var is used to control the animations
	static bool isRunning = true;


	void setup(float x, float y, float radius, float radiusAngleIncrement, float alphaAngleIncrement, float radiusAngleOffset, float alphaAngleOffset);

	void runAnimation();
	void stopAnimation();
	void threadedFunction();


	const Repulsor& getRepulsor() const;
	void setRepulsor(const Repulsor& theRepulsor);
};

#endif /* SRC_REPULSORRUNNER_H_ */
