// inheritance dr item.hpp
#ifndef _TOOL_H
#define _TOOL_H
#include <iostream>
#include "item.hpp"
using namespace std;

class tool : public item {
    private:
        int durability;
    public:
        tool();
        tool(int id, string name, string type, int quantity, int durability);
        void useTool();
};

#endif