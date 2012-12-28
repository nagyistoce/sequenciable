/* 
 * File:   MeanShift.cpp
 * Author: claudio
 * 
 * Created on November 22, 2011, 10:30 AM
 */

#include "MeanShift.h"

MeanShiftProcessor::MeanShiftProcessor(int _sigmaS, float _sigmaR, int _minRegions) {
//    input = NULL;
//    output = NULL;
    sigmaS = _sigmaS;
    sigmaR = _sigmaR;
    minRegions = _minRegions;
    msp = new MSPerformer(sigmaS,sigmaR,minRegions);
    processed = false;
    inputCompatibility.push_back(new RGBListener());
    type = NULL;

    SEQUENCIABLE_ID = 9;
    //textualDescription = "MeanShift";
    stringstream fullDescriptor;
    fullDescriptor << "MeanShift(" <<_sigmaS << "," << _sigmaR << "," << _minRegions << ")";
    textualDescription = fullDescriptor.str();
     //Sigma S
    variablesTypesAndRanges.addTypesAndRanges(1, 1, 20);
     //Sigma R
    variablesTypesAndRanges.addTypesAndRanges(0, 1, 20);
     //min Regions
    variablesTypesAndRanges.addTypesAndRanges(1, 1, 40);
}

MeanShiftProcessor::~MeanShiftProcessor() {
//    if (input != NULL)
//        cvReleaseImage(&input);
//    if (output != NULL)
//        cvReleaseImage(&output);
    processed = false;
    for(int a=0; a< inputCompatibility.size();a++){
        RGBListener *l = (RGBListener*)inputCompatibility[a];
        delete l;
    }
    inputCompatibility.clear();

    inputCompatibility.clear();
    if(type!=NULL)
        delete type;
    
    delete msp;
}
Sequenciable* MeanShiftProcessor::getClone(){
    return new MeanShiftProcessor(sigmaS,sigmaR,minRegions);
}
void MeanShiftProcessor::actionPerformed(Event* ev) {
    IplEvent *e = (IplEvent*) ev;

    IplImage *input = cvCloneImage(e->getEventIplImage());
    inputImageSet = true;
    IplImage *output = cvCreateImage(cvGetSize(input), input->depth, input->nChannels);
    
    msp->doMeanShiftEDISON(input,output);
    
    IplEvent *newEvent = new IplEvent(output);
    //notifyAll(newEvent);
    for (int a = 0; a < listeners.size(); a++) {
        //IplEvent *resultEvent = new IplEvent(output);
        listeners[a]->actionPerformed(newEvent);
    }
    delete newEvent;
    cvReleaseImage(&input);
    cvReleaseImage(&output);

    processed = true;
}
