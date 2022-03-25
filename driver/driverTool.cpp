#include "../src/tool.hpp"
#include <iostream>
using namespace std;

int main() {
    tool item1(2,"WOODEN_PICKAXE","-",1,10);
    item1.getDurability();
    item1.printDetails();
    item1.useTool();
    item1.printDetails();
  return 0;
}