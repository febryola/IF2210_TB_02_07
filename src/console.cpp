#include "Console.hpp"

#include <iostream>
using namespace std;
string getColorANSI(Color color) {
  switch (color) {
    case RED:
      return "\x1B[31m";
    case GREEN:
      return "\x1B[32m";
    case YELLOW:
      return "\x1B[33m";
    case BLUE:
      return "\x1B[34m";
    case MAGENTA:
      return "\x1B[35m";
    case CYAN:
      return "\x1B[36m";
    case WHITE:
      return "\x1B[37m";
    case HIDDEN:
      return "\x1B[90m";
    case NORMAL:
    default:
      return "\x1B[0m";
  }
}

void Console::printHeader() {
  string headerTemplate =
      
" ___      ___     ______      ___      __      _____   ____   _______   \n"  
"|  ))    //  |   /     ))    |   |    / ))    ())   ))|   ))  /  _    | \n" 
" )) ))  //   |  // ____ ))   ||  |   /   ))   |.))   ))    |(: ())___)  \n"  
" /)) ))/.    | /  /    ) :)  |:  |  /' /))))  |: )).  ))   | ))/ ))     \n"  
"|: )).        |(: (____/ //___|  /  //  __')) |.  ))   )). | //   ))___ \n" 
"|.  ))   /:  | ))       //  :|_/ )/   /  )) ))|    ))   )) |(:    _(  _|\n"
"|___|))_/|___|  ))_____/(_______/(___/    ))__)))__|))___))) ))______)  \n"                                                             ;

  cout << getColorANSI(GREEN) << headerTemplate << getColorANSI(CYAN) << endl
       << "Versi 1.0.0\n" << getColorANSI(NORMAL) << endl;
}