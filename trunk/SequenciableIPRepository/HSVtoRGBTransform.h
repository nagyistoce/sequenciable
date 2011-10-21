/*
 * HSVtoRGBTransform.h
 *
 *  Created on: Jun 28, 2011
 *      Author: claudio
 */

#ifndef HSVTORGBTRANSFORM_H_
#define HSVTORGBTRANSFORM_H_

//#include <SerializableIpl.h>
#include <ShortCircuitException.h>
#include <HSVListener.h>
//#include <RGBGenerator.h>
#include <IplEvent.h>
#include <Sequenciable.h>
//#include <HSVGenerator.h>
#include <RGBListener.h>
#include <HSVRGBTransformation.h>

class HSVtoRGBTransform: public HSVListener, public Sequenciable, public HSVRGBTransformation {
public:
	HSVtoRGBTransform();
	virtual ~HSVtoRGBTransform();
//	virtual void processingCore();
	virtual void actionPerformed(Event* ev);
//	virtual void addHSVListener(HSVListener* _hsvlis){
//			if(_hsvlis==this)
//				throw new ShortCircuitException();
//			hsvlis.clear();
//			hsvlis.push_back(_hsvlis);
//		};
//              virtual bool verifyInputCompatibility(Sequenciable* s){
//                  return dynamic_cast<HSVGenerator*>(s);
//              };
              virtual bool verifyOutputCompatibility(Sequenciable *lis){
                  if(!dynamic_cast<RGBListener*>(lis)){
                      return false;
                  }else{
                      if(dynamic_cast<HSVRGBTransformation*>(lis))
                        return false;
                      else
                        return true;
                  }

              };
//	virtual void addRGBListener(RGBListener* _rgblis){
////		if(_rgblis==this)
////			throw new ShortCircuitException();
//		rgblis.clear();
//		rgblis.push_back(_rgblis);
//	};
              	virtual bool addSequenciableListener(Sequenciable *_rgblis){
		if(_rgblis==this)
			throw new ShortCircuitException();
                
                if(verifyOutputCompatibility(_rgblis)){
		listeners.push_back(_rgblis);
                        return true;
                }
                else
                    return false;
	};
        private:
            IplImage *input,*output;
            bool processed;
};

#endif /* HSVTORGBTRANSFORM_H_ */
