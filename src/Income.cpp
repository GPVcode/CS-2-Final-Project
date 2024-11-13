#include "../include/Income.h"
#include "../include/Expense.h"

// implementation file for income class
Income::Income(double totalIncomeInput) : totalIncome(totalIncomeInput){}

// add expencse to expense collection
void Income::addExpense(const Expense& expense){
    expenses.push_back(expense);
}
// get the accumulation of expenses
double Income::getExpenses() const{
    double totalExpenses = 0.0;
    for(size_t i = 0; i < expenses.size(); i++){
        totalExpenses += expenses[i].getAmount();
    }
    return totalExpenses;
}

// Return the income availabel after expenses
double Income::calculateDisposableIncome() const {
    double totalExpenses = getExpenses();
    return totalIncome - totalExpenses;
}

