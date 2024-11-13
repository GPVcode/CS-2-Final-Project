#ifndef DEBTMANAGER_H
#define DEBTMANAGER_H

#include <iostream>
#include <vector>
#include "Debt.h"

// Debt subclass to manage integral methods used often by debt objects
class DebtManager{
private:
    std::vector<Debt*> debts; // we'll use a pointer to maintain unique characteristics of each Debt object stored in our vector

public:
    DebtManager();
    // delete all dynamically allocated debts to prevent memory leaks
    ~DebtManager();

    void addDebt(Debt* debt);
    void listDebts() const; // list out all debts
    double calculateTotalDebt() const;
    double calculateTotalInterest() const;

    // Getter to access the vector of debts
    std::vector<Debt*> getDebts() const { return debts; }

};
#endif