// base class tool dan nontool
#ifndef _ITEM_H
#define _ITEM_H
#include <iostream>
using namespace std;

class item {
    protected:
        int id;
        string name;
        string type;
        int quantity;
        int durability;
    public:
        item(); //ctor
        item(int id, string name, string type, int quantity); //ctor
        //cctor dan dtor tidak perlu

        // getter
        int getId();
        string getName();
        string getType();
        int getQuantity();

        // setter
        void setId(int id);
        void setQuantity(int quant);

        //clone 
        item* clone();

        // print details
        void printDetails(); //mencetak detail sebuah item

        bool operator==(item i);
};

#endif