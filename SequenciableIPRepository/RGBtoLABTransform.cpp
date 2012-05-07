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
}

RGBtoLABTransform::~RGBtoLABTransform() {
    // TODO Auto-generated destructor stub
    if (input != NULL)
        cvReleaseImage(&input);
    if (output!=NULL)
        cvReleaseImage(&output);
    processed = false;
    inputCompatibility.clear();
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
