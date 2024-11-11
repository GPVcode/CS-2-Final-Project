####Current Features:
1. Investment Management:
    - Track individual investment positions with amounts and performance rates.
    - Calculates the total value of investments
    - Projects future investment growth over a specified number of years.
2. Debt Management:
    - Tracks multiple debts, including credit cards and personal loans, each with its principal and interest rate.
    - Calculates the total amount of debt and the interest accrued.
    - Lists debts with detailed information on each debt's interest rate and minimum payments.
3. Overall Setup:
    -   Aggregates investments and debts, allowing users to view total funds and debt balance.
    -   Provides details on both growth in investments and obligations in debt.

### To help users find the best income allocation strategy, the following features would enhance the app:

#### Income Allocation Module:
Struture and Purpose
    1. Income and Expense Input: a class to capture the user's income and fixed expenses.
    2. Disposable Income Calculation: A method to calculate the income remaining after expenses, which will be allocated to debt and investments.
Key Classes and Responsibilites
    Income Class: Captures monthly income and calculates disposable income after deducting expenses.
    Expense Class: Holds data about each fixed expense (e.g., rent, utilities).
    AllocationCalculator: Calculates allocations for debt and investment based on disposable income.
Designing Class Relationships
    The Income class will hold a list of Expense objects.
    The Income class will communicate with AllocationCalculator to calculate allocations.
Allocation Calculator:
    The AllocationCalculator will:
        - Receive Disposable Income: Take in the disposable income amount.
        - Allocate Funds for Debt and Investment: Based on target percentages for debt reduction and investment (e.g., 50% to debt, 50% to investment).
#### Debt Repayment Strategy Module:
Prioritization Methods: 
    - Implement strategies such as the Debt Snowball (paying smallest debts first) and Debt Avalanche (paying highest-interest debts first).
Repayment Projections: 
    - Calculate how long it will take to pay off each debt based on different payment amounts and allocation strategies.
Interest Savings: 
    - Show users how much interest they’ll save by prioritizing certain debts.
### Savings and Investment Growth Strategy Module:
Emergency Fund Goal: 
    - Set up targets for emergency funds, e.g., 3–6 months of expenses, and show progress.
Investment Allocation: 
    - Recommend allocations to various investment types based on user goals, e.g., conservative, balanced, or aggressive.
Long-Term Projection: 
    - Provide future projections on investments considering regular contributions.
#### Optimization Engine Module:
Automated Suggestions: 
    - Based on income, debt levels, and investment goals, suggest the optimal way to allocate funds.
What-If Scenarios: 
    - Allow users to test different scenarios (e.g., increasing income or reducing expenses) and see how it impacts debt payoff and investment growth.
Goal Setting and Tracking: 
    - Enable users to set financial goals (debt-free date, savings milestones) and track their progress.
#### Reporting and Insights Module:
Summary Dashboard: 
    - Provide a high-level summary of financial health, including total debt, investments, projected growth, and repayment progress.
Monthly and Annual Reports: 
    - Show a breakdown of allocations, growth, and progress toward goals over time.







Some features to add:

Pending charges for currency validation - we need to ensure accounts that user is transfering funds from have funds.
Confirmation features for when moving funds around.


Considerations:
As per the demo we used streams to represent output for projections and other figures. When used as the backend structur for a frontend facing application, we'd have to convert our void functions to return real values. Suggestions are to return data through a structure such as a vector so that the data can be accessed by the client.

DebtManager:
We use dynamic memory allocation with pointers so the vector to hold various types of debt, keeping each type's specific methods and properties. This enables polymorphism, allowing each debt type to have its unique behavior.

InvestmentFunds:
We use a more static approach since the investment positions do not have individually unique characteristics, just different growth projecttions.

We can use this as the backend for a client facing application. We'd have to update the code to return data rather than using stream.