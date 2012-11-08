/* 
 * File:   LocalVariablesTypes.h
 * Author: claudio
 *
 * Created on October 30, 2012, 9:59 AM
 */

#ifndef LOCALVARIABLESTYPES_H
#define	LOCALVARIABLESTYPES_H
#include <vector>
using namespace std;
class typesAndRanges{
public:
    typesAndRanges(int t, double min, double max){
        typeID = t;
        minValue = min;
        maxValue = max;
    }
    ~typesAndRanges(){
        
    }
    int typeID;
    double minValue;
    double maxValue;
};

class LocalVariablesTypes{

public:
    LocalVariablesTypes(){}    
    ~LocalVariablesTypes(){
        if(values.size()>0)
                values.clear();
    }
    void addTypesAndRanges(int type, double min, double max){
        typesAndRanges newRange(type,min,max);
//        newRange.typeID = type;
//        newRange.minValue = min;
//        newRange.maxValue = max;
        values.push_back(newRange);
    }
    vector<typesAndRanges> getListOfTypesAndRanges(){
        return values;
    }
protected:
    int typeId;
    double minValue;
    double maxValue;
    vector<typesAndRanges> values;
};

#endif	/* LOCALVARIABLESTYPES_H */

