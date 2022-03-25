#include "exception.hpp"

/* IndexOutOfBoundException */
IndexOutOfBoundException::IndexOutOfBoundException(int idxAccessed, int containerSize) {
    this->idxAccessed = idxAccessed;
    this->containerSize = containerSize;
}

/* CraftIndexOutOfBoundException */
/*
    Error handling jika mengakses Craft dengan id diluar batas
*/
CraftIndexOutOfBoundException::CraftIndexOutOfBoundException(int idxAccessed, int craftSize) : IndexOutOfBoundException(idxAccessed, craftSize) {
    this->type = "CraftIndexOutOfBoundException";
}
void CraftIndexOutOfBoundException::printMessage() {
    cout << this->type << ": you are trying to access index " << this->idxAccessed << ", "; 
    cout << "while you have [0.." << (this->containerSize-1) << "] "; 
    cout << "slot on Craft." << endl; 
}

/* InventoryIndexOutOfBoundException */
/*
    Error handling jika mengakses Inventory dengan id diluar batas
*/
InventoryIndexOutOfBoundException::InventoryIndexOutOfBoundException(int idxAccessed, int inventorySize) : IndexOutOfBoundException(idxAccessed, inventorySize) {
    this->type = "InventoryIndexOutOfBoundException";
}
void InventoryIndexOutOfBoundException::printMessage() {
    cout << this->type << ": you are trying to access index " << this->idxAccessed << ", "; 
    cout << "while you have [0.." << (this->containerSize-1) << "] "; 
    cout << "slot on Inventory." << endl; 
}

/* FullInventoryException */
/*
    Error handling jika menambahkan item pada saat Inventory telah penuh
*/
FullInventoryException::FullInventoryException() {
    this->type = "FullInventoryException";
}
void FullInventoryException::printMessage() {
    cout << this->type << ": you are trying to add item to inventory, ";
    cout << "while your inventory is full." << endl;
}

/* FullStackException */
/*
    Error handling jika menumpuk item non-tool pada slot tertentu, sementara slot telah penuh
*/
FullStackException::FullStackException() {
    this->type = "FullStackException";
}
void FullStackException::printMessage() {
    cout << this->type << ": you are trying to stack non-tool item to an inventory slot, ";
    cout << "while the slot is full." << endl;
}

/* NonStackableException */
/*
    Error handling jika ingin menumpuk tool item pada inventory
*/
NonStackableException::NonStackableException() {
    this->type = "NonStackableException";
}
void NonStackableException::printMessage() {
    cout << this->type << ": you can't stack tool item to an inventory slot.";
    cout << endl;
}

/* DifferentItemCategoryException */
/*
    Error handling jika menumpuk item pada inventory dengan item yang berbeda
*/
DifferentItemNameException::DifferentItemNameException() {
    this->type = "DifferentItemNameException";
}
void DifferentItemNameException::printMessage() {
    cout << this->type << ": you can't stack different item to an inventory slot.";
    cout << endl;
}

/* UseEmptyException */
/*
    Error handling jika menggunakan item, sedangkan slot kosong
*/
UseEmptyException::UseEmptyException() {
    this->type = "UseEmptyException";
}
void UseEmptyException::printMessage() {
    cout << this->type << ": you are trying to use an item, ";
    cout << "while the inventory slot is empty." << endl;
}

/* UseNonToolException */
/*
    Error handling jika menggunakan non-tool item
*/
UseNonToolException::UseNonToolException() {
    this->type = "UseNonToolException";
}
void UseNonToolException::printMessage() {
    cout << this->type << ": you are trying to use a non-tool item. ";
    cout << "You can only use tool items. Try DISCARD." << endl;
}

/* DiscardEmptyException */
/*
    Error handling jika Discard item, sedangkan slot kosong
*/
DiscardEmptyException::DiscardEmptyException() {
    this->type = "DiscardEmptyException";
}
void DiscardEmptyException::printMessage() {
    cout << this->type << ": you are trying to discard an item, ";
    cout << "while the inventory slot is empty." << endl;
}

/* InvalidDiscardException */
/*
    Error handling jika Discard item dengan 
    jumlah lebih besar dari jumlah yang ada di slot
*/
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
/*
    Error handling jika move item dengan 
    jumlah tidak sesuai dengan jumlah yang ada di slot
*/
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
/*
    Error handling jika menambahkan item, 
    sedangkan inventory tidak dapat mengakomodasi hal tersebut
*/
InvalidAddItemException::InvalidAddItemException() {
    this->type = "InvalidAddItemException";
}
void InvalidAddItemException::printMessage(){
    cout << this->type << ": you are trying to add item with amount that inventory can't accomodate.";
    cout << endl;
}

/* InvalidRecipeException */
/*
    Error handling jika Crafting dilakukan, 
    sedangkan tidak ada resep yang cocok
*/
InvalidRecipeException::InvalidRecipeException() {
    this->type = "InvalidRecipeException";
}
void InvalidRecipeException::printMessage(){
    cout << this->type << ": you are trying to craft item that doesn't match to any recipes.";
    cout << endl;
}

/* CraftSlotExistException */
/*
    Error handling jika memindahkan item ke suatu slot pada Craft Table,
    sedangkan pada slot tersebut telah terisi item lain
*/
CraftSlotExistException::CraftSlotExistException() {
    this->type = "CraftSlotExistException";
}
void CraftSlotExistException::printMessage(){
    cout << this->type << ": your craft slot destination has been filled.";
    cout << endl;
}

/* CraftDifferentTypeException */
/*
    Error handling jika Crafting dilakukan,
    sedangkan terdapat item tool & non-tool pada Craft Table
*/
CraftDifferentTypeException::CraftDifferentTypeException(){
    this->type = "CraftDifferentTypeException";
}
void CraftDifferentTypeException::printMessage() {
    cout << this->type << ": you can't craft item with non-tool and tool item together in Craft Table.";
    cout << endl;
}
