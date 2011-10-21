#include "SmoothFilter.h"
#include <highgui.h>

SmoothFilter::SmoothFilter(int type, int sz1, int sz2, double p1, double p2) {
    processed = false;
    input = NULL;
    output = NULL;
    smoothType = type;
    size1 = sz1;
    size2 = sz2;
    param1 = p1;
    param2 = p2;
}

SmoothFilter::~SmoothFilter() {
    // TODO Auto-generated destructor stub
    if (input != NULL)
        cvReleaseImage(&input);
    if (output != NULL)
        cvReleaseImage(&output);
    processed = false;
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
