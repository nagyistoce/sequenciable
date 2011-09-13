/*
 * LABtoRGBTransform.cpp
 *
 *  Created on: Jun 28, 2011
 *      Author: claudio
 */

#include "LABtoRGBTransform.h"

LABtoRGBTransform::LABtoRGBTransform() {
	// TODO Auto-generated constructor stub

}

LABtoRGBTransform::~LABtoRGBTransform() {
	// TODO Auto-generated destructor stub
}

void LABtoRGBTransform::actionPerformed(Event* ev) {
    IplEvent *e = (IplEvent*) ev;
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