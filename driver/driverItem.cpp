#include "../src/item.hpp"

int main() {
  item item1(1, "OAK_LOG", "LOG", 1);
  item item2(item1);
  item2.printDetails();
  item2.getId();
  item2.getName();
  item2.getType();
  item2.getDurability();
  item2.setId(3);
  item2.setQuantity(10);
  item2.printDetails();
  return 0;
}