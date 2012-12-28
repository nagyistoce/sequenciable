/* 
 * File:   SRMSegmentation.h
 * Author: claudio
 *
 * Created on December 27, 2012, 3:54 PM
 */

#ifndef SRMSEGMENTATION_H
#define	SRMSEGMENTATION_H

#include <sstream>
#include <Sequenciable.h>
#include <RGBListener.h>
#include <ShortCircuitException.h>
#include <IplEvent.h>
#include <cv.h>

class SRMSegmentation  : public Sequenciable, public RGBListener {
public:
    SRMSegmentation();
    SRMSegmentation(const SRMSegmentation& orig);
    virtual ~SRMSegmentation();
    virtual Sequenciable* getClone();
    virtual bool addSequenciableListener(Sequenciable *_rgblis) {
        if (_rgblis == this)
            throw new ShortCircuitException();
            listeners.push_back(_rgblis);
    };
    virtual void actionPerformed(Event *e);
    virtual Type* getType(){
        return this;
    };
    virtual bool verifyOutputCompatibility(Type *lis) {
        return dynamic_cast<RGBListener*> (lis);
    };
    virtual bool verifyInputCompatibility(Type *lis) {
        return dynamic_cast<RGBListener*> (lis);
    };    
private:

};

#endif	/* SRMSEGMENTATION_H */

