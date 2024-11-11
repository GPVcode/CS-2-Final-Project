#ifndef DEBT_H
#define DEBT_H

#include <iostream>

class Debt
{
protected:
    double principal;
    double interestRate;
public:
    Debt(double principalInput = 0.0, double rateInput = 0.0) : principal(principalInput), interestRate(rateInput){}; // constructor

    virtual ~Debt(){}; // Virtual destructor for proper cleanup in derived classes

    // no reason for get principal to be overriden
    double getPrincipal() const {
        return principal;
    };

    virtual double calculateInterest() const {
        return principal * (interestRate / 100);
    };
};

#endif
// I need to see how much it costs if I paid x amount a month on my credit card.
    // debt class - totalDebt amount, interest rate,
// How long would it take to pay down using x payment amounts if my deTimbt grows in interest at n percent.

// I need to see how much I'd save if I put x amount monthly in an account returning at an n percent yield.
