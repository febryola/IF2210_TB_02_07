#include "recipe.hpp"
#include "listOfRecipe.hpp"
int main(){
    listOfRecipe *listResep = new listOfRecipe();
    int i;
    cout << "angka : ";
    cin >> i;
    listResep->getRecipe(i).showRecipe();
    listResep->getRecipe(i+1).showRecipe();
    listResep->getRecipe(i+2).showRecipe();

    // string line = "1 1";
    // string word = "";
    // int row = -1;
    // int col = -1;
    // for (auto x : line) 
    // {   
    //     cout <<"read:" << x << endl;
    //     if (x == ' ')
    //     {
    //         if(row ==-1){
    //             row = stoi(word);
    //         } else {
    //             col = stoi(word);
    //         }
    //         word = "";
    //     }
    //     else {
    //         word = word + x;
    //     }
    //     cout << "word:" << word << endl;
    // }
    // cout << "row : " << row << " col : " << endl;
    
}