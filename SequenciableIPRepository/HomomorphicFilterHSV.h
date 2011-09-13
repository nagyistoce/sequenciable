/*
 * HomomorphicFilterHSV.h
 *
 *  Created on: Jun 29, 2011
 *      Author: claudio
 */

#ifndef HOMOMORPHICFILTERHSV_H_
#define HOMOMORPHICFILTERHSV_H_

#include "HomomorphicFilter.h"
#include "HSVListener.h"
//#include "HSVGenerator.h"
#include "IplEvent.h"
#include <Sequenciable.h>
#include <ShortCircuitException.h>
class HomomorphicFilterHSV: public HomomorphicFilter, public HSVListener, public Sequenciable {
public:
	HomomorphicFilterHSV(int filterOrder=1, int cutFrequency=100,int gain=1,int filterType=-1);
	virtual ~HomomorphicFilterHSV();
	virtual void actionPerformed(Event* e);
	virtual void processingCore();
//              virtual bool verifyInputCompatibility(Sequenciable* s){
//                  return dynamic_cast<HSVGenerator*>(s);
//              };
              virtual bool verifyOutputCompatibility(Sequenciable *lis){
                  return dynamic_cast<HSVListener*>(lis);
              };
//	virtual void addHSVListener(HSVListener* _hsvlis){
//		if(_hsvlis==this)
//			throw new ShortCircuitException();
//		hsvlis.clear();
//		hsvlis.push_back(_hsvlis);
//	}
                 virtual bool addSequenciableListener(Sequenciable *_hsvlis){
		if(_hsvlis==this)
			throw new ShortCircuitException();
                
                if(verifyOutputCompatibility(_hsvlis)){
		listeners.push_back(_hsvlis);
                        return true;
                }
                else
                    return false;
	};
        private:
            IplImage *input,*output;
            bool processed;
};

#endif /* HOMOMORPHICFILTERHSV_H_ */
