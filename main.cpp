#include "Arduino.h"
#include <time.h>
#include "sntp.h"
#include "FS.h"

#include "config.h"

#include "task.hpp"
#include "tasks_utils.h"
#include "utils.h"
#include "DataStore.h"
#include "OTA.hpp"

#include "DisplayTask.hpp"

#include "ArduinoOTA.h"

using namespace Tasks;


void setup()
{
	Serial.begin(921600);

	//the filesystem is not ready yet - format it and save some settings
	if (!SPIFFS.begin())
	{
		SPIFFS.format();
		SPIFFS.begin();
		writeConfig(F("configPassword"), "password");
		logPrintf("Formatting filesystem, the default password is %s", readConfig(F("configPassword")).c_str());
	}

	readConfigFromFlash();

	setupTasks();

	String macAddress = WiFi.macAddress();
	DataStore::value("mac") = macAddress;

	logPrintf("\n\n");
	logPrintf("MAC Address: %s", macAddress.c_str());

	getDisplayTask().pushMessage("Initializing...", 2_s);
	getDisplayTask().pushMessage(versionString, 0.4_s, true);

	configTime(getTimeZone(), 0, "pool.ntp.org", "time.nist.gov", "ntp3.pl");

	configureOTA();
}

void loop()
{
	scheduleTasks();
	ArduinoOTA.handle();
}
