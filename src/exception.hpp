#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_

#include <iostream>
using namespace std;

class Exception {
    public:
        virtual void printMessage() = 0;
};

class FullInventoryException : public Exception {

};

class NonStackableException : public Exception {
    
};

class FullStackException : public Exception {

};

#endif