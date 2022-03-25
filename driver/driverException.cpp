#include "exception.hpp"
#include <iostream>
using namespace std;

int main () {
    CraftIndexOutOfBoundException e1(5, 3);
    e1.printMessage();

    InventoryIndexOutOfBoundException e2(8, 2);
    e2.printMessage();

    FullInventoryException (*e3) = new FullInventoryException();
    (*e3).printMessage();

    FullStackException (*e4) = new FullStackException();
    (*e4).printMessage();

    NonStackableException (*e5) = new NonStackableException();
    (*e5).printMessage();
    
    UseEmptyException (*e6) = new UseEmptyException();
    (*e6).printMessage();
    
    DiscardEmptyException (*e7) = new DiscardEmptyException();
    (*e7).printMessage();

    InvalidDiscardException e8(9,7);
    e8.printMessage();

    return 0;
}
