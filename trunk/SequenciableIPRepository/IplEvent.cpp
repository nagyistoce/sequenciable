/*
 * IplEvent.cpp
 *
 *  Created on: Jul 5, 2011
 *      Author: claudio
 */

#include "IplEvent.h"

IplEvent::IplEvent(IplImage *img) : Event(Event::PROCESSING_FINISHED_CORRECTLY) {
    eventImage = cvCloneImage(img);
}

IplEvent::~IplEvent() {
    cvReleaseImage(&eventImage);
}
IplImage* IplEvent::getEventIplImage(){
	return eventImage;
}
