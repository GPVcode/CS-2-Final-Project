#ifndef INVESTMENTSFUND_H
#define INVESTMENTSFUND_H

#include "Fund.h"
#include <iostream>
#include <vector>
#include <string>

// holds details about each investment
struct InvestmentPosition {
    std::string name;
    double amount;
    double avgPerformance;

    InvestmentPosition(const std::string& name, double amount, double avgPerformance)
        : name(name), amount(amount), avgPerformance(avgPerformance){}
};


// Inherited methods from Fund.h :
    // - getTotalAmount
    // - deposit - add funds to investments
    // - withdraw - withdraw funds

class InvestmentsFund : public Fund {
private:
    std::vector<InvestmentPosition> positions;

public:
    // Constructor for DerivedClass passes arguments to BaseClass constructor
    InvestmentsFund(double initialInvestmentsAmount = 0.0);

    void addPosition(const std::string& name, double amount, double avgPerformance);
    void listPositions() const;
    void projectGrowth(int years) const;

};

#endif