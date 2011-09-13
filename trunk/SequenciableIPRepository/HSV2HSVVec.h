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

class HSV2HSVVec: public HSVListener, public Sequenciable {
public:
	HSV2HSVVec(int _greyExclusion=0);
	virtual ~HSV2HSVVec();
	virtual void processingCore();
               virtual void actionPerformed(Event* e);
	//virtual void actionPerformed(IplEvent* e);
	//	virtual void addHSVListener(HSVListener* _hsvlis){
	//			if(_hsvlis==this)
	//				throw new ShortCircuitException();
	//			hsvlis.clear();
	//			hsvlis.push_back(_hsvlis);
	//		};
//	virtual void addHSVVecListener(HSVVecListener* _hsvveclis){
//		//		if(_rgblis==this)
//		//			throw new ShortCircuitException();
//		//hsvveclis.clear();
//		hsvveclis.push_back(_hsvveclis);
//	};
               virtual bool addSequenciableListener(Sequenciable* _hsvveclis){
                   if(_hsvveclis==this)
		throw new ShortCircuitException();
                listeners.push_back(_hsvveclis);
               }
                virtual bool verifyOutputCompatibility(Sequenciable *lis){
                  return dynamic_cast<HSVVecListener*>(lis);
              };
	virtual std::vector<HSVColor> getOutputHSVColorVector( );
private:
	std::vector<HSVColor> cores;
	int greyExclusionType;
        IplImage* input, *output;
        bool processed;
};

#endif /* HSV2HSVVEC_H_ */
