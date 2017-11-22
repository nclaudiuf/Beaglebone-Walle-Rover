/*
 * run.cpp
 *
 *  Created on: 13 May 2015
 *      Author: claudiu
 */
#include "mainControl/Controller.h"
#include <iostream>
#include <stdio.h>
#include <unistd.h>

using namespace std;
using namespace performActions;
using namespace Controller;
using namespace conntecRover;

int main(int argc, char *argv[])
{
	Controller::Controller* config = new Controller::Controller();
	config->print("Connecting to Rover Display...");
	SocketClient sc(IP, PORT);
	if (sc.connectToServer() == 0)
	{
		configMotors();
		string message("Rover ready!");
		config->print("Sending: [" + message + "]");
		sc.send(message);
		while(sc.connectToServer() == 0)
		{
			//config->print("Action: " + sc.receive(1024));
			config->runActions(sc.receive(1024)[0], 1);
		}
		config->print("Rover is now disconnected!");
	}
}



