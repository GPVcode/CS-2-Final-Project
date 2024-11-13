#include <iostream>
#include <vector>
#include <limits>

#include "../include/Income.h"
#include "../include/Expense.h"
#include "../include/AllocationCalculator.h"
#include "../include/Debt.h"
#include "../include/CreditCardDebt.h"
#include "../include/DebtStrategy.h"
#include "../include/InvestmentsFund.h"
#include "../include/EmergencyFund.h"
#include "../include/OptimizationEngine.h"

int main() {
    // Step 1: Income and Expense Setup
    std::cout << "=== Welcome to Grassroots Financial Planner ===" << std::endl;

    std::cout << "\n=== Income and Expense Setup ===" << std::endl;
    double monthlyIncome;
    std::cout << "Please enter your monthly income: ";
    std::cin >> monthlyIncome;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline from the input buffer

    Income userIncome(monthlyIncome);

    // Gather expense details
    std::cout << "Enter expenses (e.g., Rent, Utilities, Groceries):\n";
    std::string expenseName;
    double expenseAmount;

    std::cout << "Enter 'done' when finished adding expenses.\n";
    while (true) {
        std::cout << "Expense name: ";
        std::getline(std::cin, expenseName); // Allows for spaces in expense names
        if (expenseName == "done") break;

        std::cout << "Amount: ";
        std::cin >> expenseAmount;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
        userIncome.addExpense(Expense(expenseName, expenseAmount));
    }

    // Calculate disposable income
    double disposableIncome = userIncome.calculateDisposableIncome();
    std::cout << "Total disposable income after expenses: $" << disposableIncome << "\n\n";

    // Step 2: Emergency Fund Setup (Target Only) 
    int emergencyMonths;
    std::cout << "How many months of expenses should be saved for emergencies? ";
    std::cin >> emergencyMonths;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

    // Set emergency fund target without initial allocation
    EmergencyFund emergencyFund(0.0, userIncome.getExpenses() * emergencyMonths);

    // Step 3: Investment Fund Setup 
    std::cout << "\n=== Investment Fund Setup and Goal Progress ===\n";
    InvestmentsFund userFund(500.0); // Initial investment fund amount

    std::string investmentName;
    double investmentAmount, avgReturnRate;

    std::cout << "Enter investment positions (e.g., Stocks, Bonds):\n";
    std::cout << "Enter 'done' when finished adding investments.\n";
    while (true) {
        std::cout << "Investment name: ";
        std::getline(std::cin, investmentName); // Allows for spaces in investment names
        if (investmentName == "done") break;

        std::cout << "Amount: ";
        std::cin >> investmentAmount;
        std::cout << "Average return rate (%): ";
        std::cin >> avgReturnRate;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer -- prevents unwanted input from affecting the next input operation.

        userFund.addPosition(investmentName, investmentAmount, avgReturnRate);
    }

    std::cout << "Total in investment fund: $" << userFund.getTotalAmount() << "\n\n";

    // Step 4: Debt Setup
    std::cout << "=== Debt Setup and Repayment Strategy ===\n";
    std::vector<Debt*> debts;
    std::string debtName;
    double debtPrincipal, debtInterestRate;

    std::cout << "Enter debts (e.g., Credit Card, Student Loan):\n";
    std::cout << "Enter 'done' when finished adding debts.\n";
    while (true) {
        std::cout << "Debt name: ";
        std::getline(std::cin, debtName); // Allows for spaces in debt names
        if (debtName == "done") break;

        std::cout << "Principal: ";
        std::cin >> debtPrincipal;
        std::cout << "Interest rate (%): ";
        std::cin >> debtInterestRate;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer -- prevents unwanted input from affecting the next input operation.

        if (debtName == "CreditCard") {
            debts.push_back(new CreditCardDebt(debtPrincipal, debtInterestRate));
        } else {
            debts.push_back(new Debt(debtPrincipal, debtInterestRate));
        }
    }

    // Step 5: Optimization Engine for Optimal Allocation 
    int comparisonPeriod = 12; // 1-year period for comparison

    OptimizationEngine optimizer(debts, &userFund, &emergencyFund, disposableIncome);
    optimizer.suggestOptimalAllocation(comparisonPeriod);

    // Cleanup dynamically allocated debts
    for (Debt* debt : debts) {
        delete debt;
    }

    std::cout << "\n=== Program Completed ===\n";
    return 0;
}
