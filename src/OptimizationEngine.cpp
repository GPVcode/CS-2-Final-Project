#include "../include/OptimizationEngine.h"
#include <iostream>
#include <algorithm>
#include <cmath>

OptimizationEngine::OptimizationEngine(std::vector<Debt*> debtsList, InvestmentsFund* fund, EmergencyFund* eFund, double income) 
    : debts(debtsList), investmentsFund(fund), emergencyFund(eFund), disposableIncome(income) {};


// Calculate potential interest savings by paying off a debt over a set period
double OptimizationEngine::calculateInterestSavings(const Debt* debt, int commonPeriod) const {
    double principal = debt->getPrincipal(); // get amount of debt
    double rate = debt->getInterestRate() / 12; // get the annual interest rate

    // Interest savings formula
    return principal * (rate / (1 - pow(1 + rate, -commonPeriod)));
}

// Calculate the net present value of expected investment returns
// double OptimizationEngine::calculateNPVofInvestment(int commonPeriod) const{
//     double totalInvestment = investmentsFund->getTotalAmount();
//     double avgReturnRate = investmentsFund->getAverageReturnRate() / 12;

//     // net present value
//     double npv = 0.0;

//     for (int t = 1; t <= commonPeriod; ++t) {
//         npv += totalInvestment / pow(1 + avgReturnRate, t);
//     }
//     return npv;
// }

// Calculate expected growth on new contributions based on average return rate
double OptimizationEngine::calculateExpectedReturn(double contribution, int commonPeriod) const {
    double avgReturnRate = investmentsFund->getAverageReturnRate() / 12; // Monthly rate for consistency
    double projectedGrowth = 0.0;

    // Project the growth of the new contribution over the period
    for (int t = 1; t <= commonPeriod; ++t) {
        projectedGrowth += contribution * pow(1 + avgReturnRate, t);
    }
    return projectedGrowth - contribution; // Only return the growth amount
}

void OptimizationEngine::suggestOptimalAllocation(int comparisonPeriod) {
    double initialDisposableIncome = disposableIncome; // Store initial disposable income for summary
    double emergencyFundAllocation = 0.0;
    double debtAllocation = 0.0;
    double avgReturnRate = investmentsFund->getAverageReturnRate();
    bool debtPriority = false;

    // Step 1: Emergency Fund Priority
    if (emergencyFund->getTotalAmount() < emergencyFund->getTargetGoal()) {
        emergencyFundAllocation = disposableIncome * 0.2;
        std::cout << "Allocate $" << emergencyFundAllocation << " to emergency fund to reach goal." << std::endl;
        disposableIncome -= emergencyFundAllocation;
    }

    // Step 2: Debt vs. Investment Allocation
    for (size_t i = 0; i < debts.size(); ++i) {
        double debtInterestRate = debts[i]->getInterestRate();

        if (debtInterestRate > avgReturnRate) {
            debtAllocation = disposableIncome;
            std::cout << "Debt priority: Allocate $" << debtAllocation 
                      << " to pay off high-interest debt with interest rate " << debtInterestRate 
                      << "% over average investment return of " << avgReturnRate << "%." << std::endl;
            disposableIncome = 0;
            debtPriority = true;
            break;
        }
    }

    if (!debtPriority && disposableIncome > 0) {
        std::cout << "Investment priority: Allocate $" << disposableIncome 
                  << " to investments with expected return of " << avgReturnRate << "%." << std::endl;
    }

    // Final Summary
    std::cout << "\n=== Monthly Money Management Summary ===\n";
    std::cout << "Total Monthly Disposable Income: $" << initialDisposableIncome << "\n";
    std::cout << "Emergency Fund Contribution: $" << emergencyFundAllocation 
              << " (to reach a 6-months-of-expenses goal)\n";

    if (debtPriority) {
        std::cout << "Debt Repayment Allocation: $" << debtAllocation 
                  << " (selected due to high-interest rate exceeding average investment returns)\n";
    } else {
        std::cout << "Investment Allocation: $" << disposableIncome 
                  << " (selected due to higher projected returns over debt interest)\n";
    }
    std::cout << "\nExplanation: Based on your inputs, the app prioritized " 
              << (debtPriority ? "debt repayment" : "investments") 
              << " because the " << (debtPriority ? "interest rate on your debt" : "expected return on investments") 
              << " is greater, optimizing your monthly disposable income allocation.\n";
}


// void OptimizationEngine::suggestOptimalAllocation(int comparisonPeriod) {
//     // Step 1: Emergency Fund Priority
//     if (emergencyFund->getTotalAmount() < emergencyFund->getTargetGoal()) {
//         double emergencyFundAllocation = disposableIncome * 0.2;
//         std::cout << "Allocate $" << emergencyFundAllocation << " to emergency fund to reach goal." << std::endl;
//         disposableIncome -= emergencyFundAllocation;
//     }

//     // Step 2: Prioritize high-interest debts vs. investments over the same period
//     for (size_t i = 0; i < debts.size(); ++i) {
//         double interestSavings = calculateInterestSavings(debts[i], comparisonPeriod);
//         double investmentNPV = calculateNPVofInvestment(comparisonPeriod);
//         std::cout << "INTEREST SAVINGS: " << interestSavings << std::endl;
//         std::cout << "Net Present Value: " << investmentNPV << std::endl;

//         if (interestSavings > investmentNPV) {
//             std::cout << "Allocate remaining $" << disposableIncome << " to pay off high-interest debt: " << debts[i]->getPrincipal() << std::endl;
//             disposableIncome = 0;
//             break;
//         } else {
//             std::cout << "Allocate $" << disposableIncome << " to investments for growth." << std::endl;
//             disposableIncome = 0;
//             break;
//         }
//     }

//     // Step 3: Remaining balance to investments if disposableIncome remains
//     if (disposableIncome > 0) {
//         std::cout << "Allocate remaining $" << disposableIncome << " to investments." << std::endl;
//     }
// }
