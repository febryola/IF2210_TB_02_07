#include "item.hpp"
#include "tool.hpp"

int main() {
  item item1(1, "OAK_LOG", "LOG", 1,0, "nontool");
  item item2(item1);
  item2.printDetails();
  return 0;
}