/*
 * HSVtoRGBTransform.cpp
 *
 *  Created on: Jun 28, 2011
 *      Author: claudio
 */

#include "HSVtoRGBTransform.h"

HSVtoRGBTransform::HSVtoRGBTransform() {
	// TODO Auto-generated constructor stub
	//outputType = Serializable::IPL_RGB;
	//addInputType(Serializable::IPL_HSV);
    processed = false;
}

HSVtoRGBTransform::~HSVtoRGBTransform() {
	// TODO Auto-generated destructor stub
    if(processed){
        cvReleaseImage(&input);
        cvReleaseImage(&output);
    }
}
//void HSVtoRGBTransform::processingCore(){
////	if(inputImageSet){
////		if(output!=NULL)
////			cvReleaseImage(&output);
////		output = cvCreateImage(cvGetSize(input),input->depth,input->nChannels);
//       cvCvtColor(input,output,CV_HSV2BGR);
////		processed = true;
////		serializableEventPerformed(new Event(Event::OK));
////	}else{
////		serializableEventPerformed(new Event(Event::ERROR));
////	}
//        processed = true;
//}
void HSVtoRGBTransform::actionPerformed(Event* ev){
    IplEvent *e = (IplEvent*)ev;
	input = cvCloneImage(e->getEventIplImage());
//	inputImageSet = true;
	output = cvCreateImage(cvGetSize(input),input->depth,input->nChannels);
//	processingCore();
        cvCvtColor(input,output,CV_HSV2BGR);
        processed = true;
//	IplEvent *newEvent = new IplEvent(output);
	//notifyAll(newEvent);
            for (int a = 0; a < listeners.size(); a++) {
        IplEvent *resultEvent = new IplEvent(output);
        listeners[a]->actionPerformed(resultEvent);
        delete resultEvent;
    }

}
