#include "listOfRecipe.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <filesystem>
#include <vector>

listOfRecipe::listOfRecipe(){
    string configPath = "../config";
    vector<recipe> recipeList;
    for (const auto &entry :
       filesystem::directory_iterator(configPath + "/recipe")) {
            ifstream itemConfigFile(entry.path());
            recipe baru = recipe();
            string line;
            getline(itemConfigFile, line);

            // Line 1, dapetin row col
            string word = "";
            line += " ";
            for (auto x : line) 
            {
                if (x == ' ' || x == '\n')
                {
                    if(baru.getRow()==-1){
                        baru.setRow(stoi(word));
                    } else {
                        baru.setCol(stoi(word));
                    }
                    word = "";
                }
                else {
                    word = word + x;
                }
            }

            // Untuk tiap baru.row line selanjutnya, masukkan ke corresponding
            for(int i=0; i<baru.getRow(); i++){
                word = "";
                getline(itemConfigFile, line);
                line += " ";
                int tokenCount = 0;
                for (auto x : line) 
                {
                    if (x == ' ' || x == '\n')
                    {
                        baru.setResep((i*3+tokenCount), word);
                        tokenCount++;
                        word = "";
                    }
                    else {
                        word = word + x;
                    }
                }
                tokenCount=0;
            }

            for(int i = 0; i<9;i++){
                if(baru.getResep(i) != "-"){
                    baru.setFirstItem(baru.getResep(i));
                    break;
                }
            }

            // Mirror resep
            if(baru.getCol()>1){
                for(int i=0; i<baru.getRow(); i++){
                    baru.setResepMirror(i*3, baru.getResep((i*3)+2));
                    baru.setResepMirror(((i*3)+1), baru.getResep((i*3)+1));
                    baru.setResepMirror(((i*3)+2), baru.getResep(i*3));
                }
            } else{
                for(int i=0; i<9; i++){
                    baru.setResepMirror(i, baru.getResep(i));

                }
            }

            // Masukkan hasil dan quantity
            getline(itemConfigFile, line);
            line += " ";
            word = "";
            for (auto x : line) 
            {
                if (x == ' ' || x == '\n')
                {
                    if(baru.getHasil() == "UNKNOWN"){
                        baru.setHasil(word);
                    } else {
                        baru.setQuantity(stoi(word));
                    }
                    word = "";
                }
                else {
                    word = word + x;
                }
            }

            recipeList.push_back(baru);
            
    }
    size = recipeList.size();
    array_recipe = new recipe[size];
    for(int i=0; i<recipeList.size(); i++){
        array_recipe[i] = recipeList[i];
    }
}

int listOfRecipe::getSize(){
    return size;
}
recipe listOfRecipe::getRecipe(int idx){
    return array_recipe[idx];
}