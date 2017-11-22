/*
 * Rover.cpp
 *
 *  Created on: 13 May 2015
 *      Author: claudiu
 */
#include "/home/claudiu/workspace/Rover/mainControl/Controller.h"
#include <iostream>
#include <stdio.h>
#include <unistd.h>
using namespace std;
using namespace Controller;
using namespace performActions;
using namespace LED;
using namespace cPWM;

namespace Controller
{
	Controller::Controller()
	{
		this->currentGear = 1;
		this->currentActions = ' ';
	}

	LED::LED* configLed(int led_nr)
	{
		LED::LED* led = new LED::LED(led_nr);
		return led;
	}

	void controlLeds(int led_nr, int status)
	{
		configLed(led_nr)->LED::brightness(led_nr, status);
	}

	void Controller::runActions(char action, int gear)
	{
		controlLeds(3, 0);
		switch (action)
		{
		case FRONT:
			currentActions = action;
			shiftGear(gear, POLARITY_FRONT);
			moveFront();
			break;
		case BACK:
			Controller::currentActions = action;
			shiftGear(gear, POLARITY_BACK);
			moveBack();
			break;
		case LEFT:
			Controller::currentActions = action;
			shiftGear(gear, POLARITY_FRONT);
			moveLeft();
			break;
		case RIGHT:
			currentActions = action;
			shiftGear(gear, POLARITY_FRONT);
			moveRight();
			break;
		case STOP:
			Controller::currentActions = action;
			shiftGear(gear, POLARITY_FRONT);
			stopEngines();
			break;
		case SPIN:
			Controller::currentActions = action;
			shiftGear(gear, POLARITY_FRONT);
			spin();
			break;
		case GEAR_UP:
			if (gear > 0 && gear < 4)
				Controller::currentGear++;
				runActions(Controller::currentActions, Controller::currentGear);
				controlLeds(currentGear-1, 1);
		case GEAR_DOWN:
			if (gear < 4 && gear > 1)
				Controller::currentGear--;
				runActions(Controller::currentActions, Controller::currentGear);
				controlLeds(currentGear-1, 0);
		default:
			break;
		}
	}

	void Controller::print(string text)
	{
		cout << text << endl;
	}
}
