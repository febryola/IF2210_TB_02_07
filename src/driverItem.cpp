#include "item.hpp"

int main() {
  item item1(1, "OAK_LOG", "LOG", 1);
  item item2(item1);
  item2.printDetails();
  return 0;
}