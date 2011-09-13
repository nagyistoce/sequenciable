/*
 * RGBtoHSVTransform.h
 *
 *  Created on: Jun 28, 2011
 *      Author: claudio
 */

#ifndef RGBTOLABTRANSFORM_H_
#define RGBTOLABTRANSFORM_H_

//#include <SerializableIpl.h>
#include <RGBListener.h>
//#include <HSVGenerator.h>
#include <Sequenciable.h>
//#include <RGBGenerator.h>
#include <LABListener.h>
#include <ShortCircuitException.h>

class RGBtoLABTransform: public RGBListener, public Sequenciable {
public:
	RGBtoLABTransform();
	virtual ~RGBtoLABTransform();
	virtual void actionPerformed(Event* e);
              virtual bool verifyOutputCompatibility(Sequenciable *lis){
                  return dynamic_cast<LABListener*>(lis);
              };
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

#endif /* RGBTOHSVTRANSFORM_H_ */
