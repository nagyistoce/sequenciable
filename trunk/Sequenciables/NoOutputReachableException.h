/* 
 * File:   NoOutputReachableException.h
 * Author: Claudio
 *
 * Created on September 13, 2011, 10:52 AM
 */

#ifndef NOOUTPUTREACHABLEEXCEPTION_H
#define	NOOUTPUTREACHABLEEXCEPTION_H
#include <exception>
using namespace std;
class NoOutputReachableException : public exception {
public:
    NoOutputReachableException() throw();
    NoOutputReachableException(const NoOutputReachableException& orig);
    virtual ~NoOutputReachableException() throw();
private:

};

#endif	/* NOOUTPUTREACHABLEEXCEPTION_H */

