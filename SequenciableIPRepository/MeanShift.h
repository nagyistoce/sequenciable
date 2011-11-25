/* 
 * File:   MeanShift.h
 * Author: claudio
 *
 * Created on November 22, 2011, 10:30 AM
 */

#ifndef MEANSHIFT_H
#define	MEANSHIFT_H
#include <Sequenciable.h>
#include <RGBListener.h>
#include <MSPerformer.h>
#include <ShortCircuitException.h>
#include <IplEvent.h>

class MeanShiftProcessor : public Sequenciable, public RGBListener {
public:
    MeanShiftProcessor(int _sigmaS=6, float _sigmaR=7.0, int _minRegions=10);
    virtual ~MeanShiftProcessor();

    virtual bool addSequenciableListener(Sequenciable *_rgblis) {
        if (_rgblis == this)
            throw new ShortCircuitException();

        if (verifyOutputCompatibility(_rgblis)) {
            listeners.push_back(_rgblis);
            return true;
        } else
            return false;
    };
    virtual void actionPerformed(Event *e);

    virtual bool verifyOutputCompatibility(Sequenciable *lis) {
        return dynamic_cast<RGBListener*> (lis);
    };
private:
    int sigmaS;
    float sigmaR;
    int minRegions;
    bool inputImageSet, processed;
    IplImage *input, *output;
    MSPerformer *msp;
};

#endif	/* MEANSHIFT_H */

