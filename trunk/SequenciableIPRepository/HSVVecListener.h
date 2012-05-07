/*
 * HSVVecListener.h
 *
 *  Created on: Jul 7, 2011
 *      Author: claudio
 */

#ifndef HSVVECLISTENER_H_
#define HSVVECLISTENER_H_

#include "HSVVecEvent.h"
#include <Type.h>

class HSVVecListener : public Type {
public:
	HSVVecListener(){};
	virtual ~HSVVecListener(){};
//	virtual void actionPerformed(HSVVecEvent* )=0;
protected:
	vector<HSVColor> inputVec;
};

#endif /* HSVVECLISTENER_H_ */
