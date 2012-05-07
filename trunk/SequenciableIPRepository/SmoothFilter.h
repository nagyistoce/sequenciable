/*
 * SmoothFilter.h
 *
 *  Created on: Jun 16, 2011
 *      Author: claudio
 */

#ifndef SMOOTHFILTER_H_
#define SMOOTHFILTER_H_

#include <IncompatibleClassesException.h>
#include <ShortCircuitException.h>
#include <RGBListener.h>
//#include <RGBGenerator.h>
#include <IplEvent.h>
#include <cv.h>
#include <Sequenciable.h>

class SmoothFilter: public RGBListener, public Sequenciable {
public:
	SmoothFilter(int type = CV_GAUSSIAN, int sz1 = 3, int sz2 = 0, double p1 =0, double p2=0);
	virtual ~SmoothFilter();
	virtual bool addSequenciableListener(Sequenciable *_rgblis){
		if(_rgblis==this)
			throw new ShortCircuitException();
                
                if(verifyOutputCompatibility(_rgblis->getType())){
		listeners.push_back(_rgblis);
                        return true;
                }
                else
                    return false;
	};

    virtual Type* getType() {
        if(type==NULL){
            type = new RGBListener();
        }
        return type;
    };
              virtual void actionPerformed(Event *e);
	//virtual void actionPerformed(IplEvent* e);
//              virtual bool verifyInputCompatibility(Sequenciable* s){
//                  return dynamic_cast<RGBGenerator*>(s);
//              };
              virtual bool verifyOutputCompatibility(Type *lis){
                  return dynamic_cast<RGBListener*>(lis);
              };
protected:
//	bool inputImageSet,processed;
	int smoothType;
	int size1,size2;
	double param1,param2;
              bool inputImageSet, processed;
              IplImage *input, *output;

private:
	virtual void processingCore();

//	IplImage *input,*output;
};

#endif /* SMOOTHFILTER_H_ */
