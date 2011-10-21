/*
 * File:   newtestclass.cpp
 * Author: claudio
 *
 * Created on Sep 23, 2011, 1:56:01 PM
 */

#include <opencv/highgui.h>

#include "newtestclass.h"
#include "RGBtoHSVTransform.h"
#include <Sequenciable.h>
#include <RGBListener.h>
#include <opencv/cxcore.h>

CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass);

newtestclass::newtestclass() {
}

newtestclass::~newtestclass() {
}

void newtestclass::setUp() {
    redImage = cvCreateImage(cvSize(200,200), IPL_DEPTH_8U, 3);
    cvSet(redImage,cvScalar(0,0,255));
    cvSaveImage("tests/ThisTestImageMustBeAllRed.bmp",redImage);;
    
    greenImage = cvCreateImage(cvSize(200,200), IPL_DEPTH_8U, 3);
    cvSet(greenImage,cvScalar(0,255,0));
    cvSaveImage("tests/ThisTestImageMustBeAllGreen.bmp",greenImage);;
    
    blueImage = cvCreateImage(cvSize(200,200), IPL_DEPTH_8U, 3);
    cvSet(blueImage,cvScalar(255,0,0));
    cvSaveImage("tests/ThisTestImageMustBeAllBlue.bmp",blueImage);;
    
    yellowImage = cvCreateImage(cvSize(200,200), IPL_DEPTH_8U, 3);
    cvSet(yellowImage,cvScalar(0,255,255));
    cvSaveImage("tests/ThisTestImageMustBeAllYellow.bmp",yellowImage);;
    
    cianImage = cvCreateImage(cvSize(200,200), IPL_DEPTH_8U, 3);
    cvSet(cianImage,cvScalar(255,255,0));
    cvSaveImage("tests/ThisTestImageMustBeAllCyan.bmp",cianImage);;
    
    magentaImage = cvCreateImage(cvSize(200,200), IPL_DEPTH_8U, 3);
    cvSet(magentaImage,cvScalar(255,0,255));
    cvSaveImage("tests/ThisTestImageMustBeAllMagenta.bmp",magentaImage);;
    
    blackImage = cvCreateImage(cvSize(200,200), IPL_DEPTH_8U, 3);
    cvSet(blackImage,cvScalar(0,0,0));
    cvSaveImage("tests/ThisTestImageMustBeAllBlack.bmp",blackImage);;
    
    whiteImage = cvCreateImage(cvSize(200,200), IPL_DEPTH_8U, 3);
    cvSet(whiteImage,cvScalar(255,255,255));
    cvSaveImage("tests/ThisTestImageMustBeAllWhite.bmp",whiteImage);;
}

