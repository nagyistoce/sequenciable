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
    input = NULL;
    output = NULL;
}

LABtoRGBTransform::~LABtoRGBTransform() {
	// TODO Auto-generated destructor stub
    if(input!=NULL)
        cvReleaseImage(&input);
    if(output!=NULL)
        cvReleaseImage(&output);
    processed = false;

}

void LABtoRGBTransform::actionPerformed(Event* ev) {
    IplEvent *e = (IplEvent*) ev;
    if(input!=NULL)
        cvReleaseImage(&input);
    if(output!=NULL)
        cvReleaseImage(&output);
    input = cvCloneImage(e->getEventIplImage());
    //	inputImageSet = true;
    output = cvCreateImage(cvGetSize(input), input->depth, input->nChannels);
    cvCvtColor(input, output, CV_Lab2BGR);
    processed = true;
    //IplEvent *newEvent = new IplEvent(output);
    //notifyAll(newEvent);
    for (int a = 0; a < listeners.size(); a++) {
        IplEvent *resultEvent = new IplEvent(output);
        listeners[a]->actionPerformed(resultEvent);
        delete resultEvent;
    }

}