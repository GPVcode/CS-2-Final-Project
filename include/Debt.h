#ifndef DEBT_H
#define DEBT_H

#include <iostream>

// Debt Header class

class Debt
{
protected:
    double principal;
    double interestRate;
public:
    Debt(double principalInput, double rateInput) : principal(principalInput), interestRate(rateInput){}; // constructor

    virtual ~Debt(){}; // Virtual destructor for proper cleanup in derived classes

    // no reason for get principal to be overriden
    double getPrincipal() const {
        return principal;
    }

    // Get interest rate on a debt
    double getInterestRate() const { return interestRate; }

    // calculate cost of debt
    virtual double calculateInterest() const {
        return principal * (interestRate / 100);
    }

    // Establish debt amount
    void setPrincipal(double newPrincipal) {
        principal = newPrincipal;
    }

    // Update debt amount as result of payment payment
    void updatePrincipal(double amount) {
        principal -= amount;
        if (principal < 0) principal = 0; // So that principal doesn't go negative
    }
};

#endif
