#include <iostream>
#include <string>

#include "InvestmentsFund.h"

// Figure out most optimal strategy for paying down debts quickest and building your fund fastest.
// with this in mind, what is something we can start building?
    // inputting debt and interest rate

// WHat class template do we need?
    // Debts for all debts inputs
    // income for humans income
    // Debt algorithms

int main(){
    std::cout << "Welcome to the Good Grassroots Finanical Practice Tool. What would you like to do?" << std::endl;
    
    InvestmentsFund userFund(500.0);
    userFund.addPosition("Bond A", 1000.0, 4.0);
    userFund.addPosition("Stock A", 1500.0, 10.5);
    userFund.addPosition("Stock B", 500.0, 7.8);

    // Print the total amount to confirm it includes initial + added positions
    std::cout << "Total amount in fund after adding positions: " << userFund.getTotalAmount() << std::endl;
    // listing all positions
    userFund.listPositions();

    std::cout << std::endl;

    int years;
    std::cout << "Let's examine projected growth. Please enter years: ";
    std::cin >> years;

    std::cout << "Here is the projected growth rate for the given fund: " << std::endl;
    userFund.projectGrowth(years);


    return 0;
}
