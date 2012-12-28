/*
 * LABtoRGBTransform.cpp
 *
 *  Created on: Jun 28, 2011
 *      Author: claudio
 */

#include <opencv/cxcore.h>

#include "LABtoRGBTransform.h"

LABtoRGBTransform::LABtoRGBTransform() {
	// TODO Auto-generated constructor stub
    processed = false;
//    input = NULL;
//    output = NULL;
    inputCompatibility.push_back(new LABListener());
    
    SEQUENCIABLE_ID = 6;
    textualDescription = "LAB->RGB";
}

LABtoRGBTransform::~LABtoRGBTransform() {
	// TODO Auto-generated destructor stub
//    if(input!=NULL)
//        cvReleaseImage(&input);
//    if(output!=NULL)
//        cvReleaseImage(&output);
    processed = false;
    for(int a=0; a< inputCompatibility.size();a++){
        LABListener *l = (LABListener*)inputCompatibility[a];
        delete l;
    }
    inputCompatibility.clear();

    inputCompatibility.clear();
}
Sequenciable* LABtoRGBTransform::getClone(){
    return new LABtoRGBTransform();
}
void LABtoRGBTransform::actionPerformed(Event* ev) {
    IplEvent *e = (IplEvent*) ev;
    IplImage* input = cvCloneImage(e->getEventIplImage());
    //	inputImageSet = true;
    IplImage* output = cvCreateImage(cvGetSize(input), input->depth, input->nChannels);
    cvCvtColor(input, output, CV_Lab2BGR);
    processed = true;
    //IplEvent *newEvent = new IplEvent(output);
    //notifyAll(newEvent);
        IplEvent *resultEvent = new IplEvent(output);

    for (int a = 0; a < listeners.size(); a++) {
        listeners[a]->actionPerformed(resultEvent);

    }
                delete resultEvent;
        cvReleaseImage(&input);
        cvReleaseImage(&output);

}