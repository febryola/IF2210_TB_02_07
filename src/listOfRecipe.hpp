#ifndef _LIST_OF_RECIPE_H
#define _LIST_OF_RECIPE_H
#include "item.hpp"
#include "recipe.hpp"
#include <iostream>
#include <iterator>
#include <map>

class listOfRecipe{
    private:
        recipe* array_recipe;
        int size;
    public:
        listOfRecipe();
        int getSize();
        recipe getRecipe(int idx);
};

#endif