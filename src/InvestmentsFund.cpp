#include "Fund.h"
#include <iostream>

// methods inherited by this class:
    // - getTotalAmount
    // - deposit - add funds to investments
    // - withdraw - withdraw funds

class InvestmentsFund : public Fund {
public:
    // Constructor for DerivedClass passes arguments to BaseClass constructor
    InvestmentsFund(double investmentsAmount)
        : Fund(investmentsAmount) {}

};