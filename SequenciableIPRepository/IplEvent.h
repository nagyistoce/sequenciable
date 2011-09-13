/*
 * IplEvent.h
 *
 *  Created on: Jul 5, 2011
 *      Author: claudio
 */

#ifndef IPLEVENT_H_
#define IPLEVENT_H_

#include "Event.h"
#include <cv.h>

class IplEvent: public Event {
public:
	IplEvent(IplImage *);
	virtual ~IplEvent();
	IplImage* getEventIplImage();
protected:
	IplImage* eventImage;
};

#endif /* IPLEVENT_H_ */
