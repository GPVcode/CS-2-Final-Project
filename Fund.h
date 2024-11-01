#ifndef "main.cpp"

class Fund
{
protected:
    // Holds realtime value for fund. Can be influced thru other classes.
    float currentPocket;
    float currentInvestments;
    float currentBanking;
    float changeValue;
    float totalAll;
public:
    // TODO: Create a proper constructor

    virtual ~Fund(){}; // virtual destructor for Fund derived classes

    virtual float getCurrentFunding() const {
      return totalAll;
    }
    virtual float getCurrentInvestments() const {
      return currentInvestments;
    }
    virtual float getCurrentBanking() const {
      return currentBanking;
    }
    virtual float getCurrentBanking() const {
      return currentPocket;
    }
    // Base function (Would be manipulated and send value backward to apply change to either Banking, Investments, or Out of Pocket funds.)
    virtual void setChange(int newChange) {
      changeValue = newChange;
    }
    // In most cases will be called after a change is made to get funding up to date; unless showing a preview (TODO).
    virtual void setTotalAll() {
      totalAll = currentPocket + currentInvestments + currentBanking;
    }
    void previewFunds(); // TODO implement preview function.
};

#endif

// What would happen if it were to go negative on preview changes. "Game-ify" it so that it makes it clear that it should not be done.
// If not previewing, at all times should update funding types immediately.
// Should have an associated score that is relative to percentages and types of investment. User should set targets beforehand on these so that
// an end goal stays in mind and is displayed throughout.
