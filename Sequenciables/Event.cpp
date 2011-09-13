/*
 * Event.cpp
 *
 *  Created on: Jun 16, 2011
 *      Author: claudio
 */

#include "Event.h"

Event::Event(eventTypes tp) {
	type = tp;
}
Event::~Event() {
	// TODO Auto-generated destructor stub
}
bool Event::isEventOfType(eventTypes t){
	if(t==type)
		return true;
	else
		return false;
}
