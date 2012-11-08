/*
 * RGBtoHSVTransform.h
 *
 *  Created on: Jun 28, 2011
 *      Author: claudio
 */

#ifndef RGBTOHSVTRANSFORM_H_
#define RGBTOHSVTRANSFORM_H_

//#include <SerializableIpl.h>
#include <RGBListener.h>
//#include <HSVGenerator.h>
#include <Sequenciable.h>
//#include <RGBGenerator.h>
#include <HSVListener.h>
#include <ShortCircuitException.h>
#include <HSVRGBTransformation.h>

class RGBtoHSVTransform: public RGBListener, public Sequenciable, public HSVRGBTransformation {
public:
	RGBtoHSVTransform();
	virtual ~RGBtoHSVTransform();
        virtual Sequenciable* getClone();
	virtual void actionPerformed(Event* e);
	virtual void processingCore();
//              virtual bool verifyInputCompatibility(Sequenciable* s){
//                  return dynamic_cast<RGBGenerator*>(s);
//              };
              virtual bool verifyOutputCompatibility(Type *lis){
                  if(!dynamic_cast<HSVListener*>(lis)){
                      return false;
                  }else{
                      if(dynamic_cast<HSVRGBTransformation*>(lis))
                        return false;
                      else
                        return true;
                  }
              };
              virtual bool verifyInputCompatibility(Type *lis){
                  if(!dynamic_cast<RGBListener*>(lis))
                        return false;
                  else{
                      if(dynamic_cast<HSVRGBTransformation*>(lis))
                        return false;
                      else
                        return true;
                  }
              };

    virtual Type* getType() {
//        if(type==NULL){
//            type = new HSVListener();
//        }
//        return type;
        return this;
    };
//	virtual void addHSVListener(HSVListener* _hsvlis){
////			if(_hsvlis==this)
////				throw new ShortCircuitException();
//			//hsvlis.clear();
//			hsvlis.push_back(_hsvlis);
//		};
              	virtual bool addSequenciableListener(Sequenciable *_hsvlis){
		if(_hsvlis==this)
			throw new ShortCircuitException();
                
                if(verifyOutputCompatibility(_hsvlis->getType())){
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

#endif /* RGBTOHSVTRANSFORM_H_ */
