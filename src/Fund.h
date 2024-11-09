#ifndef FUND_H // make sure FUND_H isn't already defined
#define FUND_H // define Fund header

#include <iostream>

class Fund
{
protected:
    // Holds realtime value for fund. Can be influced thru other classes.
    double totalAmount;

public:
    Fund(double totalAmountInput = 0.0) : totalAmount(totalAmountInput){}
    
    // virtual destructor for Fund derived classes
    virtual ~Fund(){};

    // In most cases will be called after a change is made to get funding up to date; unless showing a preview (TODO).
    virtual void setTotalAmount() = 0; // pure virtual function. must be implemented by all derived classes.

    virtual double getTotalAmount() const {
        return totalAmount;
    }

    // deposit method: make sure the amount being deposit is greater than 0
    void deposit(double amount){
        if(amount > 0){
          totalAmount += amount;
          std::cout << "Deposit Successful." << std::endl;
        } 
    }

    bool withdraw(double amount){
        // to withdraw, the amount withdrawn must be greater than 0 and less than total amount in fund.
        if(amount > 0 && amount <= totalAmount){
            totalAmount -= amount;
            return true;
        } else {
          std::cout << "Withdrawal failed: insufficient funds or invalid amount." << std::endl;
          return false;
        }
    }
};

#endif


// // What would happen if it were to go negative on preview changes. "Game-ify" it so that it makes it clear that it should not be done.
// // If not previewing, at all times should update funding types immediately.
// // Should have an associated score that is relative to percentages and types of investment. User should set targets beforehand on these so that
// // an end goal stays in mind and is displayed throughout.