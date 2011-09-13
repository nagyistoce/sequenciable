/*
 * HSVColorClusterEstimation.cpp
 *
 *  Created on: Jul 7, 2011
 *      Author: claudio
 */

#include "HSVColorClusterEstimation.h"

HSVColorClusterEstimation::HSVColorClusterEstimation(int neighbor) {
	// TODO Auto-generated constructor stub
	neighborhoodEstimation = neighbor;
}

HSVColorClusterEstimation::~HSVColorClusterEstimation() {
	// TODO Auto-generated destructor stub
}
vector<HSVColor> HSVColorClusterEstimation::estimateClustersForHSV(vector<HSVColor> cores,int neighboorhood){
	//Estimating clusters based on HSV Histogram
	int hueHistogram[180];
	for(int m=0;m<=180;m++)
		hueHistogram[m] = 0;
	vector<HSVColor>::iterator coresIt = cores.begin();
	while(coresIt!=cores.end()){
		hueHistogram[(*coresIt).getH()]++;
		coresIt++;
	}
	/*ofstream hhist("hueHist.txt");
	for(int m=0;m<180;m++)
		hhist << hueHistogram[m] << endl;
	hhist.close();
*/
	vector<HSVColor> zeroes;
	//cout << endl;
	//int neighboorhood = 5;
	for(int m=0;m<=180;m++){
		double val1 = (double)hueHistogram[m];
		int greaterBefore=0;
		int lessBefore=0;
		int greaterAfter=0;
		int lessAfter=0;
		double val2;
		//Search last n bins and next 5 bins and check for how many the present bin is greater and smaller than
		for(int n=-neighboorhood;n<0;n++){
			if(m+n < 0)
				val2 = hueHistogram[181+n];
			else
				val2 = hueHistogram[m+n];
			//TODO: Decidir se basta ser maior ou se admitir-se-á alguma tolerância
			if(val1 > val2){
				lessBefore++;
			}else{
				greaterBefore++;
			}
		}
		for(int n=1;n<neighboorhood+1;n++){
			if(m+n > 180)
				val2 = hueHistogram[n];
			else
				val2 = hueHistogram[m+n];
			if(val1 > val2){
				lessAfter++;
			}else{
				greaterAfter++;
			}

		}
		//TODO: Decidir 1) se precisa ser um pico "absoluto" e 2) em que vizinhança
		//Check if this "superiority" is enough for being a cluster
		if(lessBefore >=neighboorhood && lessAfter >= neighboorhood){
			zeroes.push_back(HSVColor(m,255,255));
			//cout << m << ",";
		}
	}

	//Adding White
	zeroes.push_back(HSVColor(0,0,255));
	//Adding Grey
	zeroes.push_back(HSVColor(0,0,127));
	//Adding Black
	zeroes.push_back(HSVColor(0,0,0));

	//cout << zeroes.size();
	return zeroes;
}
void HSVColorClusterEstimation::processingCore(){

	/////  CLUSTER IDENTIFICATION...
	//vector<HSVColor> *zeroes = NULL;
	//Estimating clusters based on HSV Histogram
	vector<HSVColor> value;
	cores = estimateClustersForHSV(input,neighborhoodEstimation);
	//cores = &value;
	//zeroes = &value;
}
void HSVColorClusterEstimation::actionPerformed(Event* ev){
                HSVVecEvent* e = (HSVVecEvent*)ev;
	//input = cvCloneImage(e->getEventIplImage());
	input = e->getEventHSVVec();
	//inputImageSet = true;
	//output = cvCreateImage(cvGetSize(input),input->depth,input->nChannels);
	processingCore();
	HSVVecEvent* newEvent = new HSVVecEvent(cores);
for (int a = 0; a < listeners.size(); a++) {
//        IplEvent *resultEvent = new IplEvent(output);
        listeners[a]->actionPerformed(newEvent);
  //      delete resultEvent;
    }	
        processed = true;
}
vector<HSVColor> HSVColorClusterEstimation::getOutputHSVColorVector( ){
	return cores;
}
