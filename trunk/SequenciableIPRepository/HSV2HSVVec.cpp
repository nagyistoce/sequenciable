/*
 * HSV2HSVVec.cpp
 *
 *  Created on: Jul 7, 2011
 *      Author: claudio
 */

#include "HSV2HSVVec.h"

HSV2HSVVec::HSV2HSVVec(int _greyEclusion) {
	// TODO Auto-generated constructor stub
	greyExclusionType = _greyEclusion;
}

HSV2HSVVec::~HSV2HSVVec() {
	// TODO Auto-generated destructor stub
    if(processed){
        cvReleaseImage(&input);
    }
}
void HSV2HSVVec::processingCore(){
	cores = HSVColor::getVectorOfHSVfromHSVIplImage(input,greyExclusionType);
	if(cores.size()==0){
		cores.push_back(HSVColor(0,0,127));
	}
}

void HSV2HSVVec::actionPerformed(Event* ev) {
    IplEvent *e = (IplEvent*) ev;
    input = cvCloneImage(e->getEventIplImage());
    //inputImageSet = true;
    //output = cvCreateImage(cvGetSize(input),input->depth,input->nChannels);
    processingCore();
    //HSVVecEvent* newEvent = new HSVVecEvent(cores);
    //	notifyAll(newEvent);
    for (int a = 0; a < listeners.size(); a++) {
        //IplEvent *resultEvent = new IplEvent(output);
        HSVVecEvent* newEvent = new HSVVecEvent(cores);
        listeners[a]->actionPerformed(newEvent);
        //delete resultEvent;
        delete newEvent;
    }
    processed = true;
}
std::vector<HSVColor> HSV2HSVVec::getOutputHSVColorVector( ){
	return cores;
}
