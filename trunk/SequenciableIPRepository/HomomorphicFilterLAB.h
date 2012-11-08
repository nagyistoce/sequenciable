/*
 * HomomorphicFilterHSV.h
 *
 *  Created on: Jun 29, 2011
 *      Author: claudio
 */

#ifndef HOMOMORPHICFILTERLAB_H_
#define HOMOMORPHICFILTERLAB_H_

#include "HomomorphicFilter.h"
#include "LABListener.h"
//#include "HSVGenerator.h"
#include "IplEvent.h"
#include <Sequenciable.h>
#include <ShortCircuitException.h>

class HomomorphicFilterLAB : public HomomorphicFilter, public LABListener, public Sequenciable {
public:
    HomomorphicFilterLAB(int filterOrder = 1, int cutFrequency = 100, int gain = 1, int filterType = -1);
    virtual ~HomomorphicFilterLAB();
    Sequenciable* getClone();
    virtual void actionPerformed(Event* e);
    virtual void processingCore();

    virtual bool verifyOutputCompatibility(Type *lis) {
        return dynamic_cast<LABListener*> (lis);
    };
    virtual bool verifyInputCompatibility(Type *lis) {
        return dynamic_cast<LABListener*> (lis);
    };
    virtual Type* getType(){
//        if(type==NULL)
//            type = new LABListener();
//        return type;
        return this;
    };
    virtual bool addSequenciableListener(Sequenciable *_hsvlis) {
        if (_hsvlis == this)
            throw new ShortCircuitException();

        if (verifyOutputCompatibility(_hsvlis->getType())) {
            listeners.push_back(_hsvlis);
            return true;
        } else
            return false;
    };
private:
    IplImage *input, *output;
    bool processed;
};

#endif /* HOMOMORPHICFILTERHSV_H_ */
