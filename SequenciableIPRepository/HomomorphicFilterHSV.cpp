/*
 * HomomorphicFilterHSV.cpp
 *
 *  Created on: Jun 29, 2011
 *      Author: claudio
 */

#include "HomomorphicFilterHSV.h"
#include <highgui.h>
HomomorphicFilterHSV::HomomorphicFilterHSV(int _filterOrder, int _cutFrequency,int _gain,int _filterType) {
	// TODO Auto-generated constructor stub
	filterOrder = _filterOrder;
	cutFrequency = _cutFrequency;
	gain = _gain;
	filterType = _filterType;
//	setOutputType(Serializable::IPL_HSV);
//	addInputType(Serializable::IPL_HSV);
        processed = false;
}

HomomorphicFilterHSV::~HomomorphicFilterHSV() {
	// TODO Auto-generated destructor stub
}
void HomomorphicFilterHSV::processingCore(){
//	if(inputImageSet){
//			if(output!=NULL)
//				cvReleaseImage(&output);
//			output = cvCloneImage(input);
			cvCopy(input,output);

			IplImage *inputA = cvCreateImage(cvGetSize(output),IPL_DEPTH_8U,1);
			cvSetImageCOI(output,3);
			cvCopy(output,inputA);

			IplImage* outputPre = homomorphicFilterProcess(inputA);
			cvCopy(outputPre,output);
			cvSetImageCOI(output,0);
			cvReleaseImage(&inputA);
			cvReleaseImage(&outputPre);
//			processed = true;
//			serializableEventPerformed(new Event(Event::OK));
//	}else{
//		serializableEventPerformed(new Event(Event::ERROR));
//	}
}
void HomomorphicFilterHSV::actionPerformed(Event* ev){
    IplEvent *e = (IplEvent*)ev;
	input = cvCloneImage(e->getEventIplImage());
//	inputImageSet = true;
	output = cvCreateImage(cvGetSize(input),input->depth,input->nChannels);
	processingCore();
	IplEvent *newEvent = new IplEvent(output);
///	notifyAll(newEvent);
            for (int a = 0; a < listeners.size(); a++) {
        IplEvent *resultEvent = new IplEvent(output);
        listeners[a]->actionPerformed(resultEvent);
        delete resultEvent;
    }
	processed = true;
}
