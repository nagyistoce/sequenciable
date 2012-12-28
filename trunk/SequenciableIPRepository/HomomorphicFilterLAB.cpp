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
//    input = NULL;
//    output = NULL;
    inputCompatibility.push_back(new LABListener());
    
    SEQUENCIABLE_ID = 3;
    stringstream fullDescriptor;
    fullDescriptor << "HomomorphicLAB(" <<  _filterOrder << "," << _cutFrequency << "," << _gain << "," << _filterType << ")";
    textualDescription = fullDescriptor.str();

    //int filterOrder=1, int cutFrequency=100,int gain=1,int filterType=-1
    variablesTypesAndRanges.addTypesAndRanges(1, 0, 1);
    variablesTypesAndRanges.addTypesAndRanges(1, 0, 1000);
    variablesTypesAndRanges.addTypesAndRanges(1, 0, 5);
    
}

HomomorphicFilterLAB::~HomomorphicFilterLAB() {
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
}
Sequenciable* HomomorphicFilterLAB::getClone(){
    return new HomomorphicFilterLAB(filterOrder,cutFrequency,gain,filterType);
}
void HomomorphicFilterLAB::processingCore(IplImage* input, IplImage* output) {
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

    IplImage *input = cvCloneImage(e->getEventIplImage());
    IplImage *output = cvCreateImage(cvGetSize(input), input->depth, input->nChannels);
    processingCore(input,output);
    IplEvent *resultEvent = new IplEvent(output);
    for (int a = 0; a < listeners.size(); a++) {
        listeners[a]->actionPerformed(resultEvent);
    }
    delete resultEvent;

    cvReleaseImage(&input);
    cvReleaseImage(&output);

    processed = true;
}
