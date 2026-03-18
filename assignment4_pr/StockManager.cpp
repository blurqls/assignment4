#include "StockManager.h"
#include <iostream>

void StockManager::InitialStock(const std::string& name) {
    stock[name] = initialStockVal;
}

// 1. 재고 출력 시 등록 여부 확인 추가
void StockManager::PrintStock(const std::string& name) const {
    auto it = stock.find(name);
    if (it != stock.end()) {
        std::cout << "남은 재고 : " << it->second << std::endl;
    }
    else {
        std::cout << ">> [안내] '" << name << "'은(는) 현재 등록되지 않은 물약입니다." << std::endl;
    }
}

// 2. 반납 시 등록 여부 확인 추가
void StockManager::ReturnPotion(const std::string& name) {
    auto it = stock.find(name);
    if (it == stock.end()) {
        std::cout << ">> [거절] '" << name << "'은(는) 우리 공방 물약이 아닙니다." << std::endl;
        return;
    }

    if (it->second >= initialStockVal) {
        std::cout << "해당 물약은 최대 재고(" << initialStockVal << ")에 도달했습니다." << std::endl;
    }
    else {
        addPotionVal(name, 1);
        std::cout << "모험가로부터 1개의 물약을 돌려받았습니다." << std::endl;
        PrintStock(name);
    }
}

// 3. 지급 시 등록 여부 확인 추가
void StockManager::givePotion(const std::string& name) {
    auto it = stock.find(name);
    if (it == stock.end()) {
        std::cout << ">> [오류] '" << name << "'의 레시피를 먼저 등록해주세요." << std::endl;
        return;
    }

    if (it->second >= 1) {
        addPotionVal(name, -1);
        PrintStock(name);
    }
    else {
        std::cout << ">> '" << name << "'의 재고가 부족하여 줄 수 없습니다." << std::endl;
    }
}

void StockManager::addPotionVal(const std::string& name, int amount) {
    stock[name] += amount;
}