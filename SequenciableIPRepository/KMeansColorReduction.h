/* 
 * File:   KMeansColorReduction.h
 * Author: claudio
 *
 * Created on December 28, 2012, 10:20 AM
 */

#ifndef KMEANSCOLORREDUCTION_H
#define	KMEANSCOLORREDUCTION_H

#include <Sequenciable.h>
#include <ShortCircuitException.h>
#include <IplEvent.h>
#include <cv.h>
#include "RGBListener.h"
class KMeansColorReduction : public Sequenciable, public RGBListener {
public:
    KMeansColorReduction(int _k=3);
    KMeansColorReduction(const KMeansColorReduction& orig);
    virtual ~KMeansColorReduction();
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
        return this;
    };
    virtual void actionPerformed(Event *e);
    virtual bool verifyOutputCompatibility(Type *lis){
        return dynamic_cast<RGBListener*>(lis);
    };
    virtual bool verifyInputCompatibility(Type *lis){
        return dynamic_cast<RGBListener*>(lis);
    };

private:
    int k;
};

#endif	/* KMEANSCOLORREDUCTION_H */

