// inheritance dr item.hpp
#ifndef _NONTOOL_H
#define _NONTOOL_H
#include <iostream>
#include "item.hpp"
using namespace std;

class nontool : public item {
    private: 
        int stacked;
    public:
        nontool();
        nontool(int id, string name, string type, int quantity);
        int getStack();
};

#endif