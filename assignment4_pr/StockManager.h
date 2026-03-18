#ifndef STOCK_MANAGER_H
#define STOCK_MANAGER_H

#include <map>
#include <string>

class StockManager {
private:
    std::map<std::string, int> stock;
    int initialStockVal = 3;

public:
    void InitialStock(const std::string& name);
    void PrintStock(const std::string& name) const;
    void ReturnPotion(const std::string& name);
    void givePotion(const std::string& name);
    void addPotionVal(const std::string& name, int amount);
};

#endif