/*
 * HSVColorClusterEstimation.h
 *
 *  Created on: Jul 7, 2011
 *      Author: claudio
 */

#ifndef HSVCOLORCLUSTERESTIMATION_H_
#define HSVCOLORCLUSTERESTIMATION_H_

#include <HSVVecListener.h>
#include <HSVVecEvent.h>
#include <Sequenciable.h>
#include <ShortCircuitException.h>
#include <IplEvent.h>

class HSVColorClusterEstimation : public HSVVecListener, public Sequenciable {
public:
    HSVColorClusterEstimation(int neighbor);
    virtual ~HSVColorClusterEstimation();
    virtual void processingCore();
    virtual void actionPerformed(Event* e);
    //	virtual void addHSVListener(HSVListener* _hsvlis){
    //			if(_hsvlis==this)
    //				throw new ShortCircuitException();
    //			hsvlis.clear();
    //			hsvlis.push_back(_hsvlis);
    //		};

//    virtual void addHSVVecListener(HSVVecListener* _hsvveclis) {
//        //		if(_rgblis==this)
//        //			throw new ShortCircuitException();
//        hsvveclis.clear();
//        hsvveclis.push_back(_hsvveclis);
//    };
    virtual vector<HSVColor> getOutputHSVColorVector();
//    virtual bool verifyInputCompatibility(Sequenciable* s){
//        return dynamic_cast<HSVVecGenerator*>(s);
//    };
    virtual bool verifyOutputCompatibility(Sequenciable *lis){
        return dynamic_cast<HSVVecListener*>(lis);
    };
      	virtual bool addSequenciableListener(Sequenciable *_hsvveclis){
		if(_hsvveclis==this)
			throw new ShortCircuitException();
                
                if(verifyOutputCompatibility(_hsvveclis)){
		listeners.push_back(_hsvveclis);
                        return true;
                }
                else
                    return false;
	};
private:
    int neighborhoodEstimation;
    vector<HSVColor> input;
    vector<HSVColor> cores;
    int greyExclusionType;
    vector<HSVColor> estimateClustersForHSV(vector<HSVColor> cores, int neighboorhood);
    bool processed;
};

#endif /* HSVCOLORCLUSTERESTIMATION_H_ */
