/* 
 * File:   SequenciableOutOfRangeException.h
 * Author: claudio
 *
 * Created on October 30, 2012, 8:57 AM
 */

#ifndef SEQUENCIABLEOUTOFRANGEEXCEPTION_H
#define	SEQUENCIABLEOUTOFRANGEEXCEPTION_H
using namespace std;
#include <exception>
class SequenciableOutOfRangeException : public exception {
public:
    SequenciableOutOfRangeException() throw();
    SequenciableOutOfRangeException(const SequenciableOutOfRangeException& orig);
    virtual ~SequenciableOutOfRangeException() throw();
private:

};

#endif	/* SEQUENCIABLEOUTOFRANGEEXCEPTION_H */

