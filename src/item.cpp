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

// print details
void item::printDetails() { 
    cout << "ID: " << this->id << endl;
    cout << "Nama: " << this->name << endl;
    cout << "Tipe: " << this->type << endl;
    cout << "Jumlah: " << this->quantity << endl;
}