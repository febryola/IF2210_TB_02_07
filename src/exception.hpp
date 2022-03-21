#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_

#include <iostream>
#include <string>
using namespace std;
class BaseException {
    public:
        virtual void printMessage() = 0;
};

class CraftIndexOutOfBoundException : public BaseException {
    private:
        int idxAccessed;
        int craftSize;
    public:
        CraftIndexOutOfBoundException(int idxAccessed, int craftSize);
        void printMessage();
};
 
class InventoryIndexOutOfBoundException : public BaseException {
    private:
        int idxAccessed;
        int inventorySize;
    public:
        InventoryIndexOutOfBoundException(int idxAccessed, int inventorySize);
        void printMessage();
};

// DI-HOLD DULU
class FullInventoryException : public BaseException {
    private:
        string msg;
    public:
        FullInventoryException();
        void printMessage();
};

class NonStackableException : public BaseException {
    private:
        string msg;
    public:
        NonStackableException();
        void printMessage();
};
class FullStackException : public BaseException {
    private:
        string msg;
    public:
        FullStackException();
        void printMessage();
};

class InvalidDiscardException : public BaseException {
    private:
        int itemQty;
        int discardQty;
    public:
        InvalidDiscardException (int itemQty, int discardQty);
        void printMessage();
};

class EmptyDiscardException : public BaseException {
    private:
        int itemQty;
    public:
        EmptyDiscardException (int itemQty);
        void printMessage();
};

class EmptyUseException : public BaseException {
    private:
        int itemQty;
    public:
        EmptyUseException (int itemQty);
        void printMessage();
};

#endif