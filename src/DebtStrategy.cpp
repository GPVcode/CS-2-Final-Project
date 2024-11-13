#include "../include/DebtStrategy.h"
#include <iostream>
#include <algorithm>

// constructor
DebtStrategy::DebtStrategy(const std::vector<Debt*>& debtList) : debts(debtList){}

// destructor
DebtStrategy::~DebtStrategy(){
    // deleted in debtmanager already can leave this empty
}

// comparison helper function to use along with sort function provided by algorithm object
bool compareByPrincipal(Debt* a, Debt* b){
    // Returns true if a's principal is smaller than b's
    return a->getPrincipal() < b->getPrincipal();
}

// Debt Snowball: Pays off smallest debts first
// we create a copy of the debt list and reordeer it using sort method from smallest to bigges.
void DebtStrategy::calculateSnowballPayments(double monthlyAllocation) const{
    std::vector<Debt*> sortedDebts = debts;
    // sorts from begining to the end using the compareByPricipal sort helper
    std::sort(sortedDebts.begin(), sortedDebts.end(), compareByPrincipal);

    double remainingAllocation = monthlyAllocation;

    std::cout << "Debt Snowball Payments:" << std::endl;
    for(size_t i = 0; i < sortedDebts.size(); i++){
        // ensures that payment is never more than the remaining allocation amount of the debt's principal balance.
        double payment = std::min(remainingAllocation, sortedDebts[i]->getPrincipal());
        remainingAllocation -= payment;
        std::cout << "Pay $" << payment << " towards debt with principal $" << sortedDebts[i]->getPrincipal() << std::endl;

        if (remainingAllocation <= 0) break; // Stop if allocation is used up
    }

}

bool compareByInterestRate(Debt* a, Debt* b){
    // Returns true if a's interest rate is higher than b's for avalanche strategy
    return a->getInterestRate() > b->getInterestRate();
}

// Debt Avalanche: Pays off highest-interest debts first
void DebtStrategy::calculateAvalanchePayments(double monthlyAllocation) const{
    std::vector<Debt*> sortedDebts = debts;
    std::sort(sortedDebts.begin(), sortedDebts.end(), compareByInterestRate);

    double remainingAllocation = monthlyAllocation;

    std::cout << "Debt Avalanche Payments:" << std::endl;
    for(size_t i = 0; i < sortedDebts.size(); i++){
        // ensures that payment is never more than the remaining allocation amount of the debt's principal balance.
        double payment = std::min(remainingAllocation, sortedDebts[i]->getPrincipal());
        remainingAllocation -= payment;
        std::cout << "Pay $" << payment << " towards debt with principal $" 
            << sortedDebts[i]->getPrincipal() << " at interest rate " 
            << sortedDebts[i]->getInterestRate() << "%" << std::endl;

        if (remainingAllocation <= 0)break; // Stop if allocation is used up
    }
};