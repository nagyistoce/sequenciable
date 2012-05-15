/* 
 * File:   Sequence.h
 * Author: claudio
 *
 * Created on May 8, 2012, 9:17 AM
 */

#ifndef SEQUENCE_H
#define	SEQUENCE_H
#include "Sequenciable.h"
#include "NoOutputReachableException.h"
#include <vector>
#include <typeinfo>

using namespace std;

class Sequence {
public:
    Sequence();
    Sequence(vector<Sequenciable*> seq);
    virtual ~Sequence();
    bool addToSequence(Sequenciable* );
    vector<Sequenciable*> findPossibilities(vector<Sequenciable*> availableOptions);
    bool reachesOutput();
    static bool equalTo(Sequence *comparingFrom, Sequence *comparingTo);
    void setOutputer(Sequenciable *outp);
    void startPipeline(Event* t);
    
    //Getters and Setters
    vector<Sequenciable*> getSequence();
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

