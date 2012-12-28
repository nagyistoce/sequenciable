/*
 * Brightness.h
 *
 *  Created on: Jun 16, 2011
 *      Author: claudio
 */

#ifndef CONBRI_H_
#define CONBRI_H_

#include <IncompatibleClassesException.h>
#include <ShortCircuitException.h>
#include <RGBListener.h>
//#include <RGBGenerator.h>
#include <IplEvent.h>
#include <cv.h>
#include <Sequenciable.h>

class ContrastBrightness: public RGBListener, public Sequenciable {
public:
	ContrastBrightness(double contrast=1.0, double brightness=0.0);
	virtual ~ContrastBrightness();
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
        virtual Sequenciable* getClone();

    virtual Type* getType() {
//        if(type==NULL){
//            type = new RGBListener();
//        }
//        return type;
        return this;
    };
              virtual void actionPerformed(Event *e);
	//virtual void actionPerformed(IplEvent* e);
//              virtual bool verifyInputCompatibility(Sequenciable* s){
//                  return dynamic_cast<RGBGenerator*>(s);
//              };
              virtual bool verifyOutputCompatibility(Type *lis){
                  return dynamic_cast<RGBListener*>(lis);
              };
              virtual bool verifyInputCompatibility(Type *lis){
                  return dynamic_cast<RGBListener*>(lis);
              };
protected:
    double alpha, beta;
    bool inputImageSet, processed;
    IplImage *input, *output;



//	IplImage *input,*output;
};

#endif 
