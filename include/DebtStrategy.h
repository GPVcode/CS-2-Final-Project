#ifndef DEBTSTRATEGY_H
#define DEBTSTRATEGY_H

#include "Debt.h"
#include <vector>

// Debt subclass for presenting projections using these popular debt payment strategies
class DebtStrategy{
private:
    std::vector<Debt*> debts;
public:
    // Take in list of debts in constructor
    DebtStrategy(const std::vector<Debt*>& debtList);

    // delete Debt object dynamically
    ~DebtStrategy();

    // Calculate payments based on Debt Snowball strategy
    void calculateSnowballPayments(double monthlyAllocation) const;

    // calculate payments based on Debt Avalanche strategy
    void calculateAvalanchePayments(double monthlyAllocation) const;
};

#endif