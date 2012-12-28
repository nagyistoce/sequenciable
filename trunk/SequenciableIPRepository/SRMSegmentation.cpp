/* 
 * File:   SRMSegmentation.cpp
 * Author: claudio
 * 
 * Created on December 27, 2012, 3:54 PM
 */

#include <opencv2/highgui/highgui_c.h>
#include <opencv2/highgui/highgui.hpp>

#include "SRMSegmentation.h"
#include "IplEvent.h"

SRMSegmentation::SRMSegmentation() {
//     sigmaS = _sigmaS;
//    sigmaR = _sigmaR;
//    minRegions = _minRegions;
//    msp = new MSPerformer(sigmaS,sigmaR,minRegions);
//    processed = false;
    inputCompatibility.push_back(new RGBListener());
//    type = NULL;

    SEQUENCIABLE_ID = 11;
    //textualDescription = "MeanShift";
    std::stringstream fullDescriptor;
    fullDescriptor << "SRM(" << ")";
    textualDescription = fullDescriptor.str();
//     //Sigma S
//    variablesTypesAndRanges.addTypesAndRanges(1, 1, 20);
//     //Sigma R
//    variablesTypesAndRanges.addTypesAndRanges(0, 1, 20);
//     //min Regions
//    variablesTypesAndRanges.addTypesAndRanges(1, 1, 40);
}

SRMSegmentation::SRMSegmentation(const SRMSegmentation& orig) {
}

SRMSegmentation::~SRMSegmentation() {
}

Sequenciable* SRMSegmentation::getClone(){
    return new SRMSegmentation();
}

void SRMSegmentation::actionPerformed(Event* e){
    IplEvent* ie = (IplEvent*)e;
    
    cv::Mat input = cv::cvarrToMat(ie->getEventIplImage(),true);
    std::string testFilename = "test.tif";
    std::string testOutputFilename = "testOutput.tif";
//    cv::cvtColor(input,input,CV_RG);
    cv::imwrite(testFilename,input);
    
    std::string command = "./srm -S 2 -B 2 -s ";
    command.append(testFilename);
    command.append(" ");
    command.append(testOutputFilename);
    system(command.c_str());
    cv::Mat output = cv::imread(testOutputFilename.c_str());
    IplImage s = output;
    IplEvent* new_event = new IplEvent(&s);
    for(int a=0;a<listeners.size();a++){
        listeners[a]->actionPerformed(new_event);
    }
    delete new_event;
}