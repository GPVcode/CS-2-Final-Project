#ifndef DEBT_H
#define DEBT_H

class Debts
{
protected:
    float totalDebt;
    double interestRate;
public:
    Debts(float initialDebt, double initialInterest) : totalDebt(initialDebt), interestRate(initialInterest){}; // constructor

    virtual ~Debts(){}; // Virtual destructor for proper cleanup in derived classes

    // Getter functions
    // Public virtual methods for overriding
    virtual float getTotalDebt() const {
        return totalDebt;
    };
    virtual double getInterestRate() const {
        return interestRate;
    }

    // Getter Functions
    virtual void setTotalDebt(int newDebt) {
        totalDebt = newDebt;
    };
    virtual void setInterestRate(double rate) {
        interestRate = rate;
    }
};

#endif
// I need to see how much it costs if I paid x amount a month on my credit card.
    // debt class - totalDebt amount, interest rate,
// How long would it take to pay down using x payment amounts if my deTimbt grows in interest at n percent.

// I need to see how much I'd save if I put x amount monthly in an account returning at an n percent yield.
