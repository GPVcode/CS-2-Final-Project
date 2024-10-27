class Debts
{
protected:
    int totalDebt;
    double interestRate;
public: 
    Debts(int initialDebt = 0); // contructor

    virtual ~Debts(); // Virtual destructor for proper cleanup in derived classes

    // Public virtual methods for overriding
    virtual int getTotalDebt() const;
    virtual void setTotalDebt(int newDebt);
    
    virtual double getInterestRate() const {
        return interestRate;
    }

    virtual void setInterestRate(double rate) {
        interestRate = rate;
    }
};

Debts::Debts(int initialDebt) : totalDebt(initialDebt){

}

Debts::~Debts()
{
}
