#ifndef OPTIMIZATIONENGINE_H
#define OPTIMIZATIONENGINE_H

#include <vector>
#include "Debt.h"
#include "InvestmentsFund.h"
#include "EmergencyFund.h"

class OptimizationEngine {
private:
    std::vector<Debt*> debts;
    InvestmentsFund* investmentsFund;
    EmergencyFund* emergencyFund;
    double disposableIncome;

    // helpers for formula based calculations
    double calculateInterestSavings(const Debt* debt, int commonPeriod) const;
    // double calculateNPVofInvestment(int commonPeriod) const;
    double calculateExpectedReturn(double contribution, int commonPeriod) const;


public:
    // Constructor
    OptimizationEngine(std::vector<Debt*> debtsList, InvestmentsFund* fund, EmergencyFund* eFund, double disposableIncome);

    // Method to suggest optimal allocation
    void suggestOptimalAllocation(int comparisonPeriod);

};

#endif