/* 
 * File:   Sequence.cpp
 * Author: claudio
 * 
 * Created on May 8, 2012, 9:17 AM
 */

#include "Sequence.h"
#include "IncompatibleClassesException.h"
#include "SequenciableOutOfRangeException.h"

Sequence::Sequence() {
    outputer = NULL;
    lastOne = NULL;
}
Sequence::Sequence(vector<Sequenciable*> seq){
    outputer = NULL;
    vector<Sequenciable*>::iterator it;
    for(it = seq.begin();it < seq.end(); it++){
        addToSequence((*it));
    }
    for (int part = 0; part < definedSequence.size() - 1; part++) {
        definedSequence[part]->addSequenciableListener(definedSequence[part + 1]);
    }
}
Sequence::Sequence(Sequence* seq){
    outputer = NULL;
    lastOne = NULL;
    for(int a=0;a<seq->getSize();a++){
        addToSequence(seq->getSequenciableAt(a));
    }
    for (int part = 0; part < definedSequence.size() - 1; part++) {
        definedSequence[part]->addSequenciableListener(definedSequence[part + 1]);
    }
}
Sequence::~Sequence() {
    for(int a=0; a< definedSequence.size(); a++){
        Sequenciable *s = definedSequence[a];
        if(s!=NULL)
                delete s;
    }
    definedSequence.clear();
//    if(inputType!=NULL)
//        delete inputType;
//    if(outputType!=NULL)
//        delete outputType;
}
bool Sequence::addToSequence(Sequenciable* nextSequenciable){
    Sequenciable* nextInLine = nextSequenciable->getClone();
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

vector<Sequenciable*> Sequence::findPossibilities(vector<Sequenciable*> availableOptions) {
    vector<Sequenciable*> possibilities;
    vector<Sequenciable*>::iterator eachOption = availableOptions.begin();

    //Verify from all component, which are compatible with the present one.
    while (eachOption != availableOptions.end()) {

        
        
        bool compatible = false;
        //If no previous item was previously inserted, check with input requirements
        if(definedSequence.empty()){
                if ((*eachOption)->verifyInputCompatibility(this->inputType)) {    
                    compatible = true;
                }
        }else{
            //lastOne->verifyOutputCompatibility((*eachOption)->getType())
            if(lastOne->verifyOutputCompatibility((*eachOption)->getType())){
//            if ((*eachOption)->verifyInputCompatibility(lastOne)) {
                compatible = true;
            }
        }
        
        //First, check if the last used component is compatible with present component
        //if ((*eachOption)->verifyInputCompatibility(this->inputType)) {
        if (compatible) {

            //Once they are compatible, get list of requirements for present component
            vector<Type*> needed = (*eachOption)->getInputRequirements();

            //Verify if all requirements are met.
            //To do so, first check if there is more possibilities than requirements.
            //At the time, a component can only output one type. <= Future work to allow components return more than one type.
            //Thus, the number of already selected components (specieDescription) must be equal o greater than the number of requirements
            //to the present component (needed). specieDescription.size()+1 since there is the input.
            if (needed.size() <= definedSequence.size() + 1) {

                //if there is only one requirement. Once it is known that they are compatible, it is possible to combine them.
                if (needed.size() == 1) {
                    possibilities.push_back(*eachOption);

                    //If there is more than one requirement, it must be verified if every requirement is met.
                } else if (needed.size() > 1) {

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
    return possibilities;

}
void Sequence::setOutputer(Sequenciable *outp){
    if(lastOne->verifyOutputCompatibility(outp->getType())){
        outputer = outp;
        lastOne->addSequenciableListener(outputer);
    }else
        throw IncompatibleClassesException();
}
void Sequence::setInputer(Sequenciable *inpt){
    lastOne = inpt;
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
void Sequence::startPipeline(Event* t){
    definedSequence[0]->actionPerformed(t);
}
void Sequence::startPipeline(Event* t, Sequenciable *output){
    setOutputer(output);
    definedSequence[0]->actionPerformed(t);
    lastOne->removeSequenciableListener(output);
}
//vector<Sequenciable*> Sequence::getSequence(){
//    return definedSequence;
//}
int Sequence::getSize(){
    return definedSequence.size();
}
//bool Sequence::equalTo(Sequence *comparingFrom,Sequence *comparingTo) {
//    /*
//     * Species are identical if and only if all steps in the same order coincides
//     */
//    vector<Sequenciable*> first = comparingFrom->getSequence();
//    vector<Sequenciable*> second  = comparingTo->getSequence();
//    if (first.size() != second.size()) {
//        return false;
//    }
//    vector<Sequenciable*>::iterator specIt = first.begin();
//    vector<Sequenciable*>::iterator otherIt = second.begin();
//    while (specIt != first.end()) {
//        if (typeid (*(*specIt)) != typeid (*(*otherIt)))
//            return false;
//        specIt++;
//        otherIt++;
//    }
//    return true;
//}
Sequenciable *Sequence::getSequenciableAt(int at){
    if(at >= 0 && at < getSize()){
        return definedSequence.at(at);
    }else{
        throw SequenciableOutOfRangeException();
    }
}
bool Sequence::equalToSequence(Sequence *comparingTo) {
    /*
     * Species are identical if and only if all steps in the same order coincides
     */
    if (getSize() != comparingTo->getSize()) {
        return false;
    }
    for(int a=0;a<getSize();a++){
        Sequenciable* first = getSequenciableAt(a);
        Sequenciable* second = comparingTo->getSequenciableAt(a);
        if (typeid (first) != typeid (second))
            return false;
    }
    return true;
}