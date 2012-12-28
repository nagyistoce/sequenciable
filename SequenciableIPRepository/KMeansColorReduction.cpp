/* 
 * File:   KMeansColorReduction.cpp
 * Author: claudio
 * 
 * Created on December 28, 2012, 10:20 AM
 */

#include "KMeansColorReduction.h"

KMeansColorReduction::KMeansColorReduction(int _k) {
    k=_k;
    
    type = NULL;
    inputCompatibility.push_back(new IplListener());

    SEQUENCIABLE_ID = 12;

    stringstream fullDescriptor;
    fullDescriptor << "KMeansColorReduction(" << k << ")";
    textualDescription = fullDescriptor.str();

    //alpha beta
    variablesTypesAndRanges.addTypesAndRanges(1, 1, 20);
}

KMeansColorReduction::~KMeansColorReduction() {
    for(int a=0;a<inputCompatibility.size();a++){
        IplListener* r = (IplListener*)inputCompatibility[a];
        delete r;
    }
    inputCompatibility.clear();
    if(type!=NULL)
        delete type;
}

Sequenciable* KMeansColorReduction::getClone(){
    return new KMeansColorReduction(k);
}
void KMeansColorReduction::actionPerformed(Event* e){
    IplEvent *ie = (IplEvent*)e;
    cv::Mat src = cv::cvarrToMat(ie->getEventIplImage(),true);
    
    
 cv::Mat samples(src.rows * src.cols, 3, CV_32F);
  for( int y = 0; y < src.rows; y++ )
    for( int x = 0; x < src.cols; x++ )
      for( int z = 0; z < 3; z++)
        samples.at<float>(y + x*src.rows, z) = src.at<cv::Vec3b>(y,x)[z];


  int clusterCount = k;
  cv::Mat labels;
  int attempts = 5;
  cv::Mat centers;
  cv::kmeans(samples, clusterCount, labels, cv::TermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS, 0.0001, 10000), attempts, cv::KMEANS_PP_CENTERS, centers );


  cv::Mat output( src.size(), src.type() );
  for( int y = 0; y < src.rows; y++ )
    for( int x = 0; x < src.cols; x++ )
    { 
      int cluster_idx = labels.at<int>(y + x*src.rows,0);
      output.at<cv::Vec3b>(y,x)[0] = centers.at<float>(cluster_idx, 0);
      output.at<cv::Vec3b>(y,x)[1] = centers.at<float>(cluster_idx, 1);
      output.at<cv::Vec3b>(y,x)[2] = centers.at<float>(cluster_idx, 2);
    }
    
    
    
    IplImage s = output;
    IplEvent* new_event = new IplEvent(&s);
    for(int a=0;a<listeners.size();a++){
        listeners[a]->actionPerformed(new_event);
    }
    delete new_event;
}