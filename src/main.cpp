#include <iostream>
#include "../include/InvestmentsFund.h"
#include "../include/DebtManager.h"
#include "../include/CreditCardDebt.h"
#include "../include/Expense.h"
#include "../include/Income.h"
#include "../include/AllocationCalculator.h"
#include "../include/DebtStrategy.h"

int main() {

    // DebtManager debtManager;
    // debtManager.addDebt(new CreditCardDebt(1000, 15.0)); // Credit card debt
    // debtManager.addDebt(new Debt(5000, 8.5));            // Personal loan

    // debtManager.listDebts();
    // std::cout << "Total debt amount: $" << debtManager.calculateTotalDebt() << std::endl;
    // std::cout << "Total interest across all debts: $" << debtManager.calculateTotalInterest() << std::endl;


    // Setting up income and expenses
    std::cout << "=== Income and Expenses Setup ===" << std::endl;
    Income userIncome(5000.0); // Example total income

    // Adding fixed expenses
    userIncome.addExpense(Expense("Rent", 1500.0));
    userIncome.addExpense(Expense("Utilities", 300.0));
    userIncome.addExpense(Expense("Groceries", 400.0));

    // Calculate and display disposable income
    double disposableIncome = userIncome.calculateDisposableIncome();
    std::cout << "Total disposable income after expenses: $" << disposableIncome << std::endl;

    // Set up allocation calculator with default 50/50 ratios
    AllocationCalculator allocator;
    double debtAllocation = allocator.calculateDebtAllocation(disposableIncome);
    double investmentAllocation = allocator.calculateInvestmentAllocation(disposableIncome);

    // Display allocation results
    std::cout << "Suggested allocation to debt: $" << debtAllocation << std::endl;
    std::cout << "Suggested allocation to investment: $" << investmentAllocation << std::endl;

    // Setting up investments
    std::cout << "\n=== Investments Setup ===" << std::endl;
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

    // Debt payment strategy module
    std::cout << "\n=== Debt Repayment Strategies ===" << std::endl;
    
    // Use existing debts from DebtManager in DebtStrategy
    DebtStrategy debtStrategy(debtManager.getDebts());

    // Debt Snowball Strategy
    std::cout << "\nUsing Debt Snowball Strategy:" << std::endl;
    debtStrategy.calculateSnowballPayments(debtAllocation);

    // Debt Avalanche Strategy
    std::cout << "\nUsing Debt Avalanche Strategy:" << std::endl;
    debtStrategy.calculateAvalanchePayments(debtAllocation);


    return 0;
}
