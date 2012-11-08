/*
 * HomomorphicFilterHSV.cpp
 *
 *  Created on: Jun 29, 2011
 *      Author: claudio
 */

#include "HomomorphicFilterHSV.h"
#include <highgui.h>
#include <opencv/cxcore.h>

HomomorphicFilterHSV::HomomorphicFilterHSV(int _filterOrder, int _cutFrequency, int _gain, int _filterType) {
    // TODO Auto-generated constructor stub
    filterOrder = _filterOrder;
    cutFrequency = _cutFrequency;
    gain = _gain;
    filterType = _filterType;
    processed = false;
    input=NULL;
    output=NULL;
    type=NULL;
    inputCompatibility.push_back(new HSVListener());
    
    SEQUENCIABLE_ID = 2;
    
    stringstream fullDescriptor;
    fullDescriptor << "HomomorphicHSV(" << _filterOrder << "," << _cutFrequency << "," << _gain << "," << _filterType << ")";
    textualDescription = fullDescriptor.str();
    
    //int filterOrder=1, int cutFrequency=100,int gain=1,int filterType=-1
    variablesTypesAndRanges.addTypesAndRanges(1, 0, 1);
    variablesTypesAndRanges.addTypesAndRanges(1, 0, 1000);
    variablesTypesAndRanges.addTypesAndRanges(1, 0, 5);

}

HomomorphicFilterHSV::~HomomorphicFilterHSV() {
    // TODO Auto-generated destructor stub
    if(input!=NULL)
        cvReleaseImage(&input);
    if(output!=NULL)
        cvReleaseImage(&output);
    processed = false;
    for(int a=0;a<inputCompatibility.size();a++){
        HSVListener* h = (HSVListener*)inputCompatibility[a];
        delete h;
    }
    inputCompatibility.clear();
}

Sequenciable* HomomorphicFilterHSV::getClone(){
    return new HomomorphicFilterHSV(this->filterOrder,cutFrequency,gain,filterType);
}

void HomomorphicFilterHSV::processingCore() {
    cvCopy(input, output);

    IplImage *inputA = cvCreateImage(cvGetSize(output), IPL_DEPTH_8U, 1);
    cvSetImageCOI(output, 3);
    cvCopy(output, inputA);

    IplImage* outputPre = homomorphicFilterProcess(inputA);
    cvCopy(outputPre, output);
    cvSetImageCOI(output, 0);
    cvReleaseImage(&inputA);
    cvReleaseImage(&outputPre);
}

void HomomorphicFilterHSV::actionPerformed(Event* ev) {
    IplEvent *e = (IplEvent*) ev;
    if(input!=NULL)
        cvReleaseImage(&input);
    input = cvCloneImage(e->getEventIplImage());
    if(output!=NULL)
        cvReleaseImage(&output);
    output = cvCreateImage(cvGetSize(input), input->depth, input->nChannels);
    processingCore();
    for (int a = 0; a < listeners.size(); a++) {
        IplEvent *resultEvent = new IplEvent(output);
        listeners[a]->actionPerformed(resultEvent);
        delete resultEvent;
    }
    processed = true;
}
