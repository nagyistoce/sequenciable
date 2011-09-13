#include "cxcore.h" 
#include "cv.h"
#include "highgui.h"
#include <stdio.h>
#include <iostream>

using namespace std;
/**
  * Extern code.
  */
void crop(IplImage *source_image, IplImage *destiny_image, int row_start, int column_start, int width, int height)
{
	int internal_row = 0;
	int internal_column = 0;
	CvScalar source;
	for(int i = row_start; i < height ;i++)
	{
		for(int j = column_start; j < width;j++)
		{
			source = cvGet2D(source_image,i,j);
			cvSet2D(destiny_image,internal_row,internal_column,source);
			//extenal control variable needs explicity boundary handling
			if (j < width + column_start - 1 )
				internal_column++;
		}
		internal_column = 0;
		if (i < height + row_start - 1 )
			internal_row++;
	}
}
// Rearrange the quadrants of Fourier image so that the origin is at
// the image center
// src & dst arrays of equal size & type
void cvShiftDFT(CvArr * src_arr, CvArr * dst_arr )
{
    CvMat * tmp;
    CvMat q1stub, q2stub;
    CvMat q3stub, q4stub;
    CvMat d1stub, d2stub;
    CvMat d3stub, d4stub;
    
    CvSize size = cvGetSize(src_arr);
    CvSize dst_size = cvGetSize(dst_arr);
    int cx, cy;

    if(dst_size.width != size.width || dst_size.height != size.height){
        cvError( CV_StsUnmatchedSizes, "cvShiftDFT", "Source and Destination arrays must have equal sizes", __FILE__, __LINE__ );
    }

    if(src_arr==dst_arr)
	{
        tmp = cvCreateMat(size.height/2, size.width/2, cvGetElemType(src_arr));
    }
    
    cx = size.width/2;
    cy = size.height/2; // image center

	cvGetSubRect( src_arr, &q1stub, cvRect(0,0,cx, cy) );
    cvGetSubRect( src_arr, &q2stub, cvRect(cx,0,cx,cy) );
    cvGetSubRect( src_arr, &q3stub, cvRect(cx,cy,cx,cy) );
    cvGetSubRect( src_arr, &q4stub, cvRect(0,cy,cx,cy) );
    cvGetSubRect( src_arr, &d1stub, cvRect(0,0,cx,cy) );
    cvGetSubRect( src_arr, &d2stub, cvRect(cx,0,cx,cy) );
    cvGetSubRect( src_arr, &d3stub, cvRect(cx,cy,cx,cy) );
    cvGetSubRect( src_arr, &d4stub, cvRect(0,cy,cx,cy) );

    if(src_arr!=dst_arr){
        cvCopy(&q3stub, &d1stub, 0);
        cvCopy(&q4stub, &d2stub, 0);
        cvCopy(&q1stub, &d3stub, 0);
        cvCopy(&q2stub, &d4stub, 0);
    }
    else{
        cvCopy(&q3stub, tmp, 0);
        cvCopy(&q1stub, &q3stub, 0);
        cvCopy(tmp, &q1stub, 0);
        cvCopy(&q4stub, tmp, 0);
        cvCopy(&q2stub, &q4stub, 0);
        cvCopy(tmp, &q2stub, 0);
    }

	cvReleaseMat(&tmp);
}

