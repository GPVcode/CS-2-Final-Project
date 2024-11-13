#ifndef ALLOCATIONCALCULATOR_H
#define ALLOCATIONCALCULATOR_H

#include "InvestmentsFund.h"
#include "Income.h"
#include "EmergencyFund.h"

// Calculates how much would go into either debt or investment based on user's allocation ratio and disposable income provided by Income class.git

class AllocationCalculator{
private:
    double debtPercentage;
    double investmentPercentage;

    double investmentGoal;
    double currentInvestmentProgress;

    EmergencyFund* emergencyFund; // Pointer to an EmergencyFund object


public:
    // construcore allowing customizable allocation ratios
    AllocationCalculator(double debtRatio, double investmentRatio, double investmentGoal, EmergencyFund* emergencyFund);
    
    // Calculate allocation for debts - how much to put towards debts
    double calculateDebtAllocation(double disposableIncome) const;
    
    // Calculate allocation for investment - how much to put towards investments
    double calculateInvestmentAllocation(double disposableIncome) const;

    // Track investment progress using total from InvestmentsFund
    void updateInvestmentProgress(const InvestmentsFund& fund);

    void contributeToEmergencyFund(double amount) const;

    // Adjust allocation percentages dynamically based on goal progress
    void adjustAllocationForGoal();

};
#endif