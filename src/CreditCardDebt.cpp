#include "../include/CreditCardDebt.h"

CreditCardDebt::CreditCardDebt(double principalInput, double rateInput) : Debt(principalInput, rateInput){}

double CreditCardDebt::calculateMinimumPayment() const {
    return principal * 0.02;
}

double CreditCardDebt::calculateInterest() const {
    return principal * (interestRate / 100) / 12; // monthly interest rate calculation
}