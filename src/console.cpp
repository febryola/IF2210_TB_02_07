#include "Console.hpp"

#include <iostream>
using namespace std;
int getIDFromName(string name){
  if(name=="OAK_LOG"){return 1;}
  else if(name=="SPRUCE_LOG"){return 2;}
  else if(name=="BIRCH_LOG"){return 3;}
  else if(name=="OAK_PLANK"){return 4;}
  else if(name=="SPRUCE_PLANK"){return 5;}
  else if(name=="BIRCH_PLANK"){return 6;}
  else if(name=="STICK"){return 7;}
  else if(name=="COBBLESTONE"){return 8;}
  else if(name=="BLACKSTONE"){return 9;}
  else if(name=="IRON_INGOT"){return 10;}
  else if(name=="IRON_NUGGET"){return 11;}
  else if(name=="DIAMOND"){return 12;}
  else if(name=="WOODEN_PICKAXE"){return 13;}
  else if(name=="STONE_PICKAXE"){return 14;}
  else if(name=="IRON_PICKAXE"){return 15;}
  else if(name=="DIAMOND_PICKAXE"){return 16;}
  else if(name=="WOODEN_AXE"){return 17;}
  else if(name=="STONE_AXE"){return 18;}
  else if(name=="IRON_AXE"){return 19;}
  else if(name=="DIAMOND_AXE"){return 20;}
  else if(name=="WOODEN_SWORD"){return 21;}
  else if(name=="STONE_SWORD"){return 22;}
  else if(name=="IRON_SWORD"){return 23;}
  else if(name=="DIAMOND_SWORD"){return 24;}
  return 0;
}

string getTypeFromName(string name){
  if(name=="OAK_LOG" || name=="SPRUCE_LOG" || name=="BIRCH_LOG"){
    return "LOG";
  }
  else if(name=="OAK_LPLANK" || name=="SPRUCE_PLANK" || name=="BIRCH_PLANK"){
    return "PLANK";
  }
  else if(name=="COBBLESTONE" || name=="BLACKSTONE"){
    return "STONE";
  }
  else{
    return "-";
  }
}
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