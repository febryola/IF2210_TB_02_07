#include "exception.hpp"

IndexOutOfBoundException::IndexOutOfBoundException(int idxAccessed, int containerSize) {
    this->idxAccessed = idxAccessed;
    this->containerSize = containerSize;
}

/* CraftIndexOutOfBoundException */
CraftIndexOutOfBoundException::CraftIndexOutOfBoundException(int idxAccessed, int craftSize) : IndexOutOfBoundException(idxAccessed, craftSize) {
    this->type = "CraftIndexOutOfBoundException";
}
void CraftIndexOutOfBoundException::printMessage() {
    cout << this->type << ": you are trying to access index " << this->idxAccessed << ", "; 
    cout << "while you have [0.." << (this->containerSize-1) << "] "; 
    cout << "slot on Craft." << endl; 
}

/* InventoryIndexOutOfBoundException */
InventoryIndexOutOfBoundException::InventoryIndexOutOfBoundException(int idxAccessed, int inventorySize) : IndexOutOfBoundException(idxAccessed, inventorySize) {
    this->type = "InventoryIndexOutOfBoundException";
}
void InventoryIndexOutOfBoundException::printMessage() {
    cout << this->type << ": you are trying to access index " << this->idxAccessed << ", "; 
    cout << "while you have [0.." << (this->containerSize-1) << "] "; 
    cout << "slot on Inventory." << endl; 
}

/* FullInventoryException */
FullInventoryException::FullInventoryException() {
    this->type = "FullInventoryException";
}
void FullInventoryException::printMessage() {
    cout << this->type << ": you are trying to add item to inventory, ";
    cout << "while your inventory is full." << endl;
}

/* FullStackException */
FullStackException::FullStackException() {
    this->type = "FullStackException";
}
void FullStackException::printMessage() {
    cout << this->type << ": you are trying to stack non-tool item to an inventory slot, ";
    cout << "while the slot is full." << endl;
}

/* NonStackableException */
NonStackableException::NonStackableException() {
    this->type = "NonStackableException";
}
void NonStackableException::printMessage() {
    cout << this->type << ": you can't stack tool item to an inventory slot.";
    cout << endl;
}

/* UseEmptyException */
UseEmptyException::UseEmptyException() {
    this->type = "UseEmptyException";
}
void UseEmptyException::printMessage() {
    cout << this->type << ": you are trying to use an item, ";
    cout << "while the inventory slot is empty." << endl;
}

/* DiscardEmptyException */
DiscardEmptyException::DiscardEmptyException() {
    this->type = "DiscardEmptyException";
}
void DiscardEmptyException::printMessage() {
    cout << this->type << ": you are trying to discard an item, ";
    cout << "while the inventory slot is empty." << endl;
}

/* InvalidDiscardException */
InvalidDiscardException::InvalidDiscardException(int itemQty, int discardQty) {
    this->itemQty = itemQty;
    this->discardQty = discardQty;
    this->type = "InvalidDiscardException";
}
void InvalidDiscardException::printMessage() {
    cout << this->type << ": you are trying to discard item with " << this->discardQty << " amount, ";
    cout << "while you only have " << this->itemQty;
    cout << "." << endl;
}

/*
// TESTING EXCEPTION
int main () {
    CraftIndexOutOfBoundException e1(5, 3);
    e1.printMessage();

    InventoryIndexOutOfBoundException e2(8, 2);
    e2.printMessage();

    FullInventoryException (*e3) = new FullInventoryException();
    (*e3).printMessage();

    FullStackException (*e4) = new FullStackException();
    (*e4).printMessage();

    NonStackableException (*e5) = new NonStackableException();
    (*e5).printMessage();
    
    UseEmptyException (*e6) = new UseEmptyException();
    (*e6).printMessage();
    
    DiscardEmptyException (*e7) = new DiscardEmptyException();
    (*e7).printMessage();

    InvalidDiscardException e8(9,7);
    e8.printMessage();

    return 0;
}
*/