/*
 * LHCStatusReaderNew.h
 *
 *  Created on: 19.10.2017
 *      Author: Bartosz Bielawski
 */

#ifndef LHCSTATUSREADERTW_H_
#define LHCSTATUSREADERTW_H_

//#include <WString.h>
#include <tasks.hpp>
#include "ESP8266HTTPClient.h"

//class ESP8266WebServer;

class LHCStatusReaderNew: public Tasks::Task
{
	public:
		LHCStatusReaderNew();
		virtual void reset();
		virtual void run();
		virtual ~LHCStatusReaderNew() = default;
	private:
		String beamEnergy;
		String beamMode;
		String machineMode;
		String page1Comment;
		String refreshTime;

//		void handleStatusPage(ESP8266WebServer& ws);

		String getEnergy();
		String getStateInfo();

		String readLhcStatusField( WiFiClient& httpStream );
};

#endif /* LHCSTATUSREADERNEW_H_ */
