#ifndef EMERGENCYFUND_H
#define EMERGENCYFUND_H

#include "Fund.h"
#include <iostream>

// Emergency fund class 
class EmergencyFund : public Fund {
private:
    double targetGoal;
public:
    EmergencyFund(double initialAmount, double target) : Fund(initialAmount), targetGoal(target) {}
    // Set a new target goal
    void setTargetGoal(double target) { targetGoal = target; }

    double getTargetGoal() const { return targetGoal; }

    // Add contributions toward the emergency fund
    void contribute(double amount) {
        if (amount > 0) {
            totalAmount += amount;
            std::cout << "Added $" << amount << " to the emergency fund. Total: $" << totalAmount << std::endl;
            checkGoalStatus();
        }
    }

    // Check if the target goal is reached
    void checkGoalStatus() const {
        if (totalAmount >= targetGoal) {
            std::cout << "Congratulations! You've reached your emergency fund goal of $" << targetGoal << "!" << std::endl;
        } else {
            std::cout << "Emergency fund progress: $" << totalAmount << " / $" << targetGoal << std::endl;
        }
    }
};

#endif