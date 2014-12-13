/*
 * Timestamp.cpp
 *
 *  Created on: Dec 13, 2014
 *      Author: Michael Micke, Frank Mehne
 */

#include "Timestamp.hpp"
#include <sys/time.h>
#include <sstream>

using namespace std;

namespace asteroids {

Timestamp::Timestamp() {

	// get the current time
	timeval startTime;
	if (gettimeofday(&startTime, 0) == 0) {

		// initialize the starting time in milliseconds
		m_startTime = (startTime.tv_sec * 1000) + (startTime.tv_usec / 1000);

	} else {

		cout << "ERROR: System time could not get measured" << endl;

		// initialize starting time with zero
		m_startTime = 0;
	}
}

unsigned long Timestamp::getCurrentTimeInMs() const {

	// get current system Time
	timeval sysTime;
	gettimeofday(&sysTime, 0);

	// return time in milliseconds
	return (sysTime.tv_sec * 1000) + (sysTime.tv_usec / 1000);
}

double Timestamp::getCurrentTimeinS() const {

	// return the current Time in seconds
	return getCurrentTimeInMs() / 1000;
}

unsigned long Timestamp::getElapsedTimeInMs() const {

	// return the time difference since object creation in milliseconds
	return getCurrentTimeInMs() - m_startTime;
}

double Timestamp::getElapsedTimeInS() const {

	// return the time difference since object creation in seconds
	return getElapsedTimeInMs() / 1000;
}

void Timestamp::resetTimer(){

	// sets the timer to the current system time
	m_startTime = getCurrentTimeInMs();
}

string Timestamp::getElapsedTime() const {

	// build return string
	string retString;
	stringstream strStream;

	unsigned long elapsedTime = getElapsedTimeInMs();

	strStream << elapsedTime;
	strStream >> retString;

	retString += "ms";

	return retString;
}


Timestamp::~Timestamp() {
}

} /* namespace asteroids */
