#include "InvestmentsFund.h" 

// this is the implementation file for Investments fund

// Constructor implementation
InvestmentsFund::InvestmentsFund(double initialInvestmentsAmount) : Fund(initialInvestmentsAmount){}


// implementation for adding positions to your investments
void InvestmentsFund::addPosition(const std::string& name, double amount, double avgPerformance){
    InvestmentPosition position(name, amount, avgPerformance);
    positions.push_back(position);
    totalAmount += amount; // update totalamount in baseclass
};

void InvestmentsFund::listPositions() const{
    std::cout << "Listing all investment positions:" << std::endl;

    for(size_t i = 0; i < positions.size(); i++){
        const InvestmentPosition& position = positions[i];
        std::cout << "Name: " << position.name << ", Amount: " << position.amount << ", Average Performance: " << position.avgPerformance << "%" << std::endl;
    }
}