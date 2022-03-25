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

/* DifferentItemCategoryException */
DifferentItemNameException::DifferentItemNameException() {
    this->type = "DifferentItemNameException";
}
void DifferentItemNameException::printMessage() {
    cout << this->type << ": you can't stack different item to an inventory slot.";
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

/* UseNonToolException */
UseNonToolException::UseNonToolException() {
    this->type = "UseNonToolException";
}
void UseNonToolException::printMessage() {
    cout << this->type << ": you are trying to use a non-tool item. ";
    cout << "You can only use tool items. Try DISCARD." << endl;
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

/* InvalidMoveException */
InvalidMoveException::InvalidMoveException(int itemQty, int amount) {
    this->itemQty = itemQty;
    this->amount = amount;
    this->type = "InvalidMoveException";
}
void InvalidMoveException::printMessage() {
    cout << this->type << ": you are trying to move item with " << this->amount << " amount, ";
    cout << "while the item quantity is " << this->itemQty;
    cout << "." << endl;
}

/* InvalidAddItemException */
InvalidAddItemException::InvalidAddItemException() {
    this->type = "InvalidAddItemException";
}
void InvalidAddItemException::printMessage(){
    cout << this->type << ": you are trying to add item with amount that inventory can't accomodate.";
    cout << endl;
}

/* InvalidRecipeException */
InvalidRecipeException::InvalidRecipeException() {
    this->type = "InvalidRecipeException";
}
void InvalidRecipeException::printMessage(){
    cout << this->type << ": you are trying to craft item that doesn't match to any recipes.";
    cout << endl;
}

/* CraftSlotExistException */
CraftSlotExistException::CraftSlotExistException() {
    this->type = "CraftSlotExistException";
}
void CraftSlotExistException::printMessage(){
    cout << this->type << ": your craft slot destination has been filled.";
    cout << endl;
}

/* CraftDifferentTypeException */
CraftDifferentTypeException::CraftDifferentTypeException(){
    this->type = "CraftDifferentTypeException";
}
void CraftDifferentTypeException::printMessage() {
    cout << this->type << ": you can't craft item with non-tool and tool item together in Craft Table.";
    cout << endl;
}

// // TESTING EXCEPTION
// int main () {
//     CraftIndexOutOfBoundException e1(5, 3);
//     e1.printMessage();

//     InventoryIndexOutOfBoundException e2(8, 2);
//     e2.printMessage();

//     FullInventoryException (*e3) = new FullInventoryException();
//     (*e3).printMessage();

//     FullStackException (*e4) = new FullStackException();
//     (*e4).printMessage();

//     NonStackableException (*e5) = new NonStackableException();
//     (*e5).printMessage();
    
//     UseEmptyException (*e6) = new UseEmptyException();
//     (*e6).printMessage();
    
//     DiscardEmptyException (*e7) = new DiscardEmptyException();
//     (*e7).printMessage();

//     InvalidDiscardException e8(9,7);
//     e8.printMessage();

//     return 0;
// }
