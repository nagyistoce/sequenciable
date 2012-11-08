/* 
 * File:   Sequenciable.cpp
 * Author: Claudio
 * 
 * Created on July 26, 2011, 4:14 PM
 */

#include <stdio.h>

#include "Sequenciable.h"

Sequenciable::Sequenciable() {
    type = NULL;
}

//Sequenciable::Sequenciable(Sequenciable *orig) {
//    
//}

Sequenciable::~Sequenciable() {
    if(listeners.size()>0){
//        for(int a=0;a<listeners.size();a++){
//            Sequenciable* toDelete = listeners.at(a);
//            if(toDelete!=NULL)
//                delete toDelete;
//        }
        listeners.clear();
    }
    SEQUENCIABLE_ID = 0;
    textualDescription = "";
}

bool Sequenciable::removeSequenciableListener(Sequenciable *lis){
    for(int a=0;a<listeners.size();a++){
        if(listeners.at(a)==lis){
            listeners.erase(listeners.begin()+a);
            return true;
        }
    }
    return false;
}