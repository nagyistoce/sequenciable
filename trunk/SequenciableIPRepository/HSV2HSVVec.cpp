/*
 * HSV2HSVVec.cpp
 *
 *  Created on: Jul 7, 2011
 *      Author: claudio
 */

#include <opencv/cxcore.h>

#include "HSV2HSVVec.h"
#include "RGBListener.h"

HSV2HSVVec::HSV2HSVVec(int _greyEclusion) {
    // TODO Auto-generated constructor stub
    greyExclusionType = _greyEclusion;
    input = NULL;
    inputCompatibility.push_back(new HSVListener());
}

HSV2HSVVec::~HSV2HSVVec() {
    // TODO Auto-generated destructor stub
    if (input!=NULL) {
        cvReleaseImage(&input);
    }
    inputCompatibility.clear();
}

void HSV2HSVVec::getVectorOfHSVfromHSVIplImage(IplImage *srcHSV, int type) {

    //vector<HSVColor> cores;
    cores.clear();
    int width = srcHSV->width;
    int height = srcHSV->height;
    unsigned int h, s, v;

    if (type == 0) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                CvScalar hsvValue = cvGet2D(srcHSV, i, j);
                
                h = (unsigned int)((uchar*)(srcHSV->imageData + srcHSV->widthStep*i))[j*3];//(int) hsvValue.val[0];
                s = (unsigned int)((uchar*)(srcHSV->imageData + srcHSV->widthStep*i))[j*3+1];
                v = (unsigned int)((uchar*)(srcHSV->imageData + srcHSV->widthStep*i))[j*3+2];
                /*
                h = (int) hsvValue.val[0];
                s = (int) hsvValue.val[1];
                v = (int) hsvValue.val[2];*/
                HSVColor cor(h, s, v);
                cores.push_back(cor);
            }
        }
    } else if (type == HSV_EXCLUDE_GRAYS) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                CvScalar hsvValue = cvGet2D(srcHSV, i, j);
                h = (int) hsvValue.val[0];
                s = (int) hsvValue.val[1];
                v = (int) hsvValue.val[2];
                if ((s / 255. > 1 - (0.8 * v / 255.)) || (s / 255.0 > 0.2 && v / 255.0 > 0.2)) {
                    //Method described in Zhang, Gao, Gao, Liu's Combining Color Quantization ...
                    HSVColor cor(h, s, v);
                    cores.push_back(cor);
                }
            }
        }
    } else if (type == HSV_EXCLUDE_GRAYS_CAVALCANTI) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                CvScalar hsvValue = cvGet2D(srcHSV, i, j);
                h = (int) hsvValue.val[0];
                s = (int) hsvValue.val[1];
                v = (int) hsvValue.val[2];
                if (v < 30) {
                    continue;
                } else if (s < 30 && v < 60) {
                    continue;
                } else {
                    //Method invented ...
                    HSVColor cor(h, s, v);
                    cores.push_back(cor);
                }
            }
        }
    }
    //return cores;
}
void HSV2HSVVec::processingCore() {
    
    
    //cores = getVectorOfHSVfromHSVIplImage(input, greyExclusionType);
    getVectorOfHSVfromHSVIplImage(input, greyExclusionType);
    if (cores.size() == 0) {
        cores.push_back(HSVColor(0, 0, 127));
    }
}

void HSV2HSVVec::actionPerformed(Event* ev) {
    IplEvent *e = (IplEvent*) ev;
    if(input!=NULL)
        cvReleaseImage(&input);
    input = cvCloneImage(e->getEventIplImage());
    //inputImageSet = true;
    //output = cvCreateImage(cvGetSize(input),input->depth,input->nChannels);
    //cvSaveImage("testeBug2.bmp",input);
    processingCore();
    //HSVVecEvent* newEvent = new HSVVecEvent(cores);
    //	notifyAll(newEvent);
    for (int a = 0; a < listeners.size(); a++) {
        //IplEvent *resultEvent = new IplEvent(output);
        HSVVecEvent* newEvent = new HSVVecEvent(cores);
        listeners[a]->actionPerformed(newEvent);
        //delete resultEvent;
        delete newEvent;
    }
    processed = true;
}

std::vector<HSVColor> HSV2HSVVec::getOutputHSVColorVector() {
    return cores;
}
