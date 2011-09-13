/*
 * HSVColor.cpp
 *
 *  Created on: Mar 11, 2011
 *      Author: claudio
 */

#include "HSVColor.h"

HSVColor::HSVColor(int _h,int _s,int _v) {
	h = _h;
	s = _s;
	v = _v;
}
HSVColor::HSVColor(const HSVColor &clone) {
	h = clone.getH();
	s = clone.getS();
	v = clone.getV();
}

HSVColor::~HSVColor() {
}

bool HSVColor::operator < (const HSVColor& color2) const{
	//return (*this).getH() < hsv2.getH();
	if((*this).getH() < color2.getH()){
		return true;
	}else {
		if((*this).getH() == color2.getH()){
			if((*this).getS() < color2.getS()){
					return true;
			}else{
				if((*this).getS() == color2.getS()){
					if((*this).getV() < color2.getV()){
						return true;
					}else{
						return false;
					}
				}else{
					return false;
				}
			}
		} else {
			return false;
		}
	}
}
bool HSVColor::operator==(const HSVColor &hsv2) const{
	if(this->getH()==hsv2.getH()&&this->getS()==hsv2.getS()&&this->getV()==hsv2.getV())
		return true;
	else
		return false;
}
double HSVColor::compSmith(HSVColor color1, HSVColor color2){
	double returnValue = 0;
	double hue1 = color1.getH();
	hue1*=3.14159265;
	hue1/=90.;
	double hue2 = color2.getH();
	hue2*=3.14159265;
	hue2/=90.;
	//returnValue = 1.-(1./sqrt(5))*sqrt( pow( (color1.getV()/255.)-(color2.getV()/255.), 2 ) +
	//Retirei o 1- , pois, caso contrário, cores próximas terão valores altos. (08/04/2011)
	returnValue = (1./sqrt(5))*sqrt( pow( (color1.getV()/255.)-(color2.getV()/255.), 2 ) +
			pow( (color1.getS()/255.)*cos(hue1) - (color2.getS()/255.)*cos(hue2) ,2  ) +
			pow( (color1.getS()/255.)*sin(hue1) - (color2.getS()/255.)*sin(hue2), 2  ) );
	return returnValue;
}
double HSVColor::compCavalcanti2(HSVColor color1, HSVColor color2){
	//Modified Cavalcanti Method (DEFAULT)
	double returnValue = 0;
	double diffH=0,diffS=0,diffV=0;
	if (color1.getV() < 30 && color2.getV() < 30) {
		diffV = 0;//abs((*this).getV() - color2.getV())/255;
	} else 	if ((color1.getS() < 30 && color2.getS() < 30) && abs(color1.getV() - color2.getV()) < 50) {
		//		returnValue = 0;
		//			diffS = abs((*this).getS() - color2.getS())/255.;
		diffV = abs(color1.getV() - color2.getV())/255.;

	} else 	if ( (abs(color1.getH() - color2.getH()) < 10 || abs(color1.getH() - color2.getH()) > 170) && (abs(color1.getS() - color2.getS()) < 20) && (abs(color1.getV() - color2.getV()) < 30) ) {
		diffS = abs(color1.getS() - color2.getS())/255.;
		diffV = abs(color1.getV() - color2.getV())/255.;
	} else {
		diffH = abs(color1.getH() - color2.getH());
		if(diffH<90){
			diffH/=90;
		}else{
			diffH=180-diffH;
			diffH/=90;
		}
		diffS = abs(color1.getS() - color2.getS())/255.;
		diffV = abs(color1.getV() - color2.getV())/255.;

	}
	diffH/=3;
	diffS/=3;
	diffV/=3;
	returnValue = (0.6*diffH + 0.2*diffS + 0.2*diffV);
	if(returnValue > 1){
		return 1;
	}else{
		return returnValue;
	}
}
double HSVColor::operator-(const HSVColor &color2) const{
	double returnValue = 0;
	//TODO: Evitar comparações dentro da função diferença.
//	if(diffMethodUsed == SMITH_DIFFERENCE){

		//Smith Method
		//Divide by 90 due to OpenCV Hue mapping to 0-180;
//		double hue1 = (*this).getH();
//		hue1*=3.14159265;
//		hue1/=90.;
//		double hue2 = color2.getH();
//		hue2*=3.14159265;
//		hue2/=90.;
//		returnValue = 1.-(1./sqrt(5))*sqrt( pow( ((*this).getV()/255.)-(color2.getV()/255.), 2 ) +
//				pow( ((*this).getS()/255.)*cos(hue1) - (color2.getS()/255.)*cos(hue2) ,2  ) +
//				pow( ((*this).getS()/255.)*sin(hue1) - (color2.getS()/255.)*sin(hue2), 2  ) );
//		return returnValue;
//	}
//	}else if(diffMethodUsed == CAVALCANTI_DIFFERENCE){
		//Original Cavalcanti Method
		double diffH=0,diffS=0,diffV=0;
		if ((*this).getV() < 30 && color2.getV() < 30) {
			diffV = 0;
		} else 	if (((*this).getS() < 30 && color2.getS() < 30) && abs((*this).getV() - color2.getV()) < 30) {
			diffV = 0;
		} else 	if ( (abs((*this).getH() - color2.getH()) < 10 || abs((*this).getH() - color2.getH()) > 170) && (abs((*this).getS() - color2.getS()) < 20) && (abs((*this).getV() - color2.getV()) < 30) ) {
			diffS = 0;
			diffV = 0;
		} else {
			diffH = abs((*this).getH() - color2.getH());
			if(diffH<90){
				diffH/=90;
			}else{
				diffH=180-diffH;
				diffH/=90;
			}
			diffS = abs((*this).getS() - color2.getS())/255.;
			diffV = abs((*this).getV() - color2.getV())/255.;

		}
		diffH/=3;
		diffS/=3;
		diffV/=3;
		returnValue = (0.6*diffH + 0.2*diffS + 0.2*diffV);
		if(returnValue > 1){
			return 1;
		}else{
			return returnValue;
		}
//	}else{

//	}
}
double HSVColor::compareHSVColors(HSVColor* color1,HSVColor *color2){
	double returnValue = 0;


	if (color1->getV() < 30 && color2->getV() < 30) {
		returnValue = 0;
	} else 	if ((color1->getS() < 30 && color2->getS() < 30) && abs(color1->getV() - color2->getV()) < 25) {
		returnValue = 0;
	} else 	if ( (abs(color1->getH() - color2->getH()) < 10 || abs(color1->getH() - color2->getH()) > 170) && (abs(color1->getS() - color2->getS()) < 40) && (abs(color1->getV() - color2->getV()) < 127) ) {
		returnValue = 0;
	} else {
		double diffH = abs(color1->getH() - color2->getH());
		if(diffH<90){
			diffH/=90;
		}else{
			diffH=180-diffH;
			diffH/=90;
		}
		double diffS = abs(color1->getS() - color2->getS())/255.;
		double diffV = abs(color1->getV() - color2->getV())/255.;
		diffH/=3;
		diffS/=3;
		diffV/=3;
		returnValue = (0.6*diffH + 0.2*diffS + 0.2*diffV);

	}
	if(returnValue > 1){
		return 1;
	}else{
		return returnValue;
	}
}
IplImage *HSVColor::getHSVFromBGRIplImage(IplImage *inputBGR){
	IplImage* dstHSV = cvCreateImage(cvGetSize(inputBGR),inputBGR->depth,inputBGR->nChannels);
	cvZero(dstHSV);
	cvCvtColor(inputBGR,dstHSV,CV_BGR2HSV);
	return dstHSV;
}
vector<HSVColor> HSVColor::getVectorOfHSVfromHSVIplImage(IplImage *srcHSV, int type){

	vector<HSVColor> cores;
	int width = srcHSV->width;
	int height = srcHSV->height;
	int h,s,v;

	if(type==0){
		for ( int i = 0; i < height; i++)
		{
			for ( int j = 0; j < width; j++)
			{
				CvScalar hsvValue = cvGet2D(srcHSV,i,j);
				h = (int)hsvValue.val[0];
				s = (int)hsvValue.val[1];
				v = (int)hsvValue.val[2];
				HSVColor cor(h,s,v);
				cores.push_back(cor);
			}
		}
	}
	else if(type == HSV_EXCLUDE_GRAYS){
		for ( int i = 0; i < height; i++)
		{
			for ( int j = 0; j < width; j++)
			{
				CvScalar hsvValue = cvGet2D(srcHSV,i,j);
				h = (int)hsvValue.val[0];
				s = (int)hsvValue.val[1];
				v = (int)hsvValue.val[2];
				if(( s/255. > 1-(0.8*v/255.) ) || (s/255.0 > 0.2 && v/255.0 > 0.2) ){
					//Method described in Zhang, Gao, Gao, Liu's Combining Color Quantization ...
					HSVColor cor(h,s,v);
					cores.push_back(cor);
				}
			}
		}
	}else if(type == HSV_EXCLUDE_GRAYS_CAVALCANTI){
		for ( int i = 0; i < height; i++)
		{
			for ( int j = 0; j < width; j++)
			{
				CvScalar hsvValue = cvGet2D(srcHSV,i,j);
				h = (int)hsvValue.val[0];
				s = (int)hsvValue.val[1];
				v = (int)hsvValue.val[2];
				if (v < 30) {
					continue;
				} else 	if (s < 30 && v < 60) {
							continue;
				} else {
					//Method invented ...
					HSVColor cor(h,s,v);
					cores.push_back(cor);
				}
			}
		}
	}
	return cores;
}
IplImage* HSVColor::applyClustersToIplHSV(IplImage *srcHSV, vector<HSVColor> centroids, double (*comp)(HSVColor,HSVColor)){
	int width = srcHSV->width;
	int height = srcHSV->height;
	int h,s,v;
	IplImage* outputShiftedImage = cvCreateImage(cvSize(width,height),srcHSV->depth,3);
	for ( int i = 0; i < height; i++)
	{
		for ( int j = 0; j < width; j++)
		{
			CvScalar hsvValue = cvGet2D(srcHSV,i,j);
			h = (int)hsvValue.val[0];
			s = (int)hsvValue.val[1];
			v = (int)hsvValue.val[2];
			HSVColor cor(h,s,v);
			HSVColor closest(min(centroids,cor,(*comp)));
			cvSet2D(outputShiftedImage,i,j,cvScalar(closest.getH(),closest.getS(),closest.getV()));
		}
	}
	cvCvtColor(outputShiftedImage,outputShiftedImage,CV_HSV2BGR);
	//cvSaveImage(filename.c_str(),outputShiftedImage);
	return outputShiftedImage;
}
bool HSVColor::sortColorsHSVbyH(HSVColor* color1, HSVColor* color2){
	if(color1->getH() < color2->getH()){
		return true;
	}else {
		if(color1->getH() == color2->getH()){
			if(color1->getS() < color2->getS()){
					return true;
			}else{
				if(color1->getS() == color2->getS()){
					if(color1->getV() < color2->getV()){
						return true;
					}else{
						return false;
					}
				}else{
					return false;
				}
			}
		} else {
			return false;
		}
	}
}
HSVColor HSVColor::min(vector<HSVColor>& color1, HSVColor& color2,double (*comp)(HSVColor,HSVColor)){
	vector<HSVColor>::iterator vecIt = color1.begin();
	int smallesDifferencetIndice = 0;
	double closestDifference = 1;
	int indice = 0;
	if(comp==NULL){
		while(vecIt!=color1.end()){
			double difference = abs(color1[indice]-color2);
			if(difference<closestDifference){
				closestDifference = difference;
				smallesDifferencetIndice = indice;
			}
			indice++;
			vecIt++;
		}
	}else{
		while(vecIt!=color1.end()){
			double difference = abs((*comp)(color1[indice],color2));
			if(difference<closestDifference){
				closestDifference = difference;
				smallesDifferencetIndice = indice;
			}
			indice++;
			vecIt++;
		}
	}
	return color1[smallesDifferencetIndice];

}
