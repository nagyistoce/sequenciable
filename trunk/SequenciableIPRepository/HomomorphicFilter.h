/*
 * HomomorphicFilter.h
 *
 *  Created on: Jun 29, 2011
 *      Author: claudio
 */

#ifndef HOMOMORPHICFILTER_H_
#define HOMOMORPHICFILTER_H_

//#include <SerializableIpl.h>
#include <cv.h>
#include "homomorphic_opencv.h"

class HomomorphicFilter {
public:
	HomomorphicFilter(int filterOrder=1, int cutFrequency=100,int gain=1,int filterType=-1);
	virtual ~HomomorphicFilter();
	virtual void processingCore()=0;
//	virtual int process();
protected:
	IplImage *homomorphicFilterProcess(IplImage *toProcess);
	int filterOrder,cutFrequency,gain,filterType;
};

#endif /* HOMOMORPHICFILTER_H_ */
