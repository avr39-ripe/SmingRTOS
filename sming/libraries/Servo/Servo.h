/*
 * Servo.h
 *
 *  Created on: 22.11.2015
 *      Author: johndoe
 */

#ifndef LIB_SERVO_H_
#define LIB_SERVO_H_
#include "../../include/SmingCore.h"
#include "ServoChannel.h"

#define SERVO_CHANNEL_NUM_MAX 4


class Servo
{
public:
	Servo();
	virtual ~Servo();

//	void Init();
//	bool SetValues(uint32 value[]);

	static Servo* Self;
	static void IRAM_ATTR ServoTimerInt();
	bool addChannel(ServoChannel *channel);
	bool removeChannel(ServoChannel *channel);
	void calcTiming();
	HardwareTimer hardwareTimer;


private:
	void getPins();
	Vector<ServoChannel*> channels;
};

extern Servo servo;

#endif /* LIB_SERVO_H_ */
