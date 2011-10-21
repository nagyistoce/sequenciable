/*
 * RGBtoHSVTransform.cpp
 *
 *  Created on: Jun 28, 2011
 *      Author: claudio
 */

#include <opencv/highgui.h>

#include "RGBtoHSVTransform.h"

RGBtoHSVTransform::RGBtoHSVTransform() {
	// TODO Auto-generated constructor stub
//	setOutputType(Serializable::IPL_HSV);
//	addInputType(Serializable::IPL_RGB);
    processed = false;
    input = NULL;
    output = NULL;
}

RGBtoHSVTransform::~RGBtoHSVTransform() {
	// TODO Auto-generated destructor stub
    if(input!=NULL)
        cvReleaseImage(&input);
    if(output!=NULL)
        cvReleaseImage(&output);
    processed = false;

}
void RGBtoHSVTransform::processingCore(){
		cvCvtColor(input,output,CV_BGR2HSV);
}
void RGBtoHSVTransform::actionPerformed(Event* ev){
    IplEvent *e = (IplEvent*) ev;
    if (input != NULL)
        cvReleaseImage(&input);
    if (output != NULL)
        cvReleaseImage(&output);
    input = cvCloneImage(e->getEventIplImage());
    output = cvCreateImage(cvGetSize(input), input->depth, input->nChannels);
    cvCvtColor(input, output, CV_BGR2HSV);
    for (int a = 0; a < listeners.size(); a++) {
        IplEvent *resultEvent = new IplEvent(output);
        listeners[a]->actionPerformed(resultEvent);
        delete resultEvent;
    }
    processed = true;
}
