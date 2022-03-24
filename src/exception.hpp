#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_
#include <iostream>
#include <string>
using namespace std;

class BaseException {
    protected:
        string type;
    public:
        virtual void printMessage() = 0;
};

class IndexOutOfBoundException : public BaseException {
    protected:
        int idxAccessed;
        int containerSize;
    public:
        IndexOutOfBoundException(int idxAccessed, int containerSize);
};

class CraftIndexOutOfBoundException : public IndexOutOfBoundException {
    public:
        CraftIndexOutOfBoundException(int idxAccessed, int craftSize);
        void printMessage();
};
 
class InventoryIndexOutOfBoundException : public IndexOutOfBoundException {
    public:
        InventoryIndexOutOfBoundException(int idxAccessed, int inventorySize);
        void printMessage();
};

class FullInventoryException : public BaseException {
    public:
        FullInventoryException();
        void printMessage();
};

class FullStackException : public BaseException {
    public:
        FullStackException();
        void printMessage();
};

class NonStackableException : public BaseException {
    public:
        NonStackableException();
        void printMessage();
};

class UseEmptyException : public BaseException {
    public:
        UseEmptyException();
        void printMessage();
};

class UseNonToolException : public BaseException {
    public:
        UseNonToolException();
        void printMessage();
};

class DiscardEmptyException : public BaseException {
    public:
        DiscardEmptyException();
        void printMessage();
};

class InvalidDiscardException : public BaseException {
    private:
        int itemQty;
        int discardQty;
    public:
        InvalidDiscardException(int itemQty, int discardQty);
        void printMessage();
};

class InvalidMoveException : public BaseException {
    private:
        int itemQty;
        int amount;
    public:
        InvalidMoveException(int itemQty, int amount);
        void printMessage();
};

class InvalidQuantityException : public BaseException {
    private:
        int slotSrc;
        int slotDest;
    public:
        InvalidQuantityException(int slotSrc, int slotDest);
        void printMessage();
};

class InvalidAddItemException : public BaseException {
    public:
        InvalidAddItemException();
        void printMessage();
};

class DifferentItemNameException : public BaseException {
    public:
        DifferentItemNameException();
        void printMessage();
};

#endif
