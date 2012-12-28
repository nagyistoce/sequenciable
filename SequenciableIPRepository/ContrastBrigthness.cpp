#include "ContrastBrightness.h"
#include <highgui.h>

ContrastBrightness::ContrastBrightness(double contrast, double brightness) {
    processed = false;
//    input = NULL;
//    output = NULL;
    alpha = contrast;
    //This subtraction is to allow values between -100 & 100
    beta = brightness-100;
    
    type = NULL;
    inputCompatibility.push_back(new RGBListener());

    SEQUENCIABLE_ID = 10;

    stringstream fullDescriptor;
    fullDescriptor << "Brightness&Contrast(" << alpha << "," << beta << ")";
    textualDescription = fullDescriptor.str();

    //alpha beta
    variablesTypesAndRanges.addTypesAndRanges(0, 0, 3);
    variablesTypesAndRanges.addTypesAndRanges(1, 0, 200);
   
}

ContrastBrightness::~ContrastBrightness() {
    // TODO Auto-generated destructor stub
//    if (input != NULL)
//        cvReleaseImage(&input);
//    if (output != NULL)
//        cvReleaseImage(&output);
    processed = false;
    for(int a=0;a<inputCompatibility.size();a++){
        RGBListener* r = (RGBListener*)inputCompatibility[a];
        delete r;
    }
    inputCompatibility.clear();
    if(type!=NULL)
        delete type;
}
Sequenciable* ContrastBrightness::getClone(){
    return new ContrastBrightness(alpha,beta+100);
}
void ContrastBrightness::actionPerformed(Event* ev) {
    IplEvent *e = (IplEvent*) ev;
//    if (input != NULL)
//        cvReleaseImage(&input);
//    if (output != NULL)
//        cvReleaseImage(&output);

    inputImageSet = true;
//    IplImage *input = ;
    
    cv::Mat image = cv::cvarrToMat(e->getEventIplImage(),true);
    cv::Mat new_image = cv::Mat::zeros( image.size(), image.type() );
    image.convertTo(new_image, -1, alpha, beta);
    //output = new IplImage(new_image);
    //output = cvCloneImage(new_image);
    IplImage toTransfer = new_image;
    
    //notifyAll(newEvent);
    IplEvent *newEvent = new IplEvent(&toTransfer);
    for (int a = 0; a < listeners.size(); a++) {
        listeners[a]->actionPerformed(newEvent);
    }
    delete newEvent;
//    toTransfer = NULL;
    processed = true;
}
