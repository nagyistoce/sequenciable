/*
 * HSVColor.h
 *
 *  Created on: Mar 11, 2011
 *      Author: claudio
 */

#ifndef HSVCOLOR_H_
#define HSVCOLOR_H_

#include <cstdlib>
#include <vector>
#include "cv.h"
#include "highgui.h"

using namespace std;
class HSVColor {
public:
	static const int HSV_EXCLUDE_GRAYS=1;
	static const int HSV_EXCLUDE_GRAYS_CAVALCANTI=2;
	enum diffMethod {SMITH_DIFFERENCE,CAVALCANTI_DIFFERENCE,CAVALCANTI_MOD_DIFFERENCE};
	HSVColor(int h,int s,int v);
	HSVColor(const HSVColor &);
	virtual ~HSVColor();
	bool operator < (const HSVColor& ) const;
	bool operator==( const HSVColor& ) const;
	double operator-(const HSVColor& ) const;
	static double compareHSVColors(HSVColor* color1,HSVColor *color2);
	static bool sortColorsHSVbyH(HSVColor* color1, HSVColor* color2);
	static HSVColor min(vector<HSVColor>& color1, HSVColor& color2,double (*comp)(HSVColor,HSVColor)=NULL);
	static vector<HSVColor> getVectorOfHSVfromHSVIplImage(IplImage *srcHSV, int type=0);
	static IplImage *getHSVFromBGRIplImage(IplImage *inputBGR);
	static IplImage *applyClustersToIplHSV(IplImage *srcHSV, vector<HSVColor> centroids, double (*comp)(HSVColor,HSVColor)=NULL);

	//Comparing methods
	static double compSmith(HSVColor color1,HSVColor color2);
	static double compCavalcanti2(HSVColor color1, HSVColor color2);

	void setDiffMethodToBeUsed(int newMethod){ diffMethodUsed = newMethod; }
    int getH() const
    {
        return h;
    }

    int getS() const
    {
        return s;
    }

    int getV() const
    {
        return v;
    }

    void setH(int h)
    {
        this->h = h;
    }

    void setS(int s)
    {
        this->s = s;
    }

    void setV(int v)
    {
        this->v = v;
    }

private:
	int h;
	int s;
	int v;
	int diffMethodUsed;
};

#endif /* HSVCOLOR_H_ */
