/*
 * HSVVecEvent.h
 *
 *  Created on: Jul 7, 2011
 *      Author: claudio
 */

#ifndef HSVVECEVENT_H_
#define HSVVECEVENT_H_

#include "Event.h"
#include <vector>
#include "HSVColor.h"

using namespace std;

class HSVVecEvent: public Event {
public:
	HSVVecEvent(vector<HSVColor> vec);
	virtual ~HSVVecEvent();
	vector<HSVColor> getEventHSVVec(){return hsvVec;};
protected:
	vector<HSVColor> hsvVec;
};

#endif /* HSVVECEVENT_H_ */
