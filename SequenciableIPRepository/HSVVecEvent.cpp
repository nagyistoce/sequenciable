/*
 * HSVVecEvent.cpp
 *
 *  Created on: Jul 7, 2011
 *      Author: claudio
 */

#include "HSVVecEvent.h"

HSVVecEvent::HSVVecEvent(vector<HSVColor> vec) : Event(Event::PROCESSING_FINISHED_CORRECTLY){
	// TODO Auto-generated constructor stub
	hsvVec = vec;
}

HSVVecEvent::~HSVVecEvent() {
	// TODO Auto-generated destructor stub
}
