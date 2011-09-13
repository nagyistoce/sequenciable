/*
 * IplEvent.cpp
 *
 *  Created on: Jul 5, 2011
 *      Author: claudio
 */

#include "IplEvent.h"

IplEvent::IplEvent(IplImage *img) : Event(Event::PROCESSING_FINISHED_CORRECTLY) {
	// TODO Auto-generated constructor stub
	eventImage = img;
}

IplEvent::~IplEvent() {
	// TODO Auto-generated destructor stub
}
IplImage* IplEvent::getEventIplImage(){
	return eventImage;
}
