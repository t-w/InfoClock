#include <Arduino.h>
#include <time.h>

#include "tasks_utils.h"
#include "utils.h"

#include "config.h"

#include "LHCStatusReaderNew.h"

using namespace Tasks;

void setup()
{
	Serial.begin(SERIAL_BAUD_RATE);
	delay(2000);
	setupTasks();

	//static RegisterTask rt1(new LHCStatusReaderNew, TaskDescriptor::CONNECTED | TaskDescriptor::SLOW);

	configTime(timezone, 0, "ip-time-1-cern.ch", "ip-time-2.cern.ch", "pool.ntp.org");
}

void loop()
{
	scheduleTasks();
}
