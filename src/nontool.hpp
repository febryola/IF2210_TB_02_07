// inheritance dr item.hpp
#ifndef _NONTOOL_H
#define _NONTOOL_H
#include <iostream>
#include "item.hpp"
using namespace std;

class nontool : public item {
    public:
        nontool();
        nontool(int id, string name, string type, int quantity);
};

#endif