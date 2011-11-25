/* 
 * File:   MeanShift.cpp
 * Author: claudio
 * 
 * Created on November 22, 2011, 10:30 AM
 */

#include "MeanShift.h"

MeanShiftProcessor::MeanShiftProcessor(int _sigmaS, float _sigmaR, int _minRegions) {
    input = NULL;
    output = NULL;
    sigmaS = _sigmaS;
    sigmaR = _sigmaR;
    minRegions = _minRegions;
    msp = new MSPerformer(sigmaS,sigmaR,minRegions);
    processed = false;
    
}

MeanShiftProcessor::~MeanShiftProcessor() {
    if (input != NULL)
        cvReleaseImage(&input);
    if (output != NULL)
        cvReleaseImage(&output);
    processed = false;
}

void MeanShiftProcessor::actionPerformed(Event* ev) {
    IplEvent *e = (IplEvent*) ev;
    if (input != NULL)
        cvReleaseImage(&input);
    if (output != NULL)
        cvReleaseImage(&output);

    input = cvCloneImage(e->getEventIplImage());
    inputImageSet = true;
    output = cvCreateImage(cvGetSize(input), input->depth, input->nChannels);
    
    msp->doMeanShiftEDISON(input,output);
    
    IplEvent *newEvent = new IplEvent(output);
    //notifyAll(newEvent);
    for (int a = 0; a < listeners.size(); a++) {
        //IplEvent *resultEvent = new IplEvent(output);
        listeners[a]->actionPerformed(newEvent);
    }
    delete newEvent;
    processed = true;
}
