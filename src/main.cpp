#include <iostream>
#include <vector>
#include "Income.h"
#include "Expense.h"
#include "AllocationCalculator.h"
#include "Debt.h"
#include "CreditCardDebt.h"
#include "DebtStrategy.h"
#include "InvestmentsFund.h"
#include "EmergencyFund.h"

int main() {
    // SECTION 1: Income and Expense Setup
    std::cout << "=== Income and Expense Setup ===" << std::endl;
    Income userIncome(5000.0);
    userIncome.addExpense(Expense("Rent", 1500.0));
    userIncome.addExpense(Expense("Utilities", 300.0));
    userIncome.addExpense(Expense("Groceries", 400.0));

    double disposableIncome = userIncome.calculateDisposableIncome();
    std::cout << "Total disposable income after expenses: $" << disposableIncome << std::endl;

    // SECTION 2: Emergency Fund Setup
    std::cout << "\n=== Emergency Fund Setup ===" << std::endl;
    EmergencyFund emergencyFund(0.0, userIncome.getExpenses() * 3.0); // Initial amount of $0, target goal of $6000

    // Allocate 20% of disposable income to the emergency fund
    double emergencyFundAllocation = disposableIncome * 0.2;
    std::cout << "Suggested allocation to emergency fund: $" << emergencyFundAllocation << std::endl;
    emergencyFund.contribute(emergencyFundAllocation);

    // Recalculate remaining disposable income after emergency fund contribution
    disposableIncome -= emergencyFundAllocation;
    std::cout << "Remaining disposable income after emergency fund allocation: $" << disposableIncome << std::endl;

    // SECTION 3: Allocation Calculation for Debt and Investment
    std::cout << "\n=== Allocation Calculation for Debt and Investment ===" << std::endl;
    AllocationCalculator allocator(0.5, 0.5, 10000.0, &emergencyFund); // Set 50/50 allocation, $10,000 investment goal
    
    double debtAllocation = allocator.calculateDebtAllocation(disposableIncome);
    double investmentAllocation = allocator.calculateInvestmentAllocation(disposableIncome);
    std::cout << "Suggested allocation to debt: $" << debtAllocation << std::endl;
    std::cout << "Suggested allocation to investment: $" << investmentAllocation << std::endl;

    // SECTION 4: Investment Fund Setup and Goal Progress
    std::cout << "\n=== Investment Fund Setup and Goal Progress ===" << std::endl;
    InvestmentsFund userFund(500.0); // Initial amount in investments
    userFund.addPosition("Stock A", 1000.0, 8.0); // Example investment position
    
    std::cout << "Initial total in investment fund: $" << userFund.getTotalAmount() << std::endl;
    allocator.updateInvestmentProgress(userFund); // Check if the investment goal is reached

    // Test dynamic adjustment of allocation if investment goal isn't met
    allocator.adjustAllocationForGoal(); // Adjust allocation if goal isn't reached

    std::cout << "Adjusted debt allocation: $" << allocator.calculateDebtAllocation(disposableIncome) << std::endl;
    std::cout << "Adjusted investment allocation: $" << allocator.calculateInvestmentAllocation(disposableIncome) << std::endl;

    // SECTION 5: Debt Setup and Repayment Strategies
    std::cout << "\n=== Debt Setup and Repayment Strategy ===" << std::endl;
    std::vector<Debt*> debts;
    debts.push_back(new CreditCardDebt(1000, 15.0)); // Credit card debt example
    debts.push_back(new Debt(5000, 8.5));            // Personal loan example

    DebtStrategy debtStrategy(debts);
    std::cout << "\nDebt Snowball Strategy Payments:" << std::endl;
    debtStrategy.calculateSnowballPayments(debtAllocation); // Execute Snowball strategy

    std::cout << "\nDebt Avalanche Strategy Payments:" << std::endl;
    debtStrategy.calculateAvalanchePayments(debtAllocation); // Execute Avalanche strategy

    // Cleanup dynamically allocated debts
    for (Debt* debt : debts) {
        delete debt;
    }

    std::cout << "\n=== Program Completed ===" << std::endl;
    return 0;
}
