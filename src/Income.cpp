#include "../include/Income.h"
#include "../include/Expense.h"

// implementation file for income class
Income::Income(double totalIncomeInput) : totalIncome(totalIncomeInput){}

void Income::addExpense(const Expense& expense){
    expenses.push_back(expense);
}

double Income::calculateDisposableIncome() const {
    double totalExpenses = 0.0;
    for(size_t i = 0; i < expenses.size(); i++){
        totalExpenses += expenses[i].getAmount();
    }
    return totalIncome - totalExpenses;
}