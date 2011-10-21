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

class Sequenciable {
public:
    Sequenciable();
    Sequenciable(Sequenciable* orig);
    virtual ~Sequenciable();
    //virtual bool verifyInputCompatibility(Sequenciable* s)=0;
    virtual bool verifyOutputCompatibility(Sequenciable *lis)=0;
    virtual bool addSequenciableListener(Sequenciable *lis)=0;
    virtual void actionPerformed(Event *e)=0;
    virtual void clearListeners(){
        listeners.clear();
    }
protected:
    std::vector<Sequenciable*> listeners;
};

#endif	/* SEQUENCIABLE_H */

