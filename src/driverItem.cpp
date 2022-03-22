#include "item.hpp"
#include "tool.hpp"

int main() {
  item item1(1, "OAK_LOG", "LOG", 1);
  item item2(item1);
  item2.printDetails();

  tool tool1(2, "WOODEN_PICKAXE", "-", 1, 2);
  tool1.printDetails();
  tool1.useTool();
  tool1.printDetails();
  return 0;
}