#include "../include/OptimizationEngine.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

OptimizationEngine::OptimizationEngine(std::vector<Debt*> debtsList, InvestmentsFund* fund, EmergencyFund* eFund, double income) 
    : debts(debtsList), investmentsFund(fund), emergencyFund(eFund), disposableIncome(income) {};

// Calculate potential interest savings by paying off a debt over a set period
double OptimizationEngine::calculateInterestSavings(const Debt* debt, int commonPeriod) const {
    double principal = debt->getPrincipal(); // get amount of debt
    double rate = debt->getInterestRate() / 12; // get the annual interest rate

    // Interest savings formula - Interest Savings = Principal x (Rate/(1-(1+Rate)^-period))
    return principal * (rate / (1 - pow(1 + rate, -commonPeriod)));
}

// Calculate expected growth on new contributions based on average return rate
double OptimizationEngine::calculateExpectedReturn(double contribution, int commonPeriod) const {
    double avgReturnRate = investmentsFund->getAverageReturnRate() / 12; // Monthly rate for consistency
    double projectedGrowth = 0.0;

    // Project the growth of the new contribution over the period - Future Value = Contribution x (1+Rate)^t
    for (int t = 1; t <= commonPeriod; ++t) {
        projectedGrowth += contribution * pow(1 + avgReturnRate, t);
    }
    return projectedGrowth - contribution; // Only return the growth amount
}

void OptimizationEngine::suggestOptimalAllocation(int comparisonPeriod) {
    std::cout << std::fixed << std::setprecision(2);

    double initialDisposableIncome = disposableIncome;
    double emergencyFundAllocation = disposableIncome * 0.2;
    double debtAllocation = disposableIncome * 0.8; // 80% allocated to debt initially
    double avgReturnRate = investmentsFund->getAverageReturnRate() / 12 / 100; // Monthly return rate as decimal
    bool debtPaidOff = false;
    int loopCounter = 0;

    // Emergency Fund Setup with Monthly Projection
    std::cout << "\n=== Emergency Fund Allocation ===\n";
    std::cout << "Allocating $" << emergencyFundAllocation << " per month to reach your emergency fund goal.\n";
    double currentEmergencyFund = emergencyFund->getTotalAmount();
    double targetEmergencyFund = emergencyFund->getTargetGoal();
    int monthCount = 0;

    std::cout << "Monthly Emergency Fund Projection:\n";
    while (currentEmergencyFund < targetEmergencyFund) {
        monthCount++;
        currentEmergencyFund += emergencyFundAllocation;
        std::cout << "Month " << monthCount << ": Emergency Fund Balance: $" << currentEmergencyFund << std::endl;
    }
    std::cout << "It will take " << monthCount << " months to reach the emergency fund goal of $" << targetEmergencyFund << std::endl;

    // Deduct Emergency Fund allocation from disposable income
    disposableIncome -= emergencyFundAllocation;

    // Debt Repayment and Reallocation Logic with Monthly Projection
    std::cout << "\n=== Optimal Allocation Suggestion ===\n";
    for (int i = 0; i < debts.size(); i++) {
        if (debts[i]->getPrincipal() > 0) {
            double monthlyInterestRate = debts[i]->getInterestRate() / 12 / 100;
            double interest = debts[i]->getPrincipal() * monthlyInterestRate;
            double principalPayment = debtAllocation - interest;

            std::cout << "Monthly Debt Repayment Projection" << std::endl;
            monthCount = 0;
            while (debts[i]->getPrincipal() > 0) {
                monthCount++;
                interest = debts[i]->getPrincipal() * monthlyInterestRate;
                principalPayment = debtAllocation - interest;

                if (principalPayment >= debts[i]->getPrincipal()) {
                    principalPayment = debts[i]->getPrincipal();
                    debts[i]->setPrincipal(0); // Debt fully paid off
                    debtPaidOff = true;
                } else {
                    debts[i]->updatePrincipal(principalPayment); // Reduce principal by payment amount
                }

                std::cout << "Month " << monthCount << ": Remaining Debt: $" << debts[i]->getPrincipal()
                          << ", Interest Paid: $" << interest
                          << ", Principal Paid: $" << (principalPayment > 0 ? principalPayment : 0.0) << std::endl;

                if (debtPaidOff) {
                    std::cout << "Debt fully paid off in " << monthCount << " months.\n";
                    debtPaidOff = false;
                    break;
                }
            }
            loopCounter++;
        }
    }

    // Investment Allocation once debts are cleared
    if (loopCounter == debts.size()) {
        double investmentAllocation = disposableIncome;
        std::cout << "\nSwitching to Investment Allocation after debt is paid.\n";
        std::cout << "Allocating $" << investmentAllocation << " monthly to investments with an expected return of " << avgReturnRate * 12 * 100 << "%.\n";

        double investmentValue = investmentsFund->getTotalAmount();
        std::cout << "\nMonthly Investment Growth Projection:\n";
        for (int month = 1; month <= comparisonPeriod; ++month) {
            investmentValue += investmentAllocation; // Add monthly contribution
            investmentValue *= (1 + avgReturnRate); // Apply monthly growth rate
            std::cout << "Month " << month << ": Investment Value: $" << investmentValue << std::endl;
        }
    }

    // Final Summary
    std::cout << "\n=== Monthly Money Management Summary ===\n";
    std::cout << "Total Monthly Disposable Income: $" << initialDisposableIncome << std::endl;
    std::cout << "Emergency Fund Contribution: $" << emergencyFundAllocation << " (to reach a " << monthCount << "-month goal)\n";
    std::cout << (debtPaidOff ? "Investment Allocation: $" : "Debt Repayment Allocation: $") << (debtPaidOff ? disposableIncome : debtAllocation) << std::endl;
}
