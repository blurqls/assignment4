#ifndef RECIPE_MANAGER_H
#define RECIPE_MANAGER_H

#include <vector>
#include <string>
#include "PotionRecipe.h"

class RecipeManager {
private:
    std::vector<PotionRecipe> recipes;

public:
    void addRecipe(const std::string& name, const std::vector<std::string>& ingredients);
    void displayAllRecipes() const;
    void searchPotionIngredients(std::string name_) const;
    void searchPotionName(std::string name_) const;
};

#endif