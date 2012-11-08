/*
 * RGBtoHSVTransform.cpp
 *
 *  Created on: Jun 28, 2011
 *      Author: claudio
 */

#include <opencv/cxcore.h>

#include "RGBtoLABTransform.h"

RGBtoLABTransform::RGBtoLABTransform() {
    input = NULL;
    output = NULL;
    processed = false;
    inputCompatibility.push_back(new RGBListener());
    type = NULL;
    
    SEQUENCIABLE_ID = 7;
    textualDescription = "RGB->LAB";
}

RGBtoLABTransform::~RGBtoLABTransform() {
    // TODO Auto-generated destructor stub
    if (input != NULL)
        cvReleaseImage(&input);
    if (output!=NULL)
        cvReleaseImage(&output);
    processed = false;
    for(int a=0; a< inputCompatibility.size();a++){
        RGBListener *l = (RGBListener*)inputCompatibility[a];
        delete l;
    }
    inputCompatibility.clear();

    inputCompatibility.clear();
    if(type!=NULL)
        delete type;
}

Sequenciable* RGBtoLABTransform::getClone(){
    return new RGBtoLABTransform();
}
void RGBtoLABTransform::actionPerformed(Event* ev) {
    IplEvent *e = (IplEvent*) ev;
    if(input!=NULL)
        cvReleaseImage(&input);
    input = cvCloneImage(e->getEventIplImage());
    if(output!=NULL)
        cvReleaseImage(&output);
    output = cvCreateImage(cvGetSize(input), input->depth, input->nChannels);
    cvCvtColor(input, output, CV_BGR2Lab);
    for (int a = 0; a < listeners.size(); a++) {
        IplEvent *resultEvent = new IplEvent(output);
        listeners[a]->actionPerformed(resultEvent);
        delete resultEvent;
    }
    processed = true;
}
