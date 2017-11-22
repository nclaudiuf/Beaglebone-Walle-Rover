/*
 * Rover.h
 *
 *  Created on: 13 May 2015
 *      Author: claudiu
 */
#include "/home/claudiu/workspace/Rover/LEDs/controlLeds.h"
#include "/home/claudiu/workspace/Rover/motors/Actions.h"
#include "/home/claudiu/workspace/Rover/SocketClient/SocketClient.h"
#include <iostream>
#ifndef CONTROLL_H_
#define CONTROLL_H_
#define FRONT 'W'
#define LEFT 'A'
#define RIGHT 'D'
#define BACK 'S'
#define GEAR_UP 'G'
#define GEAR_DOWN 'H'
#define SPIN 'C'
#define STOP 'O'
#define MOVE 'F'
#define POLARITY_FRONT 1
#define POLARITY_BACK 0
#define IP "192.168.1.185"
#define PORT 23456

namespace Controller
{
class Controller
{
public:
	int currentGear;
	char currentActions;
	Controller();
	LED::LED* configLed(int led_nr);
	void print(std::string text);
	void runActions(char action, int gear);
};
}
#endif /* CONTROLL_H_ */
