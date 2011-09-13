/*
 * HomomorphicFilter.cpp
 *
 *  Created on: Jun 29, 2011
 *      Author: claudio
 */

#include "HomomorphicFilter.h"

HomomorphicFilter::HomomorphicFilter(int filterOrder, int cutFrequency,int gain,int filterType) {
	// TODO Auto-generated constructor stub
	filterOrder = filterOrder;
	cutFrequency = cutFrequency;
	gain = gain;
	filterType = filterType;
	//setOutputType(Serializable::IPL_GREY);
	//addInputType(Serializable::IPL_GREY);
}

HomomorphicFilter::~HomomorphicFilter() {
	// TODO Auto-generated destructor stub
//	if(inputImageSet)
//		cvReleaseImage(&input);
//	if(processed)
//		cvReleaseImage(&output);
}
IplImage *HomomorphicFilter::homomorphicFilterProcess(IplImage *toProcess){

	return homomorphic_filter(toProcess,filterOrder,cutFrequency,gain,filterType);

}
//int HomomorphicFilter::process(){
//	if(inputImageSet){
//			if(output!=NULL)
//				cvReleaseImage(&output);
//
//			output = homomorphicFilterProcess(input);
//
//			processed = true;
//			serializableEventPerformed(new Event(Event::OK));
//		}else{
//			serializableEventPerformed(new Event(Event::ERROR));
//		}
//
//
//}
