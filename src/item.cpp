#include "item.hpp"
#include <iostream>
using namespace std;

// ctor
item::item() {
    this->id = 0;
    this->name = "unknown";
    this->type = "unknown";
    this->quantity = 0;
}

// ctor
item::item(int id, string name, string type, int quantity) {
    this->id = id;
    this->name = name;
    this->type = type;
    this->quantity = quantity;
}

// getter
int item::getId() { return id; }
string item::getName() { return name; }
string item::getType() { return type; }
int item::getQuantity() { return quantity; }

// setter
void item :: setId(int id){
    this->id = id;
}
void item :: setQuantity(int quant){
    this->quantity = quant;
}

//clone
item* item :: clone(){
    return new item(*this);
}
// print details
void item::printDetails() { 
    cout << "ID: " << this->id << endl;
    cout << "Nama: " << this->name << endl;
    cout << "Tipe: " << this->type << endl;
    cout << "Jumlah: " << this->quantity << endl;
}

bool item::operator==(item i) {
    return (id == i.id && name == i.name && type == i.type && quantity == i.quantity);
}