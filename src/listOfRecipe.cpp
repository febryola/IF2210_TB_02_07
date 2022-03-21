#include "listOfRecipe.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

listOfRecipe::listOfRecipe(){
    for (const auto &entry :
       filesystem::directory_iterator(configPath + "/recipe")) {
            ifstream itemConfigFile(entry.Path());
            
            for (string line; getline(itemConfigFile, line);) {
            
            }
    }
}