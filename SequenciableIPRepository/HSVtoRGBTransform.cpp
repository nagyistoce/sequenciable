/*
 * HSVtoRGBTransform.cpp
 *
 *  Created on: Jun 28, 2011
 *      Author: claudio
 */

#include <opencv/cxcore.h>

#include "HSVtoRGBTransform.h"

HSVtoRGBTransform::HSVtoRGBTransform() {
    processed = false;
    input = NULL;
    output = NULL;
    inputCompatibility.push_back(new HSVListener());
    type = NULL;
    
    SEQUENCIABLE_ID = 4;
    textualDescription = "HSV->RGB";
}

HSVtoRGBTransform::~HSVtoRGBTransform() {
	// TODO Auto-generated destructor stub
    if(input!=NULL)
        cvReleaseImage(&input);
    if(output!=NULL)
        cvReleaseImage(&output);
    processed = false;
    for(int a=0; a< inputCompatibility.size();a++){
        HSVListener *l = (HSVListener*)inputCompatibility[a];
        delete l;
    }
    inputCompatibility.clear();

    inputCompatibility.clear();
    if(type!=NULL)
        delete type;
}
Sequenciable* HSVtoRGBTransform::getClone(){
    return new HSVtoRGBTransform();
}
void HSVtoRGBTransform::actionPerformed(Event* ev) {
    IplEvent *e = (IplEvent*) ev;
    if(input!=NULL)
        cvReleaseImage(&input);
    input = cvCloneImage(e->getEventIplImage());
    if(output!=NULL)
        cvReleaseImage(&output);
    output = cvCreateImage(cvGetSize(input), input->depth, input->nChannels);
    cvCvtColor(input, output, CV_HSV2BGR);
    processed = true;
    for (int a = 0; a < listeners.size(); a++) {
        IplEvent *resultEvent = new IplEvent(output);
        listeners[a]->actionPerformed(resultEvent);
        delete resultEvent;
    }

}
