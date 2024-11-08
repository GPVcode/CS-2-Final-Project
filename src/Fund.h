#ifndef "main.cpp"
#define FUND_H

class Fund
{
protected:
  // Holds realtime value for fund. Can be influced thru other classes.
  float totalAll;
  float pendingChange;
public:
  // TODO: Create a proper constructor once finished.
  Fund();
  // virtual destructor for Fund derived classes
  virtual ~Fund(){};
  // Base Class Items
  virtual float getCurrentFunding() const {
    return totalAll;
  }
  // In most cases will be called after a change is made to get funding up to date; unless showing a preview (TODO).
  virtual void setTotalAll() {
    totalAll = OutofPocket::getCurrentPocket() + Banking::getCurrentBanking() + Investments::getCurrentInvestments(); // Changed to returns from each
  }
};
class OutOfPocket : Fund {
public:
  // Changed to public to allow for call back. Need to find a way to secure this and still maintain call back.
  float currentPocket;
  OutOfPocket();
  virtual float getCurrentPocket() const {
    return currentPocket;
  }
  virtual void modifyPocket(){
    // No need for a data structure here. Will just use simple vector.
  }
};

class Investments : Fund {
public:
  // Changed to public to allow for call back. Need to find a way to secure this and still maintain call back.
  float currentInvestments;
  // Use a data structure to store investments by name and amount (for realism). (TODO)
  Investments();
  virtual float getCurrentInvestments() const {
    return currentInvestments;
  }
  virtual void addInvestment() {
    // Data Structure must follow a format of: [investmentName, investmentAmount, investmentType, memLocation]
    cout << "On the line enter your details about the investment you have wished to enter." << endl;
    // Gets line for investement; Add its to new index.
    cout << "Where would you like to take the funding for the investment from? Bank, Pocket, Surplus" << endl;
  }
  virtual void modifyInvestment(){
    // Data Structure part to modify values upon.
  }
  virtual void dissolveInvestment(){
    // Data Structure part to delete from index.
  }
};

class Banking : Fund {
public:
  // Changed to public to allow for call back. Need to find a way to secure this and still maintain call back.
  float currentBanking;
  bool isLocked;
  Banking();
  virtual float getCurrentBanking() const {
    return currentBanking;
  }
  // Utilize the following data structure: [bankName, investmentAmount, accountType, memLocation]
  virtual void withdraw() {
    char read;
    if(currentBanking <= 0) {
      cout << "Are you really sure you want withdraw this amount: " << pendingChange << endl;
      cout <<  "Doing so will lock your bank account. Y/N";
      cin >> read;
      if (read == "Y"){
        isLocked = true;
      } else {
        currentBanking = currentBanking + pendingChange;
        cout <<  "Declined Option, funds have not been modified and buffer cleared.";
      }
    }else{
      cout << "CONFIRM pending withdrawal of :" << pendingChange << "? Y/N" endl;
      cin >> read;
      if (read == "Y"){
        currentBanking = currentBanking - pendingChange;
      } else {
        cout << "Declined Option, funds have not been modified and buffer cleared.";
        pendingChange = 0;
      }
    }
  }
  virtual void deposit() {
    cout << "CONFIRM pending deposit of :" << pendingChange << "? Y/N" endl;
    char read;
    cin >> read;
    if (read == "Y"){
      currentBanking = currentBanking + pendingChange;
    } else {
      cout << "Declined Option, funds have not been modified and buffer cleared.";
      pendingChange = 0;
    }
  }
}
#endif

// What would happen if it were to go negative on preview changes. "Game-ify" it so that it makes it clear that it should not be done.
// If not previewing, at all times should update funding types immediately.
// Should have an associated score that is relative to percentages and types of investment. User should set targets beforehand on these so that
// an end goal stays in mind and is displayed throughout.
