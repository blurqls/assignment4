#include "RecipeManager.h"
#include <iostream>

void RecipeManager::addRecipe(const std::string& name, const std::vector<std::string>& ingredients) {
    recipes.push_back(PotionRecipe(name, ingredients));
    std::cout << ">> 새로운 레시피 '" << name << "'이(가) 추가되었습니다." << std::endl;
}

void RecipeManager::displayAllRecipes() const {
    if (recipes.empty()) {
        std::cout << "아직 등록된 레시피가 없습니다." << std::endl;
        return;
    }
    std::cout << "\n--- [ 전체 레시피 목록 ] ---" << std::endl;
    for (const auto& recipe : recipes) {
        std::cout << "- 물약 이름: " << recipe.potionName << std::endl;
        std::cout << "  > 필요 재료: ";
        for (size_t j = 0; j < recipe.ingredients.size(); ++j) {
            std::cout << recipe.ingredients[j];
            if (j < recipe.ingredients.size() - 1) std::cout << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << "---------------------------\n";
}

void RecipeManager::searchPotionIngredients(std::string name_) const {
    std::cout << "\n검색한 재료 이름: " << name_ << "\n해당 재료를 사용하는 물약 : \n";
    for (const auto& v : recipes) {
        for (const auto& t : v.ingredients) {
            if (name_ == t) std::cout << v.potionName << std::endl;
        }
    }
    std::cout << "---------------------------\n";
}

void RecipeManager::searchPotionName(std::string name_) const {
    for (const auto& v : recipes) {
        if (name_ == v.potionName) {
            std::cout << "\n 검색한 물약 이름: " << v.potionName << "\n  > 필요 재료: ";
            for (size_t j = 0; j < v.ingredients.size(); ++j) {
                std::cout << v.ingredients[j];
                if (j < v.ingredients.size() - 1) std::cout << ", ";
            }
            std::cout << std::endl;
        }
    }
    std::cout << "---------------------------\n";
}