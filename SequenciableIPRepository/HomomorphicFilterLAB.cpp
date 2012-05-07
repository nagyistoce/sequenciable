/*
 * HomomorphicFilterHSV.cpp
 *
 *  Created on: Jun 29, 2011
 *      Author: claudio
 */

#include "HomomorphicFilterLAB.h"
#include <highgui.h>

HomomorphicFilterLAB::HomomorphicFilterLAB(int _filterOrder, int _cutFrequency, int _gain, int _filterType) {
    // TODO Auto-generated constructor stub
    filterOrder = _filterOrder;
    cutFrequency = _cutFrequency;
    gain = _gain;
    filterType = _filterType;
    processed = false;
    input = NULL;
    output = NULL;
    inputCompatibility.push_back(new LABListener());
}

HomomorphicFilterLAB::~HomomorphicFilterLAB() {
    // TODO Auto-generated destructor stub
    if(input!=NULL)
        cvReleaseImage(&input);
    if(output!=NULL)
        cvReleaseImage(&output);

    processed = false;
    inputCompatibility.clear();
}

void HomomorphicFilterLAB::processingCore() {
    cvCopy(input, output);

    IplImage *inputA = cvCreateImage(cvGetSize(output), IPL_DEPTH_8U, 1);
    cvSetImageCOI(output, 1);
    cvCopy(output, inputA);

    IplImage* outputPre = homomorphicFilterProcess(inputA);
    cvCopy(outputPre, output);
    cvSetImageCOI(output, 0);
    cvReleaseImage(&inputA);
    cvReleaseImage(&outputPre);
}

void HomomorphicFilterLAB::actionPerformed(Event* ev) {
    IplEvent *e = (IplEvent*) ev;
    if(input!=NULL)
        cvReleaseImage(&input);
    if(output!=NULL)
        cvReleaseImage(&output);

    input = cvCloneImage(e->getEventIplImage());
    output = cvCreateImage(cvGetSize(input), input->depth, input->nChannels);
    processingCore();
    for (int a = 0; a < listeners.size(); a++) {
        IplEvent *resultEvent = new IplEvent(output);
        listeners[a]->actionPerformed(resultEvent);
        delete resultEvent;
    }
    processed = true;
}
