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
    public:
        item(); //ctor
        item(int id, string name, string type, int quantity); //ctor
        //cctor dan dtor tidak perlu

        // getter
        int getId();
        string getName();
        string getType();
        int getQuantity();
        virtual int getDurability();

        // setter
        void setId(int id);
        void setQuantity(int quant);

        //clone 
        item* clone();

        // print details
        virtual void printDetails(); //mencetak detail sebuah item


        bool operator==(item i);
        virtual void useTool();
};

#endif