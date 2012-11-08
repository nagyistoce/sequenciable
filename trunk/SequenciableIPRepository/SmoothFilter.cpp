#include "SmoothFilter.h"
#include <highgui.h>

SmoothFilter::SmoothFilter(int _smoothtype, int sz1, int sz2, double p1, double p2) {
    processed = false;
    input = NULL;
    output = NULL;
    smoothType = _smoothtype;
    size1 = sz1;
    size2 = sz2;
    param1 = p1;
    param2 = p2;
    type = NULL;
    inputCompatibility.push_back(new RGBListener());

    SEQUENCIABLE_ID = 1;

    stringstream fullDescriptor;
    fullDescriptor << "Smooth(" << smoothType << "," << sz1 << "," << sz2 << "," << p1 << "," << p2 << ")";
    textualDescription = fullDescriptor.str();

    //int type, int sz1, int sz2, double p1, double p2
    variablesTypesAndRanges.addTypesAndRanges(1,0,4);
    //Only allows Even values -> 0=3x3, 1=5x5, 2=7x7
    variablesTypesAndRanges.addTypesAndRanges(1, 0, 2);
    variablesTypesAndRanges.addTypesAndRanges(1, 0, 2);
    //Sigma 1 and 2
    variablesTypesAndRanges.addTypesAndRanges(0, 0, 15);
    variablesTypesAndRanges.addTypesAndRanges(0, 0, 15);
   
}

SmoothFilter::~SmoothFilter() {
    // TODO Auto-generated destructor stub
    if (input != NULL)
        cvReleaseImage(&input);
    if (output != NULL)
        cvReleaseImage(&output);
    processed = false;
    for(int a=0;a<inputCompatibility.size();a++){
        RGBListener* r = (RGBListener*)inputCompatibility[a];
        delete r;
    }
    inputCompatibility.clear();
    if(type!=NULL)
        delete type;
}
Sequenciable* SmoothFilter::getClone(){
    return new SmoothFilter(smoothType,size1, size2, param1, param2);
}
void SmoothFilter::processingCore() {
    cvSmooth(input, output, smoothType, size1, size2, param1, param2);
}

void SmoothFilter::actionPerformed(Event* ev) {
    IplEvent *e = (IplEvent*) ev;
    if (input != NULL)
        cvReleaseImage(&input);
    if (output != NULL)
        cvReleaseImage(&output);

    input = cvCloneImage(e->getEventIplImage());
    inputImageSet = true;
    output = cvCreateImage(cvGetSize(input), input->depth, input->nChannels);
    processingCore();
    IplEvent *newEvent = new IplEvent(output);
    //notifyAll(newEvent);
    for (int a = 0; a < listeners.size(); a++) {
        //IplEvent *resultEvent = new IplEvent(output);
        listeners[a]->actionPerformed(newEvent);
    }
    delete newEvent;
    processed = true;
}
