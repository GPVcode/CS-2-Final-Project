# Grassroots Financial Planner

Developed by Gabriel Villaruel and Brady Johnson

**Grassroots Financial Planner** is a comprehensive tool designed to optimize income allocation for debt repayment, investment growth, and emergency savings. The app uses financial principles and algorithms to determine the most effective allocation strategy for maximizing net worth.

---

## Key Features

### Completed Modules

1. **Investment Management**
   - Tracks and projects growth of individual investments.
   
2. **Debt Management**
   - Manages multiple debts, calculates total debt and interest, and provides repayment projections.
   
3. **Income Allocation**
   - Calculates disposable income after expenses and allocates funds between debt and investments based on customizable percentages.
   
4. **Debt Repayment Strategies**
   - Implements Debt Snowball and Debt Avalanche methods, showing potential interest savings for each strategy.

---

## App Modules & Structures

### Income Allocation Module

**Structure & Purpose**
   - **Income & Expense Input**: Captures user's income and expenses.
   - **Disposable Income Calculation**: Calculates remaining income after expenses for allocation.

**Key Classes & Responsibilities**
   - **Income Class**: Captures monthly income and calculates disposable income.
   - **Expense Class**: Holds data about fixed expenses.
   - **AllocationCalculator**: Uses disposable income to allocate funds toward debt and investment.

**Design & Implementation**
   - The `Income` class holds a list of `Expense` objects.
   - `AllocationCalculator` communicates with `Income` to determine allocation based on set percentages.

### Debt Repayment Strategy Module

**Features**
   - **Debt Snowball & Avalanche**: Prioritizes debt repayment based on smallest balance (Snowball) or highest interest rate (Avalanche).
   - **Repayment Projections**: Estimates the time required to pay off debts under each strategy.
   - **Interest Savings Calculation**: Provides potential interest savings for prioritized debts.

### Savings & Investment Growth Strategy Module

**Emergency Fund Goal**
   - Sets a target based on user’s monthly expenses (3–6 months).
   - Tracks progress towards achieving the emergency fund goal.

**Investment Allocation**
   - Recommends allocations to different investment types based on user goals (e.g., conservative, balanced, aggressive).
   - Provides long-term growth projections considering new contributions.

### Optimization Engine Module

**Features**
   - **Evaluate Inputs**: Analyzes debts by interest rate and investments by expected return.
   - **Priority Allocation**: Decides optimal allocation of disposable income for maximum net worth growth.
   - **Real-Time Suggestions**: Outputs recommendations based on financial inputs.

### Reporting & Insights Module

**Summary Dashboard**
   - Provides a high-level summary of financial health, total debt, investments, and repayment progress.
   
**Monthly & Annual Reports**
   - Shows a breakdown of allocation, growth, and progress over time.

---

## Financial Formulas Used

1. **Interest Savings on Debt Repayment**
   - **Formula:** `Interest Savings = Principal × (Rate / (1 - (1 + Rate)^(-Period)))`
   - **Usage:** Estimates the benefits of paying down high-interest debt earlier.

2. **Investment Growth Projection (Compound Interest)**
   - **Formula:** `Future Value = Contribution × (1 + Rate)^t`
   - **Usage:** Projects the future value of investment contributions over a set period.

3. **Average Return Rate Calculation for Investment Portfolio**
   - **Formula:** `Average Return = Σ(Investment Amount × Return Rate) / Total Investment`
   - **Usage:** Determines the overall portfolio return rate to compare with debt interest rates.

4. **Interest Accumulation on Remaining Debt**
   - **Formula:** `Monthly Interest = Remaining Principal × (Annual Interest Rate / 12)`
   - **Usage:** Calculates monthly interest payments on each debt.

---

## Additional Features for Future Development

1. **Currency Validation**: Ensures sufficient funds for transfers.
2. **Confirmation Features**: Prompts confirmations for fund transfers.
3. **Streamlined Output for Client Applications**: Adjust the backend to return structured data (e.g., via vectors) instead of direct stream output for better integration with client-facing apps.

---

## Code Structure Considerations

**DebtManager**
   - Uses dynamic memory allocation with pointers in a vector, enabling polymorphism across debt types, allowing each to maintain its specific behavior.

**InvestmentFunds**
   - Uses a more static structure since investment positions focus on growth projections without unique behaviors per investment.

**Frontend Consideration**
   - The backend currently uses stream output for projections and financial insights. For a frontend integration, functions can be adapted to return data structures rather than stream output, improving accessibility for client applications.

---

This README provides a comprehensive overview of the **Grassroots Financial Planner** app, its purpose, the financial principles applied, and areas for potential growth.

