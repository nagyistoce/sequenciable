/*
 * RGBtoHSVTransform.cpp
 *
 *  Created on: Jun 28, 2011
 *      Author: claudio
 */

#include "RGBtoLABTransform.h"

RGBtoLABTransform::RGBtoLABTransform() {
	// TODO Auto-generated constructor stub
//	setOutputType(Serializable::IPL_HSV);
//	addInputType(Serializable::IPL_RGB);
}

RGBtoLABTransform::~RGBtoLABTransform() {
	// TODO Auto-generated destructor stub
}
//void RGBtoLABTransform::processingCore(){
////	if(inputImageSet){
////		if(output!=NULL)
////			cvReleaseImage(&output);
////		output = cvCreateImage(cvGetSize(input),input->depth,input->nChannels);
//		cvCvtColor(input,output,CV_BGR2HSV);
////		processed = true;
////		serializableEventPerformed(new Event(Event::OK));
////	}else{
////		serializableEventPerformed(new Event(Event::ERROR));
////	}
//}
void RGBtoLABTransform::actionPerformed(Event* ev){
    IplEvent *e = (IplEvent*)ev;
	input = cvCloneImage(e->getEventIplImage());
//	inputImageSet = true;
	output = cvCreateImage(cvGetSize(input),input->depth,input->nChannels);
	//processingCore();
                cvCvtColor(input,output,CV_BGR2Lab);
	//IplEvent *newEvent = new IplEvent(output);
	//notifyAll(newEvent);
            for (int a = 0; a < listeners.size(); a++) {
        IplEvent *resultEvent = new IplEvent(output);
        listeners[a]->actionPerformed(resultEvent);
        delete resultEvent;
    }
	processed = true;
}
