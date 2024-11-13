#include "../include/DebtManager.h"

DebtManager::DebtManager(){}

DebtManager::~DebtManager() {
    for(size_t i = 0; i < debts.size(); i++) {
        if (debts[i] != nullptr) {
            delete debts[i];
        }
    }
    debts.clear();
}

// add to collection of debts
void DebtManager::addDebt(Debt* debt){
    debts.push_back(debt);
}

// get a list of debts in collection
void DebtManager::listDebts() const {
    std::cout << "Listing all debts:" << std::endl;
    for(size_t i = 0; i < debts.size(); i++){
        std::cout << "Debt " << (i + 1) << " - Principal: $" << debts[i]->getPrincipal() << ", Interest Rate: $" << debts[i]->getInterestRate() << std::endl;
    }
}

// go through debts collection and accumulate the totals
double DebtManager::calculateTotalDebt() const {
    double total = 0.0;
    for(size_t i = 0; i < debts.size(); i++){
        total += debts[i]->getPrincipal();
    }
    return total;
}

// return total cost of the debt
double DebtManager::calculateTotalInterest() const {
    double totalInterest = 0.0;
    for(size_t i = 0; i < debts.size(); i++){
        totalInterest += debts[i]->calculateInterest();
    }
    return totalInterest;
}
