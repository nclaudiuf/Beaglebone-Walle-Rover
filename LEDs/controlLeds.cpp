/*
 * controlLeds.cpp

 *
 *  Created on: 13 May 2015
 *      Author: claudiu
 */

#include "/home/claudiu/workspace/Rover/LEDs/controlLeds.h"
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

namespace LED
{
	LED::LED(int led_nr)
	{
		stringstream sysfsfile_brightness;
		stringstream sysfsfile_trigger;
		stringstream sysfsfile_delay_on;
		stringstream sysfsfile_delay_off;

		sysfsfile_brightness << LEDS_PATH + led_nr << "/" << SYS_LED_BRIGHTNESS;
		sysfsfile_trigger << LEDS_PATH + led_nr << "/" << SYS_LED_TRIGGER;
		sysfsfile_delay_on << LEDS_PATH + led_nr << "/" << SYS_LED_DELAY_ON;
		sysfsfile_delay_off << LEDS_PATH + led_nr << "/" << SYS_LED_DELAY_OFF;

		sysid_fs_brightness.open(sysfsfile_brightness.str().c_str());
		sysid_fs_trigger.open(sysfsfile_trigger.str().c_str());
		sysid_fs_delay_on.open(sysfsfile_delay_on.str().c_str());
		sysid_fs_delay_off.open(sysfsfile_delay_off.str().c_str());
	}

	/**
	 * Set the brightness for the LEDs
	 *
	 * @param[in] ON OFF
	 *
	 */
	void LED::brightness(int led_nr, int status)
	{
		switch(status)
		{
		case ON:
			sysid_fs_brightness << "1" << std::endl;
			break;
		case OFF:
			sysid_fs_brightness << "0" << std::endl;
			break;
		}
	}

	/**
	 * Flash the LEDs within an delay time
	 *
	 * @param[in] delay in nanoseconds
	 *
	 */
	void LED::flash_leds(int led_nr, int delay)
	{
		sysid_fs_trigger << "timer" << std::endl;
		sysid_fs_delay_on << delay << std::endl;
		sysid_fs_delay_off << delay << std::endl;
	}

	/**
	 * Stop Flashing the LEDs
	 */
	void LED::stop_flash_leds()
	{
		sysid_fs_trigger << "none" << std::endl;
	}
}

