/*
 * LABtoRGBTransform.h
 *
 *  Created on: Jun 28, 2011
 *      Author: claudio
 */

#ifndef LABTORGBTRANSFORM_H_
#define LABTORGBTRANSFORM_H_

#include <LABListener.h>
#include <Sequenciable.h>
#include <RGBListener.h>
#include <LABRGBTransformation.h>
#include <ShortCircuitException.h>

class LABtoRGBTransform : public LABListener, public LABRGBTransformation, public Sequenciable {
public:
    LABtoRGBTransform();
    virtual ~LABtoRGBTransform();
    virtual void actionPerformed(Event* ev);
    virtual Type* getType(){
        LABListener *type;
        return type;
    };
    virtual bool verifyOutputCompatibility(Type *lis) {
        if (!dynamic_cast<RGBListener*> (lis))
            return false;
        else {
            if (dynamic_cast<LABRGBTransformation*> (lis))
                return false;
            else
                return true;
        }
    };

    virtual bool addSequenciableListener(Sequenciable *_rgblis) {
        if (_rgblis == this)
            throw new ShortCircuitException();

       // if (verifyOutputCompatibility(_rgblis)) {
            listeners.push_back(_rgblis);
         //   return true;
        //} else
          //  return false;
    };
private:
    IplImage *input, *output;
    bool processed;
};

#endif /* LABTORGBTRANSFORM_H_ */
