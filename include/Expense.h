#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>

// Expense class will simply hold the expense's name and amount
class Expense{
private:
    std::string name;
    double amount;
public:
    Expense(const std::string& nameInput, double amountInput) : name(nameInput), amount(amountInput){}

    double getAmount() const { return amount; }
    std::string getName() const { return name; }
};

#endif