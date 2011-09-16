/*
 * SmoothFilter.cpp
 *
 *  Created on: Jun 16, 2011
 *      Author: claudio
 */

#include "SmoothFilter.h"
#include <highgui.h>

SmoothFilter::SmoothFilter(int type, int sz1, int sz2, double p1,double p2) {
	// TODO Auto-generated constructor stub
	//setOutputType(Serializable::IPL_RGB);
	//outputType = Serializable::IPL_RGB;
	//addInputType(Serializable::IPL_RGB);
	inputImageSet=false;
	processed = false;
	output=NULL;
	smoothType = type;
	size1 = sz1;
	size2 = sz2;
	param1 = p1;
	param2 = p2;
}

SmoothFilter::~SmoothFilter() {
	// TODO Auto-generated destructor stub
	if(inputImageSet)
		cvReleaseImage(&input);
	if(processed)
		cvReleaseImage(&output);
        inputImageSet = false;
        processed = false;
}
void SmoothFilter::processingCore(){
//	if(inputImageSet){
//		if(output!=NULL)
//			cvReleaseImage(&output);
//		output = cvCreateImage(cvGetSize(input),input->depth,input->nChannels);
		cvSmooth(input,output,smoothType,size1,size2,param1,param2);
//		processed = true;
//		serializableEventPerformed(new Event(Event::OK));
//	}else{
//		serializableEventPerformed(new Event(Event::ERROR));
//	}
}
//void SmoothFilter::actionPerformed(IplEvent* e){

void SmoothFilter::actionPerformed(Event* ev) {
    IplEvent *e = (IplEvent*) ev;
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
//void SmoothFilter::setInputIpl(IplImage* in){
//	inputImageSet = true;
//	input = cvCloneImage(in);
//}
//IplImage* SmoothFilter::getOutputIpl( ){
//	if(processed)
//		return output;
//
//}
