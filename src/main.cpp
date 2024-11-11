#include <iostream>
#include <string>

#include "../include/InvestmentsFund.h"
#include "../include/DebtManager.h"
#include "../include/CreditCardDebt.h"

// Figure out most optimal strategy for paying down debts quickest and building your fund fastest.
// with this in mind, what is something we can start building?
    // inputting debt and interest rate

// WHat class template do we need?
    // Debts for all debts inputs
    // income for humans income
    // Debt algorithms

int main(){
    // Setting up investments
    std::cout << "=== Investments Setup ===" << std::endl;
    InvestmentsFund userFund(500.0);
    userFund.addPosition("Bond A", 1000.0, 4.0);
    userFund.addPosition("Stock A", 1500.0, 10.5);
    userFund.addPosition("Stock B", 500.0, 7.8);

    // Display investment details
    std::cout << "Total amount in fund after adding positions: $" << userFund.getTotalAmount() << std::endl;
    userFund.listPositions();

    // Project growth for a given period
    int years = 5; // Example: Project growth over 5 years
    std::cout << "\n=== Investment Growth Projection ===" << std::endl;
    userFund.projectGrowth(years);

    // Setting up debts
    std::cout << "\n=== Debts Setup ===" << std::endl;
    DebtManager debtManager;
    debtManager.addDebt(new CreditCardDebt(1000, 15.0)); // Credit card debt with 15% interest
    debtManager.addDebt(new Debt(5000, 8.5));            // Personal loan with 8.5% interest

    // Display debt details
    debtManager.listDebts();
    std::cout << "Total debt amount: $" << debtManager.calculateTotalDebt() << std::endl;
    std::cout << "Total interest across all debts: $" << debtManager.calculateTotalInterest() << std::endl;

    return 0;
}
