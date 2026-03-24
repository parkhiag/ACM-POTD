# Day 3

## 1. Best Time to Buy or Sell Stocks 
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

### Screenshot of accepted solution
<img width="1919" height="850" alt="image" src="https://github.com/user-attachments/assets/44f737fc-9782-4dae-853c-c3b6e447473c" />


### Code
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cheapest=INT_MAX;
        int i=0; 
        int profit=0;

        while (i<prices.size()) {
            cheapest = min(cheapest,prices[i]);
            profit = max((prices[i] - cheapest),profit);
            i++;
        }
        return profit;
    }
};
