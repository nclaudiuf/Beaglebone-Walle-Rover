/*
 * controlMotors.h
 *
 *  Created on: 12 May 2015
 *      Author: claudiu
 */
#include "/home/claudiu/workspace/Rover/motors/dcMotors.h"

#ifndef ACTIONS_H_
#define ACTIONS_H_

#define PERIOD_RUN 200000
#define DUTY_RUN 100000
#define POLARITY_FRONT 1
#define POLARITY_BACK 0

#define GEAR1 1
#define GEAR2 2
#define GEAR3 3
#define PERIOD_GEAR1 100000
#define DUTY_GEAR1 80000
#define PERIOD_GEAR2 200000
#define DUTY_GEAR2 12000
#define PERIOD_GEAR3 300000
#define DUTY_GEAR3 180000

namespace performActions
{
	//CREATE ENGINES
	cPWM::cPWM** configMotors();
	//CONTROL ROLVER
	//MOVING FRONT
	void moving();
	//MOVING BACK
	void backing();
	//MOVE FRONT - STOP
	void moveFront();
	//MOVE BACK _STOP
	void moveBack();
	//MOVE LEFT - STOP
	void moveLeft();
	//MOVING LEFT
	void movingLeft();
	//MOVE RIGHT - STOP
	void moveRight();
	//MOVING RIGHT
	void movingRight();
	//STOP ROVER
	void stopEngines();
	//SPIN ROVER
	void spin();
	//SPEED UP/DOWN
	void shiftGear(int gear, int direction);
	//CONFIG THE SPEED OF THE ENGINES
	void setEngines(int period, int duty, int polarity);
}

#endif /* ACTIONS_H_ */
