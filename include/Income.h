#ifndef INCOME_H
#define INCOME_H

#include <vector>
#include "Expense.h"

class Income {
private:
    double totalIncome;
    std::vector<Expense> expenses;
public:
    Income(double totalIncomeInput);

    void addExpense(const Expense& expense);
    double calculateDisposableIncome() const;
    double getExpenses() const;
};

#endif