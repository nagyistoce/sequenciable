/* 
 * File:   Sequence.h
 * Author: claudio
 *
 * Created on May 8, 2012, 9:17 AM
 */

#ifndef SEQUENCE_H
#define	SEQUENCE_H
#include <stdio.h>
#include "Sequenciable.h"
#include "NoOutputReachableException.h"
#include "SequenciableOutOfRangeException.h"
#include <vector>
#include <typeinfo>

using namespace std;

class Sequence {
public:
    Sequence();
    Sequence(vector<Sequenciable*> seq);
    Sequence(Sequence* seq);
    virtual ~Sequence();
    bool addToSequence(Sequenciable* );
    vector<Sequenciable*> findPossibilities(vector<Sequenciable*> availableOptions);
    bool reachesOutput();
//    static bool equalTo(Sequence *comparingFrom, Sequence *comparingTo);
    bool equalToSequence(Sequence *comparingTo);
    void setOutputer(Sequenciable *outp);
    void setInputer(Sequenciable *inpt);
    void startPipeline(Event* t);
    void startPipeline(Event* t,Sequenciable *outp);
    int getSize();
    
    Sequenciable *getSequenciableAt(int at);
    
    //Getters and Setters
//    vector<Sequenciable*> getSequence();
    void setOutputType(Type* outputType);
    Type* getOutputType() const;
    void setInputType(Type* inputType);
    Type* getInputType() const;
    
private:
    vector<Sequenciable*> definedSequence;
    Sequenciable *lastOne;
    Type *inputType,*outputType;
    Sequenciable *outputer;
};

#endif	/* SEQUENCE_H */

