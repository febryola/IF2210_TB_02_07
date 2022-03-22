#include "listOfRecipe.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

listOfRecipe::listOfRecipe(){
    vector<recipe> recipeList;
    for (const auto &entry :
       filesystem::directory_iterator(configPath + "/recipe")) {
            ifstream itemConfigFile(entry.Path());
            recipe baru = recipe();
            string line;
            getline(itemConfigFile, line);

            // Line 1, dapetin row col
            baru.row = -1;
            baru.col = -1;
            string word = "";
            for (auto x : line) 
            {
                if (x == ' ')
                {
                    if(baru.row==-1){
                        baru.row = stoi(word);
                    } else{
                        baru.col = stoi(word);
                    }
                    word = "";
                }
                else {
                    word = word + x;
                }
            }

            // Untuk tiap baru.row line selanjutnya, masukkan ke corresponding
            for(int i=0; i<baru.row; i++){
                word = "";
                getline(itemConfigFile, line);
                int tokenCount = 0;
                for (auto x : line) 
                {
                    if (x == ' ')
                    {
                        // Gimana cara lihat 
                        resep[i+tokenCount] = word;
                        tokenCount++;
                        word = "";
                    }
                    else {
                        word = word + x;
                    }
                }
                tokenCount=0;
            }

            // Mirror resep
            if(baru.col>1){
                for(int i=0; i<baru.row; i++){
                    resepMirror[i*3] = resep[(i*3) + baru.col-1];
                    resepMirror[(i*3)+baru.col-1] = resep[i*3];
                }
            } else{
                for(int i=0; i<9; i++){
                    resepMirror[i] = resep[i];
                }
            }

            // Masukkan hasil dan quantity
            getline(itemConfigFile, line);
            string word = "";
            for (auto x : line) 
            {
                if (x == ' ')
                {
                    if(baru.hasil=="UNKNOWN"){
                        baru.hasil = word;
                    } else{
                        baru.quantity = stoi(word);
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