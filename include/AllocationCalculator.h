#ifndef ALLOCATIONCALCULATOR_H
#define ALLOCATIONCALCULATOR_H

//Calculates how much would go into either debt or investment based on user's allocation ratio and disposable income provided by Income class.git
class AllocationCalculator{
private:
    double debtPercentage;
    double investmentPercentage;
public:
    // construcore allowing customizable allocation ratios
    AllocationCalculator(double debtRatio = 0.5, double investmentRatio = 0.5)
        : debtPercentage(debtRatio), investmentPercentage(investmentRatio) {}

    // Calculate allocation for debt
    double calculateDebtAllocation(double disposableIncome) const {
        return disposableIncome * debtPercentage;
    }

    // Calculate allocation for investment
    double calculateInvestmentAllocation(double disposableIncome) const {
        return disposableIncome * investmentPercentage;
    }
};

#endif