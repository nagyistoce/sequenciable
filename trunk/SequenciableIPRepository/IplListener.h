/*
 * IplListener.h
 *
 *  Created on: Jul 5, 2011
 *      Author: claudio
 */

#ifndef IPLLISTENER_H_
#define IPLLISTENER_H_

#include <cv.h>
#include <IplEvent.h>
#include <Sequenciable.h>

class IplListener : public Type {
public:
	IplListener(){};
	virtual ~IplListener(){};
//	virtual void actionPerformed(IplEvent* )=0;
};

#endif /* IPLLISTENER_H_ */
