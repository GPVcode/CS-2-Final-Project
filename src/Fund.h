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

#endif
class OutOfPocket : Fund {
protected:
  float currentPocket;
public:
  OutOfPocket();
  virtual float getCurrentPocket() const {
    return currentPocket;
  }
};

class Investments : Fund {
protected:
  float currentInvestments;
public:
  Investments();
  virtual float getCurrentInvestments() const {
    return currentInvestments;
  }
};

class Banking : Fund {
protected:
  float currentBanking;
  bool isLocked;
public:
  Banking();
  virtual float getCurrentBanking() const {
    return currentBanking;
  }
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


// What would happen if it were to go negative on preview changes. "Game-ify" it so that it makes it clear that it should not be done.
// If not previewing, at all times should update funding types immediately.
// Should have an associated score that is relative to percentages and types of investment. User should set targets beforehand on these so that
// an end goal stays in mind and is displayed throughout.
