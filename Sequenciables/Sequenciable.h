/* 
 * File:   Sequenciable.h
 * Author: Claudio
 *
 * Created on July 26, 2011, 4:14 PM
 */

#ifndef SEQUENCIABLE_H
#define	SEQUENCIABLE_H

#include "Event.h"
#include <vector>
#include "Type.h"
#include <string>
#include "LocalVariablesTypes.h"
class Sequenciable {
public:
    Sequenciable();
//    Sequenciable(Sequenciable* orig);
    virtual ~Sequenciable();

    std::vector<Type*> getInputRequirements(){
        return inputCompatibility;
    };
    virtual Type* getType()=0;
    virtual bool verifyInputCompatibility(Type *lis)=0;
    virtual bool verifyOutputCompatibility(Type *lis)=0;
    virtual bool addSequenciableListener(Sequenciable *lis)=0;
    virtual bool removeSequenciableListener(Sequenciable *lis);
    virtual void actionPerformed(Event *e)=0;
    virtual Sequenciable* getClone()=0;
    virtual void clearListeners(){
        listeners.clear();
    }
    LocalVariablesTypes getVariblesTypesAndRanges(){return variablesTypesAndRanges;}
    std::string getTextualDescription(){return textualDescription;}
    int getUniqueID(){return SEQUENCIABLE_ID;}
protected:
    std::vector<Sequenciable*> listeners;
    std::vector<Type*> inputCompatibility;
    Type *type;
    std::string textualDescription;
    int SEQUENCIABLE_ID;
    LocalVariablesTypes variablesTypesAndRanges;
};

#endif	/* SEQUENCIABLE_H */

