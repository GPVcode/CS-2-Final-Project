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
    double emergencyFundAllocation = 0.0;
    double debtAllocation = 0.0;
    double avgReturnRate = investmentsFund->getAverageReturnRate() / 12; // Monthly rate
    bool debtPriority = false;

    // Step 1: Emergency Fund Allocation with Monthly Projection
    if (emergencyFund->getTotalAmount() < emergencyFund->getTargetGoal()) {
        emergencyFundAllocation = disposableIncome * 0.2;
        std::cout << "\n=== Emergency Fund Allocation ===\n";
        std::cout << "Allocating $" << emergencyFundAllocation << " per month to reach your emergency fund goal." << std::endl;
        disposableIncome -= emergencyFundAllocation;

        double currentEmergencyFund = emergencyFund->getTotalAmount();
        double targetEmergencyFund = emergencyFund->getTargetGoal();
        int monthsNeeded = 0;
        
        std::cout << "\nMonthly Emergency Fund Projection:\n";
        while (currentEmergencyFund < targetEmergencyFund) {
            monthsNeeded++;
            currentEmergencyFund += emergencyFundAllocation;
            std::cout << "Month " << monthsNeeded << ": Emergency Fund Balance: $" << currentEmergencyFund << std::endl;
        }
        std::cout << "It will take " << monthsNeeded << " months to reach the emergency fund goal of $" << targetEmergencyFund << "." << std::endl;
    }

    // Step 2: Debt vs. Investment Allocation
    std::cout << "\n=== Optimal Allocation Suggestion ===\n";
    for (size_t i = 0; i < debts.size(); ++i) {
        double debtInterestRate = debts[i]->getInterestRate() / 12; // Monthly rate
        if (debtInterestRate * 12 > avgReturnRate * 12) {
            debtAllocation = disposableIncome;
            std::cout << "Debt Priority: Allocating $" << debtAllocation 
                      << " monthly to high-interest debt (rate: " << debtInterestRate * 12 
                      << "%) over investments with expected return of " << avgReturnRate * 12 << "%." << std::endl;
            disposableIncome = 0;
            debtPriority = true;

    std::cout << "\nMonthly Debt Repayment Projection:\n";
    double remainingPrincipal = debts[i]->getPrincipal();
    double monthlyInterestRate = debts[i]->getInterestRate() / 12 / 100; // Divide APR by 12 and convert to decimal

    bool insufficientFundsWarningShown = false; // To show the warning only once

    for (int month = 1; month <= comparisonPeriod; ++month) {
        double interest = remainingPrincipal * monthlyInterestRate;
        double principalPayment = debtAllocation - interest;

        if (debtAllocation < interest && !insufficientFundsWarningShown) {
            std::cout << "Warning: Monthly allocation of $" << debtAllocation 
                    << " is insufficient to cover interest on debt of $" 
                    << remainingPrincipal << ". The debt may grow without a higher payment.\n";
            insufficientFundsWarningShown = true; // Only show this warning once
        }

        // If allocation is enough to cover interest
        if (principalPayment > 0) {
            remainingPrincipal -= principalPayment;
        } else {
            // If allocation is less than interest, debt grows
            remainingPrincipal += interest;
        }

        std::cout << "Month " << month << ": Remaining Debt: $" << remainingPrincipal 
                << ", Interest Paid: $" << interest 
                << ", Principal Paid: $" << (principalPayment > 0 ? principalPayment : 0.0) << std::endl;

        if (remainingPrincipal <= 0) {
            std::cout << "Debt fully paid off in " << month << " months.\n";
            break;
        }
    }

            break;
        }
    }

    // If no high-interest debt, suggest investing remaining disposable income
    if (!debtPriority && disposableIncome > 0) {
        std::cout << "\nInvestment Priority: Allocating $" << disposableIncome 
                  << " monthly to investments with expected return of " << avgReturnRate * 12 << "%." << std::endl;

        // Monthly investment growth projection
        double investmentValue = disposableIncome;
        std::cout << "\nMonthly Investment Growth Projection:\n";
        for (int month = 1; month <= comparisonPeriod; ++month) {
            investmentValue += investmentValue * avgReturnRate;
            std::cout << "Month " << month << ": Investment Value: $" << investmentValue << std::endl;
        }
    }

    // Final Summary
    std::cout << "\n=== Monthly Money Management Summary ===\n";
    std::cout << "Total Monthly Disposable Income: $" << initialDisposableIncome << std::endl;
    std::cout << "Emergency Fund Contribution: $" << emergencyFundAllocation 
              << " (to reach a 6-months-of-expenses goal)" << std::endl;

    if (debtPriority) {
        std::cout << "Debt Repayment Allocation: $" << debtAllocation 
                  << " (selected due to high-interest rate exceeding average investment returns)" << std::endl;
    } else {
        std::cout << "Investment Allocation: $" << disposableIncome 
                  << " (selected due to higher projected returns over debt interest)" << std::endl;
    }
    std::cout << "\nExplanation: Based on your inputs, the app prioritized " 
              << (debtPriority ? "debt repayment" : "investments") 
              << " because the " << (debtPriority ? "interest rate on your debt" : "expected return on investments") 
              << " is greater, optimizing your monthly disposable income allocation." << std::endl;
}