void newtestclass::tearDown() {
    cvReleaseImage(&redImage);
    cvReleaseImage(&blueImage);
    cvReleaseImage(&greenImage);
    cvReleaseImage(&yellowImage);
    cvReleaseImage(&cianImage);
    cvReleaseImage(&magentaImage);
    cvReleaseImage(&blackImage);
    cvReleaseImage(&whiteImage);
}
class OutputListener : public Sequenciable, public HSVListener{
public:
    virtual bool verifyOutputCompatibility(Sequenciable *lis){ return true;};
    virtual bool addSequenciableListener(Sequenciable *lis){return true;};
    virtual void actionPerformed(Event *e){
        IplEvent *ev = (IplEvent*)e;
        output = ev->getEventIplImage();
    };
    IplImage *getOutputImage(){
        return output;
    }
private:
    IplImage *output;
};
void newtestclass::testActionPerformed() {
    /* 
     * We want to check if all basic conversions are running well.
     */
    /////////////////////////////////////////////////// Green
    
    //Real Hue Value = 0 or 360; 
    RGBtoHSVTransform rGBtoHSVTransform;
    OutputListener output;
    IplImage *outputImage;
    IplEvent* e;
    CvScalar result;
    
    e = new IplEvent(redImage);
    
    rGBtoHSVTransform.addSequenciableListener(&output);
    rGBtoHSVTransform.actionPerformed(e);
    
    outputImage = output.getOutputImage();
    result = cvSum(outputImage);
    CPPUNIT_ASSERT(result.val[0]==0);
    CPPUNIT_ASSERT(result.val[1]==255*200*200);
    CPPUNIT_ASSERT(result.val[2]==255*200*200);
    cvSaveImage("tests/outputTest1ImageRed.bmp",outputImage);
    delete e;

    /////////////////////////////////////////////////// Green

    e = new IplEvent(greenImage);
    
    rGBtoHSVTransform.addSequenciableListener(&output);
    rGBtoHSVTransform.actionPerformed(e);
    
    outputImage = output.getOutputImage();
    result = cvSum(outputImage);
    //Real Hue Value = 120; 
    CPPUNIT_ASSERT(result.val[0]==60*200*200);
    CPPUNIT_ASSERT(result.val[1]==255*200*200);
    CPPUNIT_ASSERT(result.val[2]==255*200*200);
    cvSaveImage("tests/outputTest1ImageGreen.bmp",outputImage);
    delete e;

    /////////////////////////////////////////////////// Blue

    e = new IplEvent(blueImage);
    
    rGBtoHSVTransform.addSequenciableListener(&output);
    rGBtoHSVTransform.actionPerformed(e);
    
    outputImage = output.getOutputImage();
    result = cvSum(outputImage);
    //Real Hue Value = 240; 
    CPPUNIT_ASSERT(result.val[0]==120*200*200);
    CPPUNIT_ASSERT(result.val[1]==255*200*200);
    CPPUNIT_ASSERT(result.val[2]==255*200*200);
    cvSaveImage("tests/outputTest1ImageBlue.bmp",outputImage);
    delete e;

    /////////////////////////////////////////////////// Yellow

    e = new IplEvent(yellowImage);
    
    rGBtoHSVTransform.addSequenciableListener(&output);
    rGBtoHSVTransform.actionPerformed(e);
    
    outputImage = output.getOutputImage();
    result = cvSum(outputImage);
    //Real Hue Value = 60; 
    CPPUNIT_ASSERT(result.val[0]==30*200*200);
    CPPUNIT_ASSERT(result.val[1]==255*200*200);
    CPPUNIT_ASSERT(result.val[2]==255*200*200);
    cvSaveImage("tests/outputTest1ImageYellow.bmp",outputImage);
    delete e;
    
    /////////////////////////////////////////////////// Magenta

    e = new IplEvent(magentaImage);
    
    rGBtoHSVTransform.addSequenciableListener(&output);
    rGBtoHSVTransform.actionPerformed(e);
    
    outputImage = output.getOutputImage();
    result = cvSum(outputImage);
    //Real Hue Value = 300; 
    CPPUNIT_ASSERT(result.val[0]==150*200*200);
    CPPUNIT_ASSERT(result.val[1]==255*200*200);
    CPPUNIT_ASSERT(result.val[2]==255*200*200);
    cvSaveImage("tests/outputTest1ImageMagenta.bmp",outputImage);
    delete e;

    /////////////////////////////////////////////////// Cyan

    e = new IplEvent(cianImage);
    
    rGBtoHSVTransform.addSequenciableListener(&output);
    rGBtoHSVTransform.actionPerformed(e);
    
    outputImage = output.getOutputImage();
    result = cvSum(outputImage);
    //Real Hue Value = 180; 
    CPPUNIT_ASSERT(result.val[0]==90*200*200);
    CPPUNIT_ASSERT(result.val[1]==255*200*200);
    CPPUNIT_ASSERT(result.val[2]==255*200*200);
    cvSaveImage("tests/outputTest1ImageCyan.bmp",outputImage);
    delete e;

    /////////////////////////////////////////////////// Black

    e = new IplEvent(blackImage);
    
    rGBtoHSVTransform.addSequenciableListener(&output);
    rGBtoHSVTransform.actionPerformed(e);
    
    outputImage = output.getOutputImage();
    result = cvSum(outputImage);
    //Real Hue Value = 0; 
    CPPUNIT_ASSERT(result.val[0]==0);
    CPPUNIT_ASSERT(result.val[1]==0);
    CPPUNIT_ASSERT(result.val[2]==0);
    cvSaveImage("tests/outputTest1ImageBlack.bmp",outputImage);
    delete e;

    /////////////////////////////////////////////////// White

    e = new IplEvent(whiteImage);
    
    rGBtoHSVTransform.addSequenciableListener(&output);
    rGBtoHSVTransform.actionPerformed(e);
    
    outputImage = output.getOutputImage();
    result = cvSum(outputImage);
    //Real Hue Value = 0; 
    CPPUNIT_ASSERT(result.val[0]==0);
    CPPUNIT_ASSERT(result.val[1]==0);
    CPPUNIT_ASSERT(result.val[2]==255*200*200);
    cvSaveImage("tests/outputTest1ImageWhite.bmp",outputImage);
    delete e;

}

void newtestclass::test2(){
        ////////////////////TEST 2
    /*
     * We want to check out if the other side of the 
     * Hue circle also produces correct results...
     */
    RGBtoHSVTransform rGBtoHSVTransform;
    OutputListener output;
    IplImage *outputImage;
    IplEvent* e;
    CvScalar result;
    
    IplImage *Hue180 = cvCreateImage(cvSize(10,10),IPL_DEPTH_8U,3);
    cvSet(Hue180,cvScalar(179,255,255));
    IplImage *rgbConverted = cvCreateImage(cvSize(10,10),IPL_DEPTH_8U,3);
    cvCvtColor(Hue180,rgbConverted,CV_HSV2BGR);
    cvSaveImage("tests/Hue180.bmp",rgbConverted);
    

    
    IplImage *Hue255Image = cvCreateImage(cvSize(200,200), IPL_DEPTH_8U, 3);
    cvSet(Hue255Image,cvScalar(8,0,255));
    cvSaveImage("tests/ThisTestImageMustBe255-0-8.bmp",Hue255Image);
    e = new IplEvent(Hue255Image);
    
    //RGBtoHSVTransform rGBtoHSVTransform;
    //OutputListener output;
    rGBtoHSVTransform.addSequenciableListener(&output);
    rGBtoHSVTransform.actionPerformed(e);
    
    outputImage = output.getOutputImage();
    result = cvSum(outputImage);
    cvSaveImage("tests/outputTestImage2.bmp",outputImage);
    CPPUNIT_ASSERT(result.val[0]==255*200*200);
    CPPUNIT_ASSERT(result.val[1]==255*200*200);
    CPPUNIT_ASSERT(result.val[2]==255*200*200);

    delete e;
    cvReleaseImage(&Hue255Image);    
}

void newtestclass::test3(){
    
}

void newtestclass::test4(){
    
}

void newtestclass::test5(){
    
}

void newtestclass::test6(){
    
}

void newtestclass::test7(){
    
}

void newtestclass::test8(){
    
}
