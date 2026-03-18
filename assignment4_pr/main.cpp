#include <iostream>
#include <vector>
#include <string>
#include "AlchemyWorkshop.h"

int main() {
    // 한글 출력을 위한 설정

    AlchemyWorkshop myWorkshop;

    while (true) {
        std::cout << "연금술 공방 관리 시스템" << std::endl;
        std::cout << "1. 레시피 추가" << std::endl;
        std::cout << "2. 모든 레시피 출력" << std::endl;
        std::cout << "3. 레시피 이름으로 검색" << std::endl;
        std::cout << "4. 레시피 재료로 검색" << std::endl;
        std::cout << "5. 포션 모험가에게 주기" << std::endl;
        std::cout << "6. 포션 반납받기" << std::endl;
        std::cout << "7. 종료" << std::endl;
        std::cout << "선택: ";

        int choice;
        std::cin >> choice;

        // 입력 오류 처리 (숫자가 아닌 값 입력 시)
        if (std::cin.fail()) {
            std::cout << "잘못된 입력입니다. 숫자를 입력해주세요." << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        if (choice == 1) {
            std::string name;
            std::cout << "물약 이름: ";
            std::cin.ignore(1000, '\n');
            std::getline(std::cin, name);

            std::vector<std::string> ingredients_input;
            std::string ingredient;
            std::cout << "필요한 재료들을 입력하세요. (입력 완료 시 '끝' 입력)" << std::endl;

            while (true) {
                std::cout << "재료 입력: ";
                std::getline(std::cin, ingredient);

                if (ingredient == "끝") {
                    break;
                }
                ingredients_input.push_back(ingredient);
            }

            if (!ingredients_input.empty()) {
                myWorkshop.addRecipe(name, ingredients_input);
            }
            else {
                std::cout << ">> 재료가 입력되지 않아 레시피 추가를 취소합니다." << std::endl;
            }

        }
        else if (choice == 2) {
            myWorkshop.displayAllRecipes();
            std::cout << std::endl;

        }
        else if (choice == 3) {
            std::string name;
            std::cout << "물약 이름: ";
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, name);

            myWorkshop.searchPotionName(name);
            std::cout << std::endl;

        }
        else if (choice == 4) {
            std::string name;
            std::cout << "재료 이름: ";
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, name);
            myWorkshop.searchPotionIngredients(name);
            std::cout << std::endl;

        }
        else if (choice == 5) {
            std::string name;
            std::cout << "물약 이름: ";
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, name);

            myWorkshop.givePotion(name);
            std::cout << std::endl;

        }
        else if (choice == 6) {
            std::string name;
            std::cout << "물약 이름: ";
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, name);

            myWorkshop.returnPotion(name);
            std::cout << std::endl;

        }
        else if (choice == 7) {
            std::cout << "공방 문을 닫습니다..." << std::endl;
            break;

        }
        else {
            std::cout << "잘못된 선택입니다. 다시 시도하세요." << std::endl;
        }
    }

    return 0;
}