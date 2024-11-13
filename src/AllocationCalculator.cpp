#include "../include/AllocationCalculator.h"
#include "../include/InvestmentsFund.h"
#include <iostream>

// Constructor allowing customizable allocation ratios for debt and investment.
AllocationCalculator::AllocationCalculator(double debtRatio, double investmentRatio, double investmentGoal, EmergencyFund* emergencyFund) 
    : debtPercentage(debtRatio), investmentPercentage(investmentRatio), investmentGoal(investmentGoal), currentInvestmentProgress(0.0), emergencyFund(emergencyFund){}


double AllocationCalculator::calculateDebtAllocation(double disposableIncome) const {
        return disposableIncome * debtPercentage;
    }
double AllocationCalculator::calculateInvestmentAllocation(double disposableIncome) const {
    return disposableIncome * investmentPercentage;
}

void AllocationCalculator::updateInvestmentProgress(const InvestmentsFund& fund) {
    currentInvestmentProgress = fund.getTotalAmount();
    if (currentInvestmentProgress >= investmentGoal) {
        std::cout << "Congratulations! Investment goal of $" << investmentGoal 
                  << " has been reached." << std::endl;
        }
}

// Contribute to the emergency fund
void AllocationCalculator::contributeToEmergencyFund(double amount) const {
    if (emergencyFund) {
        emergencyFund->contribute(amount);
    } else {
        std::cout << "Emergency fund not set." << std::endl;
    }
}

void AllocationCalculator::adjustAllocationForGoal() {
    // ensure investment goal is greater than 0 and check if current investment is still below goal
    if (investmentGoal > 0 && currentInvestmentProgress < investmentGoal) {
        debtPercentage = 0.4;          // Adjusted allocation for goal
        investmentPercentage = 0.6;
    }
}