IplImage* homomorphic_filter(IplImage* source, int filter_order, int cut_frequency, int gain, int filter_type) {
	
	//filter_type low pass < 0
	IplImage * realInput = NULL;
	IplImage * inverseFourier = NULL;
    IplImage * imaginaryInput = NULL;
    IplImage * complexInput = NULL;
	IplImage * filtered = NULL;
	IplImage * filteredMagnitudeReal = NULL;
	IplImage * filteredMagnitudeImaginary = NULL;
    IplImage * image_Real = NULL;
    IplImage * image_Imaginary = NULL;
	IplImage * temp = NULL;
    CvMat* dft_A = NULL;
	//CvMat* tmp = NULL;
    CvMat tmp;
	CvMat* mask = NULL;
    CvScalar scalar;
    int i, j = 0;
	int dft_M = 0, dft_N = 0;	
	double exponencial;
	double imag_part;
	double real_part;
	double m = 0.0, M = 0.0;
	double dxy;
	double H;

	IplImage* destination = cvCreateImage( cvGetSize(source), IPL_DEPTH_8U, 1);
	realInput = cvCreateImage( cvGetSize(source), IPL_DEPTH_64F, 1);
    imaginaryInput = cvCreateImage( cvGetSize(source), IPL_DEPTH_64F, 1);
    complexInput = cvCreateImage( cvGetSize(source), IPL_DEPTH_64F, 2);
	temp = cvCreateImage( cvGetSize(source), IPL_DEPTH_64F, 1);
	cvScale(source, realInput, 1.0, 0.0);
   
	//Take the log of the realInput image
	//cvAddS( complexInput, cvScalarAll(1.0), complexInput, NULL );
	//cvLog( complexInput, complexInput );
	
	for(i = 0; i < realInput->height; i++)
	{
		for(j = 0; j < realInput->width; j++)
		{
			scalar = cvGet2D(realInput,i,j); 
			scalar.val[0] = log( (double)scalar.val[0]+1.0); 
			cvSet2D(realInput, i, j, scalar);
		}
	}
    cvZero(imaginaryInput);
	
	cvMerge(realInput, imaginaryInput, NULL, NULL, complexInput);
	cvReleaseImage(&realInput);
	cvReleaseImage(&imaginaryInput);

	//Lines bellow causes desallocation error
    //dft_M = cvGetOptimalDFTSize( source->height - 1 );
    //dft_N = cvGetOptimalDFTSize( source->width - 1 );
	dft_M = cvGetOptimalDFTSize(source->height);
	dft_N = cvGetOptimalDFTSize(source->width);

    dft_A = cvCreateMat( dft_M, dft_N, CV_64FC2 );
	//tmp = cvCreateMat( dft_M, dft_N, CV_64FC2 );

    image_Real = cvCreateImage( cvSize(dft_N, dft_M), IPL_DEPTH_64F, 1);
    image_Imaginary = cvCreateImage( cvSize(dft_N, dft_M), IPL_DEPTH_64F, 1);
	inverseFourier = cvCreateImage( cvSize(dft_N, dft_M), IPL_DEPTH_64F, 2);
	filtered = cvCreateImage( cvSize(dft_N, dft_M), IPL_DEPTH_64F, 1);
	filteredMagnitudeReal = cvCreateImage( cvSize(dft_N, dft_M), IPL_DEPTH_64F, 1);
	filteredMagnitudeImaginary = cvCreateImage( cvSize(dft_N, dft_M), IPL_DEPTH_64F, 1);

	// copy A to dft_A and pad dft_A with zeros
    cvGetSubRect( dft_A, &tmp, cvRect(0,0, source->width, source->height));
    cvCopy( complexInput, &tmp, NULL );
    
	if( dft_A->cols > source->width ) {
        cvGetSubRect( dft_A, &tmp, cvRect(source->width,0, dft_A->cols - source->width, source->height));
        cvZero( &tmp );
    }
	//cvReleaseMat(&tmp);

    // no need to pad bottom part of dft_A with zeros because of
    // use nonzero_rows parameter in cvDFT() call below
    cvDFT( dft_A, dft_A, CV_DXT_FORWARD, complexInput->height );
	cvReleaseImage(&complexInput);
	
	//Butterworth filter
    //fc = cut frequency
    //n filter order
    //type: if tipo <0, low pass, if >=0 high pass
	mask = cvCreateMat( dft_M, dft_N, CV_64FC1 );
	
	double Xmin = -dft_M/2.0;
    double Ymin = -dft_N/2.0;

	//make filter matrix (mask) http://en.wikipedia.org/wiki/Butterworth_filter
	for(i=0; i<dft_M; i++)
		for(j=0; j<dft_N; j++)
        {
			dxy = sqrt(pow(Xmin+i,2)+pow(Ymin+j,2));
            if(filter_type < 0) //low pass
            {
				H = (gain/(1 + pow(dxy/cut_frequency,2*filter_order)));
			}
            if(filter_type >= 0)
            {
				if(dxy==0)
				{
					H=0;
				}
				else 
					H = (gain/(1 + pow(cut_frequency/dxy,2*filter_order)));//high pass
             }
			cvSetReal2D(mask, i, j, H);
          } 
	
	//Split Fourier in real and imaginary parts
    cvSplit( dft_A, image_Real, image_Imaginary, 0, 0 );
	cvReleaseMat(&dft_A);
	
	//copy to show applied filter
	cvCopy(image_Real, filteredMagnitudeReal, NULL);
	cvCopy(image_Imaginary, filteredMagnitudeImaginary, NULL);
	cvShiftDFT(filteredMagnitudeReal,filteredMagnitudeReal);
	cvShiftDFT(filteredMagnitudeImaginary,filteredMagnitudeImaginary);
	cvMul(filteredMagnitudeReal, mask, filteredMagnitudeReal, 1.0);
	cvMul(filteredMagnitudeImaginary, mask, filteredMagnitudeImaginary, 1.0);

	//apply filter
	//Comment out by frango
	//cvShiftDFT(image_Real,image_Real);
	//cvShiftDFT(image_Imaginary,image_Imaginary);
	cvMul(image_Real, mask, image_Real, 1.0);
	cvMul(image_Imaginary, mask, image_Imaginary, 1.0);
	cvReleaseMat(&mask);

	//Merge to invert
	cvMerge(image_Real, image_Imaginary, NULL, NULL, inverseFourier);
	
	//inverse
	cvDFT( inverseFourier, inverseFourier, CV_DXT_INV_SCALE, inverseFourier->height );

	//exponentiate
	for (i=0; i<inverseFourier->height; i++)
	{
		for (j=0; j<inverseFourier->width; j++)
		{
			scalar = cvGet2D(inverseFourier,i,j); 
			real_part = scalar.val[0];
			imag_part = scalar.val[1];
			exponencial = sqrt(real_part*real_part + imag_part*imag_part);
			scalar.val[0] = exp((double)exponencial) - 1.0;
			cvSet2D(inverseFourier, i, j, scalar); 
		}
	}
	
	//prepare for show
	cvSplit(inverseFourier, image_Real, image_Imaginary , NULL, NULL); 	
	cvReleaseImage(&inverseFourier);

    // Compute the magnitude of the spectrum Mag = sqrt(Re^2 + Im^2)
    cvPow( image_Real, image_Real, 2.0);
    cvPow( image_Imaginary, image_Imaginary, 2.0);
    cvAdd( image_Real, image_Imaginary, filtered, NULL);
    cvPow( filtered, filtered, 0.5 );
	cvReleaseImage(&image_Real);
	cvReleaseImage(&image_Imaginary);

    // Compute log(1 + Mag)
	cvAddS( filtered, cvScalarAll(1.0), filtered, NULL ); // 1 + Mag
	//cvLog( filtered, filtered ); // log(1 + Mag)

    //Rearrange the quadrants of Fourier image so that the origin is at the image center
    //cvShiftDFT( filtered, filtered );

    cvMinMaxLoc(filtered, &m, &M, NULL, NULL, NULL);
    cvScale(filtered, filtered, 1.0/(M-m), 1.0*(-m)/(M-m));
	
	//prepare for show filteredMagnitude
    // Compute the magnitude of the spectrum Mag = sqrt(Re^2 + Im^2)
    cvPow( filteredMagnitudeReal, filteredMagnitudeReal, 2.0);
    cvPow( filteredMagnitudeImaginary, filteredMagnitudeImaginary, 2.0);
    cvAdd( filteredMagnitudeReal, filteredMagnitudeImaginary, filteredMagnitudeReal, NULL);
    cvPow( filteredMagnitudeReal, filteredMagnitudeReal, 0.5 );
	cvReleaseImage(&filteredMagnitudeImaginary);

    // Compute log(1 + Mag)
	cvAddS( filteredMagnitudeReal, cvScalarAll(1.0), filteredMagnitudeReal, NULL ); // 1 + Mag
	cvLog( filteredMagnitudeReal, filteredMagnitudeReal ); // log(1 + Mag)

    cvMinMaxLoc(filteredMagnitudeReal, &m, &M, NULL, NULL, NULL);
    cvScale(filteredMagnitudeReal, filteredMagnitudeReal, 1.0/(M-m), 1.0*(-m)/(M-m));
	cvReleaseImage(&filteredMagnitudeReal);

	//if (filtered->height > source->height || filtered->width > source->width)
	crop(filtered, temp, 0, 0, source->width, source->height);
	cvReleaseImage(&filtered);

	for(i = 0; i < temp->height ;i++)
	{
		for(j = 0; j < temp->width ;j++)
		{
			scalar = cvGet2D(temp,i,j);
			scalar.val[0] = scalar.val[0]*255.0;
			cvSet2D(destination,i,j,scalar);
		}
	}
	cvReleaseImage(&temp);

	return destination;
}
