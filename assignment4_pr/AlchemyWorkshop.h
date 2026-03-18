#ifndef ALCHEMY_WORKSHOP_H
#define ALCHEMY_WORKSHOP_H

#include "RecipeManager.h"
#include "StockManager.h"

class AlchemyWorkshop {
private:
    RecipeManager recipemanager;
    StockManager stockmanager;

public:
    void addRecipe(const std::string& name, const std::vector<std::string>& ingredients) {
        recipemanager.addRecipe(name, ingredients);
        stockmanager.InitialStock(name);
    }
    void displayAllRecipes() const { recipemanager.displayAllRecipes(); }
    void searchPotionName(std::string name_) const { recipemanager.searchPotionName(name_); }
    void searchPotionIngredients(std::string name_) const { recipemanager.searchPotionIngredients(name_); }
    void givePotion(std::string name_) { stockmanager.givePotion(name_); }
    void returnPotion(std::string name_) { stockmanager.ReturnPotion(name_); }
};

#endif