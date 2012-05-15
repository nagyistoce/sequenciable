/* 
 * File:   Sequence.cpp
 * Author: claudio
 * 
 * Created on May 8, 2012, 9:17 AM
 */

#include "Sequence.h"
#include "IncompatibleClassesException.h"

Sequence::Sequence() {
    outputer = NULL;
}
Sequence::Sequence(vector<Sequenciable*> seq){
    outputer = NULL;
    vector<Sequenciable*> it;
    for(it = seq.begin();it < seq.end(); it++){
        addToSequence((*it));
    }
}
Sequence::~Sequence() {
}
bool Sequence::addToSequence(Sequenciable* nextInLine){
    vector<Type*> needed = nextInLine->getInputRequirements();
    //If there is only one requirement, it is now met and the sequence continues.
    if (needed.size() == 1) {
        definedSequence.push_back(nextInLine);
    } else {
        //More than one input. Meeting the requirements.
        vector<Type*>::iterator neededIt = needed.begin();
        //Verify from all methods, which are compatible with the chosen one.
        while (neededIt != needed.end()) {
            //Since it is already verified, choose one of the previous requirements.
            vector<Sequenciable*>::iterator eachOption = definedSequence.begin();

            //just a guard to avoid a requirement not to be met
            bool found = false;
            while (eachOption != definedSequence.end()) {
                //The element to be chosen is the first compatible 
                //<= Future work to choose randomly and avoid conflicts
                //And to avoid a same module producing several input to the present module
                if ((*eachOption)->verifyOutputCompatibility((*neededIt))) {
                    (*eachOption)->addSequenciableListener(nextInLine);
                    found = true;
                    break;
                }

                eachOption++;
            }
            //just a guard to avoid a requirement not to be met
            if (!found)
                throw NoOutputReachableException();
            neededIt++;
        }
        //Once all requirements were met, add the method to the specie description
        definedSequence.push_back(nextInLine);
    }
    //Let the chosen method continue the pipeline
    lastOne = nextInLine;
    return true;

}

vector<Sequenciable*> Sequence::findPossibilities(vector<Sequenciable*> availableOptions){
    bool enough = false;
    while (!enough) {
        vector<Sequenciable*> possibilities;
        vector<Sequenciable*>::iterator eachOption = availableOptions.begin();
        
        //Verify from all component, which are compatible with the present one.
        while (eachOption != availableOptions.end()) {
            
            //First, check if the last used component is compatible with present component
            if (lastOne->verifyOutputCompatibility((*eachOption)->getType())) {
                
                //Once they are compatible, get list of requirements for present component
                vector<Type*> needed = (*eachOption)->getInputRequirements();
                
                //Verify if all requirements are met.
                //To do so, first check if there is more possibilities than requirements.
                //At the time, a component can only output one type. <= Future work to allow components return more than one type.
                //Thus, the number of already selected components (specieDescription) must be equal o greater than the number of requirements
                //to the present component (needed). specieDescription.size()+1 since there is the input.
                if(needed.size() <= definedSequence.size()+1){
                    
                    //if there is only one requirement. Once it is known that they are compatible, it is possible to combine them.
                    if(needed.size()==1) {
                           possibilities.push_back(*eachOption);
                           
                    //If there is more than one requirement, it must be verified if every requirement is met.
                    }else if(needed.size()>1) {
                        
                        vector<Type*>::iterator requirementsIt = needed.begin();
                        int foundCompatible = 0;

                        //For each requirement...
                        while (requirementsIt != needed.end()) {

                            //... Verify...
                            vector<Sequenciable*>::iterator possibIt = definedSequence.begin();
                            while (possibIt != definedSequence.end()) {
                                //... if there is a possibility
                                if ((*possibIt)->verifyOutputCompatibility((*requirementsIt))) {
                                    //If so, the given requirement is met...
                                    //Notice that the current implementation allows that a single component provides results for all subsequent methods
                                    //That might be improved in <= Future work
                                    foundCompatible++;
                                    //... go to the next requirement
                                    break;
                                }
                                possibIt++;
                            }

                            requirementsIt++;
                        }
                        //Are there as much possibilities as requirements?
                        if (foundCompatible >= needed.size()) {
                            //
                            possibilities.push_back(*eachOption);
                        }
                        //Otherwise, method is not a valid possibility
                    } 
                }
            }
            eachOption++;
        }
    }
}
void Sequence::setOutputer(Sequenciable *outp){
    if(lastOne->verifyOutputCompatibility(outp))
        outputer = outp;
    else
        throw IncompatibleClassesException;
}
bool Sequence::reachesOutput(){
    return lastOne->verifyOutputCompatibility(outputType);
}
void Sequence::setOutputType(Type* outputType) {
    this->outputType = outputType;
}

Type* Sequence::getOutputType() const {
    return outputType;
}

void Sequence::setInputType(Type* inputType) {
    this->inputType = inputType;
}

Type* Sequence::getInputType() const {
    return inputType;
}
vector<Sequenciable*> Sequence::getSequence(){
    return definedSequence;
}
bool Sequence::equalTo(Sequence *comparingFrom,Sequence *comparingTo) {
    /*
     * Species are identical if and only if all steps in the same order coincides
     */
    //vector<Sequenciable*> otherDescription = other->getSpecieDescription();
    //vector<Sequenciable*> thisDescription = this->getSpecieDescription();
    vector<Sequenciable*> first = comparingFrom->getSequence();
    vector<Sequenciable*> second  = comparingTo->getSequence();
    if (first.size() != second.size()) {
        return false;
    }
    vector<Sequenciable*>::iterator specIt = first.begin();
    vector<Sequenciable*>::iterator otherIt = second.begin();
    while (specIt != first.end()) {
        if (typeid (*(*specIt)) != typeid (*(*otherIt)))
            return false;
        specIt++;
        otherIt++;
    }
    return true;
}