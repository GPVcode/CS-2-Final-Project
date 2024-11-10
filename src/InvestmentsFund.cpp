#include "../include/InvestmentsFund.h"
#include <iostream>
#include <cmath>

// this is the implementation file for Investments fund

// Constructor implementation
InvestmentsFund::InvestmentsFund(double initialInvestmentsAmount) : Fund(initialInvestmentsAmount){}

// implementation for adding positions to your investments
void InvestmentsFund::addPosition(const std::string& name, double amount, double avgPerformance){
    InvestmentPosition position(name, amount, avgPerformance);
    positions.push_back(position);
    totalAmount += amount; // update totalamount in baseclass
};

// implementation to list positions in investment fund
void InvestmentsFund::listPositions() const{
    std::cout << "Listing all investment positions:" << std::endl;

    for(size_t i = 0; i < positions.size(); i++){
        const InvestmentPosition& position = positions[i];
        std::cout << "Name: " << position.name << ", Amount: " << position.amount << ", Average Performance: " << position.avgPerformance << "%" << std::endl;
    }
}

void InvestmentsFund::projectGrowth(int years) const {
    double projectedTotal = 0.0;

    for(size_t i = 0; i < positions.size(); i++){
        const InvestmentPosition& position = positions[i];
        // We re-create the Compound Interest Formula: Future Calue = Principal x (1 + Rate)^Time
            // This calculates the future value of an investment
        double futureValue = position.amount * pow(1 + (position.avgPerformance / 100), years);
        double change = futureValue - position.amount;

        std::cout << "Projected value of " << position.name << " after " << years << " years: $" << futureValue 
            << " (" << (change >= 0 ? "Increase: $" : "Decrease: $") 
                  << std::abs(change) << ")" << std::endl;
        
        projectedTotal += futureValue;
    }

    double initialTotal = getTotalAmount();
    double totalChange = projectedTotal - initialTotal;
    std::cout << "Total projected portfolio value after " << years << " years: $" 
        << projectedTotal << " (" << (totalChange >= 0 ? "Increase: $" : "Decrease: $") 
        << std::abs(totalChange) << ")" << std::endl;

}