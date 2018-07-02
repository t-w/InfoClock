/*
 * LHCStatusReaderNew.cpp
 *
 *  Created on: 19.10.2017
 *      Author: Bartosz Bielawski
 */


#include "Arduino.h"
#include "pgmspace.h"

#include "LHCStatusReaderNew.h"

#include "ESP8266HTTPClient.h"
#include "utils.h"
#include "tasks_utils.h"
//#include "web_utils.h"
#include "WString.h"

static const char pageUrl[] PROGMEM = "http://alicedcs.web.cern.ch/AliceDCS/monitoring/screenshots/rss.xml";


LHCStatusReaderNew::LHCStatusReaderNew()
{
//	getWebServerTask().registerPage("lhc", "LHC Status",
//			[this](ESP8266WebServer& ws) {handleStatusPage(ws);});

//	getDisplayTask().addRegularMessage({this, [this](){return getStateInfo();}, 0.025_s, 1, true});
//	getDisplayTask().addRegularMessage({this, [this](){return getEnergy();}, 2_s, 1, false});
//	getDisplayTask().addClock();
	sleep(15_s);
	logPrintfX("LHCStatusReaderNew()", "Constructing LHCStatusReaderNew()");

	reset();
	//page1Comment = String();
	//beamEnergy = String();
	//beamMode = String();
	//refreshTime = String();
}

void LHCStatusReaderNew::reset()
{
	sleep(15_s);
	page1Comment = String();
	beamEnergy = String();
	beamMode = String();
	machineMode = String();
	refreshTime = String();
}

String
LHCStatusReaderNew::readLhcStatusField( WiFiClient& httpStream )
{
	String    field_data;
	const int title_tag_len = 6;
	char      txt[ title_tag_len + 1 ];
	int       read_bytes;

	do {
		field_data = httpStream.readStringUntil( '<' );
		//logPrintfX(F("LSRX"), F("We are here 3"));
		read_bytes = httpStream.readBytes( txt, title_tag_len );
		if ( strncmp ( txt,  "/title", title_tag_len ) == 0 )
			break;
		field_data += String( txt );
	} while ( httpStream.available() );
	return field_data;
}

void LHCStatusReaderNew::run()
{
	HTTPClient httpClient;
	const int urlMax = 128;
    char url[ urlMax ];

	logPrintfX( F( "LSRX" ), F( "Reading LHC Status" ) );
	
	strncpy_P( url, pageUrl, urlMax ); // get var from flash to RAM
    logPrintfX( F( "LSRX" ), "Data source: " + String( url ) );
	if (! httpClient.begin( String( url ) ) )
	//if (! httpClient.begin( F("http://alicedcs.web.cern.ch/AliceDCS/monitoring/screenshots/rss.xml") ) )
	{
		logPrintfX( F( "LSRX" ), F( "Cannot start HTTP client" ) );
		sleep( 60_s );
		return;
	}

	int httpCode = httpClient.GET();
	if (httpCode != 200)
	{
		logPrintfX( F( "LSRX" ), F( "HTTP code: %d" ), httpCode );
		reset();		//this resets variables
		sleep(60_s);
		return;
	}

	auto httpStream = httpClient.getStream();

	//String rss = httpStream.readString();
	//Serial.println(rss);
	//logPrintfX( F("LHCX"), F("rss size: %d"), rss.length() );
    //logPrintfX( F("LHCX"), F("RSS: %s"), rss.c_str() );
	int valuesRead = 0;
	while ( httpStream.available() )
	{
		bool found = httpStream.findUntil( "<title>", "</rss>" );
		if (not found)
			break;
		
		auto title = httpStream.readStringUntil( ':' );
		//logPrintfX(F("LSRX"), F("We are here 2"));

		if ( title ==  F( "LhcPage1" ) ){
			page1Comment = readLhcStatusField( httpStream );
			page1Comment.trim();
			page1Comment.replace(F( "\n\n" ), F( " -- " ));
			page1Comment.replace( '\n', ' ' );
			logPrintfX( F( "LHCX" ), F( "Page1Comment: %s" ), page1Comment.c_str() );
			valuesRead++;
		}

		if (title == F("BeamEnergy"))
		{
			beamEnergy = readLhcStatusField( httpStream );
			beamEnergy.trim();
			logPrintfX(F("LHCX"), F("BeamEnergy: %s"), beamEnergy.c_str());
			valuesRead++;
		}

		if (title == F("LhcBeamMode"))
		{
			beamMode = readLhcStatusField( httpStream );
			beamMode.trim();
			logPrintfX(F("LHCX"), F("BeamMode: %s"), beamMode.c_str());
			valuesRead++;
		}

		if (title == F("LhcMachineMode"))
		{
			machineMode = readLhcStatusField( httpStream );
			machineMode.trim();
			logPrintfX(F("LHCX"), F("MachineMode: %s"), machineMode.c_str());
			valuesRead++;
		}
	}

	refreshTime = getDateTime();

	if (valuesRead)	logPrintfX( F("LSRX"), F("Done!") );
	else            logPrintfX( F("LSRX"), F("Done (but no data read!!!)") );

	sleep(60_s);
}



//------------- WEBPAGE STUFF


static const char lhcStatusPage[] PROGMEM = R"_(
<table>
<tr><th>LHC Status</th></tr>
<tr><td class="l">Last refresh:</td><td>$timestamp$</td></tr>
<tr><td class="l">Beam mode:</td><td>$mode$</td></tr>
<tr><td class="l">Page 1 Comment:</td><td>$comment$</td></tr>
<tr><td class="l">Energy:</td><td>$energy$</td></tr>
</table>
</body>
<script>setTimeout(function(){window.location.reload(1);}, 15000);</script>
</html>
)_";
/*
FlashStream lhcStatusPageNewFS(lhcStatusPage);

void LHCStatusReaderNew::handleStatusPage(ESP8266WebServer& webServer)
{
	StringStream ss(2048);
	macroStringReplace(pageHeaderFS, constString("LHC Status"), ss);

	std::map<String, String> m =
	{
			{F("timestamp"), refreshTime},
			{F("mode"), beamMode},
			{F("comment"), page1Comment},
			{F("energy"), beamEnergy}
	};

	macroStringReplace(lhcStatusPageNewFS, mapLookup(m), ss);
	webServer.send(200, textHtml, ss.buffer);
}
*/
// ----------------- DISPLAY STUFF -------------------

String LHCStatusReaderNew::getStateInfo()
{
	if (beamMode.length() && page1Comment.length())
		return beamMode + ": " + page1Comment;

	return String();
}

String LHCStatusReaderNew::getEnergy()
{
	//ALICE reports some strange value during the shutdown
	if (beamEnergy.toInt() > 7100) return String();
	return beamEnergy;
}

//static RegisterTask rt1(new LHCStatusReaderNew, TaskDescriptor::CONNECTED | TaskDescriptor::SLOW);



