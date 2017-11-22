/*
 * controlLeds.h
 *
 *  Created on: 13 May 2015
 *      Author: claudiu
 */

#ifndef CONTROLLEDS_H_
#define CONTROLLEDS_H_
#include <fstream>
#include <sstream>

#define LEDS_PATH "/sys/class/leds/beaglebone:green:usr"
#define SYS_LED_BRIGHTNESS "brightness"
#define SYS_LED_TRIGGER "trigger"
#define SYS_LED_DELAY_ON "delay_on"
#define SYS_LED_DELAY_OFF "delay_off"

namespace LED
{
class LED
{
public:
	enum Brightness {
		ON, OFF
	};
private:
	std::fstream sys_fs;
	std::ofstream sysid_fs_brightness;
	std::ofstream sysid_fs_trigger;
	std::ofstream sysid_fs_delay_on;
	std::ofstream sysid_fs_delay_off;
public:
	LED(int led_nr);
	void brightness(int led_nr, int status);
	void flash_leds(int led_nr, int delay);
	void stop_flash_leds();
};

}




#endif /* CONTROLLEDS_H_ */
