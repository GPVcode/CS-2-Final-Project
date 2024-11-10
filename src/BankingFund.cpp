#include "../include/Fund.h"

// methods inherited by this class:
    // - getTotalAmount
    // - deposit - add funds
    // - withdraw - withdraw funds
class BankingFund : public Fund {
    public:
        // constructor
        BankingFund(double initialAmount)
            : Fund(initialAmount){}
};