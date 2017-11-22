#include "/home/claudiu/workspace/Rover/motors/Actions.h"

#include <iostream>
#include <unistd.h>
using namespace std;
using namespace cPWM;

namespace performActions
{
//CONFIGURE ALL ENGINES
cPWM::cPWM** configMotors()
{
	string motorConfig[] = { "pwm_test_P9_29.13", "pwm_test_P8_45.11",
			"pwm_test_P8_36.12", "pwm_test_P9_42.14" };
	cPWM::cPWM* motors[4];
	for (int i = 0; i < 4; i++)
	{
		motors[i] = new cPWM::cPWM(motorConfig[i]);
		motors[i]->Period_ns(PERIOD_RUN);
		motors[i]->Duty_ns(DUTY_RUN);
		motors[i]->Polarity(PERIOD_RUN);
	}
	return motors;
}

//MOVE ROVER FRONT WITHOUT STOP
void moving()
{
	for (int i = 0; i < 4; i++)
	{
		configMotors()[i]->cPWM::Run();
	}
}

//MOVE ROVER BACK WITHOUT STOP
void backing()
{
	for (int i = 0; i < 4; i++)
	{
		configMotors()[i]->cPWM::Run();
	}
}

//MOVE FRONT AND STOP
void moveFront()
{
	for (int i = 0; i < 4; i++)
	{
		configMotors()[i]->cPWM::Run();
	}
	usleep(1000000);
	for (int i = 0; i < 4; i++)
	{
		configMotors()[i]->cPWM::Stop();
	}
}

//MOVE BACK AND STOP
void moveBack() {
	for (int i = 0; i < 4; i++) {
		configMotors()[i]->cPWM::Run();
	}
	usleep(1000000);
	for (int i = 0; i < 4; i++) {
		configMotors()[i]->cPWM::Stop();
	}
}

//MOVE ROVER TO LEFT
void moveLeft() {
	for (int i = 0; i < 2; i++) {
		configMotors()[i]->cPWM::Run();
	}
	usleep(2500000);
	for (int i = 0; i < 2; i++) {
		configMotors()[i]->cPWM::Stop();
	}
}

//MOVE ROVER TO LEFT WITHOUT STOP
void movingLeft()
{
	for (int i = 0; i < 2; i++)
	{
		configMotors()[i]->cPWM::Run();
	}
}

//MOVE ROVER TO RIGHT
void moveRight() {
	for (int i = 2; i < 4; i++)
	{
		configMotors()[i]->cPWM::Run();
	}
	usleep(2500000);
	for (int i = 2; i < 4; i++)
	{
		configMotors()[i]->cPWM::Stop();
	}
}

//MOVE ROVER TO RIGHT WITHOUT STOP
void movingRight()
{
	for (int i = 2; i < 4; i++)
	{
		configMotors()[i]->cPWM::Run();
	}
}

//STOP ENGINES
void stopEngines() {
	for (int i = 0; i < 4; i++) {
		configMotors()[i]->cPWM::Stop();
	}
}

//SPIN ROVER
void spin()
{
	for (int i = 2; i < 4; i++)
	{
		configMotors()[i]->cPWM::Run();
	}
	usleep(2500000 * 4);
	for (int i = 2; i < 4; i++)
	{
		configMotors()[i]->cPWM::Stop();
	}
}

//SPEED UP/DOWN
void shiftGear(int gear, int direction)
{
	switch (gear)
	{
	case GEAR1:
		if (direction == POLARITY_FRONT)
			setEngines(PERIOD_GEAR1, DUTY_GEAR1, POLARITY_FRONT);
		else
			setEngines(PERIOD_GEAR1, DUTY_GEAR1, POLARITY_BACK);
		break;
	case GEAR2:
		if (direction == POLARITY_FRONT)
			setEngines(PERIOD_GEAR2, DUTY_GEAR2, POLARITY_FRONT);
		else
			setEngines(PERIOD_GEAR2, DUTY_GEAR2, POLARITY_BACK);
		break;
	case GEAR3:
		if (direction == POLARITY_FRONT)
			setEngines(PERIOD_GEAR3, DUTY_GEAR3, POLARITY_FRONT);
		else
			setEngines(PERIOD_GEAR3, DUTY_GEAR3, POLARITY_BACK);
		break;
	default:
		break;
	}
}

void setEngines(int period, int duty, int polarity)
{
	for (int i = 0; i < 4; i++)
	{
		configMotors()[i]->cPWM::Period_ns(period);
		configMotors()[i]->cPWM::Duty_ns(duty);
		configMotors()[i]->cPWM::Polarity(polarity);
	}
}
}

