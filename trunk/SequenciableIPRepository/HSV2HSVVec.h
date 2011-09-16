/*
 * HSV2HSVVec.h
 *
 *  Created on: Jul 7, 2011
 *      Author: claudio
 */

#ifndef HSV2HSVVEC_H_
#define HSV2HSVVEC_H_

#include <HSVListener.h>
//#include <HSVVecGenerator.h>
#include <HSVVecListener.h>
#include <HSVVecEvent.h>
#include <Sequenciable.h>
#include <ShortCircuitException.h>
#include <vector>

class HSV2HSVVec : public HSVListener, public Sequenciable {
public:
    HSV2HSVVec(int _greyExclusion = 0);
    virtual ~HSV2HSVVec();
    virtual void processingCore();
    virtual void actionPerformed(Event* e);

    virtual bool addSequenciableListener(Sequenciable* _hsvveclis) {
        if (_hsvveclis == this)
            throw new ShortCircuitException();
        listeners.push_back(_hsvveclis);
    }

    virtual bool verifyOutputCompatibility(Sequenciable *lis) {
        return dynamic_cast<HSVVecListener*> (lis);
    };
    virtual std::vector<HSVColor> getOutputHSVColorVector();
private:
    std::vector<HSVColor> cores;
    int greyExclusionType;
    IplImage* input;
    bool processed;
};

#endif /* HSV2HSVVEC_H_ */
