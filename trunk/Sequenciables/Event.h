/*
 * Event.h
 *
 *  Created on: Jun 16, 2011
 *      Author: claudio
 */

#ifndef EVENT_H_
#define EVENT_H_

class Event {
public:
	enum eventTypes {PROCESSING_FINISHED_CORRECTLY,PROCESSING_FINISHED_WITH_ERROR};
	Event(eventTypes tp);
	virtual ~Event();
	bool isEventOfType(eventTypes t);
	eventTypes getEventType(){return type;};
protected:
	eventTypes type;
};

#endif /* EVENT_H_ */
