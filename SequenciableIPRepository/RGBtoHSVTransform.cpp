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
//    input = NULL;
//    output = NULL;
    inputCompatibility.push_back(new RGBListener());
    type = NULL;
    
    SEQUENCIABLE_ID = 5;
    textualDescription = "RGB->HSV";

}

RGBtoHSVTransform::~RGBtoHSVTransform() {
	// TODO Auto-generated destructor stub
//    if(input!=NULL)
//        cvReleaseImage(&input);
//    if(output!=NULL)
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
}
Sequenciable* RGBtoHSVTransform::getClone(){
    return new RGBtoHSVTransform();
}
void RGBtoHSVTransform::processingCore(){
//		cvCvtColor(input,output,CV_BGR2HSV);
}
void RGBtoHSVTransform::actionPerformed(Event* ev){
    IplEvent *e = (IplEvent*) ev;
//    if (input != NULL)
//        cvReleaseImage(&input);
//    if (output != NULL)
//        cvReleaseImage(&output);
    IplImage* input = cvCloneImage(e->getEventIplImage());
    IplImage* output = cvCreateImage(cvGetSize(input), input->depth, input->nChannels);
    cvCvtColor(input, output, CV_BGR2HSV);
    IplEvent *resultEvent = new IplEvent(output);
    for (int a = 0; a < listeners.size(); a++) {
        listeners[a]->actionPerformed(resultEvent);
    }
    delete resultEvent;
    cvReleaseImage(&input);
    cvReleaseImage(&output);
    processed = true;
}
